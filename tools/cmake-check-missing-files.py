#!/usr/bin/env python3
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

#  Python Standard Libraries
import argparse
import logging
from pathlib import Path

def valid_file( arg ):
    if (file := Path(arg)).is_file():
            return file
    else:
        raise FileNotFoundError(arg)


def parse_command_line():

    parser = argparse.ArgumentParser( description = 'Check a CMakeLists.txt file to make sure all CPP files are in the requisite variable.' )

    parser.add_argument( '-v', '--verbose',
                         dest = 'log_level',
                         default = logging.INFO,
                         action = 'store_const',
                         const = logging.DEBUG,
                         help = 'Use verbose logging.' )
    
    parser.add_argument( '-c','--cmake-path',
                         dest = 'cmake_path',
                         type = valid_file,
                         required = True,
                         help = 'Path to CMake file' )

    parser.add_argument( '-s', '--cmake-variable',
                         dest = 'cmake_variable',
                         required = True,
                         help = 'Variable inside CMakeLists.txt to check' )
    
    parser.add_argument( '-x', '--source-dir',
                         dest = 'source_path',
                         required = True,
                         action = 'append',
                         default = [],
                         help = 'Source folder to scan for files.' )

    # @todo:  Add patterns for searching
    
    return parser.parse_args()

def main():

    #  Parse command-line options
    
if __name__ == '__main__':
    main()
