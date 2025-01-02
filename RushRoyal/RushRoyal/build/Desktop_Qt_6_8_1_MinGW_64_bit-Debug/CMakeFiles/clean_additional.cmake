# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\RushRoyal_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\RushRoyal_autogen.dir\\ParseCache.txt"
  "RushRoyal_autogen"
  )
endif()
