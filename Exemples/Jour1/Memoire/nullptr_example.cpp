#include <iostream>

template<typename K> int 
sizeElement( K const* ptr ) { return sizeof(K); }

int sizeElement( void const* ptr) { return 1; }

int sizeElement( std::nullptr_t ptr ) { return 0; }

int main()
{
    int i = 0;
    double d = 3;
    void* ptr = 0ULL;

    std::cout << sizeElement(&i) << ", " << sizeElement(&d) << ", "
              << sizeElement(ptr) << ", " << sizeElement(nullptr)
              << std::endl;
    return EXIT_SUCCESS;
}