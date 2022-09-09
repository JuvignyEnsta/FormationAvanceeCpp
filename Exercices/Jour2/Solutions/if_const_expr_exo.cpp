#include <iostream>
#include <type_traits>
#include <utility>
#include <type_traits>

template<typename Integer, Integer n> constexpr Integer
Fibonnaci()
{
    if constexpr (n==0)
        return Integer(0);
    else if constexpr (n==1)
        return Integer(1);
    else
        return Fibonnaci<Integer,n-1>() + Fibonnaci<Integer,n-2>();
}

template<int a, int b> constexpr auto resteQuotient()
{
    if constexpr (b%a==0)
        return b/a;
    else
        return std::pair<int,int>{b/a,b%a};
}

template<typename ResType> void display( int a, int b, ResType const& res )
{
    if constexpr (std::is_convertible_v<decltype(res), int>)
        std::cout << a << "/" << b << " = " << res << std::endl;
    else
        std::cout << a << "/" << b << " = " << res.first << "x" << b << "+" << res.second << std::endl;
}

int main()
{
    constexpr auto fib10 = Fibonnaci<long,10L>();
    std::cout << "fib(10) = " << fib10 << std::endl;

    constexpr int a1 = 6;
    constexpr int a2=7;
    constexpr int  b=24;
    constexpr auto res1 = resteQuotient<a1,b>();
    display(a1,b,res1);
    constexpr auto res2 = resteQuotient<a2, b>();
    display(a1,b,res2);

    return EXIT_SUCCESS;
}