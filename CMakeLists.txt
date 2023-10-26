cmake_minimum_required(VERSION 3.26)
project(schedule)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/DataCollectors)
include_directories(google_tests/googletest-main/googletest/include)
include_directories(google_tests/googletest-main/googlemock/include)

add_subdirectory(google_tests/googletest-main)

add_executable(schedule
        src/DataCollectors/ClassesPerUc.cpp
        src/DataCollectors/ClassesPerUc.h
        src/DataCollectors/DataCollector.h
        src/DataCollectors/DataCollector.cpp
        src/main.cpp
        src/DataCollectors/StudentClasses.h
        src/DataCollectors/StudentClasses.cpp
        "src/ClassesStruct/UcCode.h"
        src/ClassesStruct/UcCode.cpp
)
