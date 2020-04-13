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

#ifndef BT_HPP
#define BT_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// bt API
#ifndef BT_CFG_API_HPP
#include "config/bt_api.hpp"
#endif // !BT_CFG_API_HPP

// ===========================================================
// TYPES
// ===========================================================

namespace bt
{

	// -----------------------------------------------------------

	/**
	 * @brief
	 * BTEngine - main engine class. Handles initialization & termination.
	 * 
	 * @version 0.1
	 * @authors Denis Z. (code4un@yandex.ru)
	**/
	class BT_API BTEngine final
	{

		// -----------------------------------------------------------

		// ===========================================================
		// META
		// ===========================================================

		// -----------------------------------------------------------

	private:

		// -----------------------------------------------------------

		BTEngine(const BTEngine&) = delete;
		BTEngine& operator=(const BTEngine&) = delete;
		BTEngine(BTEngine &&) = delete;
		BTEngine& operator=(BTEngine &&) = delete;

		// ===========================================================
		// CONSTANTS
		// ===========================================================

		// ===========================================================
		// FIELDS
		// ===========================================================

		// ===========================================================
		// CONSTRUCTOR
		// ===========================================================

		/**
		 * @brief
		 * BTEngine default constructor.
		 * 
		 * @throws - can throw exception.
		**/
		explicit BTEngine();

		// ===========================================================
		// GETTERS & SETTERS
		// ===========================================================

		// ===========================================================
		// METHODS
		// ===========================================================

		// -----------------------------------------------------------

	public:

		// -----------------------------------------------------------

		// ===========================================================
		// DESTRUCTOR
		// ===========================================================

		/**
		 * @brief
		 * BTEngine destructor.
		 * 
		 * @throws - can throw exception.
		**/
		virtual ~BTEngine();

		// ===========================================================
		// GETTERS & SETTERS
		// ===========================================================

		// ===========================================================
		// METHODS
		// ===========================================================

		/**
		 * @brief
		 * Initialize btEngine.
		 * 
		 * @thread_safety - main thread only.
		 * @return - 'true' if OK, 'false' if failed.
		 * @throws - can throw exception.
		**/
		static BT_API bool Initialize();

		/**
		 * @brief
		 * Terminate btEngine.
		 * 
		 * @thread_safety - main thread only.
		 * @throws - can throw exception.
		**/
		static BT_API void Terminate();

		// -----------------------------------------------------------

	}; /// bt::BTEngine

	// -----------------------------------------------------------

} /// bt

// -----------------------------------------------------------

#endif // !BT_HPP