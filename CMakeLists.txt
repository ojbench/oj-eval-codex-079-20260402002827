cmake_minimum_required(VERSION 3.10)
project(problem_079 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Optimize and keep warnings reasonable
if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

add_executable(code src/main.cpp)

# Place the executable at the repository root as required by OJ
set_target_properties(code PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}
)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  target_compile_options(code PRIVATE -O2 -pipe -Wall -Wextra -Wshadow -Wconversion -Wno-sign-conversion)
endif()

