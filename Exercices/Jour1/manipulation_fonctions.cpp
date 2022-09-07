#include <functional>
#include <cmath>

int main()
{
    auto f = composite( std::function<double(double)>(std::cos), [] (double x){ return x*x+1; });
    auto g = 
