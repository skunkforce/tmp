#ifndef OSF_TMP_REMOVE_IF_HPP_INCLUDED
#define OSF_TMP_REMOVE_IF_HPP_INCLUDED

#include "transform.hpp"
#include "../always.hpp"
#include "../call.hpp"
#include "../detail/dispatch.hpp"
#include "../if.hpp"
#include "../sequence/join.hpp"
#include "../vocabulary.hpp"

namespace osf {
	namespace tmp {
		template <typename F, typename C = listify_>
		struct remove_if_ {};
		namespace detail {
			template <unsigned N, typename F, typename C>
			struct dispatch<N, remove_if_<F, C>>
			    : dispatch<N, transform_<if_<F, always_<list_<>>, listify_>, join_<C>>> {};
		} // namespace detail
	} // namespace tmp
} // namespace osf

#endif