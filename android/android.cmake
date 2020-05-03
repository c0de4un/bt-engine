# // ------------------------------------------------------------------------------
#
# btEngine.Android
#
# // ------------------------------------------------------------------------------

# =================================================================================
# HEADERS
# =================================================================================

set ( BT_ANDROID_HEADERS
	# ASYNC
	"android/utils/async/AndroidMutex.hpp"
	# METRICS
	"android/utils/metrics/AndroidLogger.hpp" )

set ( BT_HEADERS ${BT_HEADERS} ${BT_ANDROID_HEADERS} )
set ( BT_PUBLIC_HEADERS ${BT_PUBLIC_HEADERS} ${BT_ANDROID_HEADERS} )

# =================================================================================
# SOURCES
# =================================================================================

set ( BT_ANDROID_SOURCES
	# ASYNC
	"android/utils/async/AndroidMutex.cpp"
	# METRICS
	"android/utils/metrics/AndroidLogger.cpp" )

set ( BT_SOURCES ${BT_SOURCES} ${BT_ANDROID_SOURCES} )

# =================================================================================
# EXPORT
# =================================================================================

if ( DEFINED BT_HEADERS_EXPORT )
	set ( BT_HEADERS_EXPORT ${BT_HEADERS_EXPORT} ${BT_ANDROID_HEADERS} )
	set ( BT_SOURCES_EXPORT ${BT_SOURCES_EXPORT} ${BT_ANDROID_SOURCES} )
endif ( DEFINED BT_HEADERS_EXPORT )