#ifndef OSF_TMP_CONTAINS_HPP_INCLUDED
#define OSF_TMP_CONTAINS_HPP_INCLUDED

#include "../identity.hpp"
#include "../logic.hpp"

namespace osf {
	namespace tmp {
		template <typename V, typename C = identity_>
		struct contains_;

		namespace detail {
			template <unsigned N, typename V, typename C>
			struct dispatch<N, contains_<V, C>> : dispatch<N, or_<is_<V>, C>> {};
		} // namespace detail
	} // namespace tmp
} // namespace osf

#endif