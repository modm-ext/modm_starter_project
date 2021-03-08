cmake_minimum_required(VERSION 3.15)
include(cmake/ToolChain.cmake)

# Change the project name
project(example CXX C)
include(cmake/StandardProjectSettings.cmake)
include(cmake/PreventInSourceBuilds.cmake)

add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_20)

# Colors is unsupported vscode, can also be turend off in cmake/StandardProjectSettings.cmake
target_compile_options(project_options INTERFACE -fdiagnostics-color=never)

if(NOT MODM_GCC_PATH AND NOT DEFINED ENV{GCC_PATH})
  message(WARNING "Enviroment variable GCC_PATH not set.\nDefaults to: /usr/local/arm-none-eabi")
  set(MODM_GCC_PATH
    "/usr/local/arm-none-eabi"
    CACHE STRING "Path to gcc root directory" FORCE)
endif()
if(NOT MODM_GCC_PATH AND DEFINED ENV{GCC_PATH})
  set(MODM_GCC_PATH
    $ENV{GCC_PATH}
    CACHE STRING "Path to gcc root directory" FORCE)
endif()

target_compile_options(project_options INTERFACE
  -ffile-prefix-map=${MODM_GCC_PATH}=.
  -ffile-prefix-map=${CMAKE_SOURCE_DIR}=.)

add_library(project_warnings INTERFACE)
include(cmake/Cache.cmake)

include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warnings)

include(cmake/Doxygen.cmake)
enable_doxygen()

include(cmake/StaticAnalyzers.cmake)

option(ENABLE_PCH "Enable Precompiled Headers" OFF)
if(ENABLE_PCH)
  target_precompile_headers(
    project_options
    INTERFACE
    <vector>  # Insert preferred headers
    <string>
    <map>
    <utility>)
endif()

add_subdirectory(modm)
add_subdirectory(hdr_only_lib)
add_subdirectory(src)
