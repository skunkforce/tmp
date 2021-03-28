#ifndef OSF_TMP_PIPELINE_HPP_INCLUDED
#define OSF_TMP_PIPELINE_HPP_INCLUDED
#include "call.hpp"
#include "detail/dispatch.hpp"
#include "algorithm/fold_right.hpp"

namespace osf {
	namespace tmp {
        namespace detail{
            template<typename L, typename R>
            struct pipeline_merge;
            template<template<typename> typename F, typename T1, typename L>
            struct pipeline_merge<L,F<T1>> {
                using type = F<L>;
            };
            template<template<typename,typename> typename F, typename T1, typename T2, typename L>
            struct pipeline_merge<L, F<T1, T2>> {
                using type = F<T1,L>;
            };
            template<template<typename,typename,typename> typename F, typename T1, typename T2, typename T3, typename L>
            struct pipeline_merge<L, F<T1, T2, T3>> {
                using type = F<T1,T2,L>;
            };
            template<typename...Ts>
            using pipeline_merge_t = typename pipeline_merge<Ts...>::type;
        }
        template<typename...Ts>
        using pipeline_ = typename detail::dispatch<detail::find_dispatch(sizeof...(Ts)),fold_right_<lift_<detail::pipeline_merge_t>>>::template f<Ts...>;
    }
}

#endif