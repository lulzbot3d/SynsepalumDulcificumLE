message(STATUS "dulcificumle: Compiling with Tests")
enable_testing()

find_package(GTest REQUIRED)

set(UNIT_TEST_FILES
        dulcificum_unit_tester.cpp
        miracle_jsontoolpath_dialect_test.cpp
)

add_executable(dulcificumle_unit_tester
    ${UNIT_TEST_FILES}
    test_data_dir.h
)

target_link_libraries(dulcificumle_unit_tester PUBLIC dulcificumle GTest::gtest GTest::gmock)