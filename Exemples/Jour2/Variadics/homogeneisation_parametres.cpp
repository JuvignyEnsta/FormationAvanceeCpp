#include <iostream>
#include <algorithm>

template<typename T, typename ... Ts>
T max( T const& val1, T const& val2, Ts const&... vals ) {
    if constexpr (sizeof...(vals) == 0)
        return std::max(val1, val2);
    else {
        T valmax = max(val2, vals...);
        return std::max(val1, valmax);
    }
}

int main()
{
    double dmax = max(3.5,-4.6, 6.5, 3.2, 1.7);
    std::cout << "dmax : " << dmax << std::endl;
    // Erreur de compilation ci--dessous car type paramètres inhomogènes
    //auto emax = max(4, -3, 7.5, -6, 8.9);
    //std::cout << "emax : " << emax << std::endl;

    return EXIT_SUCCESS;
}