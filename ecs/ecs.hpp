/**
* Copyright © 2020 Denis Z. (code4un@yandex.ru) All rights reserved.
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

#ifndef BT_ECS_HPP
#define BT_ECS_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include ecs::API
#ifndef BT_ECS_API_HPP
#include "types/ecs_api.hpp"
#endif // !BT_ECS_API_HPP

// Include ecs::memory
#ifndef BT_ECS_MEMORY_HPP
#include "types/ecs_memory.hpp"
#endif // !BT_ECS_MEMORY_HPP

// ===========================================================
// FORWARD-DECLARATIONS
// ===========================================================



// ===========================================================
// TYPES
// ===========================================================

namespace bt
{

	namespace ecs
	{

		// -----------------------------------------------------------

		/**
		 * @brief
		 * ECS - ECS main class.
		 * 
		 * @version 0.1
		**/
		class ECS_API ECS
		{

			// -----------------------------------------------------------

			// ===========================================================
			// META
			// ===========================================================

			ECS_CLASS

			// -----------------------------------------------------------

		private:

			// -----------------------------------------------------------

			// ===========================================================
			// FIELDS
			// ===========================================================

			// ===========================================================
			// CONSTRUCTOR
			// ===========================================================

			/**
			 * @brief
			 * ECS constructor.
			 * 
			 * @throws - no exceptions.
			**/
			explicit ECS() noexcept;

			// ===========================================================
			// DELETED
			// ===========================================================

			ECS(const ECS&) = delete;
			ECS& operator=(const ECS&) = delete;
			ECS(ECS&&) = delete;
			ECS& operator=(ECS&&) = delete;

			// -----------------------------------------------------------

		public:

			// -----------------------------------------------------------

			// ===========================================================
			// DESTRUCTOR
			// ===========================================================

			/**
			 * @brief
			 * ECS destructor.
			 * 
			 * @throws - no exceptions.
			**/
			~ECS() noexcept;

			// ===========================================================
			// GETTERS & SETTERS
			// ===========================================================



			// ===========================================================
			// METHODS
			// ===========================================================

			/**
			 * @brief
			 * Initialize ECS.
			 * 
			 * @thread_safety - main thread-only.
			 * @throws - can throw exception.
			**/
			static bool Initialize();

			/**
			 * @brief
			 * Terminate ECS.
			 * 
			 * @thread_safety - main thread-only.
			 * @throws - can throw exception.
			**/
			static void Terminate();

			// -----------------------------------------------------------

		}; /// bt::ecs::ECS

		// -----------------------------------------------------------

	} /// bt::ecs

} /// bt
using ECS = bt::ecs::ECS;

// -----------------------------------------------------------

#endif // !BT_ECS_HPP