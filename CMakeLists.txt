cmake_minimum_required(VERSION 4.1)
project(ImgFilt)

set(CMAKE_CXX_STANDARD 23)

add_executable(ImgFilt main.cpp
        Window.cpp
        library.cpp
        Image.cpp)