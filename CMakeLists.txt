cmake_minimum_required(VERSION 3.10)
project(SnappyBird)

add_subdirectory(external/raylib)

set(SOURCES
    src/main.cpp
)

add_executable(SnappyBird
    ${SOURCES}
)

target_include_directories(SnappyBird PRIVATE
    src
)

target_link_libraries(SnappyBird PRIVATE
    raylib
    glfw
    GL  
    m 
    dl
    pthread 
)

set_target_properties(SnappyBird PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED YES)