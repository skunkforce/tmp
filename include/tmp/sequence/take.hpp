#ifndef OSF_TMP_TAKE_HPP_INCLUDED
#define OSF_TMP_TAKE_HPP_INCLUDED

#include "drop.hpp"
#include "rotate.hpp"
#include "../vocabulary.hpp"

namespace osf {
	namespace tmp {
		template <typename N = uint_<0>, typename C = listify_>
		struct take_ {};

		namespace detail {
			template <unsigned N, typename P, typename C>
			struct dispatch<N, take_<P, C>> {
				template <typename... Ts>
				using f = typename dispatch<
				        find_dispatch(sizeof...(Ts)),
				        rotate_<P, drop_<uint_<(sizeof...(Ts) - P::value)>, C>>>::template f<Ts...>;
			};
		} // namespace detail
	} // namespace tmp
} // namespace osf

#endif