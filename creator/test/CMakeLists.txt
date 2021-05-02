# CMake Version
CMAKE_MINIMUM_REQUIRED (VERSION 3.2.0)

# Project Name
PROJECT(design_pattern_test_app)

SET(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

ADD_DEFINITIONS(-Wall -DCALIB_CFG_OS="${CMAKE_SYSTEM_NAME}" -DCALIB_CFG_CPU="${CMAKE_SYSTEM_PROCESSOR}")

# Configuration

include_directories(
	../include
  ../include/singleton
)

file(GLOB SRC_FILES 
	../src/*.cpp
)

add_executable (singleton_test_app
  ${SRC_FILES}
  ./singleton_test_app.cpp
)

set_target_properties(singleton_test_app PROPERTIES LINK_LIBRARIES -pthread)