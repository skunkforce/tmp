#include "test_util.hpp"
#include "tmp/sequence/take.hpp"
#include "tmp/vocabulary.hpp"
namespace take_test {
	template <int>
	struct x;

	using xs0 = list_<x<1>, x<2>, x<3>, x<4>, x<5>, x<6>, x<7>, x<8>, x<9>, x<10>>;

	using result0 = call_<unpack_<take_<uint_<0>>>, xs0>;
	using result1 = call_<unpack_<take_<uint_<1>>>, xs0>;
	using result2 = call_<unpack_<take_<uint_<9>>>, xs0>;

	int run() {

		return 0;
	}
} // namespace take_test