cmake_minimum_required(VERSION 3.20)
project(Vec
  VERSION 1.0
  DESCRIPTION "Simple vector implementation"
  LANGUAGES C)

set(SOURCES
  src/example.c
)

set(HEADERS_VEC
  src/vec/
  src/types/
)

set(SOURCES_VEC
  src/vec/vec.c
)

add_library(vec SHARED ${SOURCES_VEC})
target_include_directories(vec PUBLIC ${HEADERS_VEC})

add_library(vec_static STATIC ${SOURCES_VEC})
target_include_directories(vec_static PUBLIC ${HEADERS_VEC})

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PUBLIC vec)
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
