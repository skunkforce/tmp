#ifndef OSF_TMP_COMPARISON_HPP_INCLUDED
#define OSF_TMP_COMPARISON_HPP_INCLUDED

#include <type_traits>
#include "vocabulary.hpp"

namespace osf {
	namespace tmp {
		template <typename P, typename C = identity_>
		struct is_ {};

		template <typename C = identity_>
		struct less_ {};

		namespace detail {
			template <typename P, typename C>
			struct dispatch<1, is_<P, C>> {
				template <typename T>
				using f = typename dispatch<1, C>::template f<bool_<std::is_same<P, T>::value>>;
			};

			template <typename C>
			struct dispatch<2, less_<C>> {
				template <typename T, typename U>
				using f = typename dispatch<1, C>::template f < bool_<T::value<U::value>>;
			};
		} // namespace detail
	} // namespace tmp
} // namespace osf
#endif
