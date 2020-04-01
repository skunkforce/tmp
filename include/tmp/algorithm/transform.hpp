#ifndef OSF_TMP_TRANSFORM_HPP_INCLUDED
#define OSF_TMP_TRANSFORM_HPP_INCLUDED

#include "../call.hpp"
#include "../vocabulary.hpp"

namespace osf {
	namespace tmp {
		template <typename F = identity_, typename C = listify_>
		struct transform_ {};
		namespace detail {
			template <unsigned N, typename F, typename C>
			struct dispatch<N, transform_<F, C>> {
				template <typename... Ts>
				using f = typename dispatch<find_dispatch(sizeof...(Ts)), C>::template f<
				        typename dispatch<1, F>::template f<Ts>...>;
			};

			template <unsigned N, template <typename...> class F, typename FC, typename C>
			struct dispatch<N, transform_<lift_<F, FC>, C>> {
				template <typename... Ts>
				using f = typename dispatch<(N + (N > sizeof...(Ts))), C>::template f<F<Ts>...>;
			};
		} // namespace detail
	} // namespace tmp
} // namespace osf

#endif
