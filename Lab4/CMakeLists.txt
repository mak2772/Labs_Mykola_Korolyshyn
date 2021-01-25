cmake_minimum_required( VERSION 3.0 )

project( LAB4 )

include_directories( ./include)

add_executable( main ./src/main.cpp ./src/matrix.cpp )