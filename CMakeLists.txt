# To start, create CMakeLists.txt file firstly in the working directory, then use the following commands:
# $ mkdir build && cd build && cmake .. && cd ..
# $ cmake -S . -B build
# $ cmake --build build

# To run executable file
# $ cmake --build build
# $ build/{executable_file}

# For testing or creating docs, using the follownig command:
# $ cmake --build build --target test (docs)


cmake_minimum_required(VERSION 3.5.0)
project(
    HandyBird
    VERSION 0.1.0
    DESCRIPTION "opencv quick learning"
    LANGUAGES CXX
)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#   # Docs only available if this is the main app
# find_package(Doxygen)
# if(Doxygen_FOUND)
#   add_subdirectory(docs)
# else()
#   message(STATUS "Doxygen not found, not building docs")
# endif()

include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/src
)


## In most cases better set in the CMake cache


if(CMAKE_VERSION VERSION_LESS "3.7.0")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})


file(GLOB all_SRCS
"${PROJECT_SOURCE_DIR}/include/*.h"
"${PROJECT_SOURCE_DIR}/include/*.hpp"
"${PROJECT_SOURCE_DIR}/src/*.cpp"
"${PROJECT_SOURCE_DIR}/src/*.c"
)

add_executable(HandyBird ${all_SRCS})
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED COMPONENTS network audio graphics window system)
target_link_libraries(HandyBird ${OpenCV_LIBS})
target_link_libraries(HandyBird ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
