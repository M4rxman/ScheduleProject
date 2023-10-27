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
        src/main.cpp
        src/ClassesStruct/Student.h
        src/ClassesStruct/Student.cpp
        "src/ClassesStruct/UcCodeClassCode.h"
        src/ClassesStruct/UcCodeClassCode.cpp
        src/ClassesStruct/ClassesTimeTable.h
        src/ClassesStruct/ClassesTimeTable.cpp
        src/DataCollectors/CalssesSchedule.h
)
