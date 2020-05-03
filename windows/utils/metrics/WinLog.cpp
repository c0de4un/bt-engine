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
#ifndef BT_WIN_LOG_HPP
#include "WinLog.hpp"
#endif // !BT_WIN_LOG_HPP

// Include C++ I/O
#include <iostream>

// Windows API
#include <Windows.h>

// Include C++ string
#include <string>

// ===========================================================
// bt::win::WinLog
// ===========================================================

namespace bt
{

	namespace win
	{

		// -----------------------------------------------------------

		// ===========================================================
		// CONSTRUCTOR & DESTRUCTOR
		// ===========================================================

		WinLog::WinLog()
			: BaseLog(),
			mOutBuf()
		{
			// UTF-8 Support by Default.
			SetConsoleOutputCP(CP_UTF8);
			setvbuf(stdout, nullptr, _IONBF, 0); // @see http://www.cplusplus.com/reference/cstdio/setvbuf/
			std::cout.rdbuf(&mOutBuf);
		}

		WinLog::~WinLog()
		{
		}

		// ===========================================================
		// BaseLog
		// ===========================================================

		void WinLog::Info(const char* const pMsg)
		{
			std::string str = u8"INFO ";
			str += pMsg;

			std::cout << str << std::endl;
			OutputDebugStringA( str.c_str() );
		}

		void WinLog::Info_W(const wchar_t* const pMsg)
		{
			std::wstring str = L"INFO ";
			str += pMsg;

			std::wcout << str << std::endl;
			OutputDebugStringW(str.c_str());
		}

		void WinLog::Debug(const char* const pMsg)
		{
			std::string str = u8"DEBUG ";
			str += pMsg;

			std::cout << str << std::endl;
			OutputDebugStringA(str.c_str());
		}

		void WinLog::Debug_W(const wchar_t* const pMsg)
		{
			std::wstring str = L"INFO ";
			str += pMsg;

			std::wcout << str << std::endl;
			OutputDebugStringW(str.c_str());
		}
		
		void WinLog::Warning(const char* const pMsg)
		{
			std::string str = u8"WARNING ";
			str += pMsg;

			std::cout << str << std::endl;
			OutputDebugStringA(str.c_str());
		}

		void WinLog::Warning_W(const wchar_t* const pMsg)
		{
			std::wstring str = L"INFO ";
			str += pMsg;

			std::wcout << str << std::endl;
			OutputDebugStringW(str.c_str());
		}

		void WinLog::Error(const char* const pMsg)
		{
			std::string str = u8"ERROR ";
			str += pMsg;

			std::cout << str << std::endl;
			OutputDebugStringA(str.c_str());
		}

		void WinLog::Error_W(const wchar_t* const pMsg)
		{
			std::wstring str = L"INFO ";
			str += pMsg;

			std::wcout << str << std::endl;
			OutputDebugStringW(str.c_str());
		}

		// -----------------------------------------------------------

	} /// bt::win

} /// bt

// -----------------------------------------------------------