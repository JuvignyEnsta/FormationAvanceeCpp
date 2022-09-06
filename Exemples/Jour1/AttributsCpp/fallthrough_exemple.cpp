#include <iostream>

enum MatrixProperty {
    eRectangular,
    eSquare,
    eSymmetric,
    ePositiveDefined
};

void displayFactorizationAvailable(  MatrixProperty t_property )
{
    switch(t_property)
      {
      case ePositiveDefined:
          std::cout << "Factorisation Cholesky possible." << std::endl;
          [[fallthrough]];
   case eSymmetric:
         std::cout << "Factorisation de Crout possible." << std::endl;
          [[fallthrough]];
     case eSquare:
          std::cout << "Factorisation de Gauss possible" << std::endl;
          break;
      default:
          std::cout << "Factorisation QR seulement possible..." << std::endl;
       }
}

int main()
{
    std::cout << "Pour une matrice symmétrique, on peut faire une " << std::endl;
    displayFactorizationAvailable( eSymmetric );
    std::cout << "Pour une matrice rectangulaire, on peut faire une " << std::endl;
    displayFactorizationAvailable( eRectangular );

    return EXIT_SUCCESS;
}
