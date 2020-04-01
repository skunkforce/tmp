#ifndef OSF_TMP_ERASE_HPP_INCLUDED
#define OSF_TMP_ERASE_HPP_INCLUDED

#include "drop.hpp"
#include "pop_front.hpp"
#include "rotate.hpp"
#include "../vocabulary.hpp"

namespace osf {
	namespace tmp {
		template <typename N = uint_<0>, typename C = listify_>
		struct erase_ {};

		namespace detail {
			template <unsigned N, typename I, typename C>
			struct dispatch<N, erase_<I, C>> {
				template <typename... Ts>
				using f = typename dispatch<
				        N,
				        rotate_<I, pop_front_<rotate_<uint_<(sizeof...(Ts) - I::value - 1)>, C>>>>::
				        template f<Ts...>;
			};
			template <typename I, typename C>
			struct dispatch<0, erase_<I, C>> {
				template <typename... Ts>
				using f = typename dispatch<1, C>::template f<nothing_>;
			};
		} // namespace detail
	} // namespace tmp
} // namespace osf

#endif