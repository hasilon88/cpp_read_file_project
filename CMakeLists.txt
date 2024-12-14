cmake_minimum_required(VERSION 3.29)
project(final)

set(CMAKE_CXX_STANDARD 20)

add_executable(final
        models/patient.model.cpp
        models/patient.model.h
        services/patient.service.cpp)
