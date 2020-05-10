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

#ifndef BT_CFG_NUMERIC_HPP
#define BT_CFG_NUMERIC_HPP

// -----------------------------------------------------------

// ===========================================================
// CONFIGS
// ===========================================================

// PLATFORM
#if defined( BT_ANDROID ) || defined( BT_LINUX ) || defined( BT_WINDOWS )

// Include C++ limits
#include <limits>

using bt_int8_t = char;
using bt_uint8_t = unsigned char;
using bt_int16_t = short;
using bt_uint16_t = unsigned short;
using bt_int32_t = int;
using bt_uint32_t = unsigned int;
using bt_int64_t = long;
using bt_uint64_t = unsigned long;
using bt_float_t = double;
using bt_double_t = double;
using bt_real_t = double;

using bt_size_t = std::size_t;

#else
#error "bt_numeric.hpp - platform not detected, configuration required."
#endif
// PLATFORM

// -----------------------------------------------------------

#endif // !BT_CFG_NUMERIC_HPP