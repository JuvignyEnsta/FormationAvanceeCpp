#include <map>
#include <vector>
#include <array>
#include <list>
#include <cstdlib>

int main()
{
    [[maybe_unused]] std::vector u(5,0.);
    [[maybe_unused]] std::vector v{1.,2.,3.,4.};

    [[maybe_unused]] std::list lu(10,0.);
    [[maybe_unused]] std::list lv{2.,3.,5.,7.,11.};

    [[maybe_unused]] std::map dico{ std::pair{"Mercure",88.}, {"Venus", 224.7}, 
                                             {"Terre"  ,365.256}, {"Mars" , 687.} };

    return EXIT_SUCCESS;
}
