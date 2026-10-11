#ifndef PACK_H
#define PACK_H

template <typename... Args>
struct Pack {};
namespace pack_detail{
    template <typename... Ts>
        constexpr int packSize = 0;
    template <typename T, typename... Rest>
        constexpr int packSize<T, Rest...> = 1 + packSize<Rest...>;
    template <int Queryindex,typename ... Args>
    struct _packIndexToType;
    template <typename First, typename... Rest>
    struct _packIndexToType<0, First, Rest...> {
        using type = First;    
    };
    template <int QueryIndex, typename First, typename... Rest>
    struct _packIndexToType<QueryIndex, First, Rest...> {
        using type = typename _packIndexToType<QueryIndex - 1 , Rest...>::type; 
    };
    template <int QueryIndex, typename... Args>
    using packIndexToType = typename _packIndexToType<QueryIndex, Args...>::type;
};

#endif  // PACK_H