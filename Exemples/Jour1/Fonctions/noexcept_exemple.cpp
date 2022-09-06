#include <vector>
#include <chrono>
#include <iostream>
#include <string>
using namespace std::string_literals;

namespace Algebra
{
    inline namespace without_noexcept
    {
    class Matrix
    {
    public:
        Matrix() = default;
        Matrix( std::string const& t_name, std::size_t t_nrows, std::size_t t_ncols )
            :   m_name(t_name),
                m_coefficients(t_nrows*t_ncols)
        {}
        Matrix( Matrix const& ) = default;
        Matrix( Matrix     && M )
        {
            m_name = std::move(M.m_name);
            m_coefficients = std::move(M.m_coefficients);
        }

        ~Matrix() = default;

        Matrix& operator = ( Matrix const& ) = default;
        Matrix& operator = ( Matrix     && ) = default;

    private:
        std::string m_name{};
        std::vector<double> m_coefficients{};
    };
    }

    namespace with_noexcept
    {
    class Matrix
    {
    public:
        Matrix() = default;
        Matrix( std::string const& t_name, std::size_t t_nrows, std::size_t t_ncols )
            :   m_name(t_name),
                m_coefficients(t_nrows*t_ncols)
        {}
        Matrix( Matrix const& ) = default;
        Matrix( Matrix     && M ) noexcept
        {
            m_name = std::move(M.m_name);
            m_coefficients = std::move(M.m_coefficients);
        }
        ~Matrix() = default;

        Matrix& operator = ( Matrix const& ) = default;
        Matrix& operator = ( Matrix     && ) noexcept = default;

    private:
        std::string m_name{};
        std::vector<double> m_coefficients{};
    };
    }
}

int main()
{
    constexpr const std::size_t nbMatrices = 1'000'000;

    std::cout << "Without noexcept : " << std::endl;
    for ( int i = 0; i < 10; ++i )
    {
    std::vector<Algebra::Matrix> matrices;
    auto start = std::chrono::steady_clock::now();
    for ( std::size_t iMat = 0; iMat < nbMatrices; ++iMat )
    {
        matrices.push_back(Algebra::Matrix("A"s + std::to_string(iMat), 4,4));
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
    }
    std::cout << "With noexcept : " << std::endl;
    for ( int i = 0; i < 10; ++i )
    {
    std::vector<Algebra::with_noexcept::Matrix> matrices;
    auto start = std::chrono::steady_clock::now();
    for ( std::size_t iMat = 0; iMat < nbMatrices; ++iMat )
    {
        matrices.push_back(Algebra::with_noexcept::Matrix("A"s, 4,4));
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
    }
    return EXIT_SUCCESS;
}