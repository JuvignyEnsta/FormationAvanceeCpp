#include<iostream>

int main()
{
#if __cplusplus >= 202002L
    auto gen_add = [] <typename T> ( T const& a, T const& b )  { return a+b; };

    std::cout <<  gen_add(3,5) << std::endl;
    std::cout << gen_add(2.5,1.2) << std::endl;
# endif
#if __cplusplus >= 201402L
    auto gen_add2 = []  ( auto const& a, auto const& b ) { return a+b; };

    std::cout <<  gen_add2(3,5) << std::endl;
    std::cout << gen_add2(2,1.2) << std::endl;

    auto fibonacci = [](auto self,std::uint32_t n,std::uint32_t a=1,std::uint32_t b=1 ) ->std::uint32_t
    {
        return n>0 ? self(self,n-1,a+b,a) : b;
    };
    std::cout << "Fibonacci version 2014 " << std::endl;
    for ( std::uint32_t i=0; i<20; ++i)
        std::cout << "F_" << i << " = " << fibonacci(fibonacci, i) << std::endl;
#endif
    // Le code ci--dessous n'est pas encore supporté par la majorité des compilateurs. Wait and see...
#if __cplusplus > 202002L
    auto fibonacci23 =[]( this auto self, std::uint32_t n, std::uint32_t a=1, std::uint32_t b=1) -> std::uint32_t
    {
        return n>0 ? self(self,n-1,a+b,a) : b;
    };
    std::cout << "Fibonacci version 2023 " << std::endl;
    for ( std::uint32_t i=0; i<20; ++i)
        std::cout << "F_" << i << " = " << fibonacci23(i) << std::endl;
 #endif
    return EXIT_SUCCESS;
}

