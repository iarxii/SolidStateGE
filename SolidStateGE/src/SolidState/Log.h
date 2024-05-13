#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace SolidState {

	class SOLIDSTATE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger> & GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger> & GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}
/*__VA_ARGS__ is used to import variable arguments we have in our macro (SLD) to our function*/
// Core log macros
#define SLD_CORE_TRACE(...)		::SolidState::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SLD_CORE_INFO(...)		::SolidState::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SLD_CORE_WARN(...)		::SolidState::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SLD_CORE_ERROR(...)		::SolidState::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SLD_CORE_FATAL(...)		::SolidState::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define SLD_TRACE(...)			::SolidState::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SLD_INFO(...)			::SolidState::Log::GetClientLogger()->info(__VA_ARGS__)
#define SLD_WARN(...)			::SolidState::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SLD_ERROR(...)			::SolidState::Log::GetClientLogger()->error(__VA_ARGS__)
#define SLD_FATAL(...)			::SolidState::Log::GetClientLogger()->fatal(__VA_ARGS__)

 