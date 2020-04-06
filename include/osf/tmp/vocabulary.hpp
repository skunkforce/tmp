#ifndef OSF_TMP_VOCABULARY_HPP_INCLUDED
#define OSF_TMP_VOCABULARY_HPP_INCLUDED

#include "always.hpp"
#include "lift.hpp"

namespace osf {
	namespace tmp {
		template <typename... Ts>
		struct list_ {};

		using listify_ = lift_<list_>;

		template <unsigned long long V>
		struct uint_ {
			static constexpr unsigned long long value = V;
		};
		template <long long I>
		struct int_ {
			static constexpr long long value = I;
		};
		template <bool B>
		struct bool_ {
			static constexpr bool value = B;
		};
		template <std::size_t S>
		struct size_t_ {
			static constexpr std::size_t value = S;
		};

		using true_  = bool_<true>;
		using false_ = bool_<false>;

		struct nothing_ {};
	} // namespace tmp
} // namespace osf
#endif
