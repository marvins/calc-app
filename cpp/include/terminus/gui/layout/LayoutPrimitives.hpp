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
 * @file    LayoutPrimitives.hpp
 * @author  Marvin Smith
 * @date    03/23/2025
 *
 * @details UI Attributes.
 */
#pragma once

// C++ Standard Libraries
#include <cinttypes>
#include <optional>
#include <set>

namespace tmns::gui {

/**
 * Set the alignment policy
 */
enum class AlignmentPolicy : uint32_t {
    CENTER_VERTICAL   = 1,
    CENTER_HORIZONTAL = 2,
    LEFT              = 3,
    RIGHT             = 4,
    TOP               = 5,
    BOTTOM            = 6,
}; // End of AlignmentPolicy Enum

/**
 * Alignment helper functions
 */
[[maybe_unused]] static const std::set<AlignmentPolicy> ALIGN_TOP_CENTER(){ return std::set<AlignmentPolicy>( { { AlignmentPolicy::TOP, AlignmentPolicy::CENTER_HORIZONTAL } } ); }
[[maybe_unused]] static const std::set<AlignmentPolicy> ALIGN_BOTTOM_CENTER(){ return std::set<AlignmentPolicy>( { { AlignmentPolicy::BOTTOM, AlignmentPolicy::CENTER_HORIZONTAL } } ); }

/**
 * Set the stretch policy
 */
enum class StretchPolicy {
    FIXED = 0,
    GROW  = 1,
}; // End of StretchPolicy Enum

struct WidgetLayoutInfo {
    
    // Where in the structure to align the asset
    std::set<AlignmentPolicy> alignment; 

    // How much of the layout do you want this widget to take
    std::optional<double> ratio;

    // 
};

} // End of tmns::gui namespace
