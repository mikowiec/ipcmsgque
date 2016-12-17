cmake_minimum_required(VERSION 3.4)
project(IpcMsgQue)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

# find_package(Boost COMPONENTS)

set(SRC_LIST src/ServerApp.cpp src/ClientApp.cpp)
include_directories(src)

add_executable(${PROJECT_NAME} ${SRC_LIST})
# target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
