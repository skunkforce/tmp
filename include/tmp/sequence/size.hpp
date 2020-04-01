#ifndef OSF_TMP_SIZE_HPP_INCLUDED
#define OSF_TMP_SIZE_HPP_INCLUDED

#include "../identity.hpp"
#include "../vocabulary.hpp"
namespace osf {
	namespace tmp {
		template <typename C = identity_>
		struct size_ {};
		namespace detail {
			template <unsigned N, typename C>
			struct dispatch<N, size_<C>> {
				template <typename... Ls>
				using f = typename dispatch<1, C>::template f<uint_<sizeof...(Ls)>>;
			};
		} // namespace detail
	} // namespace tmp
} // namespace osf

#endif
