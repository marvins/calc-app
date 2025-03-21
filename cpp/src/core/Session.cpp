


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
 * @file    Options.hpp
 * @author  Marvin Smith
 * @date    3/21/2025
*/
#include <tmns/app/calc/core/Session.hpp>

// C++ Standard Libraries
#include <thread>

namespace tmns::calc::core {

/************************************************/
/*          Sleep for Designated Amount         */
/************************************************/
void Session::sleep_for( std::chrono::milliseconds sleep_time )
{
    std::this_thread::sleep_for( sleep_time );
}

/****************************************************/
/*          Create a Session API Instance           */
/****************************************************/
Session Session::create( Options config )
{
    Session new_session;
    
#if CALC_PLATFORM == 2
    #warning "Building desktop variant"
#else
    #error Not supported yet
#endif
    return new_session;
}

} // End of tmns::calc::core namespace