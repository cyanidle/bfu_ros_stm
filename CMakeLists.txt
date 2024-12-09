cmake_minimum_required(VERSION 3.22)

#
# This file is generated only once,
# and is not re-generated if converter is called multiple times.
#
# User is free to modify the file as much as necessary
#

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)


# Define the build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# Include toolchain file
include("cmake/gcc-arm-none-eabi.cmake")

# Enable compile command to ease indexing with e.g. clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# Enable CMake support for ASM and C languages
enable_language(C ASM)

# Core project settings
project(bfu_ros_stm)
message("Build type: " ${CMAKE_BUILD_TYPE})

# Create an executable object type
add_executable(bfu_ros_stm
    bfu/bfumain.cpp
)

# Add STM32CubeMX generated sources
add_subdirectory(cmake/stm32cubemx)

# Link directories setup
target_link_directories(bfu_ros_stm PRIVATE
    # Add user defined library search paths
)

# Add sources to executable
target_sources(bfu_ros_stm PRIVATE
    # Add user sources here
)

# Add include paths
target_include_directories(bfu_ros_stm PRIVATE
    # Add user defined include paths
)
# Add project symbols (macros)
target_compile_definitions(bfu_ros_stm PRIVATE
    # Add user defined symbols
)

# Add linked libraries
target_link_libraries(bfu_ros_stm
    stm32cubemx

    # Add user defined libraries
)

add_custom_command(TARGET bfu_ros_stm POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:bfu_ros_stm> bfu_ros_stm.hex
)
