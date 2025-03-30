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

/********************************/
/*          Destructor          */
/********************************/
Resource_Manager::~Resource_Manager()
{
    finalize();
}

/*****************************/
/*          Finalize         */
/*****************************/
void Resource_Manager::finalize()
{
    m_loaded_frames.clear();
}

/********************************************/
/*          Find and load the image         */
/********************************************/
std::optional<img::Frame::ptr_t> Resource_Manager::find_image( [[maybe_unused]] std::string   image_name,
                                                               [[maybe_unused]] math::Size2i  max_size )
{
    return {};
}                                                               
                                                               
/************************************/
/*          Create Instance         */
/************************************/
Resource_Manager::ptr_t Resource_Manager::create( const std::filesystem::path& resource_root,
                                                  drv::Driver_Base&            driver )
{
    return Resource_Manager::ptr_t( new Resource_Manager( resource_root, driver ) );
}

/************************************************/
/*          Parameterized Constructor           */
/************************************************/
Resource_Manager::Resource_Manager( const std::filesystem::path& resource_root,
                                    drv::Driver_Base&            driver )
    : m_resource_root { resource_root },
      m_driver { driver }
{}

} // End of tmns::gui namespace