/**
* Copyright � 2020 Denis Z. (code4un@yandex.ru) All rights reserved.
* Authors: Denis Z. (code4un@yandex.ru)
* All rights reserved.
* Language: C++
* License: see LICENSE.txt
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
* 1. Redistributions of source code must retain the above copyright notice,
* this list of conditions and the following disclaimer.
* 2. Redistributions in binary form must display the names 'Denis Zyamaev' and
* in the credits of the application, if such credits exist.
* The authors of this work must be notified via email (code4un@yandex.ru) in
* this case of redistribution.
* 3. Neither the name of copyright holders nor the names of its contributors
* may be used to endorse or promote products derived from this software
* without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS
* IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
* THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
* PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS OR CONTRIBUTORS
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
**/

#ifndef BT_ECS_COMPONENT_HPP
#define BT_ECS_COMPONENT_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include ecs::API
#ifndef BT_ECS_API_HPP
#include "../types/ecs_api.hpp"
#endif // !BT_ECS_API_HPP

// Include ecs::numeric
#ifndef BT_ECS_NUMERIC_HPP
#include "../types/ecs_numeric.hpp"
#endif // !BT_ECS_NUMERIC_HPP

// Include ecs::atomic
#ifndef BT_ECS_ATOMIC_HPP
#include "../types/ecs_atomics.hpp"
#endif // !BT_ECS_ATOMIC_HPP

// Include ecs::mutex
#ifndef BT_ECS_MUTEX_HPP
#include "../types/ecs_mutex.hpp"
#endif // !BT_ECS_MUTEX_HPP

// ===========================================================
// TYPES
// ===========================================================

// Enable structure-data (fields, variables) alignment (by compiler) to 1 byte
#pragma pack( push, 1 )

namespace bt
{

	namespace ecs
	{

		// -----------------------------------------------------------

		/**
		 * @brief
		 * Component - data container.
		 * 
		 * @version 0.1
		**/
		struct ECS_API Component
		{

			// -----------------------------------------------------------

			// ===========================================================
			// META
			// ===========================================================

			ECS_STRUCT

			// ===========================================================
			// FIELDS
			// ===========================================================

			/** Component-ID. **/
			const ECSObjectID mID;

			/** Remove flag. If true, users should't use this component. **/
			ecs_abool_t mRemoved;

			/** Mutex. **/
			ecs_mutex_t* const mMutex;

			// ===========================================================
			// CONSTRUCTOR & DESTRUCTOR
			// ===========================================================

			/**
			 * @brief
			 * Component constructor.
			 * 
			 * @param pType - Type-ID.
			 * @param pAsync - 'true' to create mutex.
			 * @throws - no exceptions.
			**/
			explicit Component(const ECSTypeID pType, const bool pAsync) ECS_NOEXCEPT;

			/**
			 * @brief
			 * Component destructor.
			 * 
			 * @throws - no exceptions.
			**/
			virtual ~Component() ECS_NOEXCEPT;

			// ===========================================================
			// GETTERS & SETTERS
			// ===========================================================

			/**
			 * @brief
			 * Returns Type-ID.
			 * 
			 * @thread_safety - not required.
			 * @throws - no exceptions.
			**/
			virtual ECSTypeID getTypeID() const noexcept;

			// -----------------------------------------------------------

		};

		// -----------------------------------------------------------

	} /// bt::ecs

} /// bt

// Restore structure-data alignment to default (8-byte on MSVC)
#pragma pack( pop )

using ecs_Component = bt::ecs::Component;
#define BT_ECS_COMPONENT_DECL

// -----------------------------------------------------------

#endif // !BT_ECS_COMPONENT_HPP