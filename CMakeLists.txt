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
        "src/ClassesStruct/UcCode.h"
        src/ClassesStruct/UcCode.cpp
        src/DataCollectors/ClassesSchedule.h
        src/ClassesStruct/ClassCode.h
        src/ClassesStruct/Schedule.cpp
        src/ClassesStruct/ClassCode.cpp
        src/DataCollectors/ClassesSchedule.cpp
        src/DataCollectors/StudentsClasses.h
        src/DataCollectors/StudentsClasses.cpp
        src/ScheduleManagment/ScheduleManager.h
        src/ScheduleManagment/ScheduleManager.cpp
)
