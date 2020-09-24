cmake_minimum_required(VERSION 3.0)

project(CmakeProjectTemplate)

include_directories(${PROJECT_SOURCE_DIR})
add_executable(clock main.cpp clock.cpp)            

install(TARGETS clock RUNTIME DESTINATION bin)
