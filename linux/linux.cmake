# // ------------------------------------------------------------------------------
#
# btEngine.Linux
#
# // ------------------------------------------------------------------------------

# =================================================================================
# HEADERS
# =================================================================================

set ( BT_LINUX_HEADERS
	# ASYNC
	"linux/utils/async/LinuxMutex.hpp"
	# METRICS
	"linux/utils/metrics/LinuxLogger.hpp" )

set ( BT_HEADERS ${BT_HEADERS} ${BT_LINUX_HEADERS} )
set ( BT_PUBLIC_HEADERS ${BT_PUBLIC_HEADERS} ${BT_LINUX_HEADERS} )

# =================================================================================
# SOURCES
# =================================================================================

set ( BT_LINUX_SOURCES
	# ASYNC
	"linux/utils/async/LinuxMutex.cpp"
	# METRICS
	"linux/utils/metrics/LinuxLogger.cpp" )

set ( BT_SOURCES ${BT_SOURCES} ${BT_LINUX_SOURCES} )

# =================================================================================
# EXPORT
# =================================================================================

if ( DEFINED BT_HEADERS_EXPORT )
	set ( BT_HEADERS_EXPORT ${BT_HEADERS_EXPORT} ${BT_LINUX_HEADERS} )
	set ( BT_SOURCES_EXPORT ${BT_SOURCES_EXPORT} ${BT_LINUX_SOURCES} )
endif ( DEFINED BT_HEADERS_EXPORT )