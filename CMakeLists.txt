cmake_minimum_required(VERSION 3.12)
project(osf-tmp VERSION 0.0.1)

set(detail_header_files
    ${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/detail/capabilities.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/detail/dispatch.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/detail/expression.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/detail/fusion_execute.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/detail/fusion_rebind.hpp
)
set(header_files
    ${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/algorithm/contains.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/algorithm/count_if.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/algorithm/filter.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/algorithm/find_if.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/algorithm/fold_left.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/algorithm/fold_right.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/algorithm/partition.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/algorithm/product.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/algorithm/remove_if.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/algorithm/replace_if.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/algorithm/sort.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/algorithm/transform.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/fusion/contains.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/fusion/filter.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/fusion/find_if.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/sequence/container.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/sequence/drop.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/sequence/each.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/sequence/erase.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/sequence/index.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/sequence/insert.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/sequence/join.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/sequence/make_sequence.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/sequence/pop_front.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/sequence/push_front.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/sequence/push_back.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/sequence/reverse.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/sequence/rotate.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/sequence/size.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/sequence/swap.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/sequence/take.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/sequence/tee.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/sequence/unpack.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/sequence/zip_with_index.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/sequence/zip.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/always.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/call.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/comparison.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/fusion.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/identity.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/if.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/lift.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/logic.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/pack.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/try.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp/vocabulary.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/osf/tmp.hpp
)

include("cmake/osf-cmake-helpers.cmake")
osf_generate_header_only_cmake(osf-tmp osf 1 0 "")

target_compile_features(osf-tmp INTERFACE cxx_std_11)


