# include <iostream>
# include <cstdlib>
# include <chrono>
# include <cassert>

using namespace std::chrono_literals;

namespace unité_internationale
{
  namespace distance
  {
    class métre
    {
    public:
      explicit constexpr métre(double dist ) : m_dist(dist) {}

      explicit operator double() const { return m_dist; }

      métre operator + ( const métre& m )
      {
        return métre{m_dist + m.m_dist};
      }

      std::ostream& print( std::ostream& out ) const
      {
        out << m_dist << "m";
        return out;
      }

      template<typename U>
      métre& operator = ( const U& d ) {
       if ( this != &d ) {
         métre md = métre(d);
         m_dist = md.m_dist;
       }
       return *this;
      }

    private:
      double m_dist;
    };

    inline std::ostream& operator << ( std::ostream& out, const métre& m ) {
      return m.print(out);
    }

    class kilométre
    {
    public:
      explicit constexpr kilométre(double dist ) : m_dist(dist) {}

      kilométre( const métre& d ) : m_dist(0.001*double(d)) {}

      explicit operator double() const { return m_dist; }

      operator métre()
      {
        return métre{1000.*double(m_dist)};
      }

      kilométre operator + ( const kilométre& m )
      {
        return kilométre{m_dist + m.m_dist};
      }

      std::ostream& print( std::ostream& out ) const
      {
        out << m_dist << "km";
        return out;
      }

      template<typename U> kilométre& operator = ( const U& d ) {
        if ( this != &d ) {
          kilométre kd = kilométre(d);
          m_dist = kd.m_dist;
        }
        return *this;
      }
    private:
      double m_dist;
    };

    inline std::ostream& operator << ( std::ostream& out, const kilométre& km ) {
      return km.print(out);
    }
    

  }
  class vitesse
  {
  public:

    constexpr vitesse(double v)
      : value(v)
    {}

    vitesse(const distance::métre& dx, const std::chrono::seconds& dt )
      : value()
    {
      assert(dt.count() != 0);
      value = double(dx)/dt.count();
    }

    double value;
  };

  std::ostream& operator << ( std::ostream& out, const vitesse& u)
  {
    out << u.value << "m.s⁻¹";
    return out;
  }
    namespace operators
    {
      constexpr distance::kilométre operator"" _km( long double dst )
      {
        return distance::kilométre{static_cast<double>(dst)};
      }
      constexpr distance::métre operator"" _m( long double dst )
      {
        return distance::métre{static_cast<double>(dst)};
      }
      constexpr vitesse operator "" _mps( long double value )
      {
        return vitesse(static_cast<double>(value));
      }
      vitesse operator / ( const distance::métre& dx, const std::chrono::seconds& dt )
      {
        return {dx,dt};
      }
    }


}



int main()
{
  using namespace unité_internationale::operators;
  auto d1 = 1.2_km;
  auto d2 = 100.0_m;
  [[maybe_unused]] double a = double(d2);
  auto d3 = d2 + d1;
  std::cout << d1 << " + " << d2 << " = " << d3 << std::endl;
  auto d4 = d1 + d2;
  std::cout << d1 << " + " << d2 << " = " << d4 << std::endl;
  std::cout << 5.0_km << " + " << 1235.0_m << " = " << 5.0_km + 1235.0_m << std::endl;
  unité_internationale::distance::métre d5 = d1 + d2;
  std::cout << d1 << " + " << d2 << " = " << d5 << std::endl;

  unité_internationale::distance::kilométre d6 = d1 + d2;
  std::cout << d1 << " + " << d2 << " = " << d6 << std::endl;

  unité_internationale::vitesse u = 5._m/1s;
  std::cout << "u = " << u << std::endl;
  unité_internationale::vitesse v = d1/45s;
  std::cout << "v = " << v << std::endl;
  auto w = 10._mps;
  std::cout << "w = " << w << std::endl;
  auto t1 = 5h+4min+30s;
  std::cout << d1 << "/" << t1.count() << "s = " << d1/t1 << std::endl;
  return EXIT_SUCCESS;
}