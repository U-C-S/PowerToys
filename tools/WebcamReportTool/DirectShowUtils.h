#pragma once
#include <initguid.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <dshow.h>

// disable warning 26471 - Don't use reinterpret_cast. A cast from void* can use static_cast
// disable warning 26492 - Don't use const_cast to cast away const on winrt
// Disable 26497 for winrt - This function function-name could be marked constexpr if compile-time evaluation is desired.
#pragma warning(push)
#pragma warning(disable : 26471 26492 26497)
#include <wil/com.h>
#pragma warning(push)

#include <winrt/Windows.Foundation.h>

#include <vector>
#include <fstream>

std::ofstream& log();

#define TRACE log() << __FUNCTION__ << '\n';
#define LOG(msg) log() << msg << '\n';

void DeleteMediaTypeHelper(AM_MEDIA_TYPE* pmt);

using unique_media_type_ptr =
    wistd::unique_ptr<AM_MEDIA_TYPE, wil::function_deleter<decltype(&DeleteMediaTypeHelper), DeleteMediaTypeHelper>>;
