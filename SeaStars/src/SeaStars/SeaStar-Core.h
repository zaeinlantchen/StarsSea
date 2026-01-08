#pragma once


#ifdef SEASTARS_PLATFORM_WINDOWS
	#ifdef SEASTARS_BUILD_DLL
		#define SEASTARS_API __declspec(dllexport)
	#else
		#define SEASTARS_API __declspec(dllimport)
	#endif
#else
	#error SeaStars only supports Windows!
#endif