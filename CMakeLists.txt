cmake_minimum_required(VERSION 3.15)
include(cmake/ToolChain.cmake)

# Change the project name
project(example CXX C)

add_library(project_options INTERFACE)

# Generate compile_commands.json to make it easier to work with clang based tools
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Colors is unsupported vscode, can also be turend off in cmake/StandardProjectSettings.cmake
target_compile_options(project_options INTERFACE -fdiagnostics-color=never)

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
