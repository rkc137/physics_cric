cmake_minimum_required(VERSION 3.10)
project(physics_cric)

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)

link_directories(${GTKMM_LIBRARY_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS})

add_executable(cric main.cpp MainWindow.cpp Scene.cpp)
target_link_libraries(cric ${GTKMM_LIBRARIES})

