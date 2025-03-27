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
 * @file    Main_Menu.hpp
 * @author  Marvin Smith
 * @date    3/27/2025
 */
#pragma once

// Project Libraries
#include <terminus/calc/ui/LayoutVertical.hpp>
#include <terminus/calc/ui/WidgetLayout.hpp>

namespace tmns::calc::page {

class Main_Menu : public ui::WidgetLayout {

    public:

        /// Pointer Type
        using ptr_t = std::shared_ptr<Main_Menu>;

        /**
         * Construct Main Menu
         */
        static Main_Menu::ptr_t create( const core::Options& config,
                                        core::Session&       session );
    
    private:

        Main_Menu() = default;

        /// Layout used to store widgets
        ui::LayoutVertical::ptr_t m_main_layout;
        
        /// List of Application Labels
        

}; // End of Main_Menu class

} // End of tmns::calc::page namespace