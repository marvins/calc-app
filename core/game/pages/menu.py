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
import time

#  Pygame Library
import pygame

#  Project Libraries
from core import Action

WHITE = 255, 255, 255
BLACK = 0,0,0

DARK_BLUE = 0, 44, 62

def render_base( config, session, cache_mgr, app_mgr ):

    #  Get configuration settings
    screen_size = config.get_screen_size()

    icon_size = [ config.cfg_args.getint('menu','icon_width'),
                  config.cfg_args.getint('menu','icon_height') ]
    
    border = config.cfg_args.getint('menu','border_length')
    gap    = config.cfg_args.getint('menu','gap_length')


    #  Get the header text
    font = pygame.font.Font(None, 40)  # None uses the default font
    text = font.render("Terminus Converter Menu", True, BLACK)  # White text
    text_size = text.get_size()
    text_tl = [ screen_size[0]/2 - text_size[0]/2,
                border ]

    #  Header length
    hdr_height = text_size[1]

    #  Width of screen for apps
    width_minus_gaps = screen_size[0] - ( border * 2 )
    icons_per_row = width_minus_gaps / icon_size[0]
    

    #  Screen size will be the header + length of apps
    napps = len(app_mgr.apps.keys())
    

    #  Compute full size of app layout (Icons + gap between icons + gap between icons and borders
    app_area_width  = screen_size[0] - border * 2 - gap * 2
    app_area_height = napps * icon_size[1] + (napps-1) * gap + gap*2
    full_height = hdr_height + border * 2 + app_area_height
    full_height = max( full_height, screen_size[1] )

    #  Full Surface
    bgr_surface = pygame.Surface( (screen_size[0], full_height) )
    print( 'BGR Surface: ', bgr_surface.get_size() )
    bgr_surface.fill( WHITE )

    #  Lay down Header
    print( f'Text Top-Left: {text_tl}' )
    bgr_surface.blit( text, text_tl )

    #  Draw Border around apps
    bgr_tl = [ border,
               text_tl[1] + gap * 2 ]
    res = pygame.draw.rect( bgr_surface, 
                            DARK_BLUE, 
                            pygame.Rect( bgr_tl[0], bgr_tl[1],
                                         app_area_width, app_area_height ),
                            width = 3 )

    #  Draw Icon
    counter = 0
    for app in app_mgr.apps.keys():

        icon_image = app_mgr.apps[app]['icon']
        
        icon_tl = [ border + gap,
                    counter * gap + gap + bgr_tl[1] ]

        bgr_surface.blit( icon_image, icon_tl )

        counter += 1

    return bgr_surface


def main_menu( config, session, app_mgr, cache_mgr ):

    #  Window Position Information
    tl_pix = [0,0]
    ssize  = config.get_screen_size()

    pos_changed = True

    #  Render the base screen
    base_surface = render_base( config, session, cache_mgr, app_mgr )

    while True:

        if pos_changed:

            #  Chop base surface out
            session.screen.blit( base_surface, pygame.Rect( tl_pix[0], tl_pix[1], ssize[0], ssize[1] ) )
    
        #  Show screen
        pygame.display.flip()
        time.sleep(10)

        #  Wait for decision


    return { 'code': Action.QUIT }

