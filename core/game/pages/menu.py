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


#  Project Libraries
from core import Action

white = 255, 255, 255
black = 0,0,0

#def scale_icon( )

def main_menu( config, session, app_mgr ):

    #  Render Screen
    session.screen.fill( white )

    #  Iterate over each app, drawing the icons
    icon_size = [ config.cfg_args.getint('display','menu_icon_width'),
                  config.cfg_args.getint('display','menu_icon_height') ]



    #  Wait for decision


    return { 'code': Action.QUIT }

