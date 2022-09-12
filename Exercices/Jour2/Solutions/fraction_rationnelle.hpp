#ifndef _FRACTION_RATIONNELLE_HPP_
#define _FRACTION_RATIONNELLE_HPP_
#include "polynome.hpp"

template<typename K>
class FractionRationnelle
{
public:
    FractionRationnelle( Polynome<K> const& t_numerateur, Polynome<K> const& t_denominateur )
        :   mNumerateur(t_numerateur), mDenominateur(t_denominateur)
    {}

    FractionRationnelle( FractionRationnelle const& ) = default;
    FractionRationnelle( FractionRationnelle     && ) = default;
    ~FractionRationnelle() = default;

    FractionRationnelle& operator = ( FractionRationnelle const& ) = default;
    FractionRationnelle& operator = ( FractionRationnelle     && ) = default;

    FractionRationnelle operator + ( FractionRationnelle const& Q) const 
    {
        return { mNumerateur*Q.mDenominateur + mDenominateur*Q.mNumerateur,
                 mDenominateur * Q.mDenominateur };
    }

    FractionRationnelle operator - ( FractionRationnelle const& Q) const 
    {
        return { mNumerateur*Q.mDenominateur - mDenominateur*Q.mNumerateur,
                 mDenominateur * Q.mDenominateur };
    }

    FractionRationnelle operator * ( FractionRationnelle const& Q) const 
    {
        return { mNumerateur*Q.mNumerateur, mDenominateur * Q.mDenominateur };
    }

    FractionRationnelle operator - () const 
    {
        return { -mNumerateur, mDenominateur};
    }

    FractionRationnelle inverse() const 
    {
        return { mDenominateur, mNumerateur };
    }

    Polynome<K> const& numerateur() const { return mNumerateur; }
    Polynome<K> const& denominateur() const { return mDenominateur; }

private:
    Polynome<K> mNumerateur, mDenominateur;
};
template<typename K> FractionRationnelle( Polynome<K> const& t_numerateur, 
                                          Polynome<K> const& t_denominateur ) -> FractionRationnelle<K>;

template<typename K>
std::ostream& operator << ( std::ostream& out, FractionRationnelle<K> const& Q )
{
    out << "(" << Q.numerateur() << ")/(" << Q.denominateur() << ")";
    return out;
}

#endif