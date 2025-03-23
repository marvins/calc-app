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
 * @file    LayoutBase.cpp
 * @author  Marvin Smith
 * @date    03/23/2025
 *
 * @details Base Layout API
 */
#include <tmns/app/calc/ui/LayoutBase.hpp>

namespace tmns::calc::ui {

/****************************************/
/*          Get Layout Dimensions       */
/****************************************/
img::Dimensions LayoutBase::layout_dimensions() const {
    return m_layout_dims;
}

/****************************************/
/*          Set Layout Dimensions       */
/****************************************/
void LayoutBase::set_layout_dimensions( img::Dimensions dims ){
    m_layout_dims = dims;
}

} // End of tmns::calc::ui namespace
