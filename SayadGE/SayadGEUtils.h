#pragma once

// Declspec - C++ microsoft compiler - therefore we need this for windows only

#ifdef SAYADGE_WINDOWS
	#ifdef SAYADGE_LIB
		#define SAYADGE_API __declspec(dllexport)
	#else
		#define SAYADGE_API __declspec(dllimport)
	#endif
#else
	#define SAYADGE_API
#endif

#ifdef SAYADGE_DEBUG
	#define SAYADGE_LOG(x) std::cout << x << std::endl;
#else
	#define SAYADGE_LOG(x)
#endif