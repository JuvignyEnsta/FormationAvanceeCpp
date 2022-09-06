#include <iostream>
#include <vector>
#include <cmath>

template<typename Func>
void transform( std::vector<double>& array, Func const& f )
{
    for (auto& val : array ) val = f(val);
}

template<typename F1, typename F2>
auto funcDiv(  F1 const& f1, F2 const& f2 )
{
    return [&f1, &f2] (double x) { return f1(x) / f2(x); };
}

int main()
{
    std::vector u{1.,2.,3.,5.,7.,11.,13.,17.};
    transform(u, [] (double x) { return x*x+1; } );
    for ( auto val : u ) std::cout << val << " ";
    std::cout << std::endl;

    const double pi = 3.141592653589793;
    
    auto f = funcDiv(  (double(*)(double))(std::cos), [] (double x) { return std::sin(x*x+1); }  );
    std::cout << "F(pi) = " << f(pi) << std::endl;

    return EXIT_SUCCESS;
}
