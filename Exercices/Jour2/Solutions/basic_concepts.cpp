#include <concepts>
#include <iostream>

template<typename T1, typename T2> 
    requires std::totally_ordered_with<T1,T2> && std::common_with<T1,T2>
auto maxValue( T1 const& val1, T2 const& val2 )
{
    using returnType = typename std::common_type_t<T1,T2>;
    if (val1 > val2 )
        return returnType(val1);
    else 
        return returnType(val2);
}

double approxQuotient( std::integral auto& numerateur, std::unsigned_integral auto& denominateur)
{
    return double(numerateur)/double(denominateur);
}

int main()
{
    auto valMax = maxValue( 2.4, 8 );
    std::cout << "max(2.4,8) = " << valMax << std::endl;

    //auto valMax2 = maxValue( 2.4, "coco");

    return EXIT_SUCCESS;
}
