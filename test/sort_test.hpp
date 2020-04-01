#include "test_util.hpp"
#include "tmp/algorithm/sort.hpp"
namespace sort_test {
	template <typename T, typename U>
	using less = bool_<(T::value < U::value)>;

	template <typename T, typename U>
	using push_ = typename T::template push<U, less>;
	int run() {
		list_<uint_<0>, uint_<1>, uint_<2>>{} =
		        call_<sort_<lift_<less>>, uint_<1>, uint_<0>, uint_<2>>{};
		call_<make_sequence_<>, uint_<100>>{} =
		        call_<sort_<lift_<less>>, uint_<0>, uint_<27>, uint_<87>, uint_<3>, uint_<56>,
		              uint_<76>, uint_<94>, uint_<17>, uint_<74>, uint_<55>, uint_<96>, uint_<54>,
		              uint_<93>, uint_<79>, uint_<14>, uint_<8>, uint_<31>, uint_<23>, uint_<25>,
		              uint_<34>, uint_<9>, uint_<44>, uint_<63>, uint_<4>, uint_<72>, uint_<46>,
		              uint_<49>, uint_<7>, uint_<83>, uint_<77>, uint_<61>, uint_<81>, uint_<91>,
		              uint_<69>, uint_<52>, uint_<28>, uint_<19>, uint_<57>, uint_<64>, uint_<75>,
		              uint_<2>, uint_<62>, uint_<43>, uint_<42>, uint_<5>, uint_<16>, uint_<18>,
		              uint_<41>, uint_<39>, uint_<6>, uint_<92>, uint_<60>, uint_<1>, uint_<35>,
		              uint_<29>, uint_<51>, uint_<12>, uint_<36>, uint_<24>, uint_<53>, uint_<11>,
		              uint_<32>, uint_<67>, uint_<58>, uint_<80>, uint_<86>, uint_<33>, uint_<85>,
		              uint_<15>, uint_<90>, uint_<20>, uint_<30>, uint_<50>, uint_<98>, uint_<99>,
		              uint_<70>, uint_<21>, uint_<95>, uint_<73>, uint_<78>, uint_<26>, uint_<38>,
		              uint_<82>, uint_<47>, uint_<40>, uint_<66>, uint_<59>, uint_<13>, uint_<89>,
		              uint_<71>, uint_<88>, uint_<37>, uint_<22>, uint_<84>, uint_<10>, uint_<97>,
		              uint_<68>, uint_<65>, uint_<48>, uint_<45>>{};

		return 0;
	}
} // namespace sort_test