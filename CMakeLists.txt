cmake_minimum_required(VERSION 3.5)

project(Queue)

set(CMAKE_SHARED_LIBRARY_PREFIX "")

add_library(queue SHARED ./src/queue.c)