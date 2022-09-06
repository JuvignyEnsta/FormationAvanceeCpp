#include <iostream>

struct UneStructure {
#if defined(COMPILE_WITH_ERROR)
  bool un_drapeau;
  double un_reel;
  bool un_autre_drapeau;
#else
  bool un_drapeau, un_autre_drapeau;
  double un_reel;
#endif
};
static_assert(sizeof(UneStructure) <= 16);

int main() {
  std::cout << "sizeof(UneStructure) = " << sizeof(UneStructure) << std::endl;
  return EXIT_SUCCESS;
}
