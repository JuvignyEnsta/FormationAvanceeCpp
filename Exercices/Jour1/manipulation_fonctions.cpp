#include <functional>
#include <cmath>
#include <iostream>

template<typename FType, typename GType>
auto composite( FType const& f, GType const& g )
{
    return [&f,&g] (double x) { return f(g(x)); };
}

int main()
{
    auto f = composite( (double(*)(double))(std::cos), [] (double x){ return x*x+1; });
    std::cout << f(3.) << " ==? " << std::cos(10.) << std::endl; 
    return EXIT_SUCCESS;
}
