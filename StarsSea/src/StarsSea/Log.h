#pragma once

#include "../StarsSea-pch.h"

#include "StarSea-Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace StarsSea
{
	class STARSSEAAPI Log
		{
		public:
			static void Init();

			inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return CoreLogger; }
			inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return ClientLogger; }
		private:
			static std::shared_ptr<spdlog::logger> CoreLogger;
			static std::shared_ptr<spdlog::logger> ClientLogger;
	};
}

// Core log macros

#define STARSEACOREERROR(...)    ::StarsSea::Log::GetCoreLogger()->error(__VA_ARGS__)
#define STARSEACOREINFO(...)     ::StarsSea::Log::GetCoreLogger()->info(__VA_ARGS__)
#define STARSEACOREWARN(...)     ::StarsSea::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define STARSEACORETRACE(...)    ::StarsSea::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define STARSEACOREFATAL(...)    ::StarsSea::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros

#define STARSEAERROR(...)         ::StarsSea::Log::GetClientLogger()->error(__VA_ARGS__)
#define STARSEAINFO(...)          ::StarsSea::Log::GetClientLogger()->info(__VA_ARGS__)
#define STARSEAWARN(...)          ::StarsSea::Log::GetClientLogger()->warn(__VA_ARGS__)
#define STARSEATRACE(...)         ::StarsSea::Log::GetClientLogger()->trace(__VA_ARGS__)
#define STARSEAFATAL(...)         ::StarsSea::Log::GetClientLogger()->critical(__VA_ARGS__)

