


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

namespace tmns::calc::core {

/****************************************************/
/*          Create a Session API Instance           */
/****************************************************/
Session Session::create( Options config )
{

#if CALC_PLATFORM == 2
    #warning "Building desktop variant"
#else
    #error Not supported yet
#endif

}

} // End of tmns::calc::core namespace