#ifndef OSF_TMP_PUSH_FRONT_HPP_INCLUDED
#define OSF_TMP_PUSH_FRONT_HPP_INCLUDED

#include "../identity.hpp"
#include "../vocabulary.hpp"
namespace osf {
	namespace tmp {
		template <typename T, typename C = listify_>
		struct push_front_ {};
		namespace detail {
			template <unsigned N, typename T, typename C>
			struct dispatch<N, push_front_<T, C>> {
				template <typename... Ts>
				using f = typename dispatch<find_dispatch(sizeof...(Ts) + 1), C>::template f<T,
				                                                                             Ts...>;
			};
		} // namespace detail
	} // namespace tmp
} // namespace osf

#endif
