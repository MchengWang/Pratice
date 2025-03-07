#include "ogpch.h"

#include "Orange/Core/Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace Orange
{
	Ref<spdlog::logger> Log::sg_CoreLogger;
	Ref<spdlog::logger> Log::sg_ClientLogger;

	void Log::Init()
	{
		std::vector<spdlog::sink_ptr> logSinks;
		logSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
		logSinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("Orange.log", true));

		logSinks[0]->set_pattern("%^[%T] %n: %v%$");
		logSinks[1]->set_pattern("[%T] [%l] %n: %v");

		sg_CoreLogger = std::make_shared<spdlog::logger>("ORANGE", begin(logSinks), end(logSinks));
		spdlog::register_logger(sg_CoreLogger);
		sg_CoreLogger->set_level(spdlog::level::trace);
		sg_CoreLogger->flush_on(spdlog::level::trace);

		sg_ClientLogger = std::make_shared<spdlog::logger>("APP", begin(logSinks), end(logSinks));
		spdlog::register_logger(sg_ClientLogger);
		sg_ClientLogger->set_level(spdlog::level::trace);
		sg_ClientLogger->flush_on(spdlog::level::trace);
	}
}
