cmake_minimum_required(VERSION 3.29)
project(MineSweeperTest)

set(CMAKE_CXX_STANDARD 20)

# Define your source files
set(SOURCE_FILES main.cpp
        SpriteSheetCutter.cpp
        SpriteSheetCutter.h
        Model.cpp
        Model.h
        View.cpp
        View.h
        Controller.cpp
        Controller.h
        Minesweeper.cpp
        Minesweeper.h)
add_executable(MineSweeperTest ${SOURCE_FILES})

# Define SFML paths
set(SFML_INCLUDE_DIR "C:/Programming/CLion + SFML/SFML/include")
set(SFML_LIBRARY_DIR "C:/Programming/CLion + SFML/SFML/lib")

# Include directories
include_directories(${SFML_INCLUDE_DIR})

# Find SFML libraries
find_library(SFML_SYSTEM_LIBRARY sfml-system PATHS ${SFML_LIBRARY_DIR})
find_library(SFML_WINDOW_LIBRARY sfml-window PATHS ${SFML_LIBRARY_DIR})
find_library(SFML_GRAPHICS_LIBRARY sfml-graphics PATHS ${SFML_LIBRARY_DIR})
find_library(SFML_AUDIO_LIBRARY sfml-audio PATHS ${SFML_LIBRARY_DIR})
find_library(SFML_NETWORK_LIBRARY sfml-network PATHS ${SFML_LIBRARY_DIR})

# List of SFML libraries
set(SFML_LIBRARIES
        ${SFML_SYSTEM_LIBRARY}
        ${SFML_WINDOW_LIBRARY}
        ${SFML_GRAPHICS_LIBRARY}
        ${SFML_AUDIO_LIBRARY}
        ${SFML_NETWORK_LIBRARY}
)

# Link SFML libraries to the target
target_link_libraries(MineSweeperTest ${SFML_LIBRARIES})

# Optionally, add definitions or configurations based on SFML requirements
if(SFML_STATIC_LIBRARIES)
    add_definitions(-DSFML_STATIC)
endif()
