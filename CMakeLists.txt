cmake_minimum_required(VERSION 4.0)
project(QQCompiler)

set(CMAKE_CXX_STANDARD 20)

find_package(Armadillo REQUIRED)

include_directories(${ARMADILLO_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} main.cpp
        qasm/qasm.h
        qasm/qasm.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE ${ARMADILLO_LIBRARIES})