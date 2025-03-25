############################# INTELLECTUAL PROPERTY RIGHTS #############################
##                                                                                    ##
##                           Copyright (c) 2025 Terminus LLC                          ##
##                                All Rights Reserved.                                ##
##                                                                                    ##
##          Use of this source code is governed by LICENSE in the repo root.          ##
##                                                                                    ##
############################# INTELLECTUAL PROPERTY RIGHTS #############################
#
#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    3/25/2025
#

#  Find GoogleTest
find_package( GTest CONFIG REQUIRED )

#  Include GoogleTest Source
include( GoogleTest )

#  Add Project Directories
include_directories( ${CMAKE_SOURCE_DIR}/cpp/include )

#  Setup Executable
set( TEST ${PROJECT_NAME}_test )

#  Until I learn how to make shared or static libraries with the RPI Pico, 
#  I need to re-add the source files
set( PROJECT_SOURCES
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/log/HandlerBase.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/log/HandlerConsole.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/log/HandlerFile.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/log/Level.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/log/Logger.hpp
    ${CMAKE_SOURCE_DIR}/cpp/src/log/HandlerConsole.cpp
    ${CMAKE_SOURCE_DIR}/cpp/src/log/Level.cpp
    ${CMAKE_SOURCE_DIR}/cpp/src/log/Logger.cpp
)

#  Here are the list of actual unit-tests
set( PROJECT_TESTS 
    calc/ui/TEST_LayoutVertical.cpp 
)

#  Compile the Executable
add_executable( ${TEST}
    main.cpp
    ${PROJECT_SOURCES}
    ${PROJECT_TESTS}
)

#  Link in googletest
target_link_libraries( ${TEST} PRIVATE
    GTest::gtest
)
