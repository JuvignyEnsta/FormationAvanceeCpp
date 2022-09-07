#include <iostream>
#include <algorithm>

template<typename T0, typename ... Tn>  
auto max( T0 const& arg0, Tn const&... args ) {
    if constexpr (sizeof...(args) == 0)
        return arg0;
    else {
        auto valmax = max(args...);
        return (decltype(valmax+arg0))(arg0>valmax ? arg0 : valmax);
    }
}

int main()
{
    auto valmax = max(0, 3.5, 2u, -6, 4LL, 8.3);
    std::cout << "valmax : " << valmax << std::endl;
    return EXIT_SUCCESS;
}
