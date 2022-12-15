cmake_minimum_required (VERSION 3.21)

set (PROJECT wxWidgetsTests)
project(${PROJECT})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Options
option(ENABLE_CCACHE        "Enable the usage of Ccache."           ON)
option(ENABLE_WARNINGS      "Enable to add warnings to a target."   ON)

# Cmake modules
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")
# CMake properies
include(CMakeConfig)
# Conan and dependencies
# include(ConanModule)

add_subdirectory(3rdParty/wxWidgets)
add_subdirectory(wxCalc)
