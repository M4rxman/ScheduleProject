cmake_minimum_required(VERSION 3.26)
project(schedule)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/DataCollectors)

add_executable(schedule
        src/ClassesStruct/ClassesPerUc.cpp
        src/ClassesStruct/ClassesPerUc.h
        src/DataCollectors/DataCollector.h
        src/DataCollectors/DataCollector.cpp
        src/DataCollectors/DataTest.cpp
)
