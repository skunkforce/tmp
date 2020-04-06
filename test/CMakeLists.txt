add_executable(osf_tmp_test test.cpp)
        
target_link_libraries(osf_tmp_test osf_tmp)
target_compile_options(osf_tmp_test PUBLIC -ftemplate-depth=2048 -Wall)