# - Main CMake script for pp6calculator
#
# - Require lastest generatation of CMake
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

# - Declare the project
project(pp6calculator)

# - Tell compiler where to find headers
include_directories(include)

# - Add the pp6calculator maths libaray
add_library(pp6maths include/maths.hpp include/maths.cpp)

# - Add the pp6calculator physics libray
add_library(pp6physics include/physics.hpp include/physics.cpp)

# - Add the pp6calculator menu libaray
add_library(menu include/menu.hpp include/menu.cpp)

# - Add the pp6calculator mainmenu libaray
add_library(mainmenu include/mainmenu.hpp include/mainmenu.cpp)

# - Add the pp6calculator mathsmenu libaray
add_library(mathsmenu include/mathsmenu.hpp include/mathsmenu.cpp)

# - Add the pp6calculator physicsmenu libaray
add_library(physicsmenu include/physicsmenu.hpp include/physicsmenu.cpp)

# - Add the pp6calculator input libaray
add_library(input include/input.hpp include/input.cpp)

# - Add the pp6calculator executable
add_executable(pp6calculator calc.cpp)

# - Link pp6calculator to the pp6maths library
target_link_libraries(pp6calculator pp6maths pp6physics menu mainmenu physicsmenu mathsmenu input)

# - Install pp6calculator to the bin subdirectory of CMAKE_INSTALL_PREFIX
install(TARGETS pp6calculator DESTINATION bin)

# - Package pp6calculator sources and executable
include(CPack)

