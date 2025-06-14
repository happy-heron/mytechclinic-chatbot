cmake_minimum_required(VERSION 3.31)
project(mytechclinic_chatbot)

set(CMAKE_CXX_STANDARD 20)

include_directories(
        "asio/asio/include"
        "include"
        "liboai/liboai/include"
        "json/include"
)

# For Linux https://everything.curl.dev/install/linux.html

if (APPLE)
    include_directories("/opt/homebrew/opt/curl/include")
    link_directories("/opt/homebrew/opt/curl/lib")
endif()

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(
        mytechclinic_chatbot
        src/main.cpp
        src/WebApp.cpp
        src/GPTApp.cpp
        liboai/liboai/core/authorization.cpp
        liboai/liboai/core/netimpl.cpp
        liboai/liboai/core/response.cpp
        liboai/liboai/components/audio.cpp
        liboai/liboai/components/azure.cpp
        liboai/liboai/components/chat.cpp
        liboai/liboai/components/completions.cpp
        liboai/liboai/components/edits.cpp
        liboai/liboai/components/embeddings.cpp
        liboai/liboai/components/files.cpp
        liboai/liboai/components/fine_tunes.cpp
        liboai/liboai/components/images.cpp
        liboai/liboai/components/models.cpp
        liboai/liboai/components/moderations.cpp
)
target_link_libraries(mytechclinic_chatbot curl)
