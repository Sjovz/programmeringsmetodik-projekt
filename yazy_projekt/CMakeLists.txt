cmake_minimum_required(VERSION 3.30)
project(yazy)

set(CMAKE_CXX_STANDARD 20)

# Include Raylib manually
include_directories(/opt/homebrew/Cellar/raylib/5.5/include)
link_directories(/opt/homebrew/Cellar/raylib/5.5/lib)

add_executable(yazy main.cpp)

# Link Raylib library
target_link_libraries(yazy raylib)