#include <vector>
#include <list>
#include <iostream>

int main()
{
    std::vector vvalues{1.,2.-3.,4.,-5.,0.};
    std::list        lvalues {1, 2, -3, 4, -5, 0  };

    auto findMax=[]( auto const& container ) {
        auto max  = container.front();
        for ( auto val : container )
            if (val > max ) max = val;
        return max;
    };

    std::cout << "max of vvalues : " << findMax(vvalues) << std::endl;
    std::cout << "max of lvalues : " << findMax(lvalues)  << std::endl;
    return EXIT_SUCCESS;
}
