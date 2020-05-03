/**
* Copyright © 2020 Denis Z. (code4un@yandex.ru) All rights reserved.
* Authors: Denis Z. (code4un@yandex.ru)
* All rights reserved.
* Language: C++
* License: see LICENSE.txt
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the follolinuxg conditions are met:
* 1. Redistributions of source code must retain the above copyright notice,
* this list of conditions and the follolinuxg disclaimer.
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

#ifndef BT_ANDROID_MUTEX_HPP
#define BT_ANDROID_MUTEX_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include bt::core::Mutex
#ifndef BT_CORE_MUTEX_HPP
#include "../../../core/utils/async/Mutex.hpp"
#endif // !BT_CORE_MUTEX_HPP

// Include C++ STL Lib, required for pthread.
#include <cstdlib>

// Include POSIX pthread
#include <pthread>

// ===========================================================
// TYPES
// ===========================================================

namespace bt
{

	namespace android
	{

		// -----------------------------------------------------------

		/**
		 * @brief
		 * AndroidMutex - mutex implementation for Android API.
		 *
		 * @version 0.1
		**/
		class BT_API AndroidMutex final : public bt::core::Mutex
		{

			// -----------------------------------------------------------

			// ===========================================================
			// META
			// ===========================================================

			BT_CLASS

			// -----------------------------------------------------------

		public:

			// -----------------------------------------------------------

			// ===========================================================
			// CONFIGS
			// ===========================================================

			using bt_native_mutex_t = pthread_mutex_t;

			// -----------------------------------------------------------

		private:

			// -----------------------------------------------------------

			// ===========================================================
			// FIELDS
			// ===========================================================

			/** Platform-specific mutex native-implementation. **/
			bt_native_mutex_t mMutex;

			// ===========================================================
			// DELETED
			// ===========================================================

			AndroidMutex(const AndroidMutex&) = delete;
			AndroidMutex& operator=(const AndroidMutex&) = delete;
			AndroidMutex(AndroidMutex&&) = delete;
			AndroidMutex& operator=(AndroidMutex&&) = delete;

			// -----------------------------------------------------------

		public:

			// -----------------------------------------------------------

			// ===========================================================
			// CONSTRUCTOR
			// ===========================================================

			/**
			 * @brief
			 * AndroidMutex constructor.
			 *
			 * @throws - can throw exception.
			**/
			explicit AndroidMutex();

			// ===========================================================
			// DESTRUCTOR
			// ===========================================================

			/**
			 * @brief
			 * AndroidMutex destructor.
			 *
			 * @throws - no exceptions.
			**/
			virtual ~AndroidMutex() BT_NOEXCEPT;

			// ===========================================================
			// bt::core::IMutex
			// ===========================================================

			/**
			 * @brief
			 * Returns native handler.
			 *
			 * @thread_safety - not thread-safe.
			 * @throws - no exceptions.
			**/
			virtual void* native_handle() BT_NOEXCEPT final;

			// ===========================================================
			// METHODS
			// ===========================================================

			/**
			 * @brief
			 * Tries to lock this mutex.
			 *
			 * @thread_safety - thread-safe (atomic, not thread-lock).
			 * @returns - 'true' if locked, 'false' if failed.
			 * @throws - (!) no exceptions
			**/
			virtual bool try_lock() BT_NOEXCEPT final;

			/**
			 * @brief
			 * Lock this mutex.
			 *
			 * @thread_safety - thread-safe (atomic, no locks).
			 * @throws - can throw exception (self-lock, etc).
			**/
			virtual void lock() final;

			/**
			 * @brief
			 * Unlock this mutex.
			 *
			 * @thread_safety - thread-safe (atomics, no locks).
			 * @throws - no exceptions.
			**/
			virtual void unlock() BT_NOEXCEPT final;

			// -----------------------------------------------------------

		}; /// bt::android::AndroidMutex

		// -----------------------------------------------------------

	} /// bt::android

} /// bt
#define BT_LINUX_MUTEX_DECL

// -----------------------------------------------------------

#endif // !BT_ANDROID_MUTEX_HPP