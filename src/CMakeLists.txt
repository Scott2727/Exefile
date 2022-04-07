cmake_minimum_required(VERSION 3.22)

set(DEBUG 1)

configure_file(config.h.in config.h)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

project(Exefile)

find_package(Vulkan REQUIRED)
link_libraries(Vulkan::Vulkan)
link_libraries(Vulkan::Headers)

add_subdirectory(../lib/glfw ../bin/lib)

include_directories(../lib/glfw)
include_directories(../lib/glfw/include)
include_directories(../lib/glfw/src)

link_libraries(glfw)

include_directories(video)

set(
    VIDEO_SRC 
    video/WindowManager.cpp
    video/VulkanManager.cpp
)

set(FILES ${VIDEO_SRC})

add_executable(${PROJECT_NAME} main.cpp ${FILES})
