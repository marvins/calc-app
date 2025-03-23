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
 * @file    Label.hpp
 * @author  Marvin Smith
 * @date    03/22/2025
 *
 * @details Label for showing text or imagery
 */
#pragma once

// Project Libraries
#include <tmns/app/calc/drivers/DriverBase.hpp>
#include <tmns/app/calc/ui/Frame.hpp>
#include <tmns/app/calc/ui/WidgetBase.hpp>

namespace tmns::calc::ui {

class Label : public WidgetBase {

    public:

        /// Pointer Type
        using ptr_t = std::shared_ptr<Label>;

        /**
         * Show the label
         */
        bool render( core::Session& session,
                     Frame&         image ) override;

        /**
         * Load an image and store in the label
         */
        static Label::ptr_t from_image( const std::filesystem::path& image_path,
                                        drv::Driver_Base::ptr_t      driver );

        /**
         * Render as text
         */
        static Label::ptr_t from_text( const std::string&       message,
                                       drv::Driver_Base::ptr_t  driver );

    private:

        /// Pixel Data
        Frame::ptr_t m_image { nullptr };

}; // End of Label Class

} // End of tmns::calc::ui namespace