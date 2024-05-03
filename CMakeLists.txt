cmake_minimum_required(VERSION 3.28)
project(SproutLands)

set(CMAKE_CXX_STANDARD 20)

find_package(raylib CONFIG REQUIRED)

add_executable(${PROJECT_NAME} main.cpp
        Game.cpp
        Game.h
        types.h
)
target_link_libraries(${PROJECT_NAME} PRIVATE opengl32 raylib)