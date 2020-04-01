#ifndef OSF_TMP_CONTAINER_HPP_INCLUDED
#define OSF_TMP_CONTAINER_HPP_INCLUDED

#include "../vocabulary.hpp"

namespace osf {
	namespace tmp {
		/// \brief
		template <typename C = identity_>
		struct container_ {};
		template <template <typename...> class W, typename C = identity_>
		using container_is_ = container_<is_<lift_<W>, C>>;
		namespace detail {
			template <typename L, typename C>
			struct container_impl {
				using type = typename dispatch<1, C>::template f<nothing_>;
			};
			template <template <typename...> class Seq, typename C, typename... Ls>
			struct container_impl<Seq<Ls...>, C> {
				using type = typename dispatch<1, C>::template f<lift_<Seq>>;
			};

			template <typename C>
			struct dispatch<1, container_<C>> {
				template <typename L>
				using f = typename detail::container_impl<L, C>::type;
			};
		} // namespace detail
	} // namespace tmp
} // namespace osf

#endif
