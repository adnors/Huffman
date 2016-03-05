cmake_minimum_required(VERSION 3.3)
project(Huffman)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Encode.cpp Encode.h Tree.cpp Tree.h Decode.cpp Decode.h Code.cpp Code.h)
add_executable(Huffman ${SOURCE_FILES})