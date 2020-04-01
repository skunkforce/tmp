#ifndef OSF_TMP_ALWAYS_HPP_INCLUDED
#define OSF_TMP_ALWAYS_HPP_INCLUDED

#include "detail/dispatch.hpp"
#include "identity.hpp"

namespace osf {
	namespace tmp {
		template <typename T, typename C = identity_>
		struct always_ {};

		namespace detail {
			template <unsigned N, typename T, typename C>
			struct dispatch<N, always_<T, C>> {
				template <typename...>
				using f = typename dispatch<1, C>::template f<T>;
			};
		} // namespace detail
	} // namespace tmp
} // namespace osf
#endif
