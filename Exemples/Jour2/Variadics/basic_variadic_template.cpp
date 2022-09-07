#include <iostream>
#include <algorithm>

template<typename T0, typename T1> 
auto max( T0 const& arg0, T1 const& arg1 ) -> decltype(arg0+arg1) 
{    return (arg0>arg1 ? arg0 : arg1);    }

template<typename T0, typename ... Tn>  auto max( T0 const& arg0, Tn const&... args ) {
    auto valmax = max(args...);
    return (decltype(valmax+arg0))(arg0>valmax ? arg0 : valmax);
}

int main()
{
    auto valmax = max(0, 3.5, 2., -6, 4LL, 8.3);
    std::cout << "valmax : " << valmax << std::endl;
    return EXIT_SUCCESS;
}
