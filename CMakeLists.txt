############################# INTELLECTUAL PROPERTY RIGHTS #############################
##                                                                                    ##
##                           Copyright (c) 2024 Terminus LLC                          ##
##                                All Rights Reserved.                                ##
##                                                                                    ##
##          Use of this source code is governed by LICENSE in the repo root.          ##
##                                                                                    ##
############################# INTELLECTUAL PROPERTY RIGHTS #############################
#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    March 21, 2025
#
#    Purpose:  Build Terminus Calculator App

#  Set CMake Version
cmake_minimum_required( VERSION 3.22 FATAL_ERROR )

#  Configure Conan Search Paths
include( "${CMAKE_BINARY_DIR}/conan_toolchain.cmake" )
set( CMAKE_FIND_PACKAGE_PREFER_CONFIG TRUE )

#  Set project info
project( ${NAME_FROM_CONANFILE}
         VERSION ${VERSION_FROM_CONANFILE}
         HOMEPAGE_URL ${URL_FROM_CONANFILE}
         DESCRIPTION ${DESCRIPTION_FROM_CONANFILE}
         LANGUAGES CXX )

#  Set C++ Folders
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#  Define C++ Level
set( CMAKE_CXX_STANDARD 23 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

#  Setup Debug Builds for Desktop
if( CMAKE_BUILD_TYPE STREQUAL "debug" OR CMAKE_BUILD_TYPE STREQUAL "Debug" )
    if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
        set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -rdynamic -ldl" )
    endif()
endif()

message( "Application Platform: ${RENDER_DRIVER}" )


#----------------------------------------#
#-          Find Dependencies           -#
#----------------------------------------#
if( ${RENDER_DRIVER} STREQUAL "allegro" )

    #  Desktop apps will need allegro
    find_package(PkgConfig REQUIRED)
    pkg_check_modules( ALLEGRO5 REQUIRED allegro-5 allegro_font-5 )

    #  Desktop apps will need a flag to tell them to use allegro rather than any other option
    add_compile_definitions( RENDER_DRIVER=2 )

    message( "ALLEGRO5_FOUND: ${ALLEGRO5_FOUND}" )
    message( "ALLEGRO5_INCLUDE_DIRS: ${ALLEGRO5_INCLUDE_DIRS}" )
    message( "ALLEGRO5_LIBRARIES: ${ALLEGRO5_LIBRARIES}" )

    include_directories( ${ALLEGRO5_INCLUDE_DIRS} )
    set( EXTRA_LIBS ${ALLEGRO5_LIBRARIES} )

    #  OpenCV
    find_package( OpenCV REQUIRED opencv_imgcodecs )
    message( "OpenCV_INCLUDE_DIRS: ${OpenCV_INCLUDE_DIRS}" )
    message( "OpenCV_LIBRARIES: ${OpenCV_LIBRARIES}" )
    set( EXTRA_LIBS ${EXTRA_LIBS} ${OpenCV_LIBRARIES} )


    set( EXTRA_SOURCES cpp/include/terminus/app/calc/drivers/DriverAllegro.hpp
                       cpp/src/drivers/DriverAllegro.cpp )
#----------------------------
#  Raylib
elseif( ${RENDER_DRIVER} STREQUAL "raylib" )

    #  Desktop apps will need a flag to tell them to use allegro rather than any other option
    add_compile_definitions( RENDER_DRIVER=3 )

    find_package( raylib REQUIRED )

    message( "raylib_FOUND: ${raylib_FOUND}" )
    message( "raylib_INCLUDE_DIRS: ${raylib_INCLUDE_DIRS}" )
    message( "raylib_LIBRARIES: ${raylib_LIBRARIES}" )

    include_directories( ${raylib_INCLUDE_DIRS} )
    set( EXTRA_LIBS ${raylib_LIBRARIES} )

    #  OpenCV
    find_package( OpenCV REQUIRED opencv_imgcodecs opencv_highgui )
    message( "OpenCV_INCLUDE_DIRS: ${OpenCV_INCLUDE_DIRS}" )
    message( "OpenCV_LIBRARIES: ${OpenCV_LIBRARIES}" )
    set( EXTRA_LIBS ${EXTRA_LIBS} ${OpenCV_LIBRARIES} )

    set( EXTRA_SOURCES cpp/include/terminus/app/calc/drivers/DriverRaylib.hpp
                       cpp/include/terminus/app/calc/drivers/Raylib_Utilities.hpp
                       cpp/src/drivers/DriverRaylib.cpp
                       cpp/src/drivers/Raylib_Utilities.cpp )

else()

    add_compile_definitions( RENDER_DRIVER=1 )
endif()

#--------------------------------#
#-      Setup Filesystem        -#
#--------------------------------#

include_directories( cpp/include )

#--------------------------------#
#-       Build Application      -#
#--------------------------------#
add_executable( terminus-calculator
    cpp/include/terminus/app/calc/core/ConfigParser.hpp
    cpp/include/terminus/app/calc/core/Options.hpp
    cpp/include/terminus/app/calc/core/Session.hpp
    cpp/include/terminus/app/calc/drivers/DriverAllegro.hpp
    cpp/include/terminus/app/calc/drivers/DriverBase.hpp
    cpp/include/terminus/app/calc/image/Frame.hpp
    cpp/include/terminus/app/calc/image/FrameView.hpp
    cpp/include/terminus/app/calc/image/Primitives.hpp
    cpp/include/terminus/app/calc/log/HandlerBase.hpp
    cpp/include/terminus/app/calc/log/HandlerConsole.hpp
    cpp/include/terminus/app/calc/log/HandlerFile.hpp
    cpp/include/terminus/app/calc/log/Level.hpp
    cpp/include/terminus/app/calc/log/Logger.hpp
    cpp/include/terminus/app/calc/pages/Splash.hpp
    cpp/include/terminus/app/calc/ui/EventType.hpp
    cpp/include/terminus/app/calc/ui/Label.hpp
    cpp/include/terminus/app/calc/ui/LayoutBase.hpp
    cpp/include/terminus/app/calc/ui/LayoutVertical.hpp
    cpp/include/terminus/app/calc/ui/WidgetBase.hpp
    cpp/include/terminus/app/calc/ui/WidgetLayoutItem.hpp
    cpp/include/terminus/app/calc/utils/StringUtilities.hpp
    cpp/include/terminus/math/Rectangle.hpp
    cpp/src/main.cpp
    cpp/src/core/ConfigParser.cpp
    cpp/src/core/Options.cpp
    cpp/src/core/Session.cpp
    cpp/src/image/Frame.cpp
    cpp/src/image/FrameView.cpp
    cpp/src/image/Primitives.cpp
    cpp/src/log/HandlerConsole.cpp
    cpp/src/log/Level.cpp
    cpp/src/log/Logger.cpp
    cpp/src/pages/Splash.cpp
    cpp/src/ui/EventType.cpp
    cpp/src/ui/Label.cpp
    cpp/src/ui/LayoutBase.cpp
    cpp/src/ui/LayoutPrimitives.cpp
    cpp/src/ui/LayoutVertical.cpp
    cpp/src/utils/StringUtilities.cpp
    ${EXTRA_SOURCES}
)

target_link_libraries( terminus-calculator 
                       ${EXTRA_LIBS} )


