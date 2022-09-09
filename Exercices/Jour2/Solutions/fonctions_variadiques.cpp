#include <cstdlib>
#include <iostream>
#include <string>
using namespace std::string_literals;

template<typename T, typename... Ts> 
constexpr T max(T const& val1, T const& val2, Ts const&... vals)
{
    if constexpr (sizeof...(vals)==0)
        return val1>val2 ? val1 : val2;
    else 
    {
        T maxval = max(val2,vals...);
        return val1 > maxval ? val1 : maxval;
    }
}

template<typename Func, typename T, typename ... Ts> void
apply( Func&& f, T& arg1, Ts&... args)
{
    f(arg1);
    if constexpr (sizeof...(args) > 0)
    {
        apply(f, args...);
    }
}

int main()
{
    constexpr double maxCoef = max(1., -3., 4., 6., 2., 2.4, -8., 3.);
    std::cout << "maxcoef = " << maxCoef << std::endl;

    //constexpr int imaxCoef = max(1, -3, 4, 6, 2, 2.4, -8, 3);

    double x = 1.57;
    int    a = 52;
    std::string s = "tin"s;

    apply([](auto& x) { x += x;}, x, a, s);

    std::cout << "x = " << x << "; a = " << a << "; s = " << s << std::endl;

    return EXIT_SUCCESS;
}