cmake_minimum_required( VERSION 3.0 )

project(HR)

include_directories( ./src ./include)

add_executable(test ./src/main.cpp ./src/employee.cpp ./src/HRMS.cpp)