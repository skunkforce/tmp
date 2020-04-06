#ifndef OSF_TMP_FUSION_FILTER_HPP_INCLUDED
#define OSF_TMP_FUSION_FILTER_HPP_INCLUDED

#include "../algorithm/filter.hpp"
#include "../call.hpp"
#include "../comparison.hpp"
#include "../detail/capabilities.hpp"
#include "../detail/dispatch.hpp"
#include "../detail/expression.hpp"
#include "../pack.hpp"
#include "../sequence/index.hpp"
#include "../sequence/make_sequence.hpp"
#include "../sequence/tee.hpp"
#include "../sequence/zip_with_index.hpp"
#include "../vocabulary.hpp"

namespace osf {
	namespace tmp {
#ifdef OSF_TMP_CPP14
		template <typename F>
		struct filter_<F, listify_> {
			template <typename CT>
			auto operator|(CT c) {
				return fusion::detail::make_expr<CT>{}(filter_<F, listify_>{}, std::move(c));
			}
		};
		namespace fusion {
			template <typename F, typename Tail>
			struct ast<filter_<F, listify_>, Tail> {
				filter_<F, listify_> head;
				Tail tail;
				template <typename... Ts, typename... FBs, typename... Bs>
				constexpr auto f(list_<list_<FBs...>, list_<Ts...>>, const pack<Bs...> &&p) {
					return tail.f(
					        typename Tail::template exec<Ts...>{},
					        pack<Ts...>{Ts{static_cast<const FBs &&>(std::move(p)).get()}...});
				};
				template <typename... Ts, typename... FBs, typename... Bs>
				constexpr auto f(list_<list_<FBs...>, list_<Ts...>>, pack<Bs...> &&p) {
					return tail.f(typename Tail::template exec<Ts...>{},
					              pack<Ts...>{Ts{static_cast<FBs &&>(std::move(p)).get()}...});
				};
				template <typename... Ts, typename... FBs, typename... Bs>
				constexpr auto f(list_<list_<FBs...>, list_<Ts...>>, const pack<Bs...> &p) {
					return tail.f(typename Tail::template exec<Ts...>{},
					              pack<Ts...>{Ts{static_cast<const FBs &>(p).get()}...});
				};
				template <typename... Ts>
				using exec = call_<filter_<unpack_<i1_<F>>,
				                           tee_<listify_,
				                                transform_<unpack_<i1_<>>,
				                                           zip_with_index_<lift_<detail::base>>>,
				                                listify_>>,
				                   Ts...>;
			};
			template <typename F>
			struct ast<filter_<F, listify_>, listify_> { // break recursion
				filter_<F, listify_> head;
				template <typename... Ts, typename... FBs, typename... Bs>
				constexpr auto f(list_<list_<FBs...>, list_<Ts...>> t, const pack<Bs...> &&p) {
					return pack<Ts...>{Ts{static_cast<const FBs &&>(p).get()}...};
				};
				template <typename... Ts, typename... FBs, typename... Bs>
				constexpr auto f(list_<list_<FBs...>, list_<Ts...>> t, const pack<Bs...> &p) {
					return pack<Ts...>{Ts{static_cast<const FBs &>(p).get()}...};
				};
				template <typename... Ts>
				using exec = call_<filter_<unpack_<i1_<F>>,
				                           tee_<listify_,
				                                transform_<unpack_<i1_<>>,
				                                           zip_with_index_<lift_<detail::base>>>,
				                                listify_>>,
				                   Ts...>;
			};

			template <typename F, typename C>
			struct rebind<filter_<F, C>> {
				using type = ast<filter_<F, listify_>, typename rebind<C>::type>;
			};

			template <typename F>
			struct rebind<filter_<F, listify_>> {
				using type = ast<filter_<F, listify_>, listify_>;
			};
		} // namespace fusion
#endif
	} // namespace tmp
} // namespace osf

#endif