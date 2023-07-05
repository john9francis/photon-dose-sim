cmake_minimum_required(VERSION 2.9) # CMake quits without it

project(photon-dose-sim) # project name

find_package(Geant4 REQUIRED ui_all vis_all) # search for Geant4Config.cmake
include(${Geant4_USE_FILE}) # Linux cannot find Geant4 header files without it
add_executable(photon-dose-sim photon-dose-sim.cpp)
target_link_libraries(photon-dose-sim ${Geant4_LIBRARIES})

if(WIN32)
  # remove Debug and other unnecessary configurations
  set(CMAKE_CONFIGURATION_TYPES "Release" CACHE INTERNAL "")
  # https://stackoverflow.com/a/37994396/1801749
  set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT photon-dose-sim)
endif()
