# // ------------------------------------------------------------------------------
#
# bt_Engine.ECS
#
# // ------------------------------------------------------------------------------

# =================================================================================
# HEADERS
# =================================================================================

set ( BT_ECS_HEADERS
	# BASE
	"ecs/types/ecs_api.hpp"
	"ecs/types/ecs_atomics.hpp"
	"ecs/types/ecs_allocator.hpp"
	"ecs/types/ecs_log.hpp"
	"ecs/types/ecs_numeric.hpp"
	"ecs/types/ecs_vector.hpp"
	"ecs/types/ecs_map.hpp"
	"ecs/types/ecs_mutex.hpp"
	"ecs/types/ecs_memory.hpp"
	"ecs/types/ecs_map.hpp"
	"ecs/types/ecs_deque.hpp"
	"ecs/types/ecs_vector.hpp"
	"ecs/types/ecs_lock.hpp"
	# COMPONENTS
	"ecs/components/Component.hpp"
	"ecs/components/ComponentsManager.hpp"
	# ENTITIES
	"ecs/entities/IEntity.hxx"
	"ecs/entities/Entity.hpp"
	"ecs/entities/EntitiesManager.hpp"
	# EVENTS
	"ecs/events/IEvent.hxx"
	"ecs/events/Event.hpp"
	"ecs/events/EventsManager.hpp"
	# SYSTEMS
	"ecs/systems/ISystem.hxx"
	"ecs/systems/SystemsManager.hpp"
	"ecs/systems/System.hpp"
	# ECS
	"ecs/ecs.hpp" )

set ( BT_HEADERS ${BT_HEADERS} ${BT_ECS_HEADERS} )
set ( BT_PUBLIC_HEADERS ${BT_PUBLIC_HEADERS} ${BT_ECS_HEADERS} )

# =================================================================================
# SOURCES
# =================================================================================

set ( BT_ECS_SOURCES
	"ecs/components/ComponentsManager.cpp"
	# ENTITIES
	"ecs/entities/Entity.cpp"
	"ecs/entities/EntitiesManager.cpp"
	# EVENTS
	"ecs/events/Event.cpp"
	"ecs/events/EventsManager.cpp"
	# SYSTEMS
	"ecs/systems/SystemsManager.cpp"
	"ecs/systems/System.cpp"
	# ECS
	"ecs/ecs.cpp" )

set ( BT_SOURCES ${BT_SOURCES} ${BT_ECS_SOURCES} )

# =================================================================================
# EXPORT
# =================================================================================

if ( DEFINED BT_HEADERS_EXPORT )
	set ( BT_HEADERS_EXPORT ${BT_HEADERS_EXPORT} ${BT_ECS_HEADERS} )
	set ( BT_SOURCES_EXPORT ${BT_SOURCES_EXPORT} ${BT_ECS_SOURCES} )
endif ( DEFINED BT_HEADERS_EXPORT )