cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

set (PROJECT_NAME draw_collisions)

project(${PROJECT_NAME})


add_executable(${PROJECT_NAME} 
${CMAKE_SOURCE_DIR}/source/main.cpp 
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)


set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
add_subdirectory(external/glfw)
target_link_libraries(${PROJECT_NAME} glfw)


add_subdirectory(external/math_cpp)
target_link_libraries(${PROJECT_NAME} math_cpp)


add_subdirectory(source/counter)
target_link_libraries(${PROJECT_NAME} _counter)



