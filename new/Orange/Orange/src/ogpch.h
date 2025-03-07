#pragma once

#include "Orange/Core/PlatformDetection.h"

#ifdef OG_PLATFORM_WINDOWS
	#ifndef NOMINMAX
		#define NOMINMAX
	#endif // !NOMINMAX
#endif // OG_PLATFORM_WINDOWS

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "Orange/Core/Base.h"

#include "Orange/Core/Log.h"

#include "Orange/Debug/Instrumentor.h"

#ifdef OG_PLATFORM_WINDOWS
	#include <Windows.h>
#endif // OG_PLATFORM_WINDOWS
