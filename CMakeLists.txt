CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

set (PROJECT_NAME draw_collisions)

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME}
${CMAKE_SOURCE_DIR}/source/main.cpp
)


target_compile_features(${PROECT_NAME} PUBLIC cxx_std_20)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)


add_subdirectory(external/glfw)
target_link_libraries(${PROJECT_NAME} glfw)

add_subdirectory(external/math_cpp)
target_link_libraries(${PROJECT_NAME} math_cpp)

option( draw_collisions-USE-GLFW-GLAD "Use GLAD from GLFW" OFF )

if( draw_collisions-USE-GLFW-GLAD )
    include_directories("${GLFW_SOURCE_DIR}/deps")
    set( GLAD_GL "${GLFW_SOURCE_DIR}/deps/glad/gl.h" )
endif()

if( MSVC )
    SET( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup" )
endif()

add_subdirectory(counter)
add_subdirectory(math_cpp)
include_directories(${CMAKE_SOURCE_DIR}/counter)
include_directories(${CMAKE_SOURCE_DIR}/math_cpp)


add_executable( draw_collisions ./source/main.cpp)
#${CMAKE_SOURCE_DIR}/glew/lib/Release/x64/glew32s.lib
target_link_libraries( draw_collisions ${OPENGL_LIBRARIES} glfw  _counter math_lib )

if( MSVC )
    if(${CMAKE_VERSION} VERSION_LESS "3.6.0")
        message( "\n\t[ WARNING ]\n\n\tCMake version lower than 3.6.\n\n\t - Please update CMake and rerun; OR\n\t - Manually set 'GLFW-CMake-starter' as StartUp Project in Visual Studio.\n" )
    else()
        set_property( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT GLFW-CMake-starter )
    endif()
endif()

