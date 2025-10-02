cmake_minimum_required(VERSION 4.0)
project(QQCompiler)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.1
)
FetchContent_MakeAvailable(googletest)

find_package(Armadillo REQUIRED)
find_package(GTest REQUIRED)

include_directories(${ARMADILLO_INCLUDE_DIRS})
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(QQCompiler 
    main.cpp
    qasm/qasm.cpp
    unitary/unitary.cpp
)
target_link_libraries(QQCompiler PRIVATE ${ARMADILLO_LIBRARIES})

enable_testing()

add_executable(tests
    tests/test.cpp
    qasm/qasm.cpp
    unitary/unitary.cpp
)
target_link_libraries(tests PRIVATE 
    ${ARMADILLO_LIBRARIES}
    ${GTEST_LIBRARIES}
)

add_test(NAME UnitTests COMMAND tests)