

cmake_minimum_required( 3.22 REQUIRED )

#  Configure Conan Search Paths
include( "${CMAKE_BINARY_DIR}/conan_toolchain.cmake" )
set( CMAKE_FIND_PACKAGE_PREFER_CONFIG TRUE )

#  Set project info
project( ${NAME_FROM_CONANFILE}
         VERSION ${VERSION_FROM_CONANFILE}
         HOMEPAGE_URL ${URL_FROM_CONANFILE}
         DESCRIPTION ${DESCRIPTION_FROM_CONANFILE}
         LANGUAGES CXX )


#  Define C++ Level
set( CMAKE_CXX_STANDARD 23 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

#  Setup Debug Builds for Desktop
if( CMAKE_BUILD_TYPE STREQUAL "debug" OR CMAKE_BUILD_TYPE STREQUAL "Debug" )
    if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
        set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -rdynamic -ldl" )
    endif()
endif()

#----------------------------------------#
#-          Find Dependencies           -#
#----------------------------------------#


