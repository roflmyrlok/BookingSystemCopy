cmake_minimum_required(VERSION 3.23)
project(l2t2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(l2t2
        BookingSystem.cpp
        BookingSystem.h
        BookingSystemUI.cpp
        BookingSystemUI.h
        main.cpp
        TicketData.cpp
        TicketData.h)
