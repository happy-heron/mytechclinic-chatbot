cmake_minimum_required(VERSION 3.31)
project(mytechclinic_chatbot)

set(CMAKE_CXX_STANDARD 20)

if (APPLE)
    include_directories("/opt/homebrew/Cellar/asio/1.34.2/include")
endif()

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")


add_executable(
        mytechclinic_chatbot
        src/main.cpp
        src/WebApp.cpp
        src/GPTApp.cpp
)
