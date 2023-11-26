# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\aed_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\aed_autogen.dir\\ParseCache.txt"
  "aed_autogen"
  )
endif()
