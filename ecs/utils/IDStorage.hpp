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

#ifndef ECS_ID_STORAGE_HPP
#define ECS_ID_STORAGE_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include ecs::API
#ifndef BT_ECS_API_HPP
#include "../types/ecs_api.hpp"
#endif // !BT_ECS_API_HPP

// Include ecs::mutex
#ifndef BT_ECS_MUTEX_HPP
#include "../types/ecs_mutex.hpp"
#endif // !BT_ECS_MUTEX_HPP

// Include ecs::lock
#ifndef BT_ECS_LOCK_HPP
#include "../types/ecs_lock.hpp"
#endif // !BT_ECS_LOCK_HPP

// Include ecs::map
#ifndef BT_ECS_MAP_HPP
#include "../types/ecs_mutex.hpp"
#endif // !BT_ECS_MAP_HPP

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
		 * IDStorage - template storage utility-class (pool) for IDs (numeric values).
		 * Useful to replace same code, when generation of the unique IDs required (Entities, Meshes, etc).
		 * 
		 * @version 0.1
		**/
		template <typename T>
		class ECS_API IDStorage final
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

			/** Available IDs **/
			ecs_map<T, bool> mIDs;

			/** Mutex. **/
			ecs_mutex_t mMutex;

			// ===========================================================
			// DELETED
			// ===========================================================

			IDStorage(const IDStorage&) = delete;
			IDStorage& operator=(const IDStorage&) = delete;
			IDStorage(IDStorage&&) = delete;
			IDStorage& operator=(IDStorage&&) = delete;

			// -----------------------------------------------------------

		public:

			// -----------------------------------------------------------

			// ===========================================================
			// CONSTRUCTOR & DESTRUCTOR
			// ===========================================================

			/**
			 * @brief
			 * IDStorage constructor.
			 * 
			 * @throws - can throw exception.
			**/
			explicit IDStorage()
				: mIDs(),
				mMutex()
			{
			}

			/**
			 * @brief
			 * IDStorage destructor.
			 *
			 * @throws - can throw exception.
			**/
			~IDStorage()
			{
			}

			// ===========================================================
			// GETTERS & SETTERS
			// ===========================================================

			/**
			 * @brief
			 * Returns available ID.
			 * 
			 * @thread_safety - thread-lock used.
			 * @throws - can throw exception.
			**/
			T getAvailable()
			{
				ecs_lock lock( &mMutex );

				auto pos = mIDs.begin();
				auto end = mIDs.cend();

				while( pos != end )
				{
					if (!pos->second)
					{
						pos->second = true;
						return pos->first;
					}
					pos++;
				}

				const T newId = (T)mIDs.size() + 1;
				mIDs[(size_t)newId] = true;
				return newId;
			}

			// ===========================================================
			// METHODS
			// ===========================================================

			/**
			 * @brief
			 * Returns ID for reusage.
			 *
			 * @thread_safety - thread-lock used.
			 * @throws - can throw exception.
			**/
			void release( T pID )
			{
				ecs_lock lock(&mMutex);
				mIDs[pID] = false;
			}

			// -----------------------------------------------------------

		}; /// bt::ecs::IDStorage

		// -----------------------------------------------------------

	} /// bt::ecs

} /// bt

template <typename T>
using ecs_IDStorage = bt::ecs::IDStorage<T>;
#define ECS_ID_STORAGE_DECL

// -----------------------------------------------------------

#endif // !ECS_ID_STORAGE_HPP