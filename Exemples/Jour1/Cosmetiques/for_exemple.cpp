#include <iostream>
#include <vector>

std::vector<int> compute_some_values() {
    return {1,-1,2,-2,3,-3};
}

int main()
{
#if __cplusplus >= 202002L
    for ( int i = 0; int prime : {2,3,5,7,11,13,17,21,23,27}) {
        std::cout << ++i << "e nombre premier : " << prime << std::endl; 
    }

    for (std::vector<int> values = compute_some_values(); int value : values ){
        std::cout << value << " ";
        }
    std::cout << std::endl;
#else
    int i = 0;
    for (int prime : {2,3,5,7,11,13,17,21,23,27}) {
        std::cout << ++i << "e nombre premier : " << prime << std::endl; 
    }
    std::vector<int> values = compute_some_values(); 
    for (int value : values ){
        std::cout << value << " ";
        }
    std::cout << std::endl;
#endif

    return EXIT_SUCCESS;
}
