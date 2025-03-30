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
 * @file    Resource_Manager.hpp
 * @author  Marvin Smith
 * @date    3/29/2025
 */
#pragma once

// C++ Standard Libraries
#include <filesystem>
#include <optional>
#include <string>

// Project Libraries
#include <terminus/driver/DriverBase.hpp>
#include <terminus/image/Frame.hpp>
#include <terminus/math/Size.hpp>

namespace tmns::gui {

/**
 * Stores resource data information
 * 
 * This helps when you have little RAM and lots of images and other
 * things which may be reusable.
 * 
 * @todo:  Establish memory limits for preservation
 * @todo:  Use UUIDs
 */
class Resource_Manager {

    public:

        /// Pointer Type
        using ptr_t = std::unique_ptr<Resource_Manager>;

        /**
         * Destructor
         */
        virtual ~Resource_Manager();

        /**
         * Finalize by clearing and deleting all resources stored by this object.
         */
        void finalize();

        /**
         * Provide an image to the resource-manager to handle.
         */
        void add_image( std::string       name,
                        img::Frame::ptr_t image );
        
        /**
         * Get an image
         */
        std::optional<img::Frame::ptr_t> get_image( std::string name );

        /**
         * Release the image
         */
        bool release_image( std::string name );

        /**
         * Retrieve an image with the given name.  This will search all images inside the folder
         * and only process the one with the correct characteristics.
         * 
         * @param image_name Subdirectory name within the cpp/resources directory.
         * @param max_size   Maximum image size.
         */
        std::optional<img::Frame::ptr_t> find_image( std::string   image_name,
                                                     math::Size2i  max_size );


        /**
         * Create a new instance of the resource-manager
         */
        static Resource_Manager::ptr_t create( const std::filesystem::path& resource_root,
                                               drv::Driver_Base&            driver );

    private:

        /// @brief Make sure users use the create() method.
        Resource_Manager() = delete;

        /// @brief This class must be non-copyable
        Resource_Manager( const Resource_Manager& ) = delete;
        Resource_Manager& operator = ( const Resource_Manager& ) = delete;
        
        /**
         * Parameterized Constructor
         */
        Resource_Manager( const std::filesystem::path& resource_root,
                          drv::Driver_Base&            driver );

        /// @brief Location of base folder for all resources
        std::filesystem::path m_resource_root;

        /// @brief Underlying Driver for loading data.
        drv::Driver_Base& m_driver;

        /// @brief List of actively loaded images
        std::map<std::string,img::Frame::ptr_t> m_loaded_frames;

}; // End of Resource_Manager Class

} // End of tmns::gui namespace