cmake_minimum_required(VERSION 3.20)
project(Vec
  VERSION 1.0
  DESCRIPTION "Simple vector implementation"
  LANGUAGES C)

add_library(vec SHARED src/vec/vec.c)
target_include_directories(vec PUBLIC src/vec/ src/types/)
target_compile_features(vec PUBLIC c_std_99)
target_compile_options(vec
  PRIVATE
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

add_executable(dvec examples/vec/example_vec.c)
target_link_libraries(dvec PUBLIC vec)
target_compile_features(dvec PUBLIC c_std_99)
target_compile_options(dvec
  PRIVATE
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

add_executable(svec examples/static_vec/example_svec.c)
target_link_libraries(svec PUBLIC vec)
target_compile_features(svec PUBLIC c_std_99)
target_compile_options(svec
  PRIVATE
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
