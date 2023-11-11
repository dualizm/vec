cmake_minimum_required(VERSION 3.20)
project(vec
  VERSION 1.0
  DESCRIPTION "Simple vector implementation"
  LANGUAGES C)

set(FLAGS
  -Werror
  -Wall
  -Wextra
  -Wpedantic
  -Wcast-align
  -Wcast-qual
  -Wconversion
  -Wenum-compare
  -Wfloat-equal
  -Wredundant-decls
  -Wsign-conversion
)

add_library(${PROJECT_NAME} SHARED src/vec/vec.c)
target_include_directories(${PROJECT_NAME} PUBLIC src/vec/ src/types/)
target_compile_features(${PROJECT_NAME} PUBLIC c_std_99)
target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})

set(EXAMPLE1 example1)
add_executable(${EXAMPLE1} examples/example1.c)
target_link_libraries(${EXAMPLE1} PUBLIC ${PROJECT_NAME})
target_compile_features(${EXAMPLE1} PUBLIC c_std_99)
target_compile_options(${EXAMPLE1} PRIVATE ${FLAGS})

set(EXAMPLE2 example2)
add_executable(${EXAMPLE2} examples/example2.c)
target_link_libraries(${EXAMPLE2} PUBLIC ${PROJECT_NAME})
target_compile_features(${EXAMPLE2} PUBLIC c_std_99)
target_compile_options(${EXAMPLE2} PRIVATE ${FLAGS})
