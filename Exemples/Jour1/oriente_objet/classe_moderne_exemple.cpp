#include <vector>
#include <iostream>
#include <cassert>
#include <string>
#include <functional> 
#include <cstdlib>  

namespace Algebra::Linear 
{
// ########################################### Classe vecteur algébrique ##############################################
class Vector 
{
public:
    using index_t = std::int32_t;
    using iterator = std::vector<double>::iterator;
    using const_iterator = std::vector<double>::const_iterator;

    Vector() = default;

    Vector( index_t t_dimension ) : m_coefficients(t_dimension)
    {}

    Vector( index_t t_dimension, double t_initValue )
        :   Vector(t_dimension)
    {
        std::fill(m_coefficients.begin(),m_coefficients.end(), t_initValue);
    }

    Vector( std::initializer_list<double> const& t_values )
        :   m_coefficients(t_values)
    {}

    Vector(index_t t_dimension, double const* t_coefficients, index_t stride);

    Vector( Vector const& ) = delete;

    Vector( Vector     && ) = default;

    ~Vector() = default;


    Vector& operator = ( Vector const& ) = delete;

    Vector& operator = ( Vector     && ) = default;

    double& operator [] ( index_t iCoef ) { return m_coefficients[iCoef]; }

    double const& operator [] ( index_t iCoef ) const { return m_coefficients[iCoef]; }

    Vector& operator += ( Vector const& u );

    Vector operator + ( Vector const& u ) const;

    Vector&& operator + ( Vector && u ) const 
    {   u += *this; return std::move(u);    }

    index_t dimension() const
    {
        return static_cast<index_t>(m_coefficients.size());
    }

    double sqrNormL2() const;

    iterator begin() { return m_coefficients.begin(); }

    const_iterator begin() const { return m_coefficients.begin(); }

    iterator end() { return m_coefficients.end(); }

    const_iterator end() const { return m_coefficients.end(); }

    const_iterator cbegin() const { return m_coefficients.cbegin(); }

    const_iterator cend()   const { return m_coefficients.cend  (); }

    explicit operator std::string() const;
private:
    std::vector<double> m_coefficients{};
};
// ................................................................................................
Vector::Vector(index_t t_dimension, double const* t_coefficients, index_t stride)
{
    if (stride==1)
        std::vector<double>(t_coefficients, t_coefficients + t_dimension).swap(m_coefficients);
    else {
        std::vector<double>(t_dimension).swap(m_coefficients);
        for ( index_t index=0; index<t_dimension; ++index)
            m_coefficients[index] = t_coefficients[stride*index];
    }
}
// ................................................................................................
Vector& 
Vector::operator += ( Vector const& u )
{
    for (index_t iCoef = 0; iCoef < dimension(); ++iCoef )
        m_coefficients[iCoef] += u[iCoef];
    return *this;
}
// ................................................................................................
Vector
Vector::operator + ( Vector const& u ) const
{
    Vector res(dimension());
    for ( index_t iCoef = 0; iCoef < dimension(); ++iCoef )
        res[iCoef] += m_coefficients[iCoef] + u[iCoef];
    return res;
}
// ................................................................................................
double Vector::sqrNormL2() const
{
    double sqrNrm = 0.;
    for (auto const& val : m_coefficients)
        sqrNrm += val*val;
    return sqrNrm;
}
// ................................................................................................
Vector::operator std::string() const
{
    std::string sres("< ");
    for ( auto value : m_coefficients )
        sres += std::to_string(value) + " ";
    sres += ">";
    return sres;
}
// ................................................................................................
inline Vector&& operator + ( Vector&& u, Vector const& v )
{ 
    u += v;
    return std::move(u); 
}
// ................................................................................................
Vector operator * ( double t_scal, Vector const& u )
{
    Vector res(u.dimension());
    for ( Vector::index_t index=0; index<u.dimension(); ++index)
    {
        res[index] = t_scal * u[index];
    }
    return res;
}
// ########################## ckasse de base pour toutes les structures matricielles ##################################
class MatrixBase 
{
public:
    using index_t = Vector::index_t;

    MatrixBase() = default;

    MatrixBase( index_t t_nrows, index_t t_ncols )
        :   m_nrows(t_nrows),
            m_ncols(t_ncols)
    {}

    MatrixBase( MatrixBase const& ) = delete;

    MatrixBase( MatrixBase&& ) = default;

    virtual ~MatrixBase() = default;

    MatrixBase& operator = ( MatrixBase const & ) = delete;

    MatrixBase& operator = ( MatrixBase      && ) = default;

    virtual Vector operator * ( Vector const& u ) const = 0;

protected:
    index_t m_nrows{0}, m_ncols{0};
};

// ###################################### Classe Matrice sans stockage mémoire ########################################
class FreeMatrix : public MatrixBase 
{
public:
    using MatrixBase::index_t;

    template<typename Func>
    FreeMatrix( index_t t_nrows, index_t t_ncols, Func const& t_function )
        :   MatrixBase(t_nrows, t_ncols),
            m_generationFunction(t_function)
    {}

    FreeMatrix( FreeMatrix && ) = default;

    ~FreeMatrix()               = default;

    FreeMatrix& operator = ( FreeMatrix && ) = default;

    virtual Vector operator * ( Vector const& u ) const override;
private:
    std::function<double(index_t,index_t)> m_generationFunction;
};

Vector 
FreeMatrix::operator * ( Vector const& u ) const
{
    Vector v(m_nrows, 0.);
    for ( index_t irow=0; irow<m_nrows; ++irow)
        for (index_t icol=0; icol<m_ncols; ++icol)
            v[irow] += m_generationFunction(irow, icol) * u[icol];
    return v;
}

// ########################################### Matrice stockage plein ###############################################
class PlainMatrix final : public MatrixBase 
{
public:
    using MatrixBase::index_t;

    PlainMatrix() = default;

    PlainMatrix(index_t t_nrows, index_t t_ncols, double t_initValue)
        :   MatrixBase(t_nrows, t_ncols),
            m_coefficients(t_nrows*t_ncols, t_initValue)
    {}

    PlainMatrix(index_t t_nrows, index_t t_ncols, double const* t_values = nullptr );

    PlainMatrix( PlainMatrix const & ) = delete;

    PlainMatrix( PlainMatrix      && ) = default;

    ~PlainMatrix() = default;

#   if __cplusplus > 202002L
    double& operator[] (index_t t_irows, index_t t_icols)
    {
        assert(t_irows < m_nrows);
        assert(t_icols < m_ncols);
        return m_coefficients[t_irows + t_icols*m_nrows];
    }

    double const& operator[] (index_t t_irows, index_t t_icols) const
    {
        assert(t_irows < m_nrows);
        assert(t_icols < m_ncols);
        return m_coefficients[t_irows + t_icols*m_nrows];
    }
#   endif
    double& operator[] ( std::pair<index_t,index_t> const& t_rowcol)
    {
        return m_coefficients[t_rowcol.first + t_rowcol.second*m_nrows];
    }

    double const& operator[] ( std::pair<index_t,index_t> const& t_rowcol) const
    {
        return m_coefficients[t_rowcol.first + t_rowcol.second*m_nrows];
    }

    virtual Vector operator * ( Vector const& u ) const final;
private:
    std::vector<double> m_coefficients;
};
// ................................................................................................
PlainMatrix::PlainMatrix(index_t t_nrows, index_t t_ncols, double const* t_values)
    :   MatrixBase(t_nrows, t_ncols),
        m_coefficients(t_nrows*t_ncols)
{
    if (t_values != nullptr)
    {
        std::copy(t_values, t_values+m_coefficients.size(), m_coefficients.begin());
    }
}
//.................................................................................................
Vector 
PlainMatrix::operator * ( Vector const& u ) const
{
    assert(u.dimension() == m_ncols);
    auto iterMatCoef = m_coefficients.begin();
    Vector v(m_nrows);
    for (index_t irow=0; irow<m_nrows; ++irow, ++iterMatCoef)
        v[irow] = (*iterMatCoef)*u[0];
    for (index_t icol=1; icol<m_ncols; ++icol)
    {
        for (index_t irow=0; irow<m_nrows; ++irow, ++iterMatCoef)
        {
            v[irow] += (*iterMatCoef)*u[icol];
        }
    }
    return v;
}

}
//=====================================================================================================================
int main()
{
    using namespace Algebra::Linear;
    using index_t = Vector::index_t;
    constexpr index_t gridDimension = 10;// Dimension direction grille cartésienne 2D.
    constexpr index_t dimension = gridDimension * gridDimension;// Dimension du problème

    FreeMatrix freeMat(dimension, dimension, [](index_t i, index_t j) {
        if (i==j) return 4.;
        auto iCoord = std::div(i, gridDimension);
        auto jCoord = std::div(j, gridDimension);
        if (std::abs(iCoord.rem-jCoord.rem)==1) return -1.;
        if (std::abs(iCoord.quot-jCoord.quot)==1) return -1.;
        return 0.;
    });

    Vector u(dimension, 0.);
    for (index_t idir=0; idir<gridDimension; ++idir)
    {
        u[idir] = 1.;
        u[idir+(gridDimension-1)*gridDimension] = 1.;
    }
    for (index_t jdir=0; jdir<gridDimension; ++jdir)
    {
        u[jdir*gridDimension] = 1.;
        u[jdir*gridDimension+gridDimension-1] = 1.;
    }

    auto v1 = freeMat * u;
    std::cout << "v1 : " << std::string(v1) << std::endl; 

    PlainMatrix plainMat( dimension, dimension);
    for (index_t jcol=0; jcol<dimension; ++jcol)
    {
        for (index_t irow=0; irow<dimension; ++irow)
        {
#           if __cplusplus > 202002
            if (irow==jcol) plainMat[irow,jcol] = 4.;
            else {            
                auto iCoord = std::div(irow, gridDimension);
                auto jCoord = std::div(jcol, gridDimension);
                if (std::abs(iCoord.rem-jCoord.rem)==1) plainMat[irow,jcol] = -1.;
                else if (std::abs(iCoord.quot-jCoord.quot)==1) plainMat[irow,jcol] = -1.;
                else plainMat[irow,jcol] = 0.;
            }
#           else
            if (irow==jcol) plainMat[{irow,jcol}] = 4.;
            else {            
                auto iCoord = std::div(irow, gridDimension);
                auto jCoord = std::div(jcol, gridDimension);
                if (std::abs(iCoord.rem-jCoord.rem)==1) plainMat[{irow,jcol}] = -1.;
                else if (std::abs(iCoord.quot-jCoord.quot)==1) plainMat[{irow,jcol}] = -1.;
                else plainMat[{irow,jcol}] = 0.;
            }
#           endif
        }
    }
    auto v2 = plainMat*u;
    std::cout << "v2 : " << std::string(v2) << std::endl; 

    auto verr = v1 + -1.*(plainMat*u); 
    std::cout << "||err||² = " << verr.sqrNormL2() << std::endl;
    return EXIT_SUCCESS;
}