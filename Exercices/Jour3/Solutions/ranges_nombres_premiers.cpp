#include <cstdlib>
#include <ranges>
#include <iostream>
#include <vector>
#include <cstdint>

struct PrimesHelper
{
    bool operator () ( std::uint64_t n ) const
    {
        bool isPrime = true;
        for ( std::size_t iPrime=0; ((iPrime<primes.size()) && (primes[iPrime]*primes[iPrime]<=n) && 
                                     (isPrime==true) ); ++iPrime )
        {
            if (n%primes[iPrime] == 0) isPrime = false;
        }
        if (isPrime) primes.emplace_back(n);
        return isPrime;
    }

    mutable std::vector<std::uint64_t> primes{};
};

int main(int nargs, char const* argv[])
{
    int nbPrimes = 1000;
    if (nargs>1) nbPrimes = std::atoi(argv[1]);

    auto primes = std::ranges::views::iota(2) 
                      | std::ranges::views::filter([pHelper=PrimesHelper{}](std::uint32_t n) { return pHelper(n); });

    for (auto p : primes | std::ranges::views::take(nbPrimes)) std::cout << p << " ";
    std::cout << std::endl;

    return EXIT_SUCCESS;
}