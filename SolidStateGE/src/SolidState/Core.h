#pragma once

#ifdef SLD_PLATFORM_WINDOWS
	#ifdef SLD_BUILD_DLL
		#define SOLIDSTATE_API _declspec(dllexport)
	#else
		#define SOLIDSTATE_API _declspec(dllimport)
	#endif // HZ_BUILD_DLL
#else
	#error SolidState only supports Windows!
#endif // HZ_PLATFORM_WINDOWS
