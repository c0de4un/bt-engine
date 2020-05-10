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

#ifndef ECS_ID_MAP_HPP
#define ECS_ID_MAP_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include ecs::IDStorage
#ifndef ECS_ID_STORAGE_HPP
#include "IDStorage.hpp"
#endif // !ECS_ID_STORAGE_HPP

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
		 * IDMap - ID managing storage with type-sorted IDs.
		 *
		 * @version 0.1
		**/
		template <typename K = unsigned int, typename V = unsigned long>
		class ECS_API IDMap final
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

			/** Mutex. **/
			ecs_mutex_t mMutex;

			/** ID Containers. **/
			ecs_map<K, ecs_IDStorage<V>> mIDs;

			// ===========================================================
			// GETTERS & SETTERS
			// ===========================================================

			/**
			 * @brief
			 * Returns IDs container.
			 * 
			 * @thread_safety - thread-lock used.
			 * @throws - can throw exception.
			**/
			ecs_IDStorage<V>& getIDList(const K pKey)
			{
				ecs_lock lock(&mMutex);

				auto pos = mIDs.find(pKey);

				if ( pos != mIDs.cend() )
				{
					ecs_IDStorage<V>& ids = pos->second;
					return ids;
				}

				return mIDs[pKey];
			}

			// ===========================================================
			// DELETED
			// ===========================================================

			IDMap(const IDMap&) = delete;
			IDMap& operator=(const IDMap&) = delete;
			IDMap(IDMap&&) = delete;
			IDMap& operator=(IDMap&&) = delete;

			// -----------------------------------------------------------

		public:

			// -----------------------------------------------------------

			// ===========================================================
			// CONSTRUCTOR & DESTRUCTOR
			// ===========================================================

			/**
			 * @brief
			 * IDMap constructor.
			 * 
			 * @throws - can throw exception.
			**/
			explicit IDMap()
				: mMutex(),
				mIDs()
			{
			}

			/**
			 * @brief
			 * IDMap destructor.
			 * 
			 * @throws - can throw exception.
			**/
			~IDMap()
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
			 * @param pType - ID Type.
			 * @throws - can throw exception.
			**/
			V getAvailableID( const K pType )
			{
				ecs_IDStorage<V>& ids = getIDList(pType);
				return ids.getAvailable();
			}

			// ===========================================================
			// METHODS
			// ===========================================================

			/**
			 * @brief
			 * Returns available ID for reusage.
			 *
			 * @thread_safety - thread-lock used.
			 * @param pType - ID Type.
			 * @param pID - ID to return.
			 * @throws - can throw exception.
			**/
			void releaseID( const K pType, const V pID )
			{
				ecs_IDStorage<V>& ids = getIDList(pType);
				ids.release(pID);
			}

			// -----------------------------------------------------------

		}; /// bt::ecs::IDMap

		// -----------------------------------------------------------

	} /// bt::ecs

} /// bt

template <typename K, typename V>
using ecs_IDMap = bt::ecs::IDMap<K, V>;
#define ECS_ID_MAP_DECL

// -----------------------------------------------------------

#endif // !ECS_ID_MAP_HPP