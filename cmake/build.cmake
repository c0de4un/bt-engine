# // ------------------------------------------------------------------------------
#
# This is CMake-file with build config for btEngine.
#
# // ------------------------------------------------------------------------------

if ( NOT DEFINED BT_BUILD_MODE )
	message ( FATAL_ERROR "${PROJECT_NAME} - build mode not defined. Use <0> for sources export, <1> for static library, <2> for shared library." )
endif ( NOT DEFINED BT_BUILD_MODE )

# =================================================================================
# EXPORT
# =================================================================================

if ( BT_BUILD_MODE EQUAL 0 )
	if ( NOT DEFINED BT_HEADERS_EXPORT OR NOT DEFINED BT_SOURCES_EXPORT )
		message ( FATAL_ERROR "${PROJECT_NAME} - required headers & sources containers not set. Set <BT_HEADERS_EXPORT> & <BT_SOURCES_EXPORT> for output list of sources." )
	endif ( NOT DEFINED BT_HEADERS_EXPORT OR NOT DEFINED BT_SOURCES_EXPORT )

	# INFO
	message ( "${PROJECT_NAME} - headers & sources will be exported into <BT_HEADERS_EXPORT> & <BT_SOURCES_EXPORT>." )
endif ( BT_BUILD_MODE EQUAL 0 )

# =================================================================================
# STATIC
# =================================================================================

if ( BT_BUILD_MODE EQUAL 1 )
	# Add defines.
	add_definitions ( -DBT_STATIC=1 )

	# Add STATIC Library Object
	add_library ( btengine STATIC ${BT_HEADERS} ${BT_SOURCES} )
	target_include_directories ( btengine PUBLIC ${BT_ENGINE_DIR} )

# Configure STATIC Library Object
set_target_properties ( btengine PROPERTIES
	OUTPUT_NAME ${PROJECT_NAME}
	LIBRARY_OUTPUT_NAME ${PROJECT_NAME}
	#PUBLIC_HEADER ${BT_PUBLIC_HEADERS}
	RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BIN_DIR}
	VERSION ${PROJECT_VERSION} )

	# INFO
	message ( STATUS "${PROJECT_NAME} - STATIC Library output enabled." )
endif ( BT_BUILD_MODE EQUAL 1 )

# =================================================================================
# SHARED
# =================================================================================

if ( BT_BUILD_MODE EQUAL 2 )
	# Add defines.
	add_definitions ( -DBT_SHARED=1 )

	# Export all Symbols by default (on Windows creates '.lib'+ '.dll').
	set ( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON )

	# Add SHARED Library Object
	add_library ( btengine SHARED ${BT_SOURCES} )

# Configure SHARED Library Object
set_target_properties ( btengine PROPERTIES
	LIBRARY_OUTPUT_NAME ${PROJECT_NAME}
	OUTPUT_NAME ${PROJECT_NAME}
	PUBLIC_HEADER ${BT_PUBLIC_HEADERS}
	RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BIN_DIR}
	VERSION ${PROJECT_VERSION} )

	# Include & Use CMake Export-Headers Generator Utils for SHARED Libraries (.dll) on Windows
	include(GenerateExportHeader)
	generate_export_header(btengine)

	# INFO
	message ( STATUS "${PROJECT_NAME} - build SHARED Library enabled." )
endif ( BT_BUILD_MODE EQUAL 2 )