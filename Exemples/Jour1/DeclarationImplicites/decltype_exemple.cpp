#include <iostream>
#include <limits>
#include <vector>
#include <cassert>

template<typename K1, typename K2>
struct MaxMeanReturn_t
{
    using value_t = decltype(K1(0)+K2(0));
    value_t meanMax = std::numeric_limits<value_t>::lowest();
    std::size_t index = -1;
};

template<typename K1, typename K2> MaxMeanReturn_t<K1,K2>
searchMaxMean( std::vector<K1> const& u1, std::vector<K2> const& u2 )
{
    assert(u1.size() == u2.size());
    using value_t = MaxMeanReturn_t<K1,K2>::value_t;
    MaxMeanReturn_t<K1,K2> maxCurrent;
    for ( std::size_t index = 0; index < u1.size(); ++index )
    {
        value_t val = (u1[index]+u2[index])/value_t(2);
        if (val > maxCurrent.meanMax){
            maxCurrent.meanMax = val;
            maxCurrent.index   = index;
        }
    }
    return maxCurrent;
}

int main()
{
    std::vector u{1.,-2., 6., 4., -3. };
    std::vector v{1 , 4 ,-3 , 8 ,  10 };
    auto ret = searchMaxMean(u, v);
    std::cout << "Max Mean value : " << ret.meanMax
              << " at " << ret.index << std::endl;
    return EXIT_SUCCESS;
}
