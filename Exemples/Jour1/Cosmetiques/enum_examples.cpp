#include <iostream>

enum eColor { red, green, blue };
enum class Altitude { haut, milieu, bas };
enum class Axis : char { X='X', Y='Y', Z='Z' };
struct Navigation
{
  enum direction : char { ouest = 'O',nord = 'N',est = 'E',sud = 'S' };
};

#if __cplusplus >= 202002L
struct Color
{
  using enum eColor;
};
#endif

std::ostream& operator << (std::ostream& out, Axis axe ) {
  out << static_cast<char>(axe);
  return out;
}

int main()
{
  eColor colour1 = green;
  char dir1 = Navigation::direction::nord;// A partir de C++ 11
  char dir2 = Navigation::sud;// Déjà ok en C++ 98
#if __cplusplus >= 202002L
  Color colors;
  eColor colour2 = colors.red;
#else
  eColor colour2 = red;
#endif
  Axis axe1 = Axis::Z;// Valeur prédéfinie d'un axe
#if __cplusplus >= 201703L
  Altitude alt{4};
  Navigation::direction dir3{'H'};// On rajoute une notion de haut...
  // eColor    col{45}; //<- Erreur de compilation
  eColor col{red};
  // On définit un nouvel axe pour faire de la 4D :
  Axis axe2{'W'};// OK en C++17 : {} obligatoires !
#else
  eColor col{static_cast<eColor>(42)};// Déconseillé mais possible...
  Axis axe2{static_cast<Axis>('W')};
#endif
  std::cout << "Direction : " << dir1 << " et " << dir2 << std::endl;
  std::cout << "Colors : " << static_cast<int>(colour1) << "/"     /* 1 */
                           << static_cast<int>(colour2) << "/"     /* 0 */
                           << static_cast<int>(col) << std::endl;  /*45 */
  std::cout << "Axis : " << axe1 << ", "  << axe2 << std::endl;

  struct ForegroundColor
  {
      using enum eColor;
  };

  struct BackgroundColor
  {
      using enum eColor;
  };

  eColor c1 = ForegroundColor::red;
  eColor c2 = BackgroundColor::blue; 
  
  
  return EXIT_SUCCESS;
}
