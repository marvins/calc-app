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

import pygame

def load_image( pathname, fixed_size = None ):
    '''
    Load an image from disk
    '''

    image = pygame.image.load( pathname )
    
    if fixed_size != None:
        image = pygame.transform.scale( image, fixed_size )
    
    return image
