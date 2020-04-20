cmake_minimum_required(VERSION 3.1)

project(timer CXX)

if(CMAKE_BUILD_TYPE MATCHES "Debug")
    message(STATUS "build MasterTimer with Debug mode")
    set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_LIST_DIR}/install/Debug)
else()
    message(STATUS "build MasterTimer with Release mode")
    set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_LIST_DIR}/install/Release)
endif()

# Remove 'lib' prefix for shared libraries on Windows
if (WIN32)
  set(CMAKE_SHARED_LIBRARY_PREFIX "")
endif ()

add_subdirectory(timersrc)

#test log
enable_testing()
add_subdirectory(test)
