#include <vector>
#include <array>
#include <iostream>
#include <cstdlib>

template<typename K> struct Matrix {
    Matrix( std::array<std::uint32_t,2> const& t_dimensions, K const& t_initValues );
    Matrix( std::array<std::uint32_t,2> const& t_dimensions, std::vector<K> const& t_values );
    ~Matrix() = default;
    std::vector<K> m_coefs;
};
template<typename K>
Matrix(std::array<std::uint32_t,2> const& t_dimensions,K const& t_initValues) -> Matrix<K>;
template<typename K>
Matrix(std::array<std::uint32_t,2> const& t_dimensions,std::vector<K> const& t_values ) -> Matrix<K>;

template<typename K>
Matrix<K>::Matrix( std::array<std::uint32_t,2> const& t_dimensions, K const& t_initValues )
    :   m_coefs(t_dimensions[0]*t_dimensions[1], t_initValues)
{}

template<typename K>
Matrix<K>::Matrix( std::array<std::uint32_t,2> const&, std::vector<K> const& t_values )
    :   m_coefs(t_values)
{}

int main()
{
    [[maybe_unused]] Matrix A( {3,3}, 0.0f);
    [[maybe_unused]] Matrix B( {2,2}, std::vector{1.,0.,
                                                  0.,1.});
}