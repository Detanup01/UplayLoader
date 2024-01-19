// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

extern "C" __declspec(dllexport) LONG WINAPI WinVerifyTrust(HWND hwnd, GUID* pgActionID, LPVOID pWVTData)
{
    return 0;
}



BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    return TRUE;
}

