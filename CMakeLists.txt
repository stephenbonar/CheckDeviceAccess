# CMakeLists.txt - CMakeLists for building the project.
#
# Copyright (C) 2024 Stephen Bonar
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http ://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissionsand
# limitations under the License.

cmake_minimum_required(VERSION 3.0.0)

project(CheckDeviceAccess VERSION 0.5.0 LANGUAGES C CXX)

# Although the project command can natively pass the name and version into
# the program through the configure_file command, there is no native RELEASE
# or COPYRIGHT info, so we define that here to pass to configure_file.
set(PROJECT_RELEASE "Alpha")
set(PROJECT_COPYRIGHT "Copyright (C) 2024 Stephen Bonar")

# Define the directories that contain the header files the tests include.
set(INCLUDES ${PROJECT_BINARY_DIR})

# Configure the program version info from the main cmake project into the
# Version.h header, which is build into the program binary. This is done so
# we centrally update the program name, version, and copyright from cmake.
configure_file(Version.h.in Version.h)

add_executable(checkdev Main.cpp)

# Include all the directories that contain headers that we need that are not
# in the current directory, otherwise the compiler won't find them.
target_include_directories(checkdev PUBLIC ${INCLUDES})

set(CMAKE_EXE_LINKER_FLAGS " -static")
