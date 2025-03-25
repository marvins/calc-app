#**************************** INTELLECTUAL PROPERTY RIGHTS ****************************#
#*                                                                                    *#
#*                           Copyright (c) 2025 Terminus LLC                          *#
#*                                                                                    *#
#*                                All Rights Reserved.                                *#
#*                                                                                    *#
#*          Use of this source code is governed by LICENSE in the repo root.          *#
#*                                                                                    *#
#**************************** INTELLECTUAL PROPERTY RIGHTS ****************************#
#
#    File:    conanfile.py
#    Author:  Marvin Smith
#    Date:    3/21/2025
#
from conan import ConanFile, tools
from conan.tools.cmake import CMake, CMakeToolchain, CMakeDeps
from conan.tools.files import copy

class ConanProject(ConanFile):

    name = "terminus_calculator"
    version = "0.0.1"

    license = "MIT"
    author  = "Marvin Smith <marvin.smith@terminus.com>"
    url     = "https://www.github.org/marvins/calc-app"
    description = "Embedded Calculator / Converter App"
    topics = ("terminus","convert")

    options = { "driver":     ['raylib','allegro','pico'],
                "with_tests": [True, False] }

    default_options = { 'driver': 'raylib',
                        'with_tests': True }

    settings = "os", "compiler", "build_type", "arch"

    def build_requirements(self):
        self.test_requires("gtest/1.15.0")

    def requirements(self):
        pass

    def _configure_cmake(self):
        cmake = CMake(self)
        cmake.configure()
        return cmake

    def generate(self):
        tc = CMakeToolchain(self)
        
        #  Project Variables
        tc.variables["NAME_FROM_CONANFILE"]        = self.name
        tc.variables["VERSION_FROM_CONANFILE"]     = self.version
        tc.variables["DESCRIPTION_FROM_CONANFILE"] = self.description
        tc.variables["URL_FROM_CONANFILE"]         = self.url

        #  Major choice here for Pico
        tc.variables["RENDER_DRIVER"]              = self.options.driver

        #  Recommend only using tests for non Pico
        tc.variables["TERMINUS_CALC_ENABLE_TESTS"]    = self.options.with_tests

        tc.generate()

        deps = CMakeDeps(self)
        deps.generate()

    def build(self):
        cmake = self._configure_cmake()
        cmake.build()

    def package(self):
        cmake = self._configure_cmake()
        cmake.install()

    def package_info(self):
        #self.cpp_info.libs = ["terminus_nitf"]
        pass

    def package_id(self):
        self.info.clear()

