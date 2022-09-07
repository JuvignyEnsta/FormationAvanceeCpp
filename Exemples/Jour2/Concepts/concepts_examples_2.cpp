#include <concepts>
#include <list>
#include <iostream>

template<typename Container> concept Iterable = requires(Container c) {
    {c.begin()} -> std::convertible_to<typename Container::const_iterator>;
    {c.end()  } -> std::convertible_to<typename Container::const_iterator>; };

template<typename Container> concept IterableOnIntegers = 
            Iterable<Container> &&  std::integral<typename Container::value_type>;

void filterPrint( IterableOnIntegers auto const& t_tableau, std::predicate<int> auto&& t_filter )
{
    for (auto const& value : t_tableau )
        if (t_filter(value)) std::cout << value << " ";
    std::cout << std::endl;
}



int main()
{
    std::list entiers{ 2, 3, 6, 11, 17, 22, 27 };
    filterPrint( entiers, [](int value) { return (value%2==0) || (value%3==0); });
    return EXIT_SUCCESS;
}