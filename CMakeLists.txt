CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

project(draw_collisions)

find_package( OpenGL REQUIRED )

include_directories( ${OPENGL_INCLUDE_DIRS} )

set( GLFW_BUILD_DOCS OFF CACHE BOOL  "GLFW lib only" )
set( GLFW_INSTALL OFF CACHE BOOL  "GLFW lib only" )
set( GLAD_GL "" )

add_subdirectory( glfw )

option( draw_collisions-USE-GLFW-GLAD "Use GLAD from GLFW" ON )

if( draw_collisions-USE-GLFW-GLAD )
    include_directories("${GLFW_SOURCE_DIR}/deps")
    set( GLAD_GL "${GLFW_SOURCE_DIR}/deps/glad/gl.h" )
endif()

add_subdirectory(counter)
include_directories(counter)

add_executable( draw_collisions ./source/main.cpp )
target_link_libraries( draw_collisions ${OPENGL_LIBRARIES} glfw _counter)

