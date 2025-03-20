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

# Python Standard Libraries
from pathlib import Path

#  Pygame Libraries
import pygame

class App_Manager:

    def __init__( self, app_list: list, icon_size ):

        self.apps = app_list

        self.load_icons( icon_size )

    def load_icons(self, icon_size):

        #  Load icons
        for app in self.apps:
            self.apps[app]['icon'] = pygame.image.load( self.apps[app]['icon_path'] )
            self.apps[app]['icon'] = pygame.transform.scale( self.apps[app]['icon'], icon_size )

