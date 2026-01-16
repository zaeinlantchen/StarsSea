#pragma once

#include "../StarsSea-pch.h"

#ifdef STARSSEAPLATFORMWINDOWS
	#ifdef STARSSEABUILDDLL
		#define STARSSEAAPI __declspec(dllexport)
	#else
		#define STARSSEAAPI __declspec(dllimport)
	#endif
#else
	#error StarsSea only supports Windows!
#endif

#ifdef STARSSEAENABLEASSERTS
	#define STARSEAASSERT(x, ...) { if(!(x)) { STARSEAERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define STARSEACOREASSERT(x, ...) { if(!(x)) { STARSEACOREERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define STARSEAASSERT(x, ...)
	#define STARSEACOREASSERT(x, ...)
#endif 


#define BIT(x) (1 << x)

#define STARSSEABINDEVENTFN(fn) std::bind(&fn, this, std::placeholders::_1)