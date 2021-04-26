cmake_minimum_required(VERSION 3.17)
project(Coursework)

set(CMAKE_CXX_STANDARD 20)

add_executable(Coursework main.cpp CWLib.cpp CWLib.h Student.cpp Student.h Subject.cpp Subject.h Semester.cpp Semester.h Active.cpp Active.h Grademeres.h OwnTypes.h)