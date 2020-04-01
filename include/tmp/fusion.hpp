#ifndef OSF_TMP_FUSION_HPP_INCLUDED
#define OSF_TMP_FUSION_HPP_INCLUDED

#include "detail/capabilities.hpp"
#include "detail/expression.hpp"
#include "detail/fusion_execute.hpp"
#include "detail/fusion_rebind.hpp"
#include "pack.hpp"
namespace osf {
	namespace tmp {
#ifdef OSF_TMP_CPP14
		namespace fusion {
			template <typename... Bs, typename T, typename C>
			constexpr auto operator>>=(pack<Bs...> &&p, expr<T, C> &&ex) {
				auto tree  = ex.reverse();
				using type = typename decltype(tree)::template exec<Bs...>;
				return tree.f(type{}, std::move(p));
			};
			// will SFINAE if there is no rebind specialization
			template <typename... Bs, typename F, typename RF = typename rebind<F>::type,
			          typename type = typename RF::template exec<Bs...>>
			constexpr auto operator>>=(const pack<Bs...> &&p, F f)
			        -> decltype(RF{}.f(type{}, std::move(p))) {
				return RF{}.f(type{}, std::move(p));
			};
			// will SFINAE if there is no rebind specialization
			template <typename... Bs, typename F, typename RF = typename rebind<F>::type,
			          typename type = typename RF::template exec<Bs...>>
			constexpr auto operator>>=(pack<Bs...> &&p, F f)
			        -> decltype(RF{}.f(type{}, std::move(p))) {
				return RF{}.f(type{}, std::move(p));
			};
			// will SFINAE if there is no rebind specialization
			template <typename... Bs, typename F, typename RF = typename rebind<F>::type,
			          typename type = typename RF::template exec<Bs...>>
			constexpr auto operator>>=(const pack<Bs...> &p, F f) {
				return RF{}.f(type{}, p);
			};
			// will SFINAE if there is no rebind specialization
			template <typename... Bs, typename F, typename RF = typename rebind<F>::type>
			constexpr auto operator>>=(pack<Bs...> &p, F f) {
				using type = typename RF::template exec<Bs...>;
				return RF{}.f(type{}, p);
			};
			// will SFINAE if rhs can not be called with pack parameters
			template <typename... Ps, typename F>
			constexpr auto operator>>=(pack<Ps...> &p, F f)
			        -> decltype(f(static_cast<Ps &>(p).data...)) {
				return f(static_cast<Ps &>(p).data...);
			};
		} // namespace fusion
#endif
	} // namespace tmp
} // namespace osf

#endif