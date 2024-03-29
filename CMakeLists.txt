﻿cmake_minimum_required (VERSION 3.21)

set (PROJECT wxWidgetsTests)
project(${PROJECT})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Options
option(ENABLE_CCACHE        "Enable the usage of Ccache."           ON)
option(ENABLE_WARNINGS      "Enable to add warnings to a target."   ON)

# Cmake modules
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")
# CMake properies
include(Config)
# Conan and dependencies
#include(ConanModule)
# CMake findpackages
#include(FindPackages)

# CCache
if (ENABLE_CCACHE)
    include(Ccache)
endif()

set(wxBUILD_SHARED OFF)

add_subdirectory(3rdParty/wxWidgets)
add_subdirectory(wxCalc)
