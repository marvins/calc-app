#!/usr/bin/env python3
############################# INTELLECTUAL PROPERTY RIGHTS #############################
##                                                                                    ##
##                           Copyright (c) 2024 Terminus LLC                          ##
##                                All Rights Reserved.                                ##
##                                                                                    ##
##          Use of this source code is governed by LICENSE in the repo root.          ##
##                                                                                    ##
############################# INTELLECTUAL PROPERTY RIGHTS #############################
#    File:    cmake-build-file-list.py
#    Author:  Marvin Smith
#    Date:    March 27, 2025
#
#    Purpose:  Scan a folder for all C++ source files and print a copy/pastable string for CMake.

#  Python Standard Libraries
import argparse
import logging
import os
import typing
from pathlib import Path


def valid_file( arg ):
    '''
    Simple script for verifying this is a valid path.
    '''
    if (file := Path(arg)).is_file():
        return file
    else:
        raise FileNotFoundError(arg)

EXTENSIONS = ['.cpp','.hpp']

def parse_command_line():
    '''
    Parse Command-Line arguments
    '''

    parser = argparse.ArgumentParser( description='Scan folder for all C++ files and generate CMake file list variable' )

    parser.add_argument( '-v','--verbose',
                         dest = 'log_level',
                         action = 'store_const',
                         const = logging.DEBUG,
                         default = logging.INFO,
                         help = 'Use verbose logging.' )

    parser.add_argument( '-d','--source-directory',
                         dest = 'source_directories',
                         default = [],
                         required = True,
                         action = 'append',
                         help = 'List of source folder to scan' )
    
    parser.add_argument( '--is-test',
                         dest = 'is_test',
                         default = False,
                         action = 'store_true',
                         help = 'Print files with ${CMAKE_SOURCE_DIR} prepended for unit-tests.' )

    # @todo:  Add patterns to scan for

    return parser.parse_args()

def remove_root( base_dir: str, filepath: str, is_test: bool ):
    if not base_dir in filepath:
        raise Exception( f'For some reason {base_dir} not the root of {filepath}' )
    
    corrected = filepath.replace( os.path.dirname( base_dir ), '' )

    #  Remove leading slashes if present
    if corrected[0] == '/':
        corrected = corrected[1:]

    #  If this is a test, prepend cmake variable
    if is_test:
        corrected = '${CMAKE_SOURCE_DIR}/' + corrected
    
    return corrected

def main():
     
    cmd_args = parse_command_line()

    logging.basicConfig( level = cmd_args.log_level )
    logger = logging.getLogger( 'cmake-build-file-list' )

    #  Print warning message
    logger.warning( 'Please run from the base of the toolbox repository. Otherwise all paths will have the wrong starting point.' )

    #  List of files to add
    main_list = []

    #  Iterate over each folder to process
    for sdir in cmd_args.source_directories:

        full_dir = os.path.realpath(sdir)
        logger.debug( f'Scanning: {full_dir} directory' )

        for root_dir, d, file_list in os.walk( full_dir, topdown = True ):

            logging.debug( f'Root: {root_dir}, Dir: {d}, File: {file_list}' )

            #  Check each file
            for filepath in file_list:

                #  Check patterns
                ext = os.path.splitext( filepath )[-1]
                if ext in EXTENSIONS:

                    #  Generate full path
                    fpath = os.path.join( root_dir, filepath )
                    logging.debug( f'Found: {fpath}' )

                    #  Remove the root, as we previously made sure it was root relative
                    fpath_rel = remove_root( full_dir, fpath, cmd_args.is_test )
                    logging.debug( f'Adjusted to: {fpath_rel}' )
                    main_list.append( fpath_rel )

    #  Sort paths
    main_list.sort()
    
    #  Construct final variable
    varname = 'set( SET_NAME_HERE\n' 
    for entry in main_list:
        varname += f'        {entry}\n'
    varname += ')'

    logging.info( f'Final Result:\n{varname}' )

if __name__ == '__main__':
    main()
    