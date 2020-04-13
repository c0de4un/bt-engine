# // ------------------------------------------------------------------------------
#
# This is CMake-file tries to detect abi.
#
# // ------------------------------------------------------------------------------

if ( NOT DEFINED BT_ABI )
	message ( SEND_ERROR "${PROJECT_NAME} - can't detect ABI ! Configuration required." )
endif ( NOT DEFINED BT_ABI )