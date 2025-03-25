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
#include <terminus/calc/drivers/DriverBase.hpp>
#include <terminus/calc/image/Frame.hpp>
#include <terminus/calc/ui/WidgetBase.hpp>
#include <terminus/math/Size.hpp>

namespace tmns::calc::ui {

class Label : public WidgetBase {

    public:

        /// Pointer Type
        using ptr_t = std::shared_ptr<Label>;

        Label() = default;
        
        /**
         * Get the label size
         */
        math::Size2i size_pixels() const override;

        /**
         * Show the label
         */
        bool render( core::Session&  session,
                     img::FrameView& image ) override;

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

        /**
         * Provide a pre-initialized frame
         */
        static Label::ptr_t from_frame( img::Frame::ptr_t frame );

    private:

        /// Pixel Data
        img::Frame::ptr_t m_image { nullptr };

}; // End of Label Class

} // End of tmns::calc::ui namespace