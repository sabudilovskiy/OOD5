cmake_minimum_required(VERSION 3.20)
project(OOD5)
set(CMAKE_CXX_STANDARD 20)

include(conan_libraries/conan_paths.cmake)
find_package(GTest)
find_package(magic_enum)

add_library(${PROJECT_NAME}
    src/BaseBank.hpp src/Sber.hpp src/Sber.cpp src/Alpha.hpp src/Tinkoff.hpp src/MakerBank.hpp src/MakerBank.cpp)
#Unit Tests
include(GoogleTest)
add_executable( ${PROJECT_NAME}_tests
        tests/basic.cpp)
target_link_libraries(${PROJECT_NAME}_tests PRIVATE
        GTest::gtest
        GTest::gtest_main
        ${PROJECT_NAME}_objs)
#Main
add_executable(${PROJECT_NAME}_console console/main.cpp)
target_link_libraries(${PROJECT_NAME} magic_enum::magic_enum)
target_link_libraries(${PROJECT_NAME}_console ${PROJECT_NAME})
include_directories(src)