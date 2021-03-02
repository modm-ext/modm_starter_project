# Shared library example CMakeLists.txt
#

# Add source files here
add_library(my_shared_lib
  STATIC
  src/mylib.cpp)

# Add include files here
target_include_directories(my_shared_lib
  PUBLIC
    include
  PRIVATE
    src/include)

target_link_libraries(my_shared_lib
  project_options
  modm_options
  modm_warnings)

# Extra compiler options for local library.
#target_compile_options(${CMAKE_PROJECT_NAME}
#  PRIVATE
#  -Wpedantic
#  -Wconversion
#)

#target_compile_definitions(my_shared_lib
#   PUBLIC
#  -DMY_DEBUG_OPTION)
