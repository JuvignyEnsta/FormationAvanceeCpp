#include <chrono>
#include <iostream>
#include <iomanip>
#include <bit>
#include <vector>

using entier_t = std::uint64_t;
constexpr entier_t maxIter        = 2'000;


inline namespace no_likely
{
double dfact(entier_t n) noexcept
{
    if (n>1)
        return n/1.*dfact(n-1);
    else
        return 1;
}

double apow( double x, entier_t n ) noexcept
{
    if (n>0)
        return x * apow(1.-x/n,n-1);
    else
        return 1;
}

double lambert_1( double q ) noexcept
{
    double sum = 0.;
    for ( entier_t iSum = 1; iSum <= 1000; ++iSum )
    {
        auto qn = apow(q,iSum);
        sum += (1./dfact(iSum))*qn/(1.-qn);
    }
    return sum;
}    
}

int main()
{
    std::cout << "Sans l'attribut [[likely]] : " << std::endl; 
  auto start = std::chrono::high_resolution_clock::now();
  std::vector<double> values(maxIter);
  for ( entier_t iter = 0; iter < maxIter; ++iter ) {
      double q = iter/(2.*maxIter);
      values[iter] = lambert_1(q);
  }
  std::chrono::duration<double> diff =
            std::chrono::high_resolution_clock::now() - start;
    std::cout << "Time: " << std::fixed << std::setprecision(6) << diff.count()
                  << " sec " << std::endl;
    double maxValue = values[0];
    for ( entier_t iter = 1; iter <= maxIter; ++iter )
        maxValue = std::max(maxValue, values[iter]);
    std::cout << "Lambert_1 max value " << maxValue << std::endl;

    std::cout << "Avec l'attribut [[likely]] : " << std::endl; 
    // ...
    
    return EXIT_SUCCESS;
}
