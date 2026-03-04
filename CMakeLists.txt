cmake_minimum_required(VERSION 3.12)
project(ring VERSION 1.0)

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

add_executable(core src/main.c src/display.c)

target_link_libraries(core PUBLIC SDL2::SDL2 OpenGL::GL GLEW::GLEW)
