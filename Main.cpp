// main.cpp - CheckDeviceAccess main program source code.
//
// Copyright (C) 2024 Stephen Bonar
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http ://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissionsand
// limitations under the License.

// This program is based on the example code provided here:
// https://blog.mbedded.ninja/programming/operating-systems/linux/linux-serial-ports-using-c-cpp/
//
// If we ever expand this to include some of the additional functionality 
// described in those examples, we'll need to uncomment these additional
// includes:
//
// #include <stdio.h>
// #include <termios.h>

#include <unistd.h> // Provides close() syscall
#include <string.h> // Provides strerror()
#include <fcntl.h>  // Provides open() syscall
#include <errno.h>  // Provides the errno global variable
#include <iostream>
#include <string>
#include "Version.h"

const char* programPurpose 
{
    "This program checks if you can access the specified device."
};

int main(int argc, char** argv)
{
    std::cout 
        << PROGRAM_NAME << " v" << VERSION_MAJOR << '.' << VERSION_MINOR
        << std::endl << PROGRAM_COPYRIGHT << std::endl << std::endl
        << programPurpose << std::endl << std::endl;

    std::string devicePath;
    std::cout << "Please enter the device path: ";
    getline(std::cin, devicePath);

    // Opens the device to see if we can access it. If we can't, then the
    // errno global variable will contain the error code. We convert this to
    // an error message by passing it to strerror().
    std::cout << std::endl << "Opening serial device..." << std::endl;
    int serialDevice = open(devicePath.c_str(), O_RDWR);
    if (serialDevice < 0)
    {
        std::cout 
            << "Error opening device (error code " << errno << "): "
            << strerror(errno) << std::endl;
    }
    else
    {
        std::cout << "Device opened successfully." << std::endl;
    }

    std::cout << "Closing serial device." << std::endl;
    close(serialDevice);

    return 0;
}
