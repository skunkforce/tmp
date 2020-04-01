#ifndef OSF_TMP_TRY_HPP_INCLUDED
#define OSF_TMP_TRY_HPP_INCLUDED

#include "always.hpp"
#include "detail/dispatch.hpp"
#include "identity.hpp"
#include "sequence/unpack.hpp"
#include "vocabulary.hpp"

namespace osf {
	namespace tmp {

		template <template <typename...> class F, typename C = identity_>
		struct try_ {};

		namespace detail {
			template <typename T>
			struct t_ {
				using type = T;
			};
			template <template <typename...> class F, typename... Ts>
			t_<F<Ts...>> try_f(lift_<F>, list_<Ts...>);
			t_<nothing_> try_f(...);

			template <unsigned N, template <typename...> class F, typename C>
			struct dispatch<N, try_<F, C>> {
				template <typename... Ts>
				using f = typename dispatch<1, C>::template f<typename decltype(
				        try_f(lift_<F>{}, list_<Ts...>{}))::type>;
			};
		} // namespace detail
	} // namespace tmp
} // namespace osf
#endif
