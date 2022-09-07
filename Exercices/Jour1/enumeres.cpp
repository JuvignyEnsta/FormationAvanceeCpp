/**
 * Exercice : 
 *   On veut pouvoir gérer les permissions de fichiers, à savoir les états :
 *     - Aucun accès de permis   : eNone (valeur 0)
 *     - Le fichier peut être lu : eRead (valeur 1)
 *     - Le fichier peut être modifier : eWrite (valeur 2)
 *     - Le fichier peut être exécuté  : eExecutable (valeur 4)
 *
 *   On veut utiliser un énuméré tenant sur un seul octet pour lequel il doit
 * être possible de configurer une combinaison de ces états. 
 *   Compléter le programme suivant (C++ 20 ou C++ 17)
 *
 */
#include <iostream>
#include <cassert>

static_assert(__cplusplus >= 201703L, "Pour C++ 17 ou supérieur seulement !");

struct File
{
  void setAccessMode( AccessMode t_permissions )
  {
    std::cout << static_cast<int>(t_permissions) << std::endl << std::flush;
  }
};

int main()
{
  File file;
# if (__cplusplus >= 202002L )
  file.setAccessMode( AccessMode{file.eRead | file.eWrite} );
# else
  file.setAccessMode( AccessMode{File::Access::eRead | File::Access::eWrite} );
# endif
  return EXIT_SUCCESS;
}
