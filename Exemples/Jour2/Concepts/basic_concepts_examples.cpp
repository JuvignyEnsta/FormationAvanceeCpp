#include <iostream>
#include <string>
#include <concepts>
#include <iomanip>
#include <list>

template <class T>
constexpr
std::string_view type_name()
{
    using namespace std;
#ifdef __clang__
    string_view p = __PRETTY_FUNCTION__;
    return string_view(p.data() + 34, p.size() - 34 - 1);
#elif defined(__GNUC__)
    string_view p = __PRETTY_FUNCTION__;
#  if __cplusplus < 201402
    return string_view(p.data() + 36, p.size() - 36 - 1);
#  else
    return string_view(p.data() + 49, p.find(';', 49) - 49);
#  endif
#elif defined(_MSC_VER)
    string_view p = __FUNCSIG__;
    return string_view(p.data() + 84, p.size() - 84 - 7);
#endif
}

template<std::derived_from<std::ostream> OS>
OS& repr(OS& output, auto const& object)
{ output << "<" << type_name<decltype(object)>() 
         << ">{" << object << "}"; return output; }

auto maFonction( std::floating_point auto const& x )
{ return x*x/3 - x/7 + 3; }

template<typename T, typename ContainerT>
    requires std::same_as<T,typename ContainerT::value_type>
void add( T const& value, ContainerT& container )
{   for (auto& coef : container ) coef += value;    }

int
main()
{
    repr(std::cout, 3.1415) << std::endl;    
    //repr(4, 3.1415);// Ne compile pas, mais message erreur intéressante

    repr(std::cout << std::setprecision(14), maFonction(1.5)) << " ... ";
    repr(std::cout << std::setprecision(14), maFonction(1.5f)) << std::endl;

    std::list aList{ 1., 3., 5., 2., 6.};
    add(0.5,aList);
    for ( auto const& val : aList )
        std::cout << val << " ";
    std::cout << std::endl;
    //add(1u,aList);

    return EXIT_SUCCESS;
}
