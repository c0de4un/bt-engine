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

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// HEADER
#ifndef BT_WIN_SPIN_LOCK_HPP
#include "WinSpinLock.hpp"
#endif // !BT_WIN_SPIN_LOCK_HPP

// Include bt::core::IMutex
#ifndef BT_CORE_I_MUTEX_HXX
#include "../../../core/utils/async/IMutex.hxx"
#endif // !BT_CORE_I_MUTEX_HXX

// DEBUG
#if defined(DEBUG) || defined(BT_DEBUG)

// Include bt::assert
#ifndef BT_CFG_ASSERTIONS_HPP
#include "../../../config/bt_assertions.hpp"
#endif // !BT_CFG_ASSERTIONS_HPP

#endif
// DEBUG

// ===========================================================
// bt::win::WinSpinLock
// ===========================================================

namespace bt
{

	namespace win
	{

		// -----------------------------------------------------------

		// ===========================================================
		// CONSTRUCTOR & DESTRUCTOR
		// ===========================================================

		WinSpinLock::WinSpinLock(bt_IMutex* const pMutex, const bool defferLock)
			: BaseLock( pMutex, defferLock )
		{
#ifdef BT_DEBUG // DEBUG
			if ( !defferLock )
			{
				bt_assert(pMutex && "BaseLock - mutex is null !");
			}
#endif // DEBUG

			if ( !defferLock && mMutex )
				this->lock();
		}

		/**
		 * @brief
		 * WinSpinLock destructor.
		 *
		 * @throws - no exceptions.
		**/
		WinSpinLock::~WinSpinLock() BT_NOEXCEPT
		{
			this->unlock();
		}

		// ===========================================================
		// GETTERS & SETTERS
		// ===========================================================

		bool WinSpinLock::isLocked() const BT_NOEXCEPT
		{ return mMutex ? mMutex->isLocked() : false; }

		// ===========================================================
		// bt::core::ILock
		// ===========================================================

		bool WinSpinLock::try_lock(bt_IMutex* const pMutex) BT_NOEXCEPT
		{

			if ( pMutex )
			{
				mMutex->unlock();
				mMutex = pMutex;
			}

#ifdef BT_DEBUG // DEBUG
			bt_assert( mMutex && "WinSpinLock::try_lock - null mutex !");
#endif // DEBUG

			for ( unsigned char i = 0; i < SPIN_LIMIT; i++ )
			{
				if ( !mMutex->isLocked() )
					break;
			}
			return mMutex->try_lock();
		}

		void WinSpinLock::lock(bt_IMutex* const pMutex)
		{

			if ( pMutex )
			{
				mMutex->unlock();
				mMutex = pMutex;
			}

#ifdef BT_DEBUG // DEBUG
			bt_assert(mMutex && "WinSpinLock::lock - null mutex !");
#endif // DEBUG

			for ( unsigned char i = 0; i < SPIN_LIMIT; i++ )
			{
				if ( !mMutex->isLocked() )
					break;
			}
			mMutex->lock();
		}

		void WinSpinLock::unlock() BT_NOEXCEPT
		{
			if ( mMutex )
				mMutex->unlock();
		}

		// -----------------------------------------------------------

	} /// bt::win

} /// bt

// -----------------------------------------------------------