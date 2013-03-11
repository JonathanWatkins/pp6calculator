# - Main CMake script for pp6calculator
#
# - Require lastest generatation of CMake
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

# - Declare the project
project(pp6calculator)

# - Tell compiler where to find headers
include_directories(include)

# - Tell compiler where to find headers
include_directories(FileReader-1.0.0)

# - Add the pp6calculator maths libaray
add_library(pp6lib 
include/maths.hpp include/maths.cpp
include/physics.hpp include/physics.cpp
include/menu.hpp include/menu.cpp
include/mainmenu.hpp include/mainmenu.cpp
include/mathsmenu.hpp include/mathsmenu.cpp
include/physicsmenu.hpp include/physicsmenu.cpp
include/advphysicsmenu.hpp include/advphysicsmenu.cpp
include/CFourVector.hpp include/CFourVector.cpp
include/CParticle.hpp include/CParticle.cpp
include/CParticleInfo.hpp include/CParticleInfo.cpp
)


# - Add the pp6calculator input libaray
add_library(input include/input.hpp include/input.cpp)

# - Add the FileReader libaray
add_library(filereader FileReader-1.0.0/FileReader.hpp FileReader-1.0.0/FileReader.cpp)

# - Add the pp6calculator executable
add_executable(pp6calculator calc.cpp)

# - Link pp6calculator to the pp6maths library
target_link_libraries(pp6calculator pp6lib input filereader)

# - Install pp6calculator to the bin subdirectory of CMAKE_INSTALL_PREFIX
install(TARGETS pp6calculator DESTINATION bin)

# - Package pp6calculator sources and executable
include(CPack)

