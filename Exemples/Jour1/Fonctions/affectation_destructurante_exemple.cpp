#include <tuple>
#include <vector>
#include <algorithm>
#include <iostream>
#include <complex>
#include <array>

std::pair<std::size_t, double>  locAbsMax( std::vector<double> const& array ) {
    std::size_t loc = 0;
    double valMax = std::abs(array[0]);
    for ( std::size_t i=1; i<array.size(); ++i) {
        double curVal = std::abs(array[i]);
        if (curVal>valMax) {
            loc=i;
            valMax=curVal;
        }
    }
    return {loc, valMax};
}

template<int deg> std::array<std::complex<double>,deg> nthUnityRoots() {
    static_assert(deg>0);
    constexpr double pi=3.141592653589793;
    double angle=2.*pi/deg;
    std::array<std::complex<double>,deg> roots;
    for ( int i=0; i<deg; ++i) roots[i] = std::complex{ std::cos(i*angle), std::sin(i*angle)};
    return roots;
}

int main()
{
    std::vector<double> data{ 1., -1., 2., -3., 4., -8., 6., -5., 2. };
    auto [iloc, val] = locAbsMax(data);
    std::cout << "data[" << iloc << "]=" << val << std::endl;

    auto [r1,r2,r3] = nthUnityRoots<3>();
    std::cout << "Racine cubique de l'unité : " << r1 << ", " << r2 << ", " << r3 << std::endl;

    std::array<std::array<double,4>,4> matrix;
    for ( auto& row : matrix )
        std::fill(row.begin(), row.end(), 0.);
    for ( auto& [i,j,x] : std::vector{ std::tuple{ 0, 0,  4.},
                                                 { 0, 1, -1.},
                                                 { 1, 0, -1.},
                                                 { 1, 1,  4.},
                                                 { 1, 2, -1.},
                                                 { 2, 1, -1.},
                                                 { 2, 2, -4.},
                                                 { 2, 3, -1.},
                                                 { 3, 2, -1.},
                                                 { 3, 3,  4.} } )
    {
        matrix[i][j] = x;
    }

    for ( int i = 0; i < 4; ++i )
    {
        for ( int j = 0; j < 4; ++j )
            std::cout << matrix[i][j] << "\t";
        std::cout << std::endl;
    }
    return EXIT_SUCCESS;
}
                                