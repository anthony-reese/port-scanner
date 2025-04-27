# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\port-scanner_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\port-scanner_autogen.dir\\ParseCache.txt"
  "port-scanner_autogen"
  )
endif()
