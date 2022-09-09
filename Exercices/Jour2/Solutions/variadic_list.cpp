#include <iostream>

template<typename Scalar, Scalar v1, Scalar... vn>
struct StaticList : public StaticList<Scalar, vn...>
{
    std::ostream& display( std::ostream& out ) const
    {
        out << v1 << " ";
        StaticList<Scalar, vn...>::display(out);
        return out;
    }

    template<Scalar v> constexpr
    auto pushFront() const { return StaticList<Scalar,v, v1, vn...>{}; }

    template<Scalar v> constexpr
    auto pushBack() const { return StaticList<Scalar,v1, vn..., v>{}; }

};

template<typename Scalar, Scalar v1> struct StaticList<Scalar, v1>
{
    std::ostream& display( std::ostream& out ) const
    {
        out << v1 << " ";
        return out;
    }

    template<Scalar v> constexpr
    auto pushFront() const { return StaticList<Scalar,v, v1>{}; }

    template<Scalar v> constexpr
    auto pushBack() const { return StaticList<Scalar,v1,v>{}; }

};

template<typename Scalar, Scalar v1, Scalar v2, Scalar... vn>
constexpr bool isSorted( StaticList<Scalar, v1,v2,vn...> const& lst )
{
    if constexpr (sizeof...(vn))
        return (v1<=v2) && isSorted(StaticList<Scalar,v2,vn...>{});
    else
        return (v1<=v2);
}

template<typename Scalar, Scalar v1, Scalar v2, Scalar... vn>
constexpr auto sort( StaticList<Scalar, v1, v2, vn...> const& lst )
{
    if constexpr (isSorted(StaticList<Scalar,v1,v2,vn...>{} ))
        return lst;
    else 
    {
        if constexpr(sizeof...(vn))
        {
            if constexpr (v1 > v2)
            {
                auto sublist = sort(StaticList<Scalar,v1,vn...>{});
                return sort(sublist.template pushFront<v2>());
            }
            else
            {
                auto sublist = sort(StaticList<Scalar,v2,vn...>{});
                return sort(sublist.template pushFront<v1>());
            }
        }
        else 
        {
            if constexpr (v1 > v2)
                return StaticList<Scalar,v2,v1>{};
            else
                return StaticList<Scalar,v1,v2>{};
        }
    }
}

template<typename Scalar, Scalar v1, Scalar v2, Scalar... vn>
constexpr auto unique( StaticList<Scalar, v1, v2, vn...> const& lst )
{
    if constexpr (!isSorted(StaticList<Scalar, v1, v2, vn...>{}))
    {
        return unique(sort(lst));
    }
    else 
    {
        if constexpr (sizeof...(vn))
        {
            if constexpr (v1==v2)
            {
                return unique(StaticList<Scalar, v1, vn...>{});
            }
            else
            {
                auto sublist = unique(StaticList<Scalar,v2,vn...>{});
                return sublist.template pushFront<v1>();
            }
        }
        else 
        {
            if constexpr (v1==v2)
            {
                return StaticList<Scalar,v2>{};
            }
            else return StaticList<Scalar,v1,v2>{};
        }
    }
}

template<typename Scalar, int v1, int... vn>
std::ostream& operator << ( std::ostream& out, StaticList<Scalar, v1,vn...> const& lst )
{
    out << "[ ";
    lst.display(out);
    out << "]";
    return out;
}

int main()
{
    constexpr StaticList<int, 2,3,5,7,11,13,17> lst1;
    std::cout << "lst1 : " << lst1 << std::endl;
    constexpr auto lst12 = lst1.pushFront<19>();
    constexpr auto lst2  = lst12.pushBack<23>();

    std::cout << "lst2 : " << lst2 << std::endl;

    if constexpr(isSorted(lst1))
        std::cout << "lst1 est trié" << std::endl;

    if constexpr(isSorted(lst2))
        std::cout << "lst2 est trié" << std::endl;

    constexpr auto lst3 = sort(lst2);
    std::cout << "lst3 : " << lst3 << std::endl;

    constexpr StaticList<double, 3.5, 7., 2.5, 52., -6.6, 3.5, 0., 9.2, -54.1, 43.> lst4;
    std::cout << "[ "; lst4.display(std::cout);  std::cout << "]" << std::endl;

    constexpr auto lst4trie = sort(lst4);
    std::cout << "lst4 trié : [ "; lst4trie.display(std::cout); std::cout << "]" << std::endl;

    constexpr auto lst4unique = unique(lst4);
    std::cout << "lst4 unique : ["; 
    lst4unique.display(std::cout); std::cout << "]" << std::endl;

    return EXIT_SUCCESS;
}