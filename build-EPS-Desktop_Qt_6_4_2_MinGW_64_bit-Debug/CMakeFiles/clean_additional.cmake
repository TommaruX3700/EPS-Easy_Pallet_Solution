# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\EPS_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\EPS_autogen.dir\\ParseCache.txt"
  "EPS_autogen"
  )
endif()
