cmake_minimum_required(VERSION 3.14)

project(sea5kg-bubble-shooter)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

add_definitions(-DWSJCPP_APP_VERSION="v0.0.1")
add_definitions(-DWSJCPP_APP_NAME="sea5kg-bubble-shooter")

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(MACOSX TRUE)
endif()

set(CMAKE_CXX_STANDARD 17)

set (WSJCPP_LIBRARIES "")
set (WSJCPP_INCLUDE_DIRS "")
set (WSJCPP_SOURCES "")

set(EXECUTABLE_OUTPUT_PATH ${sea5kg-bubble-shooter_SOURCE_DIR})


# include header dirs
list (APPEND WSJCPP_INCLUDE_DIRS "src")
list (APPEND WSJCPP_INCLUDE_DIRS "src/render")
list (APPEND WSJCPP_INCLUDE_DIRS "src/states")
list (APPEND WSJCPP_INCLUDE_DIRS "src/base")
list (APPEND WSJCPP_INCLUDE_DIRS "src/game")

# Source
# list (APPEND WSJCPP_SOURCES "SDLMain.m")

# render
list (APPEND WSJCPP_SOURCES "src/render/render_ball.cpp")
list (APPEND WSJCPP_SOURCES "src/render/render_object.cpp")
list (APPEND WSJCPP_SOURCES "src/render/render_window.cpp")

# states
list (APPEND WSJCPP_SOURCES "src/states/state_ball.cpp")
list (APPEND WSJCPP_SOURCES "src/states/state_game.cpp")

# base
list (APPEND WSJCPP_SOURCES "src/base/coordxy.cpp")

# main
list (APPEND WSJCPP_SOURCES "src/main.cpp")
list (APPEND WSJCPP_SOURCES "src/game.cpp")

if(NOT APPLE)
  find_package(Threads)
endif()

list (APPEND WSJCPP_LIBRARIES ${CMAKE_THREAD_LIBS_INIT})

############################
# SDL2
find_package(SDL2 REQUIRED)
if ( SDL2_FOUND )
    list (APPEND WSJCPP_INCLUDE_DIRS ${SDL2_INCLUDE_DIR})
    list (APPEND WSJCPP_LIBRARIES ${SDL2_LIBRARY})
endif( SDL2_FOUND )
############################

############################
# SDL2_image
find_package(SDL2_image REQUIRED)
if ( SDL2_image_FOUND )
    list (APPEND WSJCPP_INCLUDE_DIRS ${SDL2_IMAGE_INCLUDE_DIRS})
    list (APPEND WSJCPP_LIBRARIES ${SDL2_IMAGE_LIBRARIES})
    
endif( SDL2_image_FOUND )
############################

############################
# SDL2_ttf
find_package(SDL2TTF REQUIRED)
if ( SDL2_TTF_FOUND )
    list (APPEND WSJCPP_INCLUDE_DIRS ${SDL2_TTF_INCLUDE_DIRS})
    list (APPEND WSJCPP_LIBRARIES ${SDL2_TTF_LIBRARIES})
endif( SDL2_TTF_FOUND )
############################

############################
# SDL2_mixer
find_package(SDL2_mixer REQUIRED)
if ( SDL2_MIXER_FOUND )
    list (APPEND WSJCPP_INCLUDE_DIRS ${SDL2_MIXER_INCLUDE_DIRS})
    list (APPEND WSJCPP_LIBRARIES ${SDL2_MIXER_LIBRARY})
endif( SDL2_MIXER_FOUND )
############################

############################
# SDL2_gfx
find_package(SDL2_gfx REQUIRED)
if ( SDL2_GFX_FOUND )
    list (APPEND WSJCPP_INCLUDE_DIRS ${SDL2_GFX_INCLUDE_DIRS})
    list (APPEND WSJCPP_LIBRARIES ${SDL2_GFX_LIBRARIES})
endif( SDL2_GFX_FOUND )
############################

# include(FindPkgConfig)
# pkg_check_modules(SDL2_Mixer REQUIRED IMPORTED_TARGET SDL2_mixer)
# list (APPEND WSJCPP_LIBRARIES PkgConfig::SDL2_Mixer)

include_directories(${WSJCPP_INCLUDE_DIRS})

add_executable (sea5kg-bubble-shooter ${WSJCPP_SOURCES})

target_link_libraries(sea5kg-bubble-shooter ${WSJCPP_LIBRARIES} )