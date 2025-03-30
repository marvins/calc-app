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
#include <map>
#include <optional>
#include <string>
#include <type_traits>

// Project Libraries
#include <terminus/core/StringUtilities.hpp>
#include <terminus/log.hpp>

namespace tmns::core {

class Options final {

    public:

        /**
         * @brief Get a configuration setting in string format.
         * 
         * @param section Section name as defined in the configuration file.
         * @param key     Key name as defined in the configuration file.
         * @returns Value in std::optional format.  {} if not found.
         */
        template <typename VALTYPE>
        std::optional<VALTYPE> setting( const std::string& section,
                                        const std::string& key ) const {
            return get_setting( section, key );
        }

        /**
         * @brief Get a configuration setting in boolean format.
         * 
         * @param section Section name as defined in the configuration file.
         * @param key     Key name as defined in the configuration file.
         * @returns Value in std::optional format.  {} if not found.
         */
        template <typename VALTYPE>
        std::optional<VALTYPE> setting( const std::string& section,
                                        const std::string& key ) const requires std::is_same<VALTYPE,bool>::value {

            // Verify the key exists
            auto sval = get_setting( section, key );
            if( sval.has_value() ){
                auto bval = core::to_lower( sval.value() );
                return ( bval == "true" || bval == "1" );
            } else {
                return {};
            }
        }

        /**
         * @brief Get a configuration setting in integer format.
         * 
         * @param section Section name as defined in the configuration file.
         * @param key     Key name as defined in the configuration file.
         * @returns Value in std::optional format.  {} if not found.
         */
        template <typename VALTYPE>
        std::optional<VALTYPE> setting( const std::string& section,
                                        const std::string& key ) const requires std::is_same<VALTYPE,int32_t>::value {
            // Verify the key exists
            auto sval = get_setting( section, key );
            if( sval.has_value() ){
                return std::stoi( sval.value() );
            } else {
                return {};
            }
        }

        /**
         * Instanciation for integers
         */
        template <typename VALTYPE>
        std::optional<VALTYPE> setting( const std::string& section,
                                        const std::string& key ) const requires std::is_same<VALTYPE,size_t>::value {
            // Verify the key exists
            auto sval = get_setting( section, key );
            if( sval.has_value() ){
                return std::stoul( sval.value() );
            } else {
                return {};
            }
        }

        /**
         * Instanciation for floats
         */
        template <typename VALTYPE>
        std::optional<VALTYPE> setting( const std::string& section,
                                        const std::string& key ) const requires std::is_same<VALTYPE,float>::value {
            
            // Verify the key exists
            auto sval = get_setting( section, key );
            if( sval.has_value() ){
                return std::stof( sval.value() );
            } else {
                return {};
            }
        }

        /**
         * Instanciation for paths
         */
        template <typename VALTYPE>
        std::optional<VALTYPE> setting( const std::string& section,
                         const std::string& key ) const requires std::is_same<VALTYPE,std::filesystem::path>::value {
            // Verify the key exists
            auto sval = get_setting( section, key );
            if( sval.has_value() ){
                return std::filesystem::path( sval.value() );
            } else {
                return {};
            }
        }

        /**
         * Syntactic sugar for fetching settings and throwing if a value does not exist.
         */
        template <typename VALTYPE>
        VALTYPE check_and_get_setting( const std::string& section,
                                       const std::string& key ) const {
            auto res = setting<VALTYPE>( section, key );
            if( res.has_value() ){
                return res.value();
            } else {
                std::stringstream sout;
                sout << "No Value found for requested section: [" << section << "] and key: [" << key << "]";
                LOG_ERROR( sout.str() );
                throw std::runtime_error( sout.str() );
            }
        }
        
        /**
         * Get the log severity
         */
        log::Level log_level() const;

        /**
         * Print Log-Friendly String
         */
        std::string to_log_string( size_t offset = 0 ) const;

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

        /**
         * Check and throw if a flag is missing
         */
        std::optional<std::string> get_setting( std::string section_name,
                                                std::string key_name ) const;

        /// Application Name
        std::filesystem::path m_app_name;

        /// Configuration file path
        std::filesystem::path m_config_path;

        /// Log Severity
        log::Level m_log_level { log::Level::INFO };

        /// Flag to create configuration-file
        bool m_gen_config { false };

        /// Configuration File Settings
        std::map<std::string,std::map<std::string,std::string>> m_settings;

}; // End of Options Class

} // End of tmns::core namespace