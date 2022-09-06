#include <iostream>
#include <vector>

namespace algebra {
    namespace deprecated {
        struct [[deprecated]] Matrix  {
           int dimension;
           double* coefficients;
        };
    }
    inline namespace newversion {
        class Matrix {
        public:
            using index_t            = std::uint32_t;
            using coefficients_t  = std::vector<double>;
        private:
            coefficients_t m_coefficients{};
        };
    }
}

[[deprecated("Vieille version de GMRES. Plutot utiliser la nouvelle") ]]
void GMRES( algebra::deprecated::Matrix const&  A, std::vector<double> const& b,
                     std::vector<double>& x, double& residu, double epsilon,
                     int nombre_iterations_externes, int nombre_iterations_internes);

std::pair<std::vector<double>,double>
GMRES( algebra::Matrix const& A, std::vector<double> const& b, double  epsilon,
             int nombre_iterations_externes, int nombre_iterations_internes );

void GMRES( algebra::deprecated::Matrix const&  A, std::vector<double> const& b,
                     std::vector<double>& x, double& residu, double epsilon,
                     int nombre_iterations_externes, int nombre_iterations_internes)
{
    std::cout   << "Deprecated GMRES" << std::endl;
}

std::pair<std::vector<double>,double>
GMRES( algebra::Matrix const& A, std::vector<double> const& b, double epsilon,
       int nombre_iterations_externes, int nombre_iterations_internes )
{
    std::cout << "New GMRES" << std::endl;
    return { {}, 0. };
}

int main()
{
    double res;
    std::vector<double> solution;
    algebra::deprecated::Matrix A;
    GMRES(A, {}, solution, res, 1.E-14, 100, 100);

    algebra::Matrix A2;
    auto [sol,residu] = GMRES(A2, {}, 1.E-14, 100, 100);
    return EXIT_SUCCESS;
}
                                                                               

