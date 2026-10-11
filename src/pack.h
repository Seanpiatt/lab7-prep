#ifndef PACK_H
#define PACK_H

template <typename... Args>
struct Pack {};
namespace pack_detail{
    template <typename... Ts>
        constexpr int packSize = 0;
    template <typename T, typename... Rest>
    constexpr int packSize<T, Rest...> = 1 + packSize<Rest...>;
}
#endif  // PACK_H