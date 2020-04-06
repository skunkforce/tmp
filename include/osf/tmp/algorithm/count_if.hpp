#ifndef OSF_TMP_COUNT_IF_HPP_INCLUDED
#define OSF_TMP_COUNT_IF_HPP_INCLUDED

#include "transform.hpp"
#include "../call.hpp"
#include "../detail/dispatch.hpp"
#include "../if.hpp"
#include "../sequence/join.hpp"
#include "../sequence/size.hpp"
#include "../vocabulary.hpp"

namespace osf {
	namespace tmp {
		template <typename F, typename C = identity_>
		struct count_if_ {};
		namespace detail {
			template <unsigned N, typename F, typename C>
			struct dispatch<N, count_if_<F, C>>
			    : dispatch<N, transform_<if_<F, always_<list_<void>>, always_<list_<>>>,
			                             join_<size_<C>>>> {};
		} // namespace detail
	} // namespace tmp
} // namespace osf

#endif