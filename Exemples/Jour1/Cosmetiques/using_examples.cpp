#include <iostream>
#include <vector>
#include <array>

template<typename K>
using CloudOfPoints=std::vector<std::array<K,3>>;
using index_t=std::uint32_t;

int main()
{
index_t nx=4, ny=6, nz=3, nverts=nx*ny*nz;
CloudOfPoints<double> vertices(nverts);

 for (index_t iv = 0; iv < nverts; ++iv )
    vertices[iv] = { 0.1 * (iv%nx),
                     0.2 *((iv/nx)%ny),
                     0.15* (iv/nx/ny) };
 
for ( index_t iv = 0; iv < nverts; ++iv )
    std::cout << "( " << vertices[iv][0]
              << ", " << vertices[iv][1]
              << ", " << vertices[iv][2] << " ) ";
std::cout << std::endl;

 return EXIT_SUCCESS;
}
