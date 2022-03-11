cmake_minimum_required(VERSION 2.6)



project(final)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11"m)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

#target_link_libraries(${PROJECT_NAME} PRIVATE pthread)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

file(GLOB
          CPPS "*.cpp"
          CS    "*.c")

add_executable(${PROJECT_NAME} ${CPPS})