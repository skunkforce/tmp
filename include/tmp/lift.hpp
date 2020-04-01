#ifndef OSF_TMP_LIFT_HPP_INCLUDED
#define OSF_TMP_LIFT_HPP_INCLUDED

#include "detail/capabilities.hpp"
#include "detail/dispatch.hpp"
#include "identity.hpp"

namespace osf {
	namespace tmp {

		template <template <typename...> class F, typename C = identity_>
		struct lift_ {};

		template <typename C = identity_>
		struct result_ {};

		namespace detail {
#ifndef OSF_TMP_CLANG_ARITY_BUGh
			template <template <typename...> class F, typename C>
			struct dispatch<1, lift_<F, C>> {
				template <typename T>
				using f = typename dispatch<1, C>::template f<F<T>>;
			};
			template <template <typename...> class F, typename C>
			struct dispatch<2, lift_<F, C>> {
				template <typename T0, typename T1>
				using f = typename dispatch<1, C>::template f<F<T0, T1>>;
			};
			template <template <typename...> class F, typename C>
			struct dispatch<3, lift_<F, C>> {
				template <typename T0, typename T1, typename T2>
				using f = typename dispatch<1, C>::template f<F<T0, T1, T2>>;
			};
			template <template <typename...> class F, typename C>
			struct dispatch<4, lift_<F, C>> {
				template <typename T0, typename T1, typename T2, typename T3>
				using f = typename dispatch<1, C>::template f<F<T0, T1, T2, T3>>;
			};
#endif
			template <unsigned N, template <typename...> class F, typename C>
			struct dispatch<N, lift_<F, C>> {
				template <typename... Ts>
				using f = typename dispatch<1, C>::template f<F<Ts...>>;
			};
			template <typename C>
			struct dispatch<1, result_<C>> {
				template <typename T>
				using f = typename dispatch<1, C>::template f<typename T::type>;
			};
		} // namespace detail
	} // namespace tmp
} // namespace osf
#endif
