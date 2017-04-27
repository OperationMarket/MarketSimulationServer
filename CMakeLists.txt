cmake_minimum_required(VERSION 3.5)
project(MarketSimulationServer)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp)

add_executable(MarketSimulationServer ${SOURCE_FILES})

target_link_libraries(MarketSimulationServer microhttpd)
