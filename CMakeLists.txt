cmake_minimum_required(VERSION 3.24)

project(Pokemon VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC_PATH_PREFIXES ${CMAKE_CURRENT_SOURCE_DIR}/PokemonV2Code/Headers/UI)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui)


set(SOURCES
 "PokemonV2Code/main.cpp"
 "PokemonV2Code/Sources/UI/Scene/sceneBase.cpp"
 "PokemonV2Code/Sources/UI/Scene/sceneMenu.cpp"
 "PokemonV2Code/Sources/Resource/picture.cpp" 
 "PokemonV2Code/Sources/Resource/resourceStringName.cpp" 
 "PokemonV2Code/Sources/UI/Button/buttonBase.cpp" 
 "PokemonV2Code/Sources/UI/Button/clickButton.cpp" 
 "PokemonV2Code/Sources/Core/SceneManager/sceneManager.cpp" 
 "PokemonV2Code/Sources/UI/Scene/sceneSelector.cpp")
set(HEADERS
 "PokemonV2Code/Headers/UI/Scene/sceneBase.h"
 "PokemonV2Code/Headers/UI/Scene/sceneMenu.h" 
 "PokemonV2Code/Headers/Resource/picture.h" 
 "PokemonV2Code/Headers/Resource/resourceStringName.h" 
 "PokemonV2Code/Headers/UI/Button/buttonBase.h" 
 "PokemonV2Code/Headers/UI/Button/clickButton.h" 
 "PokemonV2Code/Headers/Core/SceneManager/sceneRegistry.h" 
 "PokemonV2Code/Headers/Core/SceneManager/sceneManager.h" 
 "PokemonV2Code/Headers/UI/Scene/sceneSelector.h")
set(UIS
)
set(RESOURCES
    "Resources/resources.qrc"
)

add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
    ${UIS}
    ${RESOURCES}
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/PokemonV2Code/Headers
)

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE "/utf-8")
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Gui
)
