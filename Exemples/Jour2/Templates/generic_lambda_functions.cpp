#include <iostream>
#include <array>

template<typename T> auto    tpl_adder = [] ( T const& val1, T const& val2 ) -> T
{   return val1+val2;    };

template<typename K> struct Matrix {
    Matrix( std::uint32_t nbRows, std::uint32_t nbCols )
    {
        std::cout << "Construit matrice (" << nbRows << "x" << nbCols 
                  << ") containing " << typeid(K).name() << std::endl;
    }
};

template<typename K> auto matrixBuilderAdaptater = [] ( std::array<uint32_t,2> const& dimensions ) 
{    return Matrix<K>( dimensions[0], dimensions[1] );    };


int main() {
auto auto_adder= [] ( auto val1, decltype(val1) const& val2 ) -> decltype(val1)
{   return val1+val2;    };

    auto adouble = auto_adder(3., 5.2);
    std::cout << adouble << std::endl;
    // Fait un warning avec clang++ et rien du tout avec g++ !    
auto abizzare= auto_adder(3, 5.2);// Addition d'entiers ! 
    std::cout << abizzare << std::endl;
    
    auto tdouble = tpl_adder<double>(3., 5.2);
    std::cout << tdouble << std::endl;
auto tbizzare= tpl_adder<double>(3, 5.2);// Addition de réels
    std::cout << tbizzare << std::endl;

    auto matBuilder = matrixBuilderAdaptater<double>;
    matBuilder({ 5, 8 });

    return EXIT_SUCCESS;
}