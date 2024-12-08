cmake_minimum_required(VERSION 3.30)

project(Gabrain
        VERSION 1.0
        DESCRIPTION "A Brainfuck interpreter written in C"
        LANGUAGES C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

if (CMAKE_C_COMPILER_ID STREQUAL "GNU" OR CMAKE_C_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

file(GLOB_RECURSE SRC_FILES src/*.c)

if (NOT SRC_FILES)
    message(FATAL_ERROR "No source files found in src directory.")
endif()

add_executable(${PROJECT_NAME} ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC include)

set_target_properties(${PROJECT_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

option(ENABLE_DEBUG "Enable debug mode" OFF)
if (ENABLE_DEBUG)
    target_compile_definitions(${PROJECT_NAME} PRIVATE DEBUG_MODE)
    message(STATUS "Debug mode enabled")
endif()

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_options(${PROJECT_NAME} PRIVATE -O3)
elseif (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(${PROJECT_NAME} PRIVATE -g)
endif()

enable_testing()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C Standard: ${CMAKE_C_STANDARD}")
message(STATUS "Source files:")
foreach(SRC ${SRC_FILES})
    message(STATUS "  ${SRC}")
endforeach()
