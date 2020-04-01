#ifndef OSF_TMP_IDENTITY_HPP_INCLUDED
#define OSF_TMP_IDENTITY_HPP_INCLUDED

#include "detail/capabilities.hpp"
#include "detail/dispatch.hpp"
#include "detail/fusion_rebind.hpp"
namespace osf {
	namespace tmp {
		struct identity_ {};
#ifdef OSF_TMP_CPP14
		namespace fusion {
			template <>
			struct rebind<identity_> {
				using type = identity_;
			};
		} // namespace fusion
#endif
		namespace detail {
			template <>
			struct dispatch<1, identity_> {
				template <typename T>
				using f = T;
			};
		} // namespace detail
	} // namespace tmp
} // namespace osf
#endif
