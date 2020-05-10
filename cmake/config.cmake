# // ------------------------------------------------------------------------------
#
# This is CMake-file defines config-vars for bt_Engine CMake-Project.
#
# // ------------------------------------------------------------------------------

# Project Third-party Libs Dir.
if ( NOT DEFINED PROJECT_LIBS_DIR )
	set ( PROJECT_LIBS_DIR "${CMAKE_SOURCE_DIR}/external/" )
endif ( NOT DEFINED PROJECT_LIBS_DIR )

# Binaries Output-Dir.
if ( NOT DEFINED PROJECT_BIN_DIR )
	set ( PROJECT_BIN_DIR "${CMAKE_SOURCE_DIR}/bin/" )
endif ( NOT DEFINED PROJECT_BIN_DIR )

# Project Build-Dir.
if ( NOT DEFINED PROJECT_BUILD_DIR )
	set ( PROJECT_BUILD_DIR "${CMAKE_SOURCE_DIR}/build/" )
endif ( NOT DEFINED PROJECT_BUILD_DIR )

# Resources Dir.
if ( NOT DEFINED PROJECT_RES_DIR )
	set ( PROJECT_RES_DIR "${CMAKE_SOURCE_DIR}/res/" )
endif ( NOT DEFINED PROJECT_RES_DIR )

# Assets Dir.
if ( NOT DEFINED PROJECT_ASSETS_DIR )
	set ( PROJECT_ASSETS_DIR "${CMAKE_SOURCE_DIR}/assets/" )
endif ( NOT DEFINED PROJECT_ASSETS_DIR )

# bt_Engine Dir.
if ( NOT DEFINED BT_DIR )
	set ( BT_DIR "${PROJECT_LIBS_DIR}btengine/" )
endif ( NOT DEFINED BT_DIR )

# Sources-Dir.
if ( NOT DEFINED BT_CXX_SRC_DIR )
	set ( BT_CXX_SRC_DIR "src/cxx/" )
endif ( NOT DEFINED BT_CXX_SRC_DIR )