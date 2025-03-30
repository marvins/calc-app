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

if( ${RENDER_DRIVER} STREQUAL "raylib" )
    set( EXTRA_SOURCES ${CMAKE_SOURCE_DIR}/cpp/include/terminus/driver/DriverRaylib.hpp
                       ${CMAKE_SOURCE_DIR}/cpp/include/terminus/driver/Raylib_Utilities.hpp
                       ${CMAKE_SOURCE_DIR}/cpp/src/driver/DriverRaylib.cpp
                       ${CMAKE_SOURCE_DIR}/cpp/src/driver/Raylib_Utilities.cpp )
endif()

#  Until I learn how to make shared or static libraries with the RPI Pico, 
#  I need to re-add the source files
set( PROJECT_SOURCES
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/calc/apps/App_Factory.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/calc/apps/calculator/App_Calculator.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/calc/apps/editor/App_Editor.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/calc/apps/settings/App_Settings.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/calc/pages/Config_Menu.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/calc/pages/FooterWidget.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/calc/pages/HeaderWidget.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/calc/pages/Main_Menu.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/calc/pages/Main_Window.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/calc/pages/Splash.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/core/ConfigParser.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/core/Options.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/core/StringUtilities.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/driver/DriverBase.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/gui/I_Main_Window.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/gui/I_Renderable.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/gui/app/App_Base.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/gui/core/Application.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/gui/core/Exit_Code.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/gui/core/Resource_Manager.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/gui/core/Session.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/gui/event/EventType.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/gui/layout/LayoutBase.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/gui/layout/LayoutHorizontal.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/gui/layout/LayoutPrimitives.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/gui/layout/LayoutStack.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/gui/layout/LayoutVertical.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/gui/layout/WidgetLayoutItem.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/gui/widget/Label.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/gui/widget/WidgetBase.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/gui/widget/WidgetLayout.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/image.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/image/Frame.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/image/Frame_View.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/image/Pixels.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/image/Primitives.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/log.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/log/HandlerBase.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/log/HandlerConsole.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/log/HandlerFile.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/log/Level.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/log/Logger.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/math/Enums.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/math/Fundamental_Types.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/math/Point.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/math/Point_Utilities.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/math/Rectangle.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/math/Size.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/math/Vector.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/math/VectorN.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/math/Vector_Base.hpp
    ${CMAKE_SOURCE_DIR}/cpp/include/terminus/version.hpp
    ${CMAKE_SOURCE_DIR}/cpp/src/calc/apps/App_Factory.cpp
    ${CMAKE_SOURCE_DIR}/cpp/src/calc/apps/calculator/App_Calculator.cpp
    ${CMAKE_SOURCE_DIR}/cpp/src/calc/apps/editor/App_Editor.cpp
    ${CMAKE_SOURCE_DIR}/cpp/src/calc/apps/settings/App_Settings.cpp
    ${CMAKE_SOURCE_DIR}/cpp/src/calc/pages/Config_Menu.cpp
    ${CMAKE_SOURCE_DIR}/cpp/src/calc/pages/FooterWidget.cpp
    ${CMAKE_SOURCE_DIR}/cpp/src/calc/pages/HeaderWidget.cpp
    ${CMAKE_SOURCE_DIR}/cpp/src/calc/pages/Main_Menu.cpp
    ${CMAKE_SOURCE_DIR}/cpp/src/calc/pages/Main_Window.cpp
    ${CMAKE_SOURCE_DIR}/cpp/src/calc/pages/Splash.cpp
    ${CMAKE_SOURCE_DIR}/cpp/src/core/ConfigParser.cpp
    ${CMAKE_SOURCE_DIR}/cpp/src/core/Options.cpp
    ${CMAKE_SOURCE_DIR}/cpp/src/core/StringUtilities.cpp
    ${CMAKE_SOURCE_DIR}/cpp/src/gui/app/App_Base.cpp
    ${CMAKE_SOURCE_DIR}/cpp/src/gui/core/Application.cpp
    ${CMAKE_SOURCE_DIR}/cpp/src/gui/core/Resource_Manager.cpp
    ${CMAKE_SOURCE_DIR}/cpp/src/gui/core/Session.cpp
    ${CMAKE_SOURCE_DIR}/cpp/src/gui/event/EventType.cpp
    ${CMAKE_SOURCE_DIR}/cpp/src/gui/layout/LayoutBase.cpp
    ${CMAKE_SOURCE_DIR}/cpp/src/gui/layout/LayoutHorizontal.cpp
    ${CMAKE_SOURCE_DIR}/cpp/src/gui/layout/LayoutPrimitives.cpp
    ${CMAKE_SOURCE_DIR}/cpp/src/gui/layout/LayoutStack.cpp
    ${CMAKE_SOURCE_DIR}/cpp/src/gui/layout/LayoutVertical.cpp
    ${CMAKE_SOURCE_DIR}/cpp/src/gui/widget/Label.cpp
    ${CMAKE_SOURCE_DIR}/cpp/src/gui/widget/WidgetBase.cpp
    ${CMAKE_SOURCE_DIR}/cpp/src/gui/widget/WidgetLayout.cpp
    ${CMAKE_SOURCE_DIR}/cpp/src/image/Frame.cpp
    ${CMAKE_SOURCE_DIR}/cpp/src/image/Frame_View.cpp
    ${CMAKE_SOURCE_DIR}/cpp/src/image/Image.cpp
    ${CMAKE_SOURCE_DIR}/cpp/src/image/Primitives.cpp
    ${CMAKE_SOURCE_DIR}/cpp/src/log/HandlerConsole.cpp
    ${CMAKE_SOURCE_DIR}/cpp/src/log/Level.cpp
    ${CMAKE_SOURCE_DIR}/cpp/src/log/Logger.cpp
    ${EXTRA_SOURCES}
)

#  Here are the list of actual unit-tests
set( PROJECT_TESTS 
    calc/ui/TEST_LayoutBase.cpp
    calc/ui/TEST_LayoutHorizontal.cpp
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
    ${EXTRA_LIBS}
)
