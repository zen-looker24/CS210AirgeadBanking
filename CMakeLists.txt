cmake_minimum_required(VERSION 4.2)
project(AirgeadBanking)

set(CMAKE_CXX_STANDARD 20)

add_executable(AirgeadBanking main.cpp
        UserInterface.h
        UserInterface.cpp
        Account.cpp
        Account.h)
