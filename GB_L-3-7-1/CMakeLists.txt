# CMakeList.txt : CMake project for GB_L-3-7-1, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("GB_L-3-7-1")
set(CMAKE_CXX_STANDART 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
# add parent directory containing bin/protoc.exe, cmake/protobuf-config.cmake, lib/libprotobufd.lib (or .a), etc.
list(APPEND CMAKE_PREFIX_PATH "C:/protobuf-cpp-3.19.1/protobuf_release")
set(Protobuf_USE_STATIC_LIBS ON)
#created files input here
set(GENERATED_DIR ${PROJECT_SOURCE_DIR}/protobuf)
set(CMAKE_CURRENT_BINARY_DIR ${GENERATED_DIR})

include(FindProtobuf)
find_package(Protobuf REQUIRED)
if ( Protobuf_FOUND )
    message(STATUS "Protobuf version : ${Protobuf_VERSION}" )
    message(STATUS "Protobuf include path : ${Protobuf_INCLUDE_DIRS}" )
    message(STATUS "Protobuf libraries : ${Protobuf_LIBRARIES}" )
else()
    message(WARNING "Protobuf package not found -> specify search path via PROTOBUF_ROOT variable")
endif()

include_directories(${Protobuf_INCLUDE_DIRS})

# Add source to this project's executable.
protobuf_generate_cpp (PROTO_SRCS PROTO_HDRS 
                        ${CMAKE_CURRENT_SOURCE_DIR}/protocol.proto)
ADD_LIBRARY (protocol ${PROTO_HDRS} ${PROTO_SRCS})
TARGET_LINK_LIBRARIES(protocol)
add_executable (GB_L-3-7-1 GB_L-3-7-1.cpp)
# TODO: Add tests and install targets if needed.
TARGET_LINK_LIBRARIES(GB_L-3-7-1 protocol ${PROTOBUF_LIBRARY})