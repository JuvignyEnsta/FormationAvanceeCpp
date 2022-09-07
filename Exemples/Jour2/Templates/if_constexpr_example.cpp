#include <iostream>

template<typename Integer, Integer n>
Integer factorial() {
    if constexpr (n==0) 
        return Integer(1);
    else 
        return n*factorial<Integer,n-1>();
}

int main() {
    auto factval = factorial<long long, 10LL>();
    std::cout << "10! = " << factval << std::endl;
    return EXIT_SUCCESS;
}
