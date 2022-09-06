#include <iostream>
#include <compare>
#include <limits>
#include <cstdlib>
#include <array>  


/**
 * @brief Classe modélisant la classe des entiers module P
 * 
 */
template<std::uint32_t P>
struct ModClassP
{
    std::uint32_t value;
    ModClassP( std::uint32_t t_value ) : value(t_value) {}

    auto operator <=> ( const ModClassP& t_val2 ) const
    {
        auto valModP = value%P;
        auto val2ModP= t_val2.value%P;
        if (valModP>val2ModP) return std::weak_ordering::greater;
        if (valModP<val2ModP) return std::weak_ordering::less;
        return std::weak_ordering::equivalent;
    }
#   if defined(DEFINE_EQUAL_OP)
    bool operator == ( const ModClassP& t_val2 ) const
    {
        if (value%P == t_val2.value%P) return true;
        return false;
    }
#   endif
};

template<std::uint32_t P>
std::ostream& operator << ( std::ostream& out, ModClassP<P> const& t_value )
{
    out << t_value.value << "( ≡ " << t_value.value%P << "[" << P << "] )";
    return out;
}

class Vecteur
{
public:
    enum Direction { X=0, Y=1, Z=2};

    Vecteur( std::array<double,3> const& t_coords) : m_coords(t_coords)
    {}

    std::array<double,3> const& coords() const { return m_coords; }

    auto operator <=> ( Vecteur const& ) const = default;

    double const& operator [] ( Direction dir ) const { return m_coords[dir]; }
private:
    std::array<double,3> m_coords;
};

std::ostream& operator << ( std::ostream& out, Vecteur const& u )
{
    using Direction=Vecteur::Direction;
    out << "<" << u[Direction::X] << ", " << u[Direction::Y] << ", " << u[Direction::Z] << ">";
    return out; 
}

int main()
{
    constexpr std::uint32_t number_of_sampling = 10;
    constexpr std::uint32_t maxValue = std::numeric_limits<std::uint32_t>::max();
    std::cout << "Comparaison d'entier module 13 : " << std::endl; 
    for (std::uint32_t index=0; index<number_of_sampling; ++index)
    {
        ModClassP<13> val1(rand()%maxValue);
        ModClassP<13> val2(rand()%maxValue);
        if (val1 < val2) std::cout << val1 << " < " << val2 << std::endl;
        if (val1 <= val2) std::cout << val1 << " ≤ " << val2 << std::endl;
        if (val1 > val2) std::cout << val1 << " > " << val2 << std::endl;
        if (val1 >= val2) std::cout << val1 << " ≥ " << val2 << std::endl;
#   if defined(DEFINE_EQUAL_OP)
        if (val1 == val2) std::cout << val1 << " ≡ " << val2 << std::endl;
        if (val1 != val2) std::cout << val1 << " ≠ " << val2 << std::endl;
#   endif

        auto cmp = val1 <=> val2;
        if (cmp == 0) std::cout << "\t" << val1 << " ≡ " << val2 << std::endl;
        if (cmp >  0) std::cout << "\t" << val1 << " > " << val2 << std::endl;
        if (cmp <  0) std::cout << "\t" << val1 << " < " << val2 << std::endl;

        if (cmp == std::weak_ordering::equivalent) std::cout << "\t" << val1 << " ≡ " << val2 << std::endl;
        if (cmp == std::weak_ordering::less      ) std::cout << "\t" << val1 << " < " << val2 << std::endl;
        if (cmp == std::weak_ordering::greater   ) std::cout << "\t" << val1 << " > " << val2 << std::endl;
    }

    constexpr std::uint32_t vMaxVal = 3;
    std::cout << "Comparaison de vecteurs avec opérateur vaisseau par défaut : " << std::endl;
    for (std::uint32_t index=0; index<number_of_sampling; ++index)
    {
        Vecteur u( { 0.1*(rand()%vMaxVal), 0.1*(rand()%vMaxVal), 0.1*(rand()%vMaxVal)});
        Vecteur v( { 0.1*(rand()%vMaxVal), 0.1*(rand()%vMaxVal), 0.1*(rand()%vMaxVal)});

        if (u<v) std::cout << u << " < " << v << std::endl;
        if (u>v) std::cout << u << " > " << v << std::endl;
        if (u==v) std::cout << u << " = " << v << std::endl;
    }
    return EXIT_SUCCESS;
}