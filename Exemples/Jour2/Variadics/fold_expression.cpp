#include <iostream>
#include <complex>
#include <string>
#include <tuple>
#include <cmath>

using namespace std::complex_literals;
using namespace std::string_literals;

template<typename K>
std::ostream& operator << ( std::ostream& out, std::complex<K> const& value )
{
    out << value.real();
    if (value.imag() > 0)
        out << "+" << value.imag();
    else
        out << value.imag();
    out << " i";
    return out;
}

template<typename ... Ts> auto adder( Ts const&... values )
{   return (values + ... );    }

template<typename ... Ts> void cppPrintf( Ts const&... values )
{   (std::cout << ... << values );   }

template<typename Func, typename ... Ts> 
auto fadd( double initValue, Func&& func, Ts const&... values )
{   return (func(values)+...+initValue);    }

int main()
{
    cppPrintf( 1.5, " vaut ", 3, '/', 2, '\n');
    auto sum = adder (1.+2.i, 1.5, 3, 4.f);
    std::cout << "sum = " << sum << std::endl;
    auto str = adder("Tintin"s, " et ", "Milou."s);
    std::cout << "str : " << str << std::endl;

    auto fsum = fadd( -1., [](double x){ return std::sqrt(x); }, 3.1415, 17. );
    std::cout << "fsum = " << fsum << std::endl;
    return EXIT_SUCCESS;
}