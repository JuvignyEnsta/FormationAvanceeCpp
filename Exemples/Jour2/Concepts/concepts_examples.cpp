#include <concepts>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "polynome.hpp"

using namespace std::string_literals;

template<typename K> concept AnneauStructure = requires(K a, K b) {
    {a+b} -> std::convertible_to<K>;
    {a-b} -> std::convertible_to<K>;
    {a*b} -> std::convertible_to<K>;
    {-a } -> std::convertible_to<K>;
};

auto iteration_anneau( AnneauStructure auto const& X1, AnneauStructure auto const& X2, AnneauStructure auto const& X3)
{
    return X1*X2 - X3;
}

template<typename Container> concept Iterable = requires(Container c) {
    {c.begin()} -> std::convertible_to<typename Container::const_iterator>;
    {c.end()  } -> std::convertible_to<typename Container::const_iterator>; };

template<typename K> requires std::floating_point<K> || 
                            ( std::invocable<K> && 
                              std::floating_point<typename std::invoke_result<K>::type>)
void fill_container( Iterable auto& container, K&& value ) {
    if constexpr (std::invocable<K>) for (auto& coef : container ) coef = value();
    else for (auto& coef : container ) coef = value;       }

template<typename K,typename... ArgsType> concept ReelPeutEtreProcedural = std::floating_point<K> ||
      (std::regular_invocable<K,ArgsType...> && 
       std::floating_point<typename std::invoke_result<K,ArgsType...>::type>);

template<typename... ArgsType>
void fill_container_v2( Iterable auto& container, ReelPeutEtreProcedural<ArgsType...> auto&& value, 
                        ArgsType const& ... args )
{
    if constexpr (std::invocable<decltype(value),decltype(args)...>) 
        for (auto& coef : container ) coef = value(args...);
    else 
        for (auto& coef : container ) coef = value;
}

int main()
{
    auto val1 = iteration_anneau(1.5, -2., -4.);
    std::cout << "1.5*(-2.) - (-4.) = " << val1 << std::endl;

    Polynome P{1., 3., -2.}; // 1 + 3X -2X^2
    Polynome Q{-1., 2., 1.}; // -1 + 2X + X^2
    Polynome R{1.,1.}; // 1 + X
    auto val2 =  iteration_anneau(P, R, Q);
    std::cout << "(" << P << ").(" << R << ")-(" << Q << ") = " << val2 << std::endl;

    // Erreur compilation car operator - et * non définis
    // auto val3 = iteration_anneau("toto"s, "titi"s, "tutu"s);

    std::vector<double> tableau1(20), tableau2(20);
fill_container(tableau1, 3.14);
fill_container(tableau2, [counter=0]() mutable { ++counter; return 0.5*counter; } );
    for (auto const& value : tableau1 ) std::cout << value << "\t";
    std::cout << std::endl;
    for (auto const& value : tableau2 ) std::cout << value << "\t";
    std::cout << std::endl;

fill_container_v2(tableau2, [counter=0](int m) mutable { ++counter; return double(counter*m); }, 
                  random()%257 );
    for (auto const& value : tableau2 ) std::cout << value << "\t";
    std::cout << std::endl;

    return EXIT_SUCCESS;
}