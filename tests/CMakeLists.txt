set(test_name "moving_objects")

add_executable(${test_name}
    ${CMAKE_SOURCE_DIR}/tests/main.cpp
    ${CMAKE_SOURCE_DIR}/tests/movement.cpp
    ${CMAKE_SOURCE_DIR}/tests/rotation.cpp
)

target_link_libraries(${test_name}
    gtest_main
    otus::hw2
)

set_target_properties(
    ${test_name}
    PROPERTIES
    CXX_STANDARD 23
    CXX_EXTENSIONS OFF
)

add_test(NAME ${test_name} COMMAND ${test_name})
