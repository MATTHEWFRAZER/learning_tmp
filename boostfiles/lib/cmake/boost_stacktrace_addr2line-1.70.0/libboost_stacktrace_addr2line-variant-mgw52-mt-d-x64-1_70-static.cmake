# Generated by Boost 1.70.0

# address-model=64

if(CMAKE_SIZEOF_VOID_P EQUAL 4)
  return()
endif()

# layout=versioned

# toolset=mgw52

if(Boost_COMPILER AND NOT Boost_COMPILER STREQUAL "mgw52")
  return()
endif()

if(BOOST_DETECTED_TOOLSET AND NOT BOOST_DETECTED_TOOLSET STREQUAL "mgw52")
  return()
endif()

# link=static

if(NOT "${Boost_USE_STATIC_LIBS}" STREQUAL "" AND NOT Boost_USE_STATIC_LIBS)
  return()
endif()

if(BUILD_SHARED_LIBS)
  return()
endif()

# runtime-link=shared

if(Boost_USE_STATIC_RUNTIME)
  return()
endif()

# runtime-debugging=on

if(NOT "${Boost_USE_DEBUG_RUNTIME}" STREQUAL "" AND NOT Boost_USE_DEBUG_RUNTIME)
  return()
endif()

# threading=multi

# variant=debug

if(NOT "${Boost_USE_DEBUG_LIBS}" STREQUAL "" AND NOT Boost_USE_DEBUG_LIBS)
  return()
endif()


set_property(TARGET Boost::stacktrace_addr2line APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(Boost::stacktrace_addr2line PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG CXX
  )

list(APPEND _BOOST_STACKTRACE_ADDR2LINE_DEPS headers)
