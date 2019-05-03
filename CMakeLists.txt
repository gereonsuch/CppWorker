cmake_minimum_required(VERSION 2.8)

project(CppWorker)

SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 -pthread")
find_package (Threads)


add_library(processingunit.h INTERFACE) #only to make it visible in the project. ProcessingUnit is header only implemented.
add_library(threadfifoqueue.h INTERFACE) #only to make it visible in the project. ThreadFIFOQueue is header only implemented.

add_library(messagehandler.h INTERFACE) #only to make it visible in the project. ThreadFIFOQueue is header only implemented.

add_library(PMTTools pmttools.cpp)

add_executable(${PROJECT_NAME} "main.cpp")
target_link_libraries (${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})


