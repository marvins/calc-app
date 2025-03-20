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
import datetime
import time

#  Pygame
import pygame

#  Project Libraries
from screen import get_resolution

WHITE = (255,255,255)
BLACK = (0,0,0)

#  Display splash screen
def display_splash( session ):

    #  Our logo
    logo = pygame.image.load("core/images/logo.png")
    logo_size = logo.get_size()

    #  Check logo position
    win_size = session.screen.get_size()
    print( 'win size: ', win_size )
    print( 'logo size: ', logo_size )

    # Put logo at top
    logo_tl = ( max( win_size[0]/2 - logo_size[0]/2, 0 ), 0 )   


    # Define text
    font = pygame.font.Font(None, 40)  # None uses the default font
    text = font.render("Terminus Converter", True, BLACK)  # White text
    text_size = text.get_size()

    text_tl = ( max( win_size[0]/2 - text_size[0]/2, 0 ), 
                logo_tl[1] + logo_size[1] + 50 )

    #  Create screen
    session.screen.fill( WHITE )  # Black background
    session.screen.blit(logo, logo_tl)  # Center the image (adjust as needed)
    session.screen.blit(text, text_tl)  # Position the text (adjust as needed)
    pygame.display.flip()
    
    time.sleep(5)

    #  Use intro_text_surface.set_alpha(a) for fade-in/out later