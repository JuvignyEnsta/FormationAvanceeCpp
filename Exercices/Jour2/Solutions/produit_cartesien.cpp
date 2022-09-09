#include <tuple>
#include <iostream>
#include <utility>  
#include <string>
using namespace std::string_literals;

template<class Ch, class Tr, typename S, typename T> std::basic_ostream<Ch,Tr>&
operator << ( std::basic_ostream<Ch,Tr>& os, std::pair<S,T> const& pair )
{
    os << "{" << pair.first << "," << pair.second << "}";
    return os; 
} 

template<class Ch, class Tr, class... Args>
auto& operator<<(std::basic_ostream<Ch, Tr>& os,
                 const std::tuple<Args...>& t);

// pretty-print a tuple
template<class Ch, class Tr, class Tuple, std::size_t... Is>
void print_tuple_impl(std::basic_ostream<Ch,Tr>& os,
                      const Tuple& t,
                      std::index_sequence<Is...>)
{
    ((os << (Is == 0? "" : ", ") << std::get<Is>(t)), ...);
}
 
template<class Ch, class Tr, class... Args>
auto& operator<<(std::basic_ostream<Ch, Tr>& os,
                 const std::tuple<Args...>& t)
{
    os << "(";
    print_tuple_impl(os, t, std::index_sequence_for<Args...>{});
    return os << ")";
}

template<typename K1, typename Tuple, std::size_t... Indices> constexpr auto
productObjTuple( K1 const& obj11, Tuple const& tuple2,
                 std::index_sequence<Indices...> )
{
    return std::make_tuple(std::pair{obj11,std::get<Indices>(tuple2)}...);
}

template<typename Tuple1, typename Tuple2, std::size_t... Indices> constexpr auto
productCartHelper( Tuple1 const& tuple1, Tuple2 const& tuple2, std::index_sequence<Indices...> )
{
    return std::make_tuple( productObjTuple( std::get<Indices>(tuple1), tuple2, 
                            std::make_index_sequence<std::tuple_size_v<Tuple2>>{})...);
}

template<typename Tuple1, typename Tuple2> constexpr auto 
cartesianProduct( Tuple1 const& tuple1, Tuple2 const& tuple2 )
{
    return productCartHelper( tuple1, tuple2, std::make_index_sequence<std::tuple_size_v<Tuple1>>{});
}

int main()
{
    std::tuple tuple1{ "tin"s, 3.14, -3L, "mi"s, 4u, " FIN"s };
    std::cout << "Tuple1 : " << tuple1 << std::endl;

    std::tuple tuple2{ 3, "tin"s, 1.414, "lou"s, 0ULL, std::pair{"<---"s, 3}, "\n"s};
    std::cout << "Tuple2 : " << tuple2 << std::endl;

    auto prod = cartesianProduct(tuple1, tuple2);
    std::cout << "prod => \n" << prod << std::endl;
    return EXIT_SUCCESS;
}