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

message( "Application Platform: ${CALC_PLATFORM}" )


#----------------------------------------#
#-          Find Dependencies           -#
#----------------------------------------#
if( ${CALC_PLATFORM} STREQUAL "desktop" )

    #  Desktop apps will need allegro
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(ALLEGRO5 REQUIRED allegro)

    #  Desktop apps will need a flag to tell them to use allegro rather than any other option
    add_compile_definitions( CALC_PLATFORM=2 )

else()

    add_compile_definitions( CALC_PLATFORM=1 )
endif()

#--------------------------------#
#-      Setup Filesystem        -#
#--------------------------------#

include_directories( cpp/include )

#--------------------------------#
#-       Build Application      -#
#--------------------------------#
add_executable( terminus-calculator
    cpp/include/tmns/app/calc/core/ConfigParser.hpp
    cpp/include/tmns/app/calc/core/Options.hpp
    cpp/include/tmns/app/calc/core/Session.hpp
    cpp/include/tmns/app/calc/log/HandlerBase.hpp
    cpp/include/tmns/app/calc/log/HandlerConsole.hpp
    cpp/include/tmns/app/calc/log/HandlerFile.hpp
    cpp/include/tmns/app/calc/log/Level.hpp
    cpp/include/tmns/app/calc/log/Logger.hpp
    cpp/include/tmns/app/calc/utils/StringUtilities.hpp
    cpp/src/main.cpp
    cpp/src/core/ConfigParser.cpp
    cpp/src/core/Options.cpp
    cpp/src/core/Session.cpp
    cpp/src/log/HandlerConsole.cpp
    cpp/src/log/Level.cpp
    cpp/src/log/Logger.cpp
    cpp/src/utils/StringUtilities.cpp
)




