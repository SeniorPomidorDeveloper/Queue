cmake_minimum_required(VERSION 3.5)
cmake_policy(SET CMP0060 NEW)

project(Queue)

add_library(queue SHARED ./src/queue.c)