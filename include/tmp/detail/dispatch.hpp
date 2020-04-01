#ifndef OSF_TMP_DISPATCH_HPP_INCLUDED
#define OSF_TMP_DISPATCH_HPP_INCLUDED

namespace osf {
	namespace tmp {
		namespace detail {
			constexpr unsigned find_dispatch(unsigned n) {
				return n <= 8 ? n :
				                n < 16 ?
				                9 :
				                n == 16 ?
				                16 :
				                n < 32 ?
				                17 :
				                n == 32 ?
				                32 :
				                n < 64 ? 33 : n == 64 ? 64 : n < 128 ? 65 : n == 128 ? 128 : 129;
			}

			template <unsigned N, typename T>
			struct dispatch;

			template <typename C>
			struct dispatch_unknown {
				template <typename... Ts>
				using f = typename dispatch<find_dispatch(sizeof...(Ts)), C>::template f<Ts...>;
			};
		} // namespace detail
	} // namespace tmp
} // namespace osf
#endif
