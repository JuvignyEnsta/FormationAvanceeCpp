#include <vector>
#include <iostream>
#include <memory>

namespace Algebra {
class Vecteur {
public:
    using iterator = std::vector<double>::iterator;

    iterator begin();
    iterator end  ();
private:
    std::vector<double> m_coefficients;
};
}

Algebra::Vecteur::iterator Algebra::Vecteur::begin()
{  return m_coefficients.begin();  }

auto Algebra::Vecteur::end() -> iterator
{  return m_coefficients.end();  }

template<typename K> 
auto square( K const& x ) -> K 
{  return x*x;  }

#include <complex>
#include <cmath>
using namespace std::complex_literals;

// Style C++ 11
template<typename K1, typename K2>
auto absadd(  K1 val1, K2 val2) -> decltype(std::abs(val1)+std::abs(val2))
{
    return std::abs(val1)+std::abs(val2);
}

// Style C++ 14
template<typename K1, typename K2>
auto absadd2(  K1 val1, K2 val2)
{
    return std::abs(val1)+std::abs(val2);
}

template<typename K1, typename K2>
auto maskedVAbsAdd( std::vector<K1> const& vecteur1, std::vector<K2> const& vecteur2,
                    std::vector<bool> const& mask ) -> std::shared_ptr<std::vector<decltype(std::abs(vecteur1[0])+std::abs(vecteur2[0]))>>
{
    // Compte le nombre d'éléments non masqués :
    std::size_t cpteur = 0;
    for ( auto const& flag : mask ) cpteur += (flag ? 1 : 0);
    if (cpteur == 0) return nullptr;
    using value_t = decltype(std::abs(vecteur1[0])+std::abs(vecteur2[0]));
    std::shared_ptr<std::vector<value_t>> pt_ret = std::make_shared<std::vector<value_t>>();
    pt_ret->reserve(cpteur);
    for ( std::size_t index = 0; auto const& flag : mask )
        {
            if (flag) pt_ret->push_back(std::abs(vecteur1[index])+std::abs(vecteur2[index]));
            ++index;
        }
    return pt_ret;
}

int main()
{
    std::complex<double> z = 1.+2.i;
    auto res1 = absadd(z, 2.f);
    std::cout << "res(dcomplex+float) = " << res1 << std::endl;
    std::cout << "sizeof(res(dcomplex+float)) = " << sizeof(res1) << std::endl;
    auto res2 = absadd(2.f+3.if, 2);
    std::cout << "res(fcomplex+int) = " << res2 << std::endl;
    std::cout << "sizeof(res(fcomplex+int)) = " << sizeof(res2) << std::endl;

    auto res3 = absadd2(z, 2.f);
    std::cout << "res(dcomplex+float) = " << res3 << std::endl;
    std::cout << "sizeof(res(dcomplex+float)) = " << sizeof(res3) << std::endl;
    auto res4= absadd(2.f+3.if, 2);
    std::cout << "res(fcomplex+int) = " << res4 << std::endl;
    std::cout << "sizeof(res(fcomplex+int)) = " << sizeof(res4) << std::endl;

    auto pt_res = maskedVAbsAdd( std::vector{1.+2.i, 3.+4.i,-1.+1.i}, std::vector{1, 3, 5},std::vector{ true, false, true} );
    for (auto const& val : *pt_res ) std::cout << val << " ";
    std::cout << std::endl;
    
    return EXIT_SUCCESS;
}
