
#  Python Standard Libraries
import argparse
import configparser
import logging
import os
import sys

def parse_command_line():
    '''
    Parse Command-Line Options
    '''
    parser = argparse.ArgumentParser( description = 'Terminus Converter Application' )
    
    #  Provide configuration-file for parsing
    parser.add_argument( '-c','--config-path',
                         default='./data/options.cfg',
                         required=False,
                         help = 'Path to system default options' )
    #  Set verbose logging
    parser.add_argument( '-v','--verbose',
                         dest='log_level',
                         default = logging.INFO,
                         action = 'store_const',
                         const = logging.DEBUG,
                         help = 'Set debug logging.' )
    
    #  Use log file
    parser.add_argument( '-l','--log-path',
                         dest = 'log_path',
                         default = None,
                         required = False,
                         help = 'Write to log file.' )
    
    #  Generate config file
    parser.add_argument( '-g','--gen-config',
                         dest = 'gen_config',
                         default = False,
                         required = False,
                         action = 'store_true',
                         help = 'Create new config-file and exit.' )
    
    return parser.parse_args()

def parse_config_file( config_path ):
    '''
    Parse the configuration file
    '''
    parser = configparser.ConfigParser()

    parser.read( config_path )

    return parser

def generate_config( config_path ):

    with open( config_path, 'w' ) as fout:

        fout.write( '#  Override Default Display Settings\n' )
        fout.write( '[display]\n' )
        fout.write( '\n' )
        fout.write( '#  Display Driver\n')
        fout.write( '#  - pygame:  Used for non-embedded apps\n')
        fout.write( '#  - micropython:  Used for RPI Pico or other embedded apps\n')
        fout.write( 'driver=pygame\n')
        fout.write( '\n' )
        fout.write( '#  Screen size\n' )
        fout.write( '#screen_size = 320 320)\n' )
        fout.write( '\n' )
        fout.write( '#  Application Configuration\n' )
        fout.write( '[apps]\n')


class Options:

    def __init__(self, cmd_args, cfg_args):
        self.cmd_args = cmd_args
        self.cfg_args = cfg_args

    def get( self, section, key ):
        return self.cfg_args.get(section,key)
    

    def get_screen_size(self):
        return [ self.cfg_args.getint('display','screen_width'),
                 self.cfg_args.getint('display','screen_height') ]

    def initialize_logger(self):

        LOG_FORMAT = '%(asctime)s - %(levelname)8s - [%(filename)s] : %(message)s'

        if self.cmd_args.log_path != None:
            logging.basicConfig( level   = self.cmd_args.log_level,
                                 filemode = 'w',
                                 filename = self.cmd_args.log_path,
                                 format = LOG_FORMAT )
        else:
            logging.basicConfig( level  = self.cmd_args.log_level,
                                 format = LOG_FORMAT )

        self.logger = logging.getLogger('main')
        self.logger.debug( 'Logger initialized' )

    def get_apps(self):

        apps = {}

        base_dir = os.path.realpath(os.path.dirname(sys.argv[0]) + '/../../')

        #  Parse the app-list entry to get names
        app_tags = self.cfg_args.get('apps','list').split(' \n')

        for tag in app_tags:

            disp_name = self.cfg_args.get( tag, 'display_name' )
            main_path = self.cfg_args.get( tag, 'main_path' )
            icon_path = str(self.cfg_args.get( tag, 'icon_path' )).replace('__BASE__',base_dir)

            apps[tag] = { 'name':      disp_name,
                          'main_path': main_path,
                          'icon_path': icon_path }

        return apps

    @staticmethod
    def parse():

        #  First, parse the command-line
        cmd_args = parse_command_line()

        #  Do we want to generate a config?
        if cmd_args.gen_config:
            if cmd_args.config_path != None:
                raise RuntimeError('When generating config, config-path must be provided.')
            else:
                generate_config( cmd_args.config_path )
                sys.exit(0)

        #  Next, parse our config file
        cfg_args = parse_config_file( config_path=cmd_args.config_path )

        return Options( cmd_args, cfg_args )