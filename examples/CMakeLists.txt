cmake_minimum_required(VERSION 3.15)
add_executable(BasicApp "${CMAKE_CURRENT_SOURCE_DIR}/BasicApp.cpp")
target_link_libraries(BasicApp RayApp)
