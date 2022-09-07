#include <iostream>
#include <array>

template<typename K, std::size_t dimension_n, std::size_t... dimensions> class Tenseur {
public:
    Tenseur() = default;
#   if __cplusplus > 202002L
    // Les deux opérateurs ne marchent pas. g++ me dit que operator [] ne doit contenir qu'un seul argument...*
    // Même si la norme C++ 23 dit qu'on peut avoir plusieurs paramètres pour l'opérateur [].
    // Donc Ne marchent pas, mais je ne sais pas pourquoi. 
    // Bogue du compilateur ? Dans un coin obscur de la norme ?
    template<typename... Integers>
    K const& operator[] ( std::size_t index0, Integers... indices ) const
    {
        return m_coefs[index0][indices...];
    }

    K& operator[] ( std::size_t index0, decltype(dimensions)... indices )
    {
        return m_coefs[index0][indices...];
    }
#   else
    K& coefs(std::size_t indexn,decltype(dimensions)... indices) 
    {    return m_coefs[indexn].coefs(indices...);    }
    K const& coefs( std::size_t indexn, decltype(dimensions)... indices ) const
    {
        return m_coefs[indexn].coefs(indices...);
    }
    K& operator [] ( std::array<std::size_t, sizeof...(dimensions)+1> const& t_indices )
    {
        return (*this)[t_indices.data()];
    }

    K const& operator [] ( std::array<std::size_t, sizeof...(dimensions)+1> const& t_indices ) const
    {
        return (*this)[t_indices.data()];
    }
    K const& operator [] ( std::size_t const* t_indices ) const
    {
        return m_coefs[t_indices[0]][t_indices+1];
    }
    K& operator [] ( std::size_t const* t_indices )
    {
        return m_coefs[t_indices[0]][t_indices+1];
    }
#   endif
private:
    std::array<Tenseur<K,dimensions...>,dimension_n> m_coefs;          };
template<typename K, std::size_t dimension> class Tenseur<K,dimension> {
public:
    Tenseur() = default;

#   if __cplusplus > 202002L
    K& operator [] ( std::size_t index )
    {
        return m_coefs[index];
    }

    K const& operator [] ( std::size_t t_index ) const
    {
        return m_coefs[t_index];
    }

#   else
    K& coefs( std::size_t index ) {   return m_coefs[index];   }
    K const& coefs( std::size_t index ) const
    {
        return m_coefs[index];
    }
    K& operator [] ( std::array<std::size_t,1> const& t_index )
    {
        return m_coefs[t_index[0]];
    }
    K const& operator [] ( std::array<std::size_t,1> const& t_index ) const
    {
        return m_coefs[t_index[0]];
    }
    K const& operator [] ( std::size_t const* t_index ) const
    {
        return m_coefs[t_index[0]];
    }
    K& operator [] ( std::size_t const* t_index )
    {
        return m_coefs[t_index[0]];
    }
#   endif
private:
    std::array<K, dimension> m_coefs;
};


int main()
{
    Tenseur<double,3,3,3> tenseur;
#   if __cplusplus > 202002L
    for ( std::size_t ind0=0; ind0<3; ++ind0)
        for ( std::size_t ind1=0; ind1<3; ++ind1)
            for ( std::size_t ind2=0; ind2<3; ++ind2)
                tenseur[ind0,ind1,ind2] = ind0 + 4*ind1 + 16*ind2;
    for ( std::size_t ind0=0; ind0<3; ++ind0)
    {
        for ( std::size_t ind1=0; ind1<3; ++ind1)
        {
            for ( std::size_t ind2=0; ind2<3; ++ind2)
                std::cout << tenseur[ind0,ind1,ind2] << "\t";
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
#   else
    for ( std::size_t ind0=0; ind0<3; ++ind0)
        for ( std::size_t ind1=0; ind1<3; ++ind1)
            for ( std::size_t ind2=0; ind2<3; ++ind2)
                tenseur.coefs(ind0,ind1,ind2) = ind0 + 4*ind1 + 16*ind2;
   for ( std::size_t ind0=0; ind0<3; ++ind0)
    {
        for ( std::size_t ind1=0; ind1<3; ++ind1)
        {
            for ( std::size_t ind2=0; ind2<3; ++ind2)
                std::cout << tenseur.coefs(ind0,ind1,ind2) << "\t";
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
#   endif
}