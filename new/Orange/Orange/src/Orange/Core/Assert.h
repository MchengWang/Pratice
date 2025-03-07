#pragma once

#include "Orange/Core/Base.h"
#include "Orange/Core/Log.h"
#include <filesystem>

#ifdef OG_ENABLE_ASSERTS

	// 或者，我们可以对 “WITH_MSG” 和 “NO_MSG” 使用相同的 “default” 消息，并且
	// 通过连接格式字符串而不是将格式包含在默认消息中，为自定义格式提供支持
	#define OG_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { OG##type##ERROR(msg, __VA_ARGS__); OG_DEBUGBREAK(); } }
	#define OG_INTERNAL_ASSERT_WITH_MSG(type, check, ...) OG_INTERNAL_ASSERT_IMPL(type, check, "断言失败: {0}", __VA_ARGS__)
	#define OG_INTERNAL_ASSERT_NO_MSG(type, check) OG_INTERNAL_ASSERT_IMPL(type, check, "断言 '{0}' 在 {1}：{2} 失败", OG_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)
	#define OG_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
	#define OG_INTERNAL_ASSERT_GET_MACRO(...) OG_EXPAND_MACRO( OG_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, OG_INTERNAL_ASSERT_WITH_MSG, OG_INTERNAL_ASSERT_NO_MSG) )
	// 当前至少接受 condition 和一个可选的附加参数（消息）
	#define OG_ASSERT(...) OG_EXPAND_MACRO( OG_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
	#define OG_CORE_ASSERT(...) OG_EXPAND_MACRO( OG_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
	#define OG_ASSERT(...)
	#define OG_CORE_ASSERT(...)
#endif
