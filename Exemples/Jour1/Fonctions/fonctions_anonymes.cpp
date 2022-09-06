#include <vector>
#include <algorithm>
#include <iostream>

int main() {
    auto print = [] ( std::vector<double> const& a ) { for (auto v : a ) std::cout << v << " "; 
                                                        std::cout << std::endl; };
    std::vector<double> a_array{1., -3., 2., -7., 6., 4.};
    std::cout << "Tableau avant tri : "; print(a_array);
    std::sort(a_array.begin(), a_array.end(), 
              [](double x, double y) { return std::abs(x) < std::abs(y); } );
    std::cout << "Tableau apres tri par valeur absolue : "; print(a_array);
    return EXIT_SUCCESS;
}
