cmake_minimum_required(VERSION 3.17)
project(stack)

set(CMAKE_CXX_STANDARD 14)

add_executable(stack main.cpp stack.h stackArray.h StackUnderflow.h StackOverflow.h main_headers.h WrongStackSize.h)