#pragma once

#include "Orange/Core/PlatformDetection.h"

#include <memory>

#ifdef OG_DEBUG
	#if defined(OG_PLATFORM_WINDOWS)
		#define OG_DEBUGBREAK() __debugbreak()
	#elif defined(OG_PLATFORM_LINUX)
		#include <signal.h>
		#define OG_DEBUGBREAK() raise(SIGTRAP)
	#else
		#error "当前平台暂不支持调试！"
	#endif // defined(OG_PLATFORM_WINDOWS)
	#define OG_ENABLE_ASSERTS
#else
	#define OG_DEBUGBREAK()
#endif // OG_DEBUG


#define OG_EXPAND_MACRO(x) x
#define OG_STRINGIFY_MACRO(x) #x

#define BIT(x) (1 << x)

#define OG_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace Orange
{
	template <typename T>
	using Scope = std::unique_ptr<T>;

	template <typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template <typename T>
	using Ref = std::shared_ptr<T>;

	template <typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}

#include "Orange/Core/Log.h"
#include "Orange/Core/Assert.h"
