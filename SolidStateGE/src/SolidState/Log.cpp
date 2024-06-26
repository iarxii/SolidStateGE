#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace SolidState {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$"); 
		/* %^ = *color of severity* | [%T] = timestamp | %n = name of the logger (core/client) | %v%$ = message*/

		s_CoreLogger = spdlog::stdout_color_mt("SOLIDSTATE");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}