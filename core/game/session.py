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

#  Pygame Engine
import pygame

#  Project Libraries
from screen import get_resolution


class Session:

    def __init__(self, screen: pygame.Surface ):
        
        self.screen: pygame.Surface = screen


    def quit(self):

        # Quit Pygame
        pygame.quit()

    @staticmethod
    def create( config ):

        #  Get max allowable size
        max_size = get_resolution()

        screen = pygame.display.set_mode( max_size )

        pygame.display.set_caption("Terminus Converter")

        session = Session( screen )

        #  Setup Pygame
        pygame.init()

        return session


