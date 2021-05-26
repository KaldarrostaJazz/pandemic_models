
cmake_minimum_required(VERSION 3.20.2)
project(Logistic_Forecasts)
enable_testing()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAG} -fsanitize=address")

add_executable(logistic_model logistic_model.cpp main.cpp)
target_compile_options(logistic_model PRIVATE -Wall -Wextra -fsanitize=address)

add_executable(converter converter.cpp)
target_compile_options(converter PRIVATE -Wall -Wextra -fsanitize=address)

add_executable(logistic_test.t logistic_model.cpp logistic_test.cpp)
target_compile_options(logistic_test.t PRIVATE -Wall -Wextra -fsanitize=address)
add_test(COMMAND logistic_test.t)
