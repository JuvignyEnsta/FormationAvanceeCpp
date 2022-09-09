#include <iostream>

template<typename Type, Type val> constexpr Type constante1 = val;
template<auto val> constexpr decltype(val) constante2 = val;

template<auto A, auto n> constexpr decltype(A) heron = 0.5*(heron<A,n-1>+A/heron<A,n-1>);
template<auto A> constexpr decltype(A) heron<A,0> = A;


int main()
{
    std::cout << constante1<float,3.141592653589793f>  << "= " 
              << constante2<3.141592653589793f> << std::endl;


    std::cout << heron<2.,10> << std::endl;

    return EXIT_SUCCESS;
}
