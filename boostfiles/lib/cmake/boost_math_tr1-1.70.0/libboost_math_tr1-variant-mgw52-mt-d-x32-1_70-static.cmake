# Generated by Boost 1.70.0

# address-model=32

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
  _BOOST_SKIPPED("libboost_math_tr1-mgw52-mt-d-x32-1_70.a" "32 bit, need 64")
  return()
endif()

# layout=versioned

# toolset=mgw52

if(Boost_COMPILER AND NOT Boost_COMPILER STREQUAL "mgw52")
  _BOOST_SKIPPED("libboost_math_tr1-mgw52-mt-d-x32-1_70.a" "mgw52, Boost_COMPILER=${Boost_COMPILER}")
  return()
endif()

if(BOOST_DETECTED_TOOLSET AND NOT BOOST_DETECTED_TOOLSET STREQUAL "mgw52")
  _BOOST_SKIPPED("libboost_math_tr1-mgw52-mt-d-x32-1_70.a" "mgw52, detected ${BOOST_DETECTED_TOOLSET}, set Boost_COMPILER to override")
  return()
endif()

# link=static

if(NOT "${Boost_USE_STATIC_LIBS}" STREQUAL "" AND NOT Boost_USE_STATIC_LIBS)
  _BOOST_SKIPPED("libboost_math_tr1-mgw52-mt-d-x32-1_70.a" "static, Boost_USE_STATIC_LIBS=${Boost_USE_STATIC_LIBS}")
  return()
endif()

if(BUILD_SHARED_LIBS)
  _BOOST_SKIPPED("libboost_math_tr1-mgw52-mt-d-x32-1_70.a" "static, BUILD_SHARED_LIBS=${BUILD_SHARED_LIBS}, set Boost_USE_STATIC_LIBS=ON to override")
  return()
endif()

# runtime-link=shared

if(Boost_USE_STATIC_RUNTIME)
  _BOOST_SKIPPED("libboost_math_tr1-mgw52-mt-d-x32-1_70.a" "shared runtime, Boost_USE_STATIC_RUNTIME=${Boost_USE_STATIC_RUNTIME}")
  return()
endif()

# runtime-debugging=on

if(NOT "${Boost_USE_DEBUG_RUNTIME}" STREQUAL "" AND NOT Boost_USE_DEBUG_RUNTIME)
  _BOOST_SKIPPED("libboost_math_tr1-mgw52-mt-d-x32-1_70.a" "debug runtime, Boost_USE_DEBUG_RUNTIME=${Boost_USE_DEBUG_RUNTIME}")
  return()
endif()

# threading=multi

# variant=debug

if(NOT "${Boost_USE_DEBUG_LIBS}" STREQUAL "" AND NOT Boost_USE_DEBUG_LIBS)
  _BOOST_SKIPPED("libboost_math_tr1-mgw52-mt-d-x32-1_70.a" "debug, Boost_USE_DEBUG_LIBS=${Boost_USE_DEBUG_LIBS}")
  return()
endif()

message(STATUS "  libboost_math_tr1-mgw52-mt-d-x32-1_70.a")

# Target file name: libboost_math_tr1-mgw52-mt-d-x32-1_70.a
set_property(TARGET Boost::math_tr1 APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(Boost::math_tr1 PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG CXX
  IMPORTED_LOCATION_DEBUG "${_BOOST_LIBDIR}/libboost_math_tr1-mgw52-mt-d-x32-1_70.a"
  )

list(APPEND _BOOST_MATH_TR1_DEPS headers)
