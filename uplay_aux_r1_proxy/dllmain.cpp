// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

template<typename T>
T FnCast(FARPROC fnToCast, T pFnCastTo)
{
    return (T)fnToCast;
}

HMODULE originalDLL = nullptr;

#define GET_PROXY_FUNC(FUNC) \
	static auto proxyFunc = FnCast(GetProcAddress(originalDLL, #FUNC), FUNC);

EXPORT int UPLAY_GetActivate(int a1, unsigned int* a2, unsigned int a3, __int64** a4)
{
    std::ofstream myfile;
    myfile.open("UPLAY_GetActivate_log.txt", std::ios::app);
#ifdef _WIN64
    originalDLL = LoadLibraryW(L"uplay_aux_r164_o.dll");
#else
    originalDLL = LoadLibraryW(L"uplay_aux_r1_o.dll");
#endif
    GET_PROXY_FUNC(UPLAY_GetActivate);
    myfile << "function starts:.\n";
    myfile << "a1: " << a1 << "\n";
    myfile << "a2: " << a2 << "\n";
    myfile << "*a2: " << *a2 << "\n";
    myfile << "a3: " << a3 << "\n";
    myfile << "a4: " << a4 << "\n";
    myfile << "*a4: " << *a4 << "\n";
    int returned = proxyFunc(a1, a2, a3, a4);
    myfile << "Function Called!\n";
    myfile << "a1: " << a1 << "\n";
    myfile << "a2: " << a2 << "\n";
    myfile << "*a2: " << *a2 << "\n";
    myfile << "a3: " << a3 << "\n";
    myfile << "a4: " << a4 << "\n";
    myfile << "*a4: " << *a4 << "\n";
    myfile << "**a4: " << **a4 << "\n";
    /*
    myfile << "*a4[0]: " << *a4[0] << "\n";
    myfile << "*a4[1]: " << *a4[1] << "\n";
    myfile << "*a4[2]: " << *a4[2] << "\n";
    */
    myfile << "ret: " << returned << "\n";
    myfile.close();
    return returned;
}
