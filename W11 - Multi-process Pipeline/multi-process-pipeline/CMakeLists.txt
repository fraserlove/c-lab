cmake_minimum_required(VERSION 3.17)
project(multi_process_pipeline C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(multi_process_pipeline
        src/Pipeline.c
        src/Pipeline.h
        src/SievePipeline.c
        src/SumSquaresPipeline.c)
