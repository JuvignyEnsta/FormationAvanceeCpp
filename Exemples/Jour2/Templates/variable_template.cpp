#include <cstdio>
#include <cstdint>
#include <cstdlib>

template<typename K, std::uint32_t n> constexpr K fact = n*fact<K,n-1>;
template<typename K> constexpr K fact<K,0> = K(1);

int main() {
    printf("10! = %12.6lf\n", fact<double,10>);
    return EXIT_SUCCESS;
}