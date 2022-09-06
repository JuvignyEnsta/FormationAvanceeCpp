#include <vector>
#include <iostream>

template<typename K1, typename K2>
auto sub( K1 const& v1, K2 const& v2 )
{ return v1-v2; }

int main() {
    std::vector vals{ 1.5, 1.4, 1.3 };

    for (auto it=vals.begin(); it!=vals.end(); ++it)
        std::cout << sub(int(*it),3) << "; "
                  << sub(*it,2) << "; "
                  << sub(2,*it) << std::endl;
    return EXIT_SUCCESS;
}
