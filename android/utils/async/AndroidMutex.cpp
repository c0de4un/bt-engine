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

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// HEADER
#ifndef BT_ANDROID_MUTEX_HPP
#include "AndroidMutex.hpp"
#endif // !BT_ANDROID_MUTEX_HPP

// ===========================================================
// bt::android::AndroidMutex
// ===========================================================

namespace bt
{

	namespace android
	{

		// -----------------------------------------------------------

		// ===========================================================
		// CONSTRUCTOR
		// ===========================================================

		AndroidMutex::AndroidMutex()
			: Mutex(),
			mMutex()
		{
			pthread_mutex_init(&mMutex, nullptr);
		}

		// ===========================================================
		// DESTRUCTOR
		// ===========================================================

		AndroidMutex::~AndroidMutex() BT_NOEXCEPT
		{
			pthread_mutex_destroy(&mMutex);
		}

		// ===========================================================
		// bt::core::IMutex
		// ===========================================================

		void* AndroidMutex::native_handle() BT_NOEXCEPT
		{
			return &mMutex;
		}

		// ===========================================================
		// METHODS
		// ===========================================================

		bool AndroidMutex::try_lock() BT_NOEXCEPT
		{
			if ( mLockedFlag )
				return false;

			AndroidMutex::lock();
		}

		void AndroidMutex::lock()
		{
			mLockedFlag = true;
			pthread_mutex_lock(&mMutex);
		}

		void AndroidMutex::unlock() BT_NOEXCEPT
		{
			mLockedFlag = false;
			pthread_mutex_unlock(&mMutex);
		}

		// -----------------------------------------------------------

	} /// bt::android

} /// bt

// -----------------------------------------------------------