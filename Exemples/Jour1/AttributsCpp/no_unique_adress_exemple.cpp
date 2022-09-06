#include <iostream>

struct  Couleur {
    enum eValue {
        eBlack = 0,
        eBlue  = 1,
        eGreen=2,
        eRed   = 4
    };
};
class NodeAllocator {
public:
    NodeAllocator() = default;
    double* allocate( std::size_t t_size ) { return nullptr; }
};

struct GLNode2 {
    [[no_unique_address ]]  NodeAllocator allocator;
    double coords[3];
    [[no_unique_address ]]  Couleur color;
};

struct GLNode {
    NodeAllocator allocator;
    double coords[3];
    Couleur color;
};

int main() {
    std::cout << "sizeof(Couleur) = " << sizeof(Couleur) << std::endl;
    std::cout << "sizeof(GLNode) = " << sizeof(GLNode) << std::endl;
    std::cout << "sizeof(GLNode2) = " << sizeof(GLNode2) << std::endl;
    GLNode2 node;
    auto col = node.color.eBlue;
    return EXIT_SUCCESS;
}
