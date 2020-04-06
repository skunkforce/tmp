#ifndef OSF_TMP_REPLACE_IF_HPP_INCLUDED
#define OSF_TMP_REPLACE_IF_HPP_INCLUDED

#include "transform.hpp"
#include "../always.hpp"
#include "../call.hpp"
#include "../detail/dispatch.hpp"
#include "../if.hpp"
#include "../sequence/join.hpp"
#include "../vocabulary.hpp"

namespace osf {
	namespace tmp {
		template <typename Input, typename F, typename C = listify_>
		struct replace_if_ {};
		namespace detail {
			template <unsigned N, typename Input, typename F, typename C>
			struct dispatch<N, replace_if_<Input, F, C>>
			    : dispatch<N, transform_<if_<F, always_<Input>, identity_>, C>> {};
		} // namespace detail
	} // namespace tmp
} // namespace osf

#endif