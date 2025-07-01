# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "CMakeFiles\\sortingAlgorithmDeluxe_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\sortingAlgorithmDeluxe_autogen.dir\\ParseCache.txt"
  "sortingAlgorithmDeluxe_autogen"
  )
endif()
