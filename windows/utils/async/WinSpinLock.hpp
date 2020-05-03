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

#ifndef BT_WIN_SPIN_LOCK_HPP
#define BT_WIN_SPIN_LOCK_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include bt::core::WinSpinLock
#ifndef BT_CORE_BASE_LOCK_HPP
#include "../../../core/utils/async/BaseLock.hpp"
#endif // !BT_CORE_BASE_LOCK_HPP

// ===========================================================
// TYPES
// ===========================================================

namespace bt
{

	namespace win
	{

		// -----------------------------------------------------------

		/**
		 * @brief
		 * WinSpinLock - spin-based thread-lock for Windows API.
		 * 
		 * @version 0.1
		**/
		class BT_API WinSpinLock final : public btBaseLock
		{

			// -----------------------------------------------------------

			// ===========================================================
			// META
			// ===========================================================

			BT_CLASS

			// -----------------------------------------------------------

		private:

			// -----------------------------------------------------------

			// ===========================================================
			// CONSTANTS
			// ===========================================================

			static constexpr const unsigned char SPIN_LIMIT = 2;

			// ===========================================================
			// DELETED
			// ===========================================================

			WinSpinLock(const WinSpinLock&) = delete;
			WinSpinLock& operator=(const WinSpinLock&) = delete;
			WinSpinLock(WinSpinLock&&) = delete;
			WinSpinLock& operator=(WinSpinLock&&) = delete;

			// -----------------------------------------------------------

		public:

			// -----------------------------------------------------------

			// ===========================================================
			// CONSTRUCTOR & DESTRUCTOR
			// ===========================================================

			/**
			 * @brief
			 * WinSpinLock constructor.
			 *
			 * @param pMutex - mutex to store. Automatically unlocked, not deleted (instance not managed).
			 * @param defferLock - 'false' to lock mutex, 'true' to delay until #lock called.
			 * @throws - no exceptions.
			**/
			explicit WinSpinLock(btIMutex* const pMutex = nullptr, const bool defferLock = true);

			/**
			 * @brief
			 * WinSpinLock destructor.
			 *
			 * @throws - no exceptions.
			**/
			virtual ~WinSpinLock() BT_NOEXCEPT;

			// ===========================================================
			// GETTERS & SETTERS
			// ===========================================================

			/**
			 * @brief
			 * Check if this lock is locked.
			 *
			 * @thread_safety - thread-safe (atomic, not thread-lock).
			 * @throws - no exceptions.
			**/
			virtual bool isLocked() const BT_NOEXCEPT final;

			// ===========================================================
			// bt::core::ILock
			// ===========================================================

			/**
			 * @brief
			 * Tries to lock this lock.
			 *
			 * @thread_safety - thread-safe (atomic, not thread-lock).
			 * @returns - 'true' if locked, 'false' if failed.
			 * @throws - (!) no exceptions
			**/
			virtual bool try_lock(btIMutex* const pMutex = nullptr) BT_NOEXCEPT final;

			/**
			 * @brief
			 * Lock this lock.
			 *
			 * @thread_safety - thread-safe (atomic, no locks).
			 * @throws - can throw exception (self-lock, etc).
			**/
			virtual void lock(btIMutex* const pMutex = nullptr) final;

			/**
			 * @brief
			 * Unlock this lock.
			 *
			 * @thread_safety - thread-safe (atomics, no locks).
			 * @throws - no exceptions.
			**/
			virtual void unlock() BT_NOEXCEPT final;

			// -----------------------------------------------------------

		}; /// bt::win::WinSpinLock

		// -----------------------------------------------------------

	} /// bt::win

} /// bt
using btWinSpinLock = bt::win::WinSpinLock;
#define BT_WIN_SPIN_LOCK_DECL

// -----------------------------------------------------------

#endif // !BT_WIN_SPIN_LOCK_HPP