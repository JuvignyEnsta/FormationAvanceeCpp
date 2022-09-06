#include <iostream>
  
[[noreturn]] void f() {
    // Bien que possédant l'attribut [[noreturn]], cette
    // fonction retourne à l'appelant. Il y aura donc
    // un warning généré par le compilateur :
    // "'noreturn' function does return"
}
  
void g() {
    // Fonction sans l'attribut [[noreturn]] et rendant la main.
    // Il n'y aura pas de warning, puisqu'on lui permet de
    // rendre la main.
    std::cout << "Code is intented to reach here";
}

[[noreturn]] void h() {
    // Cette fonction ne rend jamais la main et donc je retourne jamais à l'appelant.
    // Il n'y aura donc pas de warning à la compilation.
    while (true)
    {}
}

int main()
{
    f();
    h();
    g();
}
