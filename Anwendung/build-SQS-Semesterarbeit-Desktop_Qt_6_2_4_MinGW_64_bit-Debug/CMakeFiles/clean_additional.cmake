# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\SQS-Semesterarbeit_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\SQS-Semesterarbeit_autogen.dir\\ParseCache.txt"
  "SQS-Semesterarbeit_autogen"
  )
endif()
