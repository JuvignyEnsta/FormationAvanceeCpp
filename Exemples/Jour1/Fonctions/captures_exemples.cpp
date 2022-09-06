#include <vector>
#include <cmath>
#include <iostream>
#include <functional>

class Polynome {
public:
    Polynome( std::vector<double> const& t_coefs )
        :    m_coefs(t_coefs)
    {}
    Polynome( Polynome const& ) = default;
    ~Polynome() = default;

    double& operator[] ( std::uint32_t t_index ) {
        return m_coefs[t_index];
    }

    double const& operator [] ( std::int32_t t_index ) const
    {
        return m_coefs[t_index];
    }

    std::uint32_t  degree() const { return static_cast<std::uint32_t>(m_coefs.size()-1); }

 auto primitive( double t_constante ) const  {
    return [*this,t_constante] ( double x ) {
      double value = t_constante;
      for ( std::uint32_t iDeg = 0;
                 iDeg <= degree(); ++iDeg ) 
           value += std::pow(x,iDeg+1)/(iDeg+1.);
       return value;
     };
    }
    
private:
    std::vector<double> m_coefs;
};// Fin class Polynome

auto d( Polynome const& P ) {
  return [P] ( double x )
  {
    double value = 0.;
    for (std::uint32_t i=1; i<=P.degree(); ++i)  {
        value += i*P[i]*std::pow(x, i-1);
     }
    return value;
  };
}


int main()
{
    Polynome P({1.,1.,1.});
    auto intP = P.primitive(1.);
    std::cout << "intP(1.) = " << intP(1.) << std::endl;
    auto dP = d(P);
    std::cout << "dP(1.) = " << dP(1.) << std::endl;


    // Variable globale
    std::vector<std::uint32_t> fibCoefs;

    // Deux remarques pour la fonction anonyme ci--dessous :
    // 1. Pour employer un appel récursif dans une lambda-fonction, il est obligatoire d'encapsuler la lambda-fonction
    //     dans le wrapper std::function afin que le compilateur sache qu'il est licite de faire un appel à fibonacci.
    //     En effet, pour une lambda fonction, il est obligatoire d'utiliser auto qui n'est résolu qu'à la fin de la compilation
    //     de la lambda-fonction, et donc le compilateur ne peut pas savoir durant la compilation si fibonacci est un foncteur
    //     (un type ressemblant à une fonction )  ou non.
    // 2. Toujours pour la récursion, il faut capturer le foncteur lui-même pour pouvoir l'appeler récursivement. Pour cela,
    //      il est obligatoire de le capturer par référence, car une copie par valeur n'est pas valide (pourquoi ? je ne sais pas).
    std::function<std::uint32_t(std::uint32_t)>
        fibonacci =
        [&fibCoefs,&fibonacci] (std::uint32_t n)
        ->std::uint32_t {
        if (fibCoefs.size() < n+1)
            fibCoefs.resize(n+1);
        if (n>0) fibonacci(n-1);
        if (n < 2) fibCoefs[n] = 1; else
            fibCoefs[n]=fibCoefs[n-1]+fibCoefs[n-2];
        return fibCoefs[n];
    };
    for ( std::uint32_t iter = 0; iter<20; ++iter)
        {
            std::cout << "Fibonacci(" << iter << ") = " << fibonacci(iter) << std::endl;
        }
    return EXIT_SUCCESS;
}
