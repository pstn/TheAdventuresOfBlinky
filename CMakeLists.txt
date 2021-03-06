cmake_minimum_required(VERSION 3.5)

if (NOT_CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

project(TheAdventuresOfBlinky)

set(dot_VERSION_MAJOR 0)
set(dot_VERSION_MINOR 1)
configure_file(
	"${PROJECT_SOURCE_DIR}/config.h.in"
	"${PROJECT_SOURCE_DIR}/config.h"
	)
include_directories("${PROJECT_BINARY_DIR}")

set(EXECUTABLE_NAME "TheAdventuresOfBlinky")
add_executable(${EXECUTABLE_NAME} Source/Main.cpp Source/Game.cpp Source/World.cpp Source/Utilities.cpp
 Source/Command_Empty.cpp Source/Command_Move.cpp Source/Command_Reset.cpp
 Source/Entity_Character.cpp Source/Entity_Background.cpp Source/Entity_Object.cpp Source/Entity_Maze_Tile.cpp Source/Entity_TitleScreen.cpp Source/Entity_EndGame.cpp
 Source/InputHandler.cpp Source/Maze.cpp)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++")

add_custom_command(TARGET ${EXECUTABLE_NAME} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
		${CMAKE_SOURCE_DIR}/Media Media)

find_package(SFML 2 REQUIRED system window graphics network audio)
if (SFML_FOUND)
	include_directories(${SFML_INCLUDE_DIR})
	target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()