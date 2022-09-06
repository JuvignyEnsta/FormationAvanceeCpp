#include <iostream>
#include <vector>
#include <cassert>

class Vecteur
{
public:
    using iterator = std::vector<double>::iterator;
    Vecteur() = default;
    Vecteur( std::size_t dim )
        :    m_coefs(dim)
    {}
    Vecteur( std::initializer_list<double> const& coefs )
        :    m_coefs(coefs)
    {}
    
    Vecteur( Vecteur const& u )
        :    m_coefs(u.m_coefs)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    
    Vecteur( Vecteur           && u)
        :    m_coefs(std::move(u.m_coefs))
     {
         std::cout << __PRETTY_FUNCTION__ << std::endl;
     }
  
    ~Vecteur()                                 = default;

    Vecteur& operator = ( Vecteur const &  u)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        m_coefs = u.m_coefs;
        return *this;
    }

    Vecteur& operator = ( Vecteur            &&  u)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        m_coefs.swap(u.m_coefs);;
        return *this;
    }

    std::size_t dimension() const { return m_coefs.size(); }
    
    double& operator[] ( std::size_t index )
    {
        assert(index < m_coefs.size());
        return m_coefs[index];
    }
    double const& operator [] ( std::size_t index ) const
    {
           assert(index < m_coefs.size());
        return m_coefs[index];
    }     
    
   Vecteur operator + (  Vecteur const& u ) const {
      std::cout << __PRETTY_FUNCTION__ << std::endl; 
      assert(this->dimension() == u.dimension());
      Vecteur res(u.dimension());
      for (std::size_t i=0; i<u.dimension();++i)
          res[i] = m_coefs[i] + u[i];
      return res;
    }

    Vecteur&& operator + ( Vecteur&& u ) const  {
      std::cout << __PRETTY_FUNCTION__ << std::endl;
      for (std::size_t i=0;i<u.dimension();++i)
          u[i] += m_coefs[i];
      return std::move(u);
    }

    iterator begin() { return m_coefs.begin(); }
    iterator end() { return m_coefs.end(); }
    
private:
    std::vector<double> m_coefs;
};

Vecteur&& operator + ( Vecteur&& u, Vecteur const& v ) {
      std::cout << __PRETTY_FUNCTION__ << std::endl;
      for (std::size_t i=0; i<u.dimension(); ++i)
          u[i] += v[i];
      return std::move(u);
}

Vecteur&& operator + ( Vecteur&& u, Vecteur && v ) {
      std::cout << __PRETTY_FUNCTION__ << std::endl;
      for (std::size_t i=0; i<u.dimension();++i)
          u[i] += v[i];
      return std::move(u);
}
int main() {
    Vecteur u({1.,2.,3.,4.,5.}), v({2.,4.,6.,8.,10.});
    Vecteur w({-1.,-2.,-1.,-2.,-1.}), x({ 0.,1.,0.,1.,0.});
    Vecteur y({ 1.,0., 1., 0.,  1.});
    Vecteur z = u + v + w + x +  y;
     for ( auto v : z ) std::cout << v << " ";
     std::cout << std::endl;
     return EXIT_SUCCESS;
}
