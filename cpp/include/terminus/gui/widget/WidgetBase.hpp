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
 * @file    WidgetBase.hpp
 * @author  Marvin Smith
 * @date    03/21/2025
 *
 * @details Base Widget API
 */
#pragma once

// C++ Libraries
#include <memory>
#include <string>

// Project Libraries
#include <terminus/gui/core/Session.hpp>
#include <terminus/gui/I_Renderable.hpp>
#include <terminus/image/Frame_View.hpp>
#include <terminus/math/Size.hpp>

namespace tmns::gui {

/**
 * @class WidgetBase
 */
class WidgetBase : public I_Renderable
{
    public:

        /// @brief  Pointer Type
        using ptr_t = std::shared_ptr<WidgetBase>;

        /**
         * Destructor
         */
        virtual ~WidgetBase() = default;

        /**
         * @brief Get the size of the widget, in pixels
         */
        virtual math::Size2i size_pixels() const = 0;

        /**
         * Primarily a troubleshooting tool to draw a border around the label
         */
        void set_border( math::Vector4u color );

        /**
         * Get the log tag
         */
        std::string log_tag() const;
        
        /**
         * Set the log-friendly tag string
         */
        void set_log_tag( std::string log_tag );

        /**
         * Print Log-Friendly Information
         */
        virtual std::string to_log_string( size_t offset = 0 ) const = 0;

    protected:

        virtual bool render_border( Session&         session,
                                    img::Frame_View& image );

    private:

        /// Flag if we want to render a border
        std::optional<math::Vector4u> m_border {};

        /// Log-Friendly String
        std::string m_log_tag;

};// End of WidgetBase class

} // End of tmns::gui namespace
