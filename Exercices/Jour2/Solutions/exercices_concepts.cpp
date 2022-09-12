#include <concepts>
#include <iostream>
#include "fraction_rationnelle.hpp"

template<typename K> concept AnneauStructure = requires(K a, K b) {
    {a+b} -> std::convertible_to<K>;
    {a-b} -> std::convertible_to<K>;
    {a*b} -> std::convertible_to<K>;
    {-a } -> std::convertible_to<K>;
};

template<typename K> concept Divisible = requires(K a, K b) {
    {a/b} -> std::convertible_to<K>;
};

template<typename K> concept Inversible = requires(K a) {
    {a.inverse()} -> std::convertible_to<K>;
};

template<typename K> concept CorpsStructure = AnneauStructure<K> && (Divisible<K> || Inversible<K>);

template<typename K> requires CorpsStructure<K>
auto solve( K const& aValue, K const& bValue)
{
    if constexpr(Divisible<K>) return -bValue/aValue;
    else return -aValue.inverse()*bValue;
}

int main()
{
    auto sol1 = solve(3.,5.);

    auto sol2 = solve(3,5);// Marche mais bon, pas la bonne solution ^^

    auto Q1 = FractionRationnelle{ Polynome{1.,-2.,1.}, Polynome{1.,0.,1.} };
    auto Q2 = FractionRationnelle{ Polynome{1.,+2.,1.}, Polynome{1.,0.,2.} };

    auto sol3 = solve(Q1,Q2);

    std::cout << "5./3. = " << sol1 << ", 5/3 = " << sol2 << " et " << Q1 << " / " << Q2
              << " = " << sol3 << std::endl;

    return EXIT_SUCCESS;
}