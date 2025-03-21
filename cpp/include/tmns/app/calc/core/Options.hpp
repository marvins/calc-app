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
#pragma once

// C++ Standard Libraries
#include <filesystem>

namespace tmns::calc::core {

class Options final {

    public:

        /**
         * Print usage as log-friendly string
         */
        std::string usage() const;

        /**
         * @brief Parse command-line and config-file options and return 
         *        usable Options structure. 
         * 
         * @note  This method will abort if it finds a configuration that is
         *        not usable 
         */
        static Options parse( int argc, char* argv[] );

        /**
         * @brief Generate a configuration file at the specified path.
         * 
         * @param pathname
         */
        static void generate_config_file( const std::filesystem::path& pathname );

    private:

        /**
         * Parameterized Constructor
         */
        Options( const std::filesystem::path& app_name );

        /**
         * Verify configuration
         */
        bool verify( std::string& error_str ) const;

        /// Application Name
        std::filesystem::path m_app_name;

        /// Configuration file path
        std::filesystem::path m_config_path;

        /// Flag to create configuration-file
        bool m_gen_config { false };

}; // End of Options Class

} // End of tmns::core namespace