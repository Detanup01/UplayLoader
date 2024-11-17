// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <stdint.h>
#include <emmintrin.h>
#include <string>
#include <cstring>
#include <sstream>

HMODULE originalDLL = nullptr;
HMODULE this_hModule = nullptr;
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
    this_hModule = hModule;
#ifdef _WIN64
    originalDLL = LoadLibraryW(L"uplay_aux_r164_o.dll");
#else
    originalDLL = LoadLibraryW(L"uplay_aux_r1_o.dll");
#endif
    return TRUE;
}

template <typename T>
std::string __m128i_toString(const __m128i var) {
    std::stringstream sstr;
    T values[16 / sizeof(T)];
    std::memcpy(values, &var, sizeof(values)); //See discussion below
    if (sizeof(T) == 1) {
        for (unsigned int i = 0; i < sizeof(__m128i); i++) { //C++11: Range for also possible
            sstr << (int)values[i] << " ";
        }
    }
    else {
        for (unsigned int i = 0; i < sizeof(__m128i) / sizeof(T); i++) { //C++11: Range for also possible
            sstr << values[i] << " ";
        }
    }
    return sstr.str();
}

template<typename T>
T FnCast(FARPROC fnToCast, T pFnCastTo)
{
    return (T)fnToCast;
}

struct denuvo_functions_vtable_t
{
    void* GetInternal8;
    void* return0;
    void* GetCachedOrFreshToken;
    void* InvalidateCachedToken;
    void* GetBuffer;
    void* NewThread_GetBurnTicketReq;
    void* GetThread;
};


denuvo_functions_vtable_t real_denuvo_functions = {};

struct DenuvoFunctionVTablePTR
{
    struct denuvo_functions_vtable_t* vtable;
};

struct call_offset_t
{
    struct DenuvoFunctionVTablePTR* something;
};

__int64 __fastcall GetInternal8(__int64 internal_ptr) // AKA sub_18000DF7B
{
    __int64 (*internal_8)(__int64 internal_ptr) = (__int64 (*)(__int64 internal_ptr))real_denuvo_functions.GetInternal8;
    std::ofstream myfile;
    myfile.open("UPLAY_GetActivate_GetInternal8_log.txt", std::ios::app);
    myfile << "\n";
    myfile << "GetInternal8!" << GetCurrentThreadId() << "\n";
    myfile << "internal_ptr:" << std::hex << internal_ptr << "\n";
    auto ret = internal_8(internal_ptr);
    myfile << "internal_DWORD:" << *(DWORD*)(internal_ptr + 8) << "\n";
    myfile << "ret:" << ret << "\n";
    myfile.close();
    return ret;
}

__int64 __fastcall return0() // AKA sub_180001DF2
{
    return 0;
}

char __fastcall GetCachedOrFreshToken(__int64 internal_ptr, __int64 token_buffer_ptr, int notused) // AKA sub_18000CEE6
{
    char (*_GetCachedOrFreshToken)(__int64 internal_ptr, __int64 token_buffer_ptr, int notused) = (char (*)(__int64 internal_ptr, __int64 token_buffer_ptr, int notused))real_denuvo_functions.GetCachedOrFreshToken;
    std::ofstream myfile;
    myfile.open("UPLAY_GetActivate_GetCachedOrFreshToken_log.txt", std::ios::app);
    myfile << "\n";
    myfile << "GetCachedOrFreshToken!" << GetCurrentThreadId() << "\n";
    myfile << "internal_ptr:" << std::hex << internal_ptr << "\n";
    myfile << "token_buffer_ptr:" << std::hex << token_buffer_ptr << "\n";
    myfile << "notused:" << notused << "\n";
    auto ret = _GetCachedOrFreshToken(internal_ptr, token_buffer_ptr, notused);
    myfile << "internal_DWORD:" << *(DWORD*)(internal_ptr + 8) << "\n";
    myfile << "ret:" << int(ret) << "\n";
    myfile.close();
    return ret;
}

void __fastcall InvalidateCachedToken(__int64 internal_ptr) // sub_180002DF6
{
    void (*_InvalidateCachedToken)(__int64 internal_ptr) = (void (*)(__int64 internal_ptr))real_denuvo_functions.InvalidateCachedToken;
    std::ofstream myfile;
    myfile.open("UPLAY_GetActivate_InvalidateCachedToken_log.txt", std::ios::app);
    myfile << "\n";
    myfile << "InvalidateCachedToken!" << GetCurrentThreadId() << "\n";
    myfile << "internal_ptr:" << std::hex << internal_ptr << "\n";
    myfile.close();
    _InvalidateCachedToken(internal_ptr);
    //Reset(internal_ptr);
}

__int64 __fastcall Reset(__int64 internal_ptr) // sub_180002DF6
{
    *(DWORD*)(internal_ptr + 8) = 0;
    auto buffer = *(void***)(internal_ptr + 16);
    if (buffer)
    {
        free(*buffer);
        free(buffer);
        *(QWORD*)(internal_ptr + 16) = 0;
    }
    return 1;
}
__int64 __fastcall GetBuffer(__int64 internal_ptr, QWORD* out_iternal_8) // AKA sub_180005B05
{
    __int64 (*_GetBuffer)(__int64 internal_ptr, QWORD * out_iternal_8) = (__int64 (*)(__int64 internal_ptr, QWORD * out_iternal_8))real_denuvo_functions.GetCachedOrFreshToken;
    std::ofstream myfile;
    myfile.open("UPLAY_GetActivate_GetBuffer_log.txt", std::ios::app);
    myfile << "\n";
    myfile << "GetBuffer!" << GetCurrentThreadId() << "\n";
    myfile << "internal_ptr:" << std::hex << internal_ptr << "\n";
    myfile << "token_buffer_ptr:" << std::hex << out_iternal_8 << "\n";
    auto ret = _GetBuffer(internal_ptr, out_iternal_8);
    myfile << "internal_DWORD:" << *(DWORD*)(internal_ptr + 8) << "\n";
    myfile << "*out_iternal_8:" << *out_iternal_8 << "\n";
    myfile << "ret:" << ret << "\n";
    myfile.close();
    return ret;
    /*
    __int64 result = *(QWORD*)(internal_ptr + 16);
    if (result)
    {
        if (out_iternal_8)
            *out_iternal_8 = *(unsigned int*)(result + 8);
        return **(QWORD**)(internal_ptr + 16);
    }
    return result;*/
}

uintptr_t __fastcall NewThread_GetBurnTicketReq(__int64 internal_ptr, __int64 _TEST_PTR) // AKA sub_180001AAA
{
    __int64 (*_NewThread_GetBurnTicketReq)(__int64 internal_ptr, __int64 _TEST_PTR) = (__int64 (*)(__int64 internal_ptr, __int64 _TEST_PTR))real_denuvo_functions.NewThread_GetBurnTicketReq;
    std::ofstream myfile;
    myfile.open("UPLAY_GetActivate_NewThread_GetBurnTicketReq_log.txt", std::ios::app);
    myfile << "\n";
    myfile << "NewThread_GetBurnTicketReq!" << GetCurrentThreadId() << "\n";
    myfile << "internal_ptr:" << std::hex << internal_ptr << "\n";
    myfile << "_TEST_PTR:" << std::hex << _TEST_PTR << "\n";
    auto ret = _NewThread_GetBurnTicketReq(internal_ptr, _TEST_PTR);
    myfile << "ret:" << ret << "\n";
    myfile.close();
    return ret;
}

__int64 __fastcall GetThread(__int64 internal_ptr, QWORD* unk_ret) // AKA sub_18000B05A | WTF is this?
{
    __int64 (*_GetThread)(__int64 internal_ptr, QWORD * unk_ret) = (__int64 (*)(__int64 internal_ptr, QWORD * unk_ret))real_denuvo_functions.GetThread;
    std::ofstream myfile;
    myfile.open("UPLAY_GetActivate_GetThread_log.txt", std::ios::app);
    myfile << "\n";
    myfile << "GetCachedOrFreshToken!" << GetCurrentThreadId() << "\n";
    myfile << "internal_ptr:" << std::hex << internal_ptr << "\n";
    myfile << "unk_ret:" << std::hex << unk_ret << "\n";
    auto ret = _GetThread(internal_ptr, unk_ret);
    myfile << "*unk_ret:" << *unk_ret << "\n";
    myfile << "ret:" << ret << "\n";
    myfile.close();
    return ret;
}


__int64 __fastcall CheckRet0(void* ptr)
{
    __int64(__fastcall * _ret02)() = (__int64(__fastcall*)())ptr;
    return _ret02();
}


#define GET_PROXY_FUNC(FUNC) \
	auto proxyFunc = FnCast(GetProcAddress(originalDLL, #FUNC), FUNC);

//UPLAY_GetActivate(1i64, a1, 8i64, &token_interface)
EXPORT int UPLAY_GetActivate(int always_1, unsigned int* product_id_ptr, unsigned int _always_8, call_offset_t* token_interface) //void**** token_interface)// __int64(__fastcall**** token_interface)())
{
    std::ofstream myfile;
    myfile.open("UPLAY_GetActivate_log.txt", std::ios::app);
    myfile << "CALLED!:" << this_hModule << GetCurrentThreadId() << "\n";
    myfile.flush();
    GET_PROXY_FUNC(UPLAY_GetActivate);
    myfile << "function starts:\n";
    myfile << "Product Id: " << *product_id_ptr << "\n";
    myfile << "token_interface: " << token_interface << "\n";
    myfile << "token_interface->something:" << token_interface->something << "\n";
    myfile.flush();
    int returned = proxyFunc(always_1, product_id_ptr, _always_8, token_interface);
    myfile << "Function Called!\n";
    myfile << "ret: " << returned << "\n";
    myfile << "token_interface: " << token_interface << "\n";
    myfile << "token_interface->something:" << token_interface->something << "\n";
    myfile << "token_interface->something->vtable:" << token_interface->something->vtable << "\n";
    myfile.flush();
    myfile << "token_interface->something->vtable->GetInternal8:" << token_interface->something->vtable->GetInternal8 << "\n";
    myfile << "token_interface->something->vtable->return0:" << token_interface->something->vtable->return0 << "\n";
    myfile << "token_interface->something->vtable->GetCachedOrFreshToken:" << token_interface->something->vtable->GetCachedOrFreshToken << "\n";
    myfile << "token_interface->something->vtable->InvalidateCachedToken:" << token_interface->something->vtable->InvalidateCachedToken << "\n";
    myfile << "token_interface->something->vtable->NewThread_GetBurnTicketReq:" << token_interface->something->vtable->NewThread_GetBurnTicketReq << "\n";
    myfile << "token_interface->something->vtable->GetThread:" << token_interface->something->vtable->GetThread << "\n";
    myfile.flush();
    //return returned;
    if (token_interface->something->vtable == NULL)
    {
        myfile << "token_interface->something->vtable!\n";
        myfile.flush();
        return returned;
    }
    real_denuvo_functions = {};
    real_denuvo_functions.GetInternal8 = token_interface->something->vtable->GetInternal8;
    real_denuvo_functions.return0 = token_interface->something->vtable->return0;
    real_denuvo_functions.GetCachedOrFreshToken = token_interface->something->vtable->GetCachedOrFreshToken;
    real_denuvo_functions.InvalidateCachedToken = token_interface->something->vtable->InvalidateCachedToken;
    real_denuvo_functions.GetBuffer = token_interface->something->vtable->GetBuffer;
    real_denuvo_functions.NewThread_GetBurnTicketReq = token_interface->something->vtable->NewThread_GetBurnTicketReq;
    real_denuvo_functions.GetThread = token_interface->something->vtable->GetThread;
    myfile << "CheckRet0: " << CheckRet0(token_interface->something->vtable->return0) << "\n";
    myfile.flush();
    myfile << "real_denuvo_functions done \n";
    myfile << "CheckRet0: " << CheckRet0(real_denuvo_functions.return0) << "\n";
    myfile.flush();
    myfile << "return0: " << return0() << "\n";
    myfile.flush();
    myfile.close();
    return returned;
    try
    {
        myfile << "try!\n";
        myfile.flush();
        token_interface->something->vtable->GetInternal8 = GetInternal8;
        myfile << "GetInternal8!\n";
        myfile.flush();
        token_interface->something->vtable->return0 = return0;
        myfile << "return0!\n";
        myfile.flush();
        token_interface->something->vtable->GetCachedOrFreshToken = GetCachedOrFreshToken;
        myfile << "GetCachedOrFreshToken!\n";
        myfile.flush();
        token_interface->something->vtable->InvalidateCachedToken = InvalidateCachedToken;
        myfile << "InvalidateCachedToken!\n";
        myfile.flush();
        token_interface->something->vtable->GetBuffer = GetBuffer;
        myfile << "GetBuffer!\n";
        myfile.flush();
        token_interface->something->vtable->NewThread_GetBurnTicketReq = NewThread_GetBurnTicketReq;
        myfile << "NewThread_GetBurnTicketReq!\n";
        myfile.flush();
        token_interface->something->vtable->GetThread = GetThread;
        myfile << "GetThread!\n";
        myfile.flush();
        myfile << "CheckRet0: " << CheckRet0(token_interface->something->vtable->return0) << "\n";
        myfile.flush();
        myfile << "NEW token_interface->something->vtable!" << token_interface->something->vtable << "\n";
        myfile.flush();
        myfile << "token_interface->something->vtable->GetInternal8:" << token_interface->something->vtable->GetInternal8 << "\n";
        myfile.flush();
    }
    catch (const std::exception& ex)
    {
        myfile << "ex:" << ex.what() << "\n";
        myfile.flush();
    }

    /*
    token_interface->something->vtable
    myfile << "**token_interface!" << **token_interface << "\n";
    myfile.flush();
    auto shouldBeZero = (**token_interface)[1];
    myfile << "CheckRet0: " << CheckRet0(shouldBeZero) << "\n";
    myfile.flush();
    real_denuvo_ptr = **token_interface;
    real_denuvo_functions.GetInternal8 = (**token_interface)[0];
    real_denuvo_functions.return0 = (**token_interface)[1];
    real_denuvo_functions.GetCachedOrFreshToken = (**token_interface)[2];
    real_denuvo_functions.InvalidateCachedToken = (**token_interface)[3];
    real_denuvo_functions.GetBuffer = (**token_interface)[4];
    real_denuvo_functions.NewThread_GetBurnTicketReq = (**token_interface)[5];
    real_denuvo_functions.GetThread = (**token_interface)[6];
    myfile << "real_denuvo_functions done \n";
    myfile.flush();
    myfile << "return0: " << return0() << "\n";
    fake_denuvo_functions.GetInternal8 = GetInternal8;
    fake_denuvo_functions.return0 = return0;
    fake_denuvo_functions.GetCachedOrFreshToken = GetCachedOrFreshToken;
    fake_denuvo_functions.InvalidateCachedToken = InvalidateCachedToken;
    fake_denuvo_functions.GetBuffer = GetBuffer;
    fake_denuvo_functions.NewThread_GetBurnTicketReq = NewThread_GetBurnTicketReq;
    fake_denuvo_functions.GetThread = GetThread;
    myfile << "CheckRet0: " << CheckRet0(fake_denuvo_functions.return0) << "\n";
    myfile.flush();
    fake_denuvo_ptr = &fake_denuvo_functions;
    myfile << "fake_denuvo_functions done \n";
    myfile.flush();
    fake_denuvo_functions_ptr = &fake_denuvo_functions;
    
    myfile << "CheckRet0: " << CheckRet0(fake_denuvo_functions_ptr->return0) << "\n";
    myfile.flush();

    **token_interface = (void**)&fake_denuvo_functions_ptr;
    myfile << "token_interface override done! \n";
    myfile << "NEW **token_interface!" << **token_interface << "\n";
    myfile.flush();
    auto shouldBeZero2 = (**token_interface)[1];
    myfile << "CheckRet0: " << CheckRet0(shouldBeZero2) << "\n";
    myfile.flush();
    myfile << "NEW **token_interface!" << **token_interface << "\n";
    */



    myfile.close();
    return returned;
}