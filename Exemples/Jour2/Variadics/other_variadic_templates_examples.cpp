#include <iostream>
#include <array>
#include <cmath>

template<std::size_t size1, std::size_t... sizes>
double gen_sqrnorms( std::array<double,size1> const& array1,
                     std::array<double,sizes> const&... arrays )
{
    double nrm = 0.;
    for ( std::size_t iCoefs=0; iCoefs<size1; ++iCoefs)
        nrm += array1[iCoefs]*array1[iCoefs];
    if constexpr (sizeof...(arrays))
        return nrm + std::move(gen_sqrnorms(arrays...));
    else
        return nrm;
}

int main()
{
    std::array arr1{2., 3., 6.};
    std::array arr2{4., 3.};
    std::array arr3{-2., 7., 8., -1.};

    auto res = gen_sqrnorms( arr1, arr2, arr3 );
    std::cout << res << std::endl;

    return EXIT_SUCCESS;
}