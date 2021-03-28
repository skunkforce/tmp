#include <osf/tmp/sequence/push_back.hpp>
#include <osf/tmp/pipeline.hpp>
#include "test_util.hpp"

namespace pipeline_test {

	using result0 = call_<pipeline_<push_back_<int>,push_back_<int>>, int>;

	int run() {
        list_<int,int,int>{} = result0{};
		return 0;
	}
} // namespace product_test