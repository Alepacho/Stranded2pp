cmake_minimum_required(VERSION 3.20)

# C++ Settings
set(PROJECT_NAME "Stranded2pp")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra -Werror -pedantic")
if (APPLE)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated-copy -Wno-deprecated-declarations -Wno-gnu -Wno-null-pointer-arithmetic")
endif()
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/stranded2_en")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

# So yeah, this is a project.
project(${PROJECT_NAME} CXX)

# Find all necessary packages
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

find_package(SFML 2.4 REQUIRED COMPONENTS system window graphics network audio)
include_directories(${SFML_INCLUDE_DIR})

# Set source code and libraries
include_directories(source)
file(GLOB_RECURSE SOURCES source/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
	${OPENGL_gl_LIBRARY}
	${SFML_LIBRARIES}
)
