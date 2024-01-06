cmake_minimum_required(VERSION 3.5)

project(kuy)

set(SOURCES
    src/main.cpp
    src/Vec2.cpp
    src/Vec2.h
    src/Components.h
    src/EntityManager.h
    src/EntityManager.cpp
    src/Entity.h
    src/Entity.cpp
    src/Animation.cpp
    src/Animation.h
    src/Scene.h
    src/Scene.cpp
    src/Kuy.h
    src/Kuy.cpp
    src/Plugin.h
    src/Plugin.cpp
    src/Assets.h
    src/Assets.cpp
    src/Action.h
)

set(SFML_PATH /opt/homebrew/Cellar/sfml/2.6.1)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS  "-L${SFML_PATH}/lib -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -framework OpenGL")

add_executable(game ${SOURCES})

target_include_directories(game
    PRIVATE
    ${SFML_PATH}/include
)