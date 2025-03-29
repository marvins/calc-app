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
 * @file    Resource_Manager.cpp
 * @author  Marvin Smith
 * @date    3/29/2025
 */
#include <terminus/gui/core/Resource_Manager.hpp>

// Project Libraries
#include <terminus/log.hpp>

namespace tmns::gui {

/********************************************/
/*          Find and load the image         */
/********************************************/
std::optional<img::Frame::ptr_t> Resource_Manager::find_image( std::string   image_name,
                                                               math::Size2i  max_size )
{
    return {};
}                                                               
                                                               
/************************************/
/*          Create Instance         */
/************************************/
Resource_Manager::ptr_t Resource_Manager::create( const std::filesystem::path& resource_root,
                                                  drv::Driver_Base::ptr_t      driver )
{
    auto inst = std::shared_ptr<Resource_Manager>( new Resource_Manager() );
    inst->m_resource_root = resource_root;
    inst->m_driver = driver;

    return inst;
}


} // End of tmns::gui namespace