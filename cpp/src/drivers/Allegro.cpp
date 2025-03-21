/**************************** INTELLECTUAL PROPERTY RIGHTS ****************************/
/*                                                                                    */
/*                           Copyright (c) 2025 Terminus LLC                          */
/*                                                                                    */
/*                                All Rights Reserved.                                */
/*                                                                                    */
/*          Use of this source code is governed by LICENSE in the repo root.          */
/*                                                                                    */
/**************************** INTELLECTUAL PROPERTY RIGHTS ****************************/
/**
 * @file    Allegro.cpp
 * @author  Marvin Smith
 * @date    03/21/2025
 *
 * @details Vertical Layout API
 */
#include <tmns/app/calc/drivers/Allegro.hpp>


namespace tmns::calc::drv {

/****************************************/
/*          Initialize Driver           */
/****************************************/
bool Driver_Allegro::initialize( core::Options& config )
{
    al_init();

    al_install_keyboard();

    m_timer = al_create_timer(1.0 / 30.0);

    m_queue = al_create_event_queue();

    m_display = al_create_display(320, 200);

    m_font = al_create_builtin_font();

    // Configure handlers
    al_register_event_source( m_queue, al_get_keyboard_event_source() );
    al_register_event_source( m_queue, al_get_display_event_source(m_display) );
    al_register_event_source( m_queue, al_get_timer_event_source(m_timer) );
}

/****************************************/
/*            Finalize Driver           */
/****************************************/
bool Driver_Allegro::finalize()
{
    
}

} // End of tmns::calc::drv namespace
