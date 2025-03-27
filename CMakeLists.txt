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
#    Purpose:  Build Terminus Geospatial Toolbox App

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

message( "VERSION: ${PROJECT_VERSION}" )
message( "VERSION MAJOR: ${PROJECT_VERSION_MAJOR}" )
message( "VERSION MINOR: ${PROJECT_VERSION_MINOR}" )
message( "VERSION PATCH: ${PROJECT_VERSION_PATCH}" )

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
#-          Update Version File         -#
#----------------------------------------#

# Get the current date
string(TIMESTAMP PROJECT_BUILD_DATE "%Y-%m-%d %H:%M:%S" )

configure_file( ${CMAKE_SOURCE_DIR}/cpp/templates/version.hpp.in
                ${CMAKE_SOURCE_DIR}/cpp/include/terminus/version.hpp )

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

    set( EXTRA_SOURCES cpp/include/terminus/drv/DriverRaylib.hpp
                       cpp/include/terminus/drv/Raylib_Utilities.hpp
                       cpp/src/drv/DriverRaylib.cpp
                       cpp/src/drv/Raylib_Utilities.cpp )

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
add_executable( ${PROJECT_NAME}
    cpp/include/terminus/log.hpp
    cpp/include/terminus/version.hpp
    cpp/include/terminus/math/Point_Utilities.hpp
    cpp/include/terminus/math/Point.hpp
    cpp/include/terminus/math/Rectangle.hpp
    cpp/include/terminus/math/Size.hpp
    cpp/include/terminus/math/Enums.hpp
    cpp/include/terminus/math/Vector.hpp
    cpp/include/terminus/math/VectorN.hpp
    cpp/include/terminus/math/Vector_Base.hpp
    cpp/include/terminus/math/Fundamental_Types.hpp
    cpp/include/terminus/log/Logger.hpp
    cpp/include/terminus/log/Level.hpp
    cpp/include/terminus/log/HandlerBase.hpp
    cpp/include/terminus/log/HandlerFile.hpp
    cpp/include/terminus/log/HandlerConsole.hpp
    cpp/include/terminus/calc/core/Options.hpp
    cpp/include/terminus/calc/core/Session.hpp
    cpp/include/terminus/calc/core/ConfigParser.hpp
    cpp/include/terminus/calc/utils/StringUtilities.hpp
    cpp/include/terminus/calc/pages/Splash.hpp
    cpp/include/terminus/calc/pages/Main_Window.hpp
    cpp/include/terminus/calc/pages/HeaderWidget.hpp
    cpp/include/terminus/calc/pages/FooterWidget.hpp
    cpp/include/terminus/calc/pages/Main_Menu.hpp
    cpp/include/terminus/calc/pages/Config_Menu.hpp
    cpp/include/terminus/calc/image/Frame.hpp
    cpp/include/terminus/calc/image/Primitives.hpp
    cpp/include/terminus/calc/image/FrameView.hpp
    cpp/include/terminus/calc/apps/coord_convert/app.hpp
    cpp/include/terminus/calc/apps/coord_convert/app.cpp
    cpp/include/terminus/gui/core/Exit_Code.hpp
    cpp/include/terminus/gui/core/I_Main_Window.hpp
    cpp/include/terminus/gui/core/Application.hpp
    cpp/include/terminus/gui/layout/LayoutBase.hpp
    cpp/include/terminus/gui/layout/LayoutHorizontal.hpp
    cpp/include/terminus/gui/layout/LayoutPrimitives.hpp
    cpp/include/terminus/gui/layout/LayoutStack.hpp
    cpp/include/terminus/gui/layout/LayoutVertical.hpp
    cpp/include/terminus/gui/layout/WidgetLayoutItem.hpp
    cpp/include/terminus/gui/widget/WidgetLayout.hpp
    cpp/include/terminus/gui/widget/WidgetBase.hpp
    cpp/include/terminus/gui/widget/Label.hpp
    cpp/include/terminus/gui/event/EventType.hpp
    cpp/include/terminus/drv/DriverAllegro.hpp
    cpp/include/terminus/drv/DriverBase.hpp
    cpp/include/terminus/drv/DriverRaylib.hpp
    cpp/include/terminus/drv/Raylib_Utilities.hpp
    cpp/src/main.cpp
    cpp/src/log/Level.cpp
    cpp/src/log/Logger.cpp
    cpp/src/log/HandlerConsole.cpp
    cpp/src/calc/core/Options.cpp
    cpp/src/calc/core/Session.cpp
    cpp/src/calc/core/ConfigParser.cpp
    cpp/src/calc/image/Frame.cpp
    cpp/src/calc/image/Primitives.cpp
    cpp/src/calc/image/FrameView.cpp
    cpp/src/calc/pages/Splash.cpp
    cpp/src/calc/pages/Main_Window.cpp
    cpp/src/calc/pages/HeaderWidget.cpp
    cpp/src/calc/pages/FooterWidget.cpp
    cpp/src/calc/pages/Main_Menu.cpp
    cpp/src/calc/pages/Config_Menu.cpp
    cpp/src/calc/utils/StringUtilities.cpp
    cpp/src/gui/widgets/Label.cpp
    cpp/src/gui/widgets/WidgetLayout.cpp
    cpp/src/gui/layouts/LayoutBase.cpp
    cpp/src/gui/layouts/LayoutHorizontal.cpp
    cpp/src/gui/layouts/LayoutPrimitives.cpp
    cpp/src/gui/layouts/LayoutStack.cpp
    cpp/src/gui/layouts/LayoutVertical.cpp
    cpp/src/gui/event/EventType.cpp
    cpp/src/img/Image.cpp
    ${EXTRA_SOURCES}
)

target_link_libraries( ${PROJECT_NAME}
                       ${EXTRA_LIBS} )

if( TERMINUS_CALC_ENABLE_TESTS )
    add_subdirectory( test/unit )
endif()
