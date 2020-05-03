# // ------------------------------------------------------------------------------
#
# btEngine.Windows
#
# // ------------------------------------------------------------------------------

# =================================================================================
# HEADERS
# =================================================================================

set ( BT_WINDOWS_HEADERS
	# ASYNC
	"windows/utils/async/WinMutex.hpp"
	"windows/utils/async/WinSpinLock.hpp"
	# METRICS
	"windows/utils/metrics/WinLog.hpp" )

set ( BT_HEADERS ${BT_HEADERS} ${BT_WINDOWS_HEADERS} )
set ( BT_PUBLIC_HEADERS ${BT_PUBLIC_HEADERS} ${BT_WINDOWS_HEADERS} )

# =================================================================================
# SOURCES
# =================================================================================

set ( BT_WINDOWS_SOURCES
	# ASYNC
	"windows/utils/async/WinMutex.cpp"
	"windows/utils/async/WinSpinLock.cpp"
	# METRICS
	"windows/utils/metrics/WinLog.cpp" )

set ( BT_SOURCES ${BT_SOURCES} ${BT_WINDOWS_SOURCES} )

# =================================================================================
# EXPORT
# =================================================================================

if ( DEFINED BT_HEADERS_EXPORT )
	set ( BT_HEADERS_EXPORT ${BT_HEADERS_EXPORT} ${BT_WINDOWS_HEADERS} )
	set ( BT_SOURCES_EXPORT ${BT_SOURCES_EXPORT} ${BT_WINDOWS_SOURCES} )
endif ( DEFINED BT_HEADERS_EXPORT )