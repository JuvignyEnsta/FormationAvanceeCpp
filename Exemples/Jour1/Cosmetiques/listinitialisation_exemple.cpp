#include <iostream>

template<typename K> K
max( std::initializer_list<K> const& t_values )
{
   auto max = *t_values.begin();
   for (auto it = t_values.begin();
        it != t_values.end(); ++it) {
      max = (max < *it ? *it : max); 
   }
   return max;
}

int main() {
    auto maxVal = max({1,3,-3,6,2,4});
    std::cout << "maxVal : " << maxVal << std::endl;
    return EXIT_SUCCESS;
}
