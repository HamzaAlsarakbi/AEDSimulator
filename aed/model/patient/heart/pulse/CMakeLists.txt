cmake_minimum_required(VERSION 3.26)
project(Pulse)

# Create a library target for the Heart class
add_library(pulse Pulse.cpp Pulse.h)

# Assuming GoogleTest is added as a submodule or otherwise available
# Include the tests directory
add_subdirectory(tests)