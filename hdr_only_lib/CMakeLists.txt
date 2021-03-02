# Header only library example CMakeLists.txt
#

add_library(my_header_lib INTERFACE)

# Add header directories here
target_include_directories(my_header_lib
   INTERFACE
   include/)
