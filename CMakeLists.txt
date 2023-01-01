cmake_minimum_required(VERSION 3.20)

project(root_hook_up_debugger C CXX)

set(CMAKE_CXX_STANDARD 17)

include(cmake/fetch_content.cmake)
include(cmake/find_packages.cmake)

enable_testing()
include(GoogleTest)

add_subdirectory(src)