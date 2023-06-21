#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "flir_spinnaker_common::flir_spinnaker_common" for configuration "RelWithDebInfo"
set_property(TARGET flir_spinnaker_common::flir_spinnaker_common APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(flir_spinnaker_common::flir_spinnaker_common PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libflir_spinnaker_common.so"
  IMPORTED_SONAME_RELWITHDEBINFO "libflir_spinnaker_common.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS flir_spinnaker_common::flir_spinnaker_common )
list(APPEND _IMPORT_CHECK_FILES_FOR_flir_spinnaker_common::flir_spinnaker_common "${_IMPORT_PREFIX}/lib/libflir_spinnaker_common.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
