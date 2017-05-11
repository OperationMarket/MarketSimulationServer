cmake_minimum_required(VERSION 3.5)
project(MarketSimulationServer)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES src/main.cpp src/util/logger.cpp src/util/logger.h)

link_directories(/usr/lib/python3.5/site-packages/boost)

add_executable(MarketSimulationServer ${SOURCE_FILES})

target_link_libraries(MarketSimulationServer boost_system)
target_link_libraries(MarketSimulationServer boost_regex)
