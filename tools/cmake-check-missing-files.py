#!/usr/bin/env python3

#  Python Standard Libraries
import argparse
import logging
from pathlist import Path

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
