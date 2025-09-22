cmake_minimum_required(VERSION 3.15)
project(RayApp)
option(RAYAPP_BUILD_DOCS "Build Doxygen documentation" OFF)
option(RAYAPP_BUILD_EXAMPLES "Build examples" OFF)
# doxygen
if(RAYAPP_BUILD_DOCS)
    find_package(Doxygen REQUIRED)
    if(DOXYGEN_FOUND)
        set(DOXYGEN_IN "${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile")
        set(DOXYGEN_OUT "${CMAKE_CURRENT_SOURCE_DIR}/docs")
        add_custom_target(doc ALL
            COMMAND "${DOXYGEN_EXECUTABLE}" "${DOXYGEN_IN}"
            WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
            COMMENT "Generating documentation with Doxygen"
            VERBATIM)
    endif()
endif()
#examples
if(RAYAPP_BUILD_EXAMPLES)
    add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/examples")
endif()
include(FetchContent)
FetchContent_Declare(
	raylib
	GIT_REPOSITORY https://github.com/raysan5/raylib.git
	GIT_TAG 5.5
)
FetchContent_MakeAvailable(raylib)
# globbing lol
# might replace
file(GLOB_RECURSE rayapp_srcs "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_library(RayApp STATIC "${rayapp_srcs}")
target_link_libraries(RayApp raylib)
target_include_directories(RayApp PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
