#ifndef OSF_TMP_PARTITION_HPP_INCLUDED
#define OSF_TMP_PARTITION_HPP_INCLUDED

#include "filter.hpp"
#include "remove_if.hpp"
#include "../call.hpp"
#include "../sequence/tee.hpp"
#include "../vocabulary.hpp"

namespace osf {
	namespace tmp {
		template <typename F, typename C = listify_>
		struct partition_ {};

		namespace detail {
			template <unsigned N, typename F, typename C>
			struct dispatch<N, partition_<F, C>> : dispatch<N, tee_<filter_<F>, remove_if_<F>, C>> {
			};
		} // namespace detail
	} // namespace tmp
} // namespace osf

#endif