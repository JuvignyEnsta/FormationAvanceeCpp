#ifndef _POLYNOME_HPP_
#define _POLYNOME_HPP_
#include <vector>
#include <iostream>
#include <cassert>

template<typename K>
class Polynome
{
public:
    using index_t=std::int32_t;
    Polynome() = default;
    Polynome( std::initializer_list<K> const& t_coefficients )
        :   m_monomes(t_coefficients)
    {}
    Polynome( index_t t_degree )
        :   m_monomes(t_degree+1)
    {
        assert(t_degree >= 0);
    }
    Polynome( index_t t_degree, K const& value )
        :   m_monomes(t_degree+1, value)
    {
        assert(t_degree >= 0);
    }
    Polynome( Polynome const& ) = default;
    Polynome( Polynome     && ) = default;
    ~Polynome()                 = default;

    index_t degre() const { return m_monomes.size()-1; }

    K const& operator [] ( index_t t_index ) const {
        assert(t_index >= 0       );
        assert(t_index <= degre() );
        return m_monomes[t_index];
    }

    K& operator [] ( index_t t_index ) {
        assert(t_index >= 0       );
        assert(t_index <= degre() );
        return m_monomes[t_index];
    }

    Polynome& operator = ( Polynome const& ) = default;
    Polynome& operator = ( Polynome     && ) = default;

    Polynome operator + ( Polynome const& P ) const {
        Polynome R( std::max(degre(), P.degre()) );
        for ( index_t iCoef=0; iCoef<=std::min(degre(), P.degre()); ++iCoef ) {
            R[iCoef] = m_monomes[iCoef] + P[iCoef];
        }
        for ( index_t iCoef=std::min(degre(),P.degre()); iCoef<=degre(); ++iCoef) {
            R[iCoef] = m_monomes[iCoef];
        }
        for ( index_t iCoef=std::min(degre(),P.degre()); iCoef<=P.degre(); ++iCoef) {
            R[iCoef] = P[iCoef];
        }
        return R;
    }

    Polynome operator - ( Polynome const& P ) const {
        Polynome R( std::max(degre(), P.degre()) );
        for ( index_t iCoef=0; iCoef<=std::min(degre(), P.degre()); ++iCoef ) {
            R[iCoef] = m_monomes[iCoef] - P[iCoef];
        }
        for ( index_t iCoef=std::min(degre(),P.degre()); iCoef<=degre(); ++iCoef) {
            R[iCoef] = m_monomes[iCoef];
        }
        for ( index_t iCoef=std::min(degre(),P.degre()); iCoef<=P.degre(); ++iCoef) {
            R[iCoef] = -P[iCoef];
        }
        return R;
    }

    Polynome operator - () const 
    {
        Polynome R( degre() );
        for ( index_t iCoef = 0; iCoef <= degre(); ++iCoef )
            R[iCoef] = -m_monomes[iCoef];
        return R;
    }

    Polynome operator * ( Polynome const& P ) const {
        if ( (degre()==-1) || (P.degre()==-1) ) return {};
        Polynome R( degre()+P.degre(), K(0) );

        for ( index_t iCoef=0; iCoef<=degre(); ++iCoef )
            for ( index_t jCoef=0; jCoef<=P.degre(); ++jCoef)
                R[iCoef+jCoef] += m_monomes[iCoef]*P[jCoef];
        return R;
    }
private:
    std::vector<K> m_monomes{};
};
template<typename K> 
Polynome( typename Polynome<K>::index_t deg, K const& value ) -> Polynome<K>;

template<typename K> 
Polynome( std::initializer_list<K> const& t_coefs  ) -> Polynome<K>;

template<typename K>
std::ostream& operator << ( std::ostream& out, Polynome<K> const& P )
{
    for ( typename Polynome<K>::index_t iCoef = 0; iCoef <= P.degre(); ++iCoef )
    {
        out << (P[iCoef]>0 ? "+":"") << P[iCoef] << ".x^" << iCoef;
    }
    return out;
}

#endif
