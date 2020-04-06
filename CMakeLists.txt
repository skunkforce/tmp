cmake_minimum_required(VERSION 3.8)
project(osf_tmp VERSION 0.0.1)

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

# create a target for the library
add_library(osf_tmp INTERFACE)
target_sources(osf_tmp INTERFACE "$<BUILD_INTERFACE:${detail_header_files};${header_files}>")

# tmp requires a number of features to compile, this will automatically set the c++ standard version
# to support those features. The c++ version is not explicitly set, so that cmake can figure
# things out by itself
target_compile_features(osf_tmp INTERFACE
		cxx_generic_lambdas
		cxx_variable_templates
		cxx_variadic_templates
		cxx_constexpr
		cxx_alias_templates
		cxx_auto_type
		cxx_long_long_type
		cxx_right_angle_brackets
		cxx_static_assert
		cxx_uniform_initialization
		cxx_user_literals
		${CPP_EXTRA_FEATURES})

target_include_directories(osf_tmp SYSTEM INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
        $<INSTALL_INTERFACE:include/>)

# installation
    include(CMakePackageConfigHelpers)
    write_basic_package_version_file(osf_tmp-config-version.cmake COMPATIBILITY ExactVersion)
    install(TARGETS osf_tmp EXPORT osf_tmp_targets
            INCLUDES DESTINATION include)
    install(EXPORT osf_tmp_targets
            DESTINATION lib/cmake/osf_tmp
            FILE osf_tmp-targets.cmake
            NAMESPACE foonathan::)
    install(DIRECTORY include/
            DESTINATION include)
    install(FILES osf_tmp-config.cmake ${CMAKE_CURRENT_BINARY_DIR}/osf_tmp-config-version.cmake
            DESTINATION lib/cmake/osf_tmp)

# subdirectories
option(OSF_TMP_BUILD_TEST "build tests of osf.tmp" OFF)
if(${OSF_TMP_BUILD_TEST} OR (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR))
	add_subdirectory(test)
endif()

option(MAKE_INCLUDE_TESTS OFF)
if (MAKE_INCLUDE_TESTS)
	function(convert_name out filename)
		string(REGEX REPLACE "[\\./]" "_" result "${filename}")
		set(${out} ${result} PARENT_SCOPE)
	endfunction()
	function(make_test_includes_file file)
		convert_name(basename "${file}")
		file(WRITE ${CMAKE_BINARY_DIR}/include_test/${basename}.cpp
				"#include <${file}>\nint main() {}")
	endfunction()
	file(GLOB_RECURSE headers RELATIVE "${CMAKE_CURRENT_LIST_DIR}/tmp/"
			"${CMAKE_CURRENT_LIST_DIR}/tmp/*.hpp")
	foreach(file IN LISTS headers)
		make_test_includes_file(${file})
		convert_name(basename "${file}")
		add_executable(${basename} include_test/${basename}.cpp)
		target_link_libraries(${basename} skunkforce_tmp)
		target_compile_options(${basename} PUBLIC -Wall)
		add_dependencies(skunkforce_tmp_test ${basename})
	endforeach()
	file(GLOB_RECURSE tests RELATIVE "${CMAKE_CURRENT_LIST_DIR}/"
			"${CMAKE_CURRENT_LIST_DIR}/test/*.hpp")
	foreach (file IN LISTS tests)
		make_test_includes_file(${file})
		convert_name(basename "${file}")
		add_executable(${basename} include_test/${basename}.cpp)
		target_link_libraries(${basename} skunkforce_tmp)
		target_include_directories(${basename} PRIVATE ${CMAKE_CURRENT_LIST_DIR})
		target_compile_options(${basename} PUBLIC -Wall)
		add_dependencies(skunkforce_tmp_test ${basename})
	endforeach ()
endif ()
