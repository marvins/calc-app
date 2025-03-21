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

#  Project Libraries
from 
import pygame

class Session:

    def __init__(self, screen: pygame.Surface ):
        
        self.screen: pygame.Surface = screen


    def quit(self):

        # Quit Pygame
        pygame.quit()

    @staticmethod
    def create( config ):

        screen = pygame.display.set_mode( config.get_screen_size() )

        pygame.display.set_caption("Terminus Converter")

        session = Session( screen )

        #  Setup Pygame
        pygame.init()

        return session


