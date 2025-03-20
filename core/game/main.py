#**************************** INTELLECTUAL PROPERTY RIGHTS ****************************#
#*                                                                                    *#
#*                           Copyright (c) 2025 Terminus LLC                          *#
#*                                                                                    *#
#*                                All Rights Reserved.                                *#
#*                                                                                    *#
#*          Use of this source code is governed by LICENSE in the repo root.          *#
#*                                                                                    *#
#**************************** INTELLECTUAL PROPERTY RIGHTS ****************************#
#

#  Python Standard Libraries
import sys
import time

#  Pygame Engine
import pygame

#  App Utilities
from app_manager import App_Manager
from config import Options
from core import Action
from pages.menu import main_menu
from session import Session
from splash import display_splash

def main():
    
    #  Parse command-line and config-file options
    options = Options.parse()
    options.initialize_logger()

    #  Build Session
    session = Session.create( options )
    display_splash( session )

    #  Create application manager
    app_mgr = App_Manager( options.get_apps() )

    while True:

        action = main_menu( options, session, app_mgr )

        if action['code'] == Action.QUIT:
            break
    
    return session.quit()

if __name__ == '__main__':
    main()

