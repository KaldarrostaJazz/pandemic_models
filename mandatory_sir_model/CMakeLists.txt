cmake_minimum_required(VERSION 3.20.2)
project(SIR_model_implementation)
enable_testing()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAG} -fsanitize=address")

add_executable(sir_model State.cpp Virus.cpp Pandemy.cpp Least_Squares.cpp main.cpp)
target_compile_options(sir_model PRIVATE -Wall -Wextra -fsanitize=address)

add_executable(sir_model.t State.cpp Virus.cpp Pandemy.cpp Least_Squares.cpp pandemy.test.cpp)
target_compile_options(sir_model.t PRIVATE -Wall -Wextra -fsanitize=address)
add_test(COMMAND sir_model.t)
