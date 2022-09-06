#include <iostream>
#include <array>
#include<cmath> 
#if __cplusplus >= 202002L
#include <numbers>
using std::numbers::pi;
#else
constexpr double pi = 3.141592653589793116;
#endif

class Circle
{
public:
    constexpr Circle( double radius ) : m_radius(radius)
    {}

    constexpr double aera() const { return pi*m_radius*m_radius; }
private:
    double m_radius;
};

constexpr double squareRoot( double x )
{
#   if __cplusplus > 202002L
    if consteval 
    {
#   endif
    // Utilise la méthode de Wilkes -- Wheeler et Gill (1950)
    double alpha=1, s = x;
    while (s >= 3) {
        alpha *= 2; s = s/4;
    }
    double a = s, c = s-1;
   
    while (std::abs(c)>1.E-16) {
        a = a - a*c/2.; c = c*c*(c-3)/4.;
    }
    return alpha*a;
#   if __cplusplus > 202002L
    }
    else { /*std::cout << "std::sqrt..." << std::endl;*/ return std::sqrt(x); }
#   endif
}

struct Vector
{
    double x,y,z;
    constexpr Vector(  double t_x, double t_y, double t_z )
        : x(t_x), y(t_y), z(t_z)
    {}
    constexpr double normL2() const
    {
        return squareRoot(x*x+y*y+z*z);
    }
};

#if __cplusplus >= 202002L
consteval double ipow( double x, unsigned p )
{
    double res = 1;
    for ( unsigned i = 0; i < p; ++i )
    {
        res *= x;
    }
    return res;
}
#endif

int main()
{
    constexpr int n1 = 10;
    const int n2 = 20;
    constexpr int n3 = n1 + n2;

    [[maybe_unused]] std::array<int,n1> a1;
    [[maybe_unused]] std::array<int,n3> a3;

    constexpr Circle circle(2.); 
    constexpr auto  aeraCircle = circle.aera();

    std::cout << "Aire du cercle : " << aeraCircle << std::endl;  

    constexpr Vector u{0.,3., -4.};
    constexpr auto nrmU = u.normL2();
    std::cout << "Norme de u : " <<  nrmU << std::endl;
    Vector v{0.,3.,-4.};
    std::cout << "Norme de v : " << v.normL2() << std::endl;

    double ip = ipow(2,10);
    std::cout << "2.^10 = " << ip << std::endl;
    [[maybe_unused]] double x = 3.;
    // Décommenter la ligne ci--dessous pour une erreur de compilation
    // double xp = ipow(x,10);
    return EXIT_SUCCESS;
}
