#pragma once

#include "Orange/Core/Base.h"

#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/string_cast.hpp"

// 这将忽略因引入额外头文件引发的所有警告
#pragma warning(push, 0)
	#include <spdlog/spdlog.h>
	#include <spdlog/fmt/ostr.h>
#pragma warning(pop)


namespace Orange
{
	class Log
	{
	public:
		static void Init();

		static Ref<spdlog::logger>& GetCoreLogger() { return sg_CoreLogger; }
		static Ref<spdlog::logger>& GetClientLogger() { return sg_ClientLogger; }
	private:
		static Ref<spdlog::logger> sg_CoreLogger;
		static Ref<spdlog::logger> sg_ClientLogger;
	};
}

template<typename OStream, glm::length_t L, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, const glm::vec<L, T, Q>& vector)
{
	return os << glm::to_string(vector);
}

template<typename OStream, glm::length_t C, glm::length_t R, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, const glm::mat<C, R, T, Q>& matrix)
{
	return os << glm::to_string(matrix);
}

template<typename OStream, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, glm::qua<T, Q> quaternion)
{
	return os << glm::to_string(quaternion);
}

// 内核日志宏函数
#define OG_CORE_TRACE(...)          ::Orange::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define OG_CORE_INFO(...)           ::Orange::Log::GetCoreLogger()->info(__VA_ARGS__)
#define OG_CORE_WARN(...)           ::Orange::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define OG_CORE_ERROR(...)          ::Orange::Log::GetCoreLogger()->error(__VA_ARGS__)
#define OG_CORE_CRITICAL(...)       ::Orange::Log::GetCoreLogger()->critical(__VA_ARGS__)

// 客户端日志宏函数
#define OG_CLIENT_TRACE(...)        ::Orange::Log::GetClientLogger()->trace(__VA_ARGS__)
#define OG_CLIENT_INFO(...)         ::Orange::Log::GetClientLogger()->info(__VA_ARGS__)
#define OG_CLIENT_WARN(...)         ::Orange::Log::GetClientLogger()->warn(__VA_ARGS__)
#define OG_CLIENT_ERROR(...)        ::Orange::Log::GetClientLogger()->error(__VA_ARGS__)
#define OG_CLIENT_CRITICAL(...)     ::Orange::Log::GetClientLogger()->critical(__VA_ARGS__)
