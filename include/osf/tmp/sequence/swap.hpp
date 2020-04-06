#ifndef OSF_TMP_SWAP_HPP_INCLUDED
#define OSF_TMP_SWAP_HPP_INCLUDED

#include "../identity.hpp"
#include "../vocabulary.hpp"
namespace osf {
	namespace tmp {
		template <typename C = listify_>
		struct swap_ {};
		namespace detail {
			template <typename C>
			struct dispatch<2, swap_<C>> {
				template <typename T, typename U>
				using f = typename dispatch<2, C>::template f<U, T>;
			};
		} // namespace detail
	} // namespace tmp
} // namespace osf

#endif
