#ifndef PACK_H
#define PACK_H

template <typename... Args>
struct Pack {}
namespace pack_detail{
    <typename T, typename... Rest>
    template <typename... Ts>
        constexpr int packSize = 0;
    constexpr int packSize<T, Rest...> = 1 +
        packSize<Rest...>;
};
#endif  // PACK_H
s