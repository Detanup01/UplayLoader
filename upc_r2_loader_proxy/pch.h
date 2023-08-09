// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

// add headers that you want to pre-compile here
#include "framework.h"
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#pragma warning(disable : 4996).
#define EXPORT extern "C" _declspec(dllexport)

template<typename T>
T FnCast(FARPROC fnToCast, T pFnCastTo)
{
	return (T)fnToCast;
}

#define PRINT_DEBUG(a, ...) do {FILE *t = fopen("upc_r2_proxy_LOG.txt", "a"); fprintf(t, "%u " a, GetCurrentThreadId(), __VA_ARGS__); fclose(t);} while (0)

#ifdef _WIN64
constexpr auto ORIG_DLL = L"upc_r2_loader64_o.dll";
#else
constexpr auto ORIG_DLL = L"upc_r2_loader_o.dll";
#endif

#endif //PCH_H
