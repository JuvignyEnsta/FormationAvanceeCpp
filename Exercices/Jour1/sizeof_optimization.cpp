/**
 * @file sizeof_optimization.cpp
 * @author Xavier Juvigny (juvigny@onera.fr)
 * @brief Le but de cet exercice est d'optimiser la place mémoire prise par la structure
 *        Tableau. De plus, pour ceux qui peuvent compiler en C++ 20, pour  des  raisons
 *        de contruction et de libération mémoire, on veut que  l'attribut  allocator de
 *        Tableau soit déclaré en premier attribut dans la structure.
 *        NB : On pourrait stocker les deux booléens au sein d'un même entier, mais pour
 *             cet exercice, on les conservera en tant que booléens (ce qui ne  changera
 *             de toute façon pas grand chose à la taille de la structure).  
 * @version 0.10
 * @date 2022-07-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream> 

struct Allocator
{
    double* allocate( std::size_t size )
    {
        return (double*)malloc(size*sizeof(double));
    }
    void free(double* t_pointer)
    {
        free(t_pointer);
    }
};

struct Tableau
{
    Allocator allocator;
    std::size_t size;
    bool is_static;
    double* coefs;
    bool is_persistant;
};

static_assert(sizeof(Tableau)<=24, "Desole, votre structure prend encore trop de place !");

int main()
{
    std::cout << "Bravo, votre structure a une taille inferieure a " << sizeof(Tableau) << " octets !" << std::endl;
    return EXIT_SUCCESS;
}