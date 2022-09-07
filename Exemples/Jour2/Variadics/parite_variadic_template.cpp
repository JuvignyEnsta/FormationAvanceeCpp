#include <iostream>
#include <algorithm>
#include <tuple>
#include <string>
using namespace std::string_literals;

template<typename T, typename ... Ts>
auto pair_wise_addition( T const& val1, T const& val2, Ts const&... vals )
{
    if constexpr (sizeof...(vals) == 0)
        return std::make_tuple(val1+val2);
    else
    {
        auto res = pair_wise_addition(vals...);
        return std::tuple_cat(std::make_tuple(val1+val2), res);
    }
}

int main()
{
    auto res = pair_wise_addition( 1, 3, 4.6, -1.2, "tintin et "s, "milou"s );
    std::cout << std::get<0>(res) << ", " << std::get<1>(res) << ", " << std::get<2>(res) << std::endl;

    return EXIT_SUCCESS;
}
