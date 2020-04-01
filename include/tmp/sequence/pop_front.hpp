#ifndef OSF_TMP_POP_FRONT_HPP_INCLUDED
#define OSF_TMP_POP_FRONT_HPP_INCLUDED

#include "../identity.hpp"
#include "../vocabulary.hpp"
namespace osf {
	namespace tmp {
		template <typename C = listify_>
		struct pop_front_ {};
		namespace detail {
			template <unsigned N, typename C>
			struct dispatch<N, pop_front_<C>> {
				template <typename T, typename... Ts>
				using f = typename dispatch<find_dispatch(sizeof...(Ts)), C>::template f<Ts...>;
			};
			template <typename C>
			struct dispatch<0, pop_front_<C>> {
				template <typename... Ts>
				using f = typename dispatch<1, C>::template f<nothing_>;
			};
		} // namespace detail
	} // namespace tmp
} // namespace osf

#endif
