#ifndef OSF_TMP_PUSH_BACK_HPP_INCLUDED
#define OSF_TMP_PUSH_BACK_HPP_INCLUDED

#include "../identity.hpp"
#include "../vocabulary.hpp"
namespace osf {
	namespace tmp {
		template <typename T, typename C = listify_>
		struct push_back_ {};
		namespace detail {
			template <unsigned N, typename T, typename C>
			struct dispatch<N, push_back_<T, C>> {
				template <typename... Ts>
				using f = typename dispatch<find_dispatch(sizeof...(Ts) + 1), C>::template f<Ts...,
				                                                                             T>;
			};
		} // namespace detail
	} // namespace tmp
} // namespace osf

#endif
