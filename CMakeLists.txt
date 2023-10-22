cmake_minimum_required(VERSION 3.20)
project(vec
  VERSION 1.0
  DESCRIPTION "Simple vector implementation"
  LANGUAGES C)

set(SOURCES
  src/example.c
  src/vec/vec.c
)

set(HEADERS
  src/vec/
  src/types/
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${HEADERS})
target_compile_features(${PROJECT_NAME} PUBLIC c_std_11)
target_compile_options(${PROJECT_NAME}
  PRIVATE
  -Werror
  -Wall
  -Wextra
  -Wpedantic
  -Wcast-align
  -Wcast-qual
  -Wconversion
  -Wctor-dtor-privacy
  -Wenum-compare
  -Wfloat-equal
  -Wnon-virtual-dtor
  -Wold-style-cast
  -Woverloaded-virtual
  -Wredundant-decls
  -Wsign-conversion
  -Wsign-promo
)
