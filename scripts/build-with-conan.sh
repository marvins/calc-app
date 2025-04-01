#!/usr/bin/env bash
############################# INTELLECTUAL PROPERTY RIGHTS #############################
##                                                                                    ##
##                           Copyright (c) 2025 Terminus LLC                          ##
##                                All Rights Reserved.                                ##
##                                                                                    ##
##          Use of this source code is governed by LICENSE in the repo root.          ##
##                                                                                    ##
############################# INTELLECTUAL PROPERTY RIGHTS #############################
#
#   File:    build-with-conan.sh
#   Author:  Marvin Smith
#   Date:    3/30/2025
#
#   Purpose:  Build repo with standard conan commands
#

set -e 

BUILD_TYPE='Release'
#BUILD_MISSING='--build=missing'

#  Run conan-install
conan install conanfile.py ${BUILD_MISSING} --output-folder build -s build_type=${BUILD_TYPE}

#  Kick off generate
conan build --output-folder build -s build_type=${BUILD_TYPE} conanfile.py

#  Navigate into build folder
pushd build

make -j4

popd