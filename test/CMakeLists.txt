add_executable(osf-tmp_test test.cpp)

target_compile_features(osf-tmp_test INTERFACE cxx_std_14)
        
target_link_libraries(osf-tmp_test osf-tmp)
target_compile_options(osf-tmp_test PUBLIC -ftemplate-depth=2048 -Wall)