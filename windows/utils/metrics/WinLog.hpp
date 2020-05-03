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

#ifndef BT_WIN_LOG_HPP
#define BT_WIN_LOG_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include bt::core::BaseLog
#ifndef BT_CORE_BASE_LOG_HPP
#include "../../../core/utils/metrics/BaseLog.hpp"
#endif // !BT_CORE_BASE_LOG_HPP

// Include stringbuf
#include <sstream> // stringbuf

// ===========================================================
// TYPES
// ===========================================================

namespace bt
{

	namespace win
	{

		// -----------------------------------------------------------

		// -----------------------------------------------------------

		/**
		 * @see https://stackoverflow.com/questions/45575863/how-to-print-utf-8-strings-to-stdcout-on-windows
		**/
		class MBuf final : public std::stringbuf
		{

		public:

			// -----------------------------------------------------------

			int sync()
			{
				std::fputs(str().c_str(), stdout);
				str("");
				return 0;
			}

			// -----------------------------------------------------------

		}; /// c0de4un::MBuf

		// -----------------------------------------------------------

		/**
		 * @brief
		 * WinLog - default logger for Windows.
		 *
		 * @version 0.1
		 * @authors Denis Z. (code4un@yandex.ru)
		**/
		class WinLog final : public btBaseLog
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
			// FIELDS
			// ===========================================================

			/** Output Buffer **/
			MBuf mOutBuf;

			// -----------------------------------------------------------

		protected:

			// -----------------------------------------------------------

			// ===========================================================
			// DELETED
			// ===========================================================

			WinLog(const WinLog&) = delete;
			WinLog& operator=(const WinLog&) = delete;
			WinLog(WinLog&&) = delete;
			WinLog& operator=(WinLog&&) = delete;

			// ===========================================================
			// BaseLog
			// ===========================================================

			/**
			 * @brief
			 *
			 * Print INFO-Level Log-message.
			 *
			 * @thread_safety - thread-safe.
			 * @param pMsg - Log-Message to print.
			 * @throws - can throw exception.
			**/
			virtual void Info(const char* const pMsg) final;

			/**
			 * @brief
			 *
			 * Print INFO-Level Log-message.
			 *
			 * @thread_safety - thread-safe.
			 * @param pMsg - Log-Message to print.
			 * @throws - can throw exception.
			**/
			virtual void Info_W(const wchar_t* const pMsg) final;

			/**
			 * @brief
			 *
			 * Print DEBUG-Level Log-message.
			 *
			 * @thread_safety - thread-safe.
			 * @param pMsg - Log-Message to print.
			 * @throws - can throw exception.
			**/
			virtual void Debug(const char* const pMsg) final;

			/**
			 * @brief
			 *
			 * Print DEBUG-Level Log-message.
			 *
			 * @thread_safety - thread-safe.
			 * @param pMsg - Log-Message to print.
			 * @throws - can throw exception.
			**/
			virtual void Debug_W(const wchar_t* const pMsg) final;

			/**
			 * @brief
			 *
			 * Print WARNING-Level Log-message.
			 *
			 * @thread_safety - thread-safe.
			 * @param pMsg - Log-Message to print.
			 * @throws - can throw exception.
			**/
			virtual void Warning(const char* const pMsg) final;

			/**
			 * @brief
			 *
			 * Print WARNING-Level Log-message.
			 *
			 * @thread_safety - thread-safe.
			 * @param pMsg - Log-Message to print.
			 * @throws - can throw exception.
			**/
			virtual void Warning_W(const wchar_t* const pMsg) final;

			/**
			 * @brief
			 *
			 * Print ERROR-Level Log-message.
			 *
			 * @thread_safety - thread-safe.
			 * @param pMsg - Log-Message to print.
			 * @throws - can throw exception.
			**/
			virtual void Error(const char* const pMsg) final;

			/**
			 * @brief
			 *
			 * Print ERROR-Level Log-message.
			 *
			 * @thread_safety - thread-safe.
			 * @param pMsg - Log-Message to print.
			 * @throws - can throw exception.
			**/
			virtual void Error_W(const wchar_t* const pMsg) final;

			// -----------------------------------------------------------

		public:

			// -----------------------------------------------------------

			// ===========================================================
			// CONSTRUCTOR & DESTRUCTOR
			// ===========================================================

			/**
			 * @brief
			 * WinLog constructor.
			 *
			 * @throws - can throw exception.
			**/
			explicit WinLog();

			/**
			 * @brief
			 * WinLog destructor.
			 * 
			 * @throws - no exceptions.
			**/
			virtual ~WinLog();

			// -----------------------------------------------------------

		}; /// bt::win::WinLog

		// -----------------------------------------------------------

	} /// bt::win

} /// bt

// -----------------------------------------------------------

#endif // !BT_WIN_LOG_HPP