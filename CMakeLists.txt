cmake_minimum_required(VERSION 3.5)
project(MarketSimulationServer)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES src/main.cpp src/util/logger.cpp src/util/logger.h)

find_package(Boost 1.58 COMPONENTS program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_executable(MarketSimulationServer ${SOURCE_FILES})

target_link_libraries(MarketSimulationServer boost_system)
target_link_libraries(MarketSimulationServer boost_regex)
target_link_libraries(MarketSimulationServer pthread)
