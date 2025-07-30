cmake_minimum_required(VERSION 3.11)

project(rps)

add_executable(${PROJECT_NAME} scripts/main.cpp 
     scripts/window.cpp
     scripts/menu.cpp
     scripts/button.cpp
)

include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)


target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_INCLUDE_DIRS})

target_include_directories(
	${PROJECT_NAME} PRIVATE 

	${SDL2_INCLUDE_DIRS}
	${SDL2_MIXER_INCLUDE_DIRS}
    ${SDL2_TTF_INCLUDE_DIRS}
    ./scripts/
    ./headers/
	)

target_link_libraries(${PROJECT_NAME} PRIVATE
    ${SDL2_LIBRARIES}
    ${SDL2_MIXER_LIBRARIES}
    ${SDL2_TTF_LIBRARIES}
)

if(PSP)
    create_pbp_file(
        TARGET ${PROJECT_NAME}
        ICON_PATH NULL
        BACKGROUND_PATH NULL
        PREVIEW_PATH NULL
        TITLE ${PROJECT_NAME}
        VERSION 01.00
    )
endif()
