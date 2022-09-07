#include <iostream>
#include <string>

template<typename T, typename... Types> struct Tuple : public Tuple<Types...> {
    T current_obj;
    Tuple( T const& current_value, Types const &... other_values)
        :   Tuple<Types...>(other_values...), current_obj(current_value) {}
    template<std::size_t n> auto const& get()
    { if constexpr (n==0) return current_obj; else  return Tuple<Types...>:: template get<n-1>(); }
};

template<typename T> struct Tuple<T> {
    T current_obj;
    Tuple( T const& current_value ) :   current_obj(current_value)    {}
    template<std::size_t n> auto const& get() 
    { static_assert(n==0, "Error, n out of range"); return current_obj; }
};

int main() { 
    Tuple<double, std::string,int,char> tuple(3.5, "Milou", 42, 'c');
    std::cout << tuple.get<0>() << " " << tuple.get<1>() << " "
              << tuple.get<2>() << " " << tuple.get<3>() << std::endl;

    return EXIT_SUCCESS;
}