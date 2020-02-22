cmake_minimum_required(VERSION 3.11)#VERSION 2.8)
project(learning_tmp)

set(BOOST_URL "https://dl.bintray.com/boostorg/release/1.71.0/source/boost_1_71_0.tar.bz2" CACHE STRING "Boost download URL")
set(BOOST_URL_SHA256 "d73a8da01e8bf8c7eda40b4c84915071a8c8a0df4a6734537ddde4a8580524ee" CACHE STRING "Boost download URL SHA256 checksum")

include(FetchContent)
FetchContent_Declare(
  Boost
  URL ${BOOST_URL}
  URL_HASH SHA256=${BOOST_URL_SHA256}
)
FetchContent_GetProperties(Boost)

if(NOT Boost_POPULATED)
  message(STATUS "Fetching Boost")
  FetchContent_Populate(Boost)
  message(STATUS "Fetching Boost - done")
  set(BOOST_SOURCE ${boost_SOURCE_DIR})
endif()


set(Boost_INCLUDE_DIR _deps/boost-src)
set(BOOST_ROOT _deps/boost-src)
set(BOOST_LIBRARYDIR _deps/boost-src/libs)
include_directories(${Boost_INCLUDE_DIR} ${PROJECT_SOURCE_DIR})

#set(SOURCES ${PROJECT_SOURCE_DIR}/answer_getter.cpp)

add_executable(main main.cpp)
