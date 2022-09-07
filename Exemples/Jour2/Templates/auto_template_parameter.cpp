#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <string_view>

template<auto value1, auto... values> struct static_tuple : public static_tuple<values...> {
    template<auto index> auto get() const {
        if constexpr (index==0) return value1; 
        else return static_tuple<values...>::template get<index-1>();
    }
};
template<auto value> struct static_tuple<value> {
    template<auto index> auto get() const {
        static_assert(index==0, "Out of bound index value");
        return value;
    }
};

int main() {
    static_tuple<3, 7LL, 3.14> stuple;
    printf("stuple : (%d, %lld, %lf)\n", stuple.get<0>(), stuple.get<1U>(), stuple.get<2ULL>());

    return EXIT_SUCCESS;
}