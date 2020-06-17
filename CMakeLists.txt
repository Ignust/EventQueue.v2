cmake_minimum_required(VERSION 3.5.1)

#project(EventQueue.v2 LANGUAGES CXX )
project(EventQueue.v2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -pthread")

include_directories(PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/headers/
)

set(SOURCES
    main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/EventHandler.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/EventManager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/IEventHandler.cpp
)

add_executable(EventQueue.v2 ${SOURCES})
