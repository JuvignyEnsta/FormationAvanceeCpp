#include<iostream>
#include <list>
#include <cassert>

[[maybe_unused]]
void uneFonction( std::list<double> const& u )
{
    // Calcul de la taille coûte assez cher pour une liste
    std::size_t size = u.size();
    assert(size > 0);
    assert(size < 100);
    // Et on continue ici
}

void uneAutreFonction()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl; 
}

int main()
{
    uneAutreFonction();
}
