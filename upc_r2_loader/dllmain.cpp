// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

#pragma region Basic
std::wstring string_to_wstring(const std::string& text) {
    return std::wstring(text.begin(), text.end());
}


template<typename T>
T FnCast(FARPROC fnToCast, T pFnCastTo)
{
    return (T)fnToCast;
}

HMODULE originalDLL = nullptr;

#define GET_PROXY_FUNC(FUNC) \
	static auto proxyFunc = FnCast(GetProcAddress(originalDLL, #FUNC), FUNC);
#pragma endregion
#pragma region Init/ShutDown
void Init()
{
    std::string InstallPath;
    std::fstream pathtxt;
    pathtxt.open("path.txt", std::ios::in);
    if (pathtxt.is_open())
    {
        std::string tp;
        while (getline(pathtxt, tp))
        {
            InstallPath.append(tp);
        }
        pathtxt.close();
    }
    else
    {
        InstallPath = std::filesystem::current_path().string();
    }
#ifdef _WIN64
    InstallPath = InstallPath + "\\upc_r264.dll";
#else
    InstallPath = InstallPath + "\\upc_r2.dll";
#endif
    originalDLL = LoadLibraryW((LPCWSTR)string_to_wstring(InstallPath).c_str());
    std::cout << originalDLL << std::endl;
}


void End()
{
    FreeLibrary(originalDLL);
}
#pragma endregion
#pragma region DLLMAIN
BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        Init();
        break;
    case DLL_PROCESS_DETACH:
        End();
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
        break;
    }
    return TRUE;
}
#pragma endregion

#pragma region FULL UPC
EXPORT void UPC_Uninit()
{
    GET_PROXY_FUNC(UPC_Uninit);
    proxyFunc();
}

EXPORT int UPC_AchievementImageFree(intptr_t inContext, intptr_t inImageRGBA)
{
    GET_PROXY_FUNC(UPC_AchievementImageFree);
    return proxyFunc(inContext, inImageRGBA);
}

EXPORT int UPC_AchievementImageGet(intptr_t inContext, unsigned inId, intptr_t outImageRGBA, intptr_t inCallback, intptr_t inCallbackData)
{
    GET_PROXY_FUNC(UPC_AchievementImageGet);
    return proxyFunc(inContext, inId, outImageRGBA, inCallback, inCallbackData);
}

EXPORT int UPC_AchievementListFree(intptr_t inContext, intptr_t inAchievementList)
{
    GET_PROXY_FUNC(UPC_AchievementListFree);
    return proxyFunc(inContext, inAchievementList);
}

EXPORT int UPC_AchievementListGet(intptr_t inContext, intptr_t inOptUserIdUtf8, unsigned inFilter, intptr_t outAchievementList, intptr_t inCallback, intptr_t inCallbackData)
{
    GET_PROXY_FUNC(UPC_AchievementListGet);
    return proxyFunc(inContext, inOptUserIdUtf8, inFilter, outAchievementList, inCallback, inCallbackData);
}

EXPORT int UPC_AchievementUnlock(intptr_t inContext, unsigned inId, intptr_t inOptCallback, intptr_t inOptCallbackData)
{
    GET_PROXY_FUNC(UPC_AchievementUnlock);
    return proxyFunc(inContext, inId, inOptCallback, inOptCallbackData);
}

EXPORT int UPC_ApplicationIdGet(intptr_t inContext, intptr_t appID)
{
    GET_PROXY_FUNC(UPC_ApplicationIdGet);
    return proxyFunc(inContext, appID);
}

EXPORT int UPC_AvatarFree(intptr_t inContext, intptr_t inImageRGBA)
{
    GET_PROXY_FUNC(UPC_AvatarFree);
    return proxyFunc(inContext, inImageRGBA);
}

EXPORT int UPC_AvatarGet(intptr_t inContext, intptr_t inOptUserIdUtf8, unsigned inSize, intptr_t outImageRGBA, intptr_t inCallback, intptr_t inCallbackData)
{
    GET_PROXY_FUNC(UPC_AvatarGet);
    return proxyFunc(inContext, inOptUserIdUtf8, inSize, outImageRGBA, inCallback, inCallbackData);
}

EXPORT int UPC_BlacklistAdd(intptr_t inContext, intptr_t inUserIdUtf8, intptr_t inOptCallback, intptr_t inOptCallbackData)
{
    GET_PROXY_FUNC(UPC_BlacklistAdd);
    return proxyFunc(inContext, inUserIdUtf8, inOptCallback, inOptCallbackData);
}

EXPORT int UPC_BlacklistHas(intptr_t inContext, intptr_t inUserIdUtf8)
{
    GET_PROXY_FUNC(UPC_BlacklistHas);
    return proxyFunc(inContext, inUserIdUtf8);
}

EXPORT int UPC_BlacklistHas_Extended(intptr_t inContext, intptr_t inUserIdUtf8, intptr_t outIsBlacklisted)
{
    GET_PROXY_FUNC(UPC_BlacklistHas_Extended);
    return proxyFunc(inContext, inUserIdUtf8, outIsBlacklisted);
}

EXPORT int UPC_CPUScoreGet(intptr_t inContext, intptr_t outScore)
{
    GET_PROXY_FUNC(UPC_CPUScoreGet);
    return proxyFunc(inContext, outScore);
}

EXPORT int UPC_Cancel(intptr_t inContext, int inHandle)
{
    GET_PROXY_FUNC(UPC_Cancel);
    return proxyFunc(inContext, inHandle);
}

EXPORT int UPC_ContextFree(intptr_t inContext)
{
    GET_PROXY_FUNC(UPC_ContextFree);
    return proxyFunc(inContext);
}

EXPORT int UPC_EmailGet_Extended(intptr_t inContext, intptr_t outEmail)
{
    GET_PROXY_FUNC(UPC_EmailGet_Extended);
    return proxyFunc(inContext, outEmail);
}

EXPORT int UPC_EventNextPeek(intptr_t inContext, intptr_t outEvent)
{
    GET_PROXY_FUNC(UPC_EventNextPeek);
    return proxyFunc(inContext, outEvent);
}

EXPORT int UPC_EventNextPoll(intptr_t inContext, intptr_t outEvent)
{
    GET_PROXY_FUNC(UPC_EventNextPoll);
    return proxyFunc(inContext, outEvent);
}

EXPORT int UPC_EventRegisterHandler(intptr_t inContext, unsigned inType, intptr_t inHandler, intptr_t inOptData)
{
    GET_PROXY_FUNC(UPC_EventRegisterHandler);
    return proxyFunc(inContext, inType, inHandler, inOptData);
}

EXPORT int UPC_EventUnegisterHandler(intptr_t inContext, unsigned inType)
{
    GET_PROXY_FUNC(UPC_EventUnegisterHandler);
    return proxyFunc(inContext, inType);
}

EXPORT int UPC_FriendAdd(intptr_t inContext, intptr_t inSearchStringUtf8, intptr_t inOptCallback, intptr_t inOptCallbackData)
{
    GET_PROXY_FUNC(UPC_FriendAdd);
    return proxyFunc(inContext, inSearchStringUtf8, inOptCallback, inOptCallbackData);
}

EXPORT int UPC_FriendCheck(intptr_t inContext, intptr_t inUserIdUtf8)
{
    GET_PROXY_FUNC(UPC_FriendCheck);
    return proxyFunc(inContext, inUserIdUtf8);
}

EXPORT int UPC_FriendCheck_Extended(intptr_t inContext, intptr_t inUserIdUtf8, intptr_t outIsFriend)
{
    GET_PROXY_FUNC(UPC_FriendCheck_Extended);
    return proxyFunc(inContext, inUserIdUtf8, outIsFriend);
}

EXPORT int UPC_FriendListFree(intptr_t inContext, intptr_t inFriendList)
{
    GET_PROXY_FUNC(UPC_FriendListFree);
    return proxyFunc(inContext, inFriendList);
}

EXPORT int UPC_FriendListGet(intptr_t inContext, unsigned inOptOnlineStatusFilter, intptr_t outFriendList, intptr_t inCallback, intptr_t inOptCallbackData)
{
    GET_PROXY_FUNC(UPC_FriendListGet);
    return proxyFunc(inContext, inOptOnlineStatusFilter, outFriendList, inCallback, inOptCallbackData);
}

EXPORT int UPC_FriendRemove(intptr_t inContext, intptr_t inUserIdUtf8, intptr_t inOptCallback, intptr_t inOptCallbackData)
{
    GET_PROXY_FUNC(UPC_FriendRemove);
    return proxyFunc(inContext, inUserIdUtf8, inOptCallback, inOptCallbackData);
}

EXPORT int UPC_GPUScoreGet(intptr_t inContext, intptr_t outScore, intptr_t outConfidenceLevel)
{
    GET_PROXY_FUNC(UPC_GPUScoreGet);
    return proxyFunc(inContext, outScore, outConfidenceLevel);
}

EXPORT int UPC_IdGet_Extended(intptr_t inContext, intptr_t outId)
{
    GET_PROXY_FUNC(UPC_IdGet_Extended);
    return proxyFunc(inContext, outId);
}

EXPORT int UPC_Init(unsigned inVersion, unsigned inProductId)
{
    GET_PROXY_FUNC(UPC_Init);
    return proxyFunc(inVersion, inProductId);
}

EXPORT int UPC_InstallChunkListFree(intptr_t inContext, intptr_t inChunkList)
{
    GET_PROXY_FUNC(UPC_InstallChunkListFree);
    return proxyFunc(inContext, inChunkList);
}

EXPORT int UPC_InstallChunkListGet(intptr_t inContext, intptr_t outChunkList)
{
    GET_PROXY_FUNC(UPC_InstallChunkListGet);
    return proxyFunc(inContext, outChunkList);
}

EXPORT int UPC_InstallChunksOrderUpdate(intptr_t context, intptr_t inChunkIds, unsigned inChunkCount)
{
    GET_PROXY_FUNC(UPC_InstallChunksOrderUpdate);
    return proxyFunc(context, inChunkIds, inChunkCount);
}

EXPORT int UPC_InstallChunksOrderUpdate_Extended(intptr_t context, intptr_t inChunkIds, unsigned inChunkCount, intptr_t unknown1, intptr_t unknown2)
{
    GET_PROXY_FUNC(UPC_InstallChunksOrderUpdate_Extended);
    return proxyFunc(context, inChunkIds, inChunkCount, unknown1, unknown2);
}

EXPORT int UPC_InstallChunksPresenceCheck(intptr_t context, intptr_t inChunkIds, unsigned inChunkCount)
{
    GET_PROXY_FUNC(UPC_InstallChunksPresenceCheck);
    return proxyFunc(context, inChunkIds, inChunkCount);
}

EXPORT int UPC_InstallLanguageGet_Extended(intptr_t context, intptr_t outInstallLanguage)
{
    GET_PROXY_FUNC(UPC_InstallLanguageGet_Extended);
    return proxyFunc(context, outInstallLanguage);
}

EXPORT int UPC_LaunchApp(intptr_t inContext, unsigned inProductId, intptr_t MustBeZero)
{
    GET_PROXY_FUNC(UPC_LaunchApp);
    return proxyFunc(inContext, inProductId, MustBeZero);
}

EXPORT int UPC_MultiplayerInvite(intptr_t inContext, intptr_t inUserIdUtf8, intptr_t inOptCallback, intptr_t inOptCallbackData)
{
    GET_PROXY_FUNC(UPC_MultiplayerInvite);
    return proxyFunc(inContext, inUserIdUtf8, inOptCallback, inOptCallbackData);
}

EXPORT int UPC_MultiplayerInviteAnswer(intptr_t inContext, intptr_t inSenderIdUtf8, int inIsAccepted, intptr_t inOptCallback, intptr_t inOptCallbackData)
{
    GET_PROXY_FUNC(UPC_MultiplayerInviteAnswer);
    return proxyFunc(inContext, inSenderIdUtf8, inIsAccepted, inOptCallback, inOptCallbackData);
}

EXPORT int UPC_MultiplayerSessionClear(intptr_t inContext)
{
    GET_PROXY_FUNC(UPC_MultiplayerSessionClear);
    return proxyFunc(inContext);
}

EXPORT int UPC_MultiplayerSessionClear_Extended(intptr_t inContext, intptr_t unknown1, intptr_t unknown2)
{
    GET_PROXY_FUNC(UPC_MultiplayerSessionClear_Extended);
    return proxyFunc(inContext, unknown1, unknown2);
}

EXPORT int UPC_MultiplayerSessionFree(intptr_t inContext, intptr_t inMultiplayerSession)
{
    GET_PROXY_FUNC(UPC_MultiplayerSessionFree);
    return proxyFunc(inContext, inMultiplayerSession);
}

EXPORT int UPC_MultiplayerSessionGet(intptr_t inContext, intptr_t outMultiplayerSession)
{
    GET_PROXY_FUNC(UPC_MultiplayerSessionGet);
    return proxyFunc(inContext, outMultiplayerSession);
}

EXPORT int UPC_MultiplayerSessionSet(intptr_t inContext, intptr_t inMultiplayerSession)
{
    GET_PROXY_FUNC(UPC_MultiplayerSessionSet);
    return proxyFunc(inContext, inMultiplayerSession);
}

EXPORT int UPC_MultiplayerSessionSet_Extended(intptr_t inContext, intptr_t inMultiplayerSession, intptr_t unknown1, intptr_t unknown2)
{
    GET_PROXY_FUNC(UPC_MultiplayerSessionSet_Extended);
    return proxyFunc(inContext, inMultiplayerSession, unknown1, unknown2);
}

EXPORT int UPC_NameGet_Extended(intptr_t inContext, intptr_t userName)
{
    GET_PROXY_FUNC(UPC_NameGet_Extended);
    return proxyFunc(inContext, userName);
}

EXPORT int UPC_OverlayBrowserUrlShow(intptr_t inContext, intptr_t inBrowserUrlUtf8, intptr_t inOptCallback, intptr_t inOptCallbackData)
{
    GET_PROXY_FUNC(UPC_OverlayBrowserUrlShow);
    return proxyFunc(inContext, inBrowserUrlUtf8, inOptCallback, inOptCallbackData);
}

EXPORT int UPC_OverlayFriendInvitationShow(intptr_t inContext, intptr_t inOptIdListUtf8, unsigned inOptIdListLength)
{
    GET_PROXY_FUNC(UPC_OverlayFriendInvitationShow);
    return proxyFunc(inContext, inOptIdListUtf8, inOptIdListLength);
}

EXPORT int UPC_OverlayFriendInvitationShow_Extended(intptr_t inContext, intptr_t inOptIdListUtf8, unsigned inOptIdListLength, intptr_t unknown1, intptr_t unknown2)
{
    GET_PROXY_FUNC(UPC_OverlayFriendInvitationShow_Extended);
    return proxyFunc(inContext, inOptIdListUtf8, inOptIdListLength, unknown1, unknown2);
}

EXPORT int UPC_OverlayFriendSelectionFree(intptr_t inContext, intptr_t inSelectedFriends)
{
    GET_PROXY_FUNC(UPC_OverlayFriendSelectionFree);
    return proxyFunc(inContext, inSelectedFriends);
}

EXPORT int UPC_OverlayFriendSelectionShow(intptr_t inContext, intptr_t inIdListUtf8, unsigned inIdListLength, intptr_t outSelectedFriends, intptr_t inCallback, intptr_t inCallbackData)
{
    GET_PROXY_FUNC(UPC_OverlayFriendSelectionShow);
    return proxyFunc(inContext, inIdListUtf8, inIdListLength, outSelectedFriends, inCallback, inCallbackData);
}

EXPORT int UPC_OverlayMicroAppShow(intptr_t inContext, intptr_t inAppName, intptr_t inOptMicroAppParamList, intptr_t inOptCallback, intptr_t inOptCallbackData)
{
    GET_PROXY_FUNC(UPC_OverlayMicroAppShow);
    return proxyFunc(inContext, inAppName, inOptMicroAppParamList, inOptCallback, inOptCallbackData);
}

EXPORT int UPC_OverlayNotificationShow(intptr_t inContext, unsigned inId)
{
    GET_PROXY_FUNC(UPC_OverlayNotificationShow);
    return proxyFunc(inContext, inId);
}

EXPORT int UPC_OverlayNotificationShow_Extended(intptr_t inContext, unsigned inId, intptr_t unknown1, intptr_t unknown2)
{
    GET_PROXY_FUNC(UPC_OverlayNotificationShow_Extended);
    return proxyFunc(inContext, inId, unknown1, unknown2);
}

EXPORT int UPC_OverlayShow(intptr_t inContext, unsigned inSection, intptr_t inOptCallback, intptr_t inOptCallbackData)
{
    GET_PROXY_FUNC(UPC_OverlayShow);
    return proxyFunc(inContext, inSection, inOptCallback, inOptCallbackData);
}

EXPORT int UPC_ProductConsume(intptr_t inContext, unsigned inProductId, unsigned inQuantity, intptr_t inTransactionIdUtf8, intptr_t inSignatureUtf8, intptr_t outResponseSignatureUtf8, intptr_t inCallback, intptr_t inOptCallbackData)
{
    GET_PROXY_FUNC(UPC_ProductConsume);
    return proxyFunc(inContext, inProductId, inQuantity, inTransactionIdUtf8, inSignatureUtf8, outResponseSignatureUtf8, inCallback, inOptCallbackData);
}

EXPORT int UPC_ProductConsumeSignatureFree(intptr_t inContext, intptr_t inResponseSignature)
{
    GET_PROXY_FUNC(UPC_ProductConsumeSignatureFree);
    return proxyFunc(inContext, inResponseSignature);
}

EXPORT int UPC_ProductListFree(intptr_t inContext, intptr_t inProductList)
{
    GET_PROXY_FUNC(UPC_ProductListFree);
    return proxyFunc(inContext, inProductList);
}

EXPORT int UPC_ProductListGet(intptr_t inContext, intptr_t inOptUserIdUtf8, unsigned inFilter, intptr_t outProductList, intptr_t inCallback, intptr_t inOptCallbackData)
{
    GET_PROXY_FUNC(UPC_ProductListGet);
    return proxyFunc(inContext, inOptUserIdUtf8, inFilter, outProductList, inCallback, inOptCallbackData);
}

EXPORT int UPC_RichPresenceSet(intptr_t inContext, unsigned inId, intptr_t inOptTokenList)
{
    GET_PROXY_FUNC(UPC_RichPresenceSet);
    return proxyFunc(inContext, inId, inOptTokenList);
}

EXPORT int UPC_RichPresenceSet_Extended(intptr_t inContext, unsigned inId, intptr_t inOptTokenList, intptr_t unknown1, intptr_t unknown2)
{
    GET_PROXY_FUNC(UPC_RichPresenceSet_Extended);
    return proxyFunc(inContext, inId, inOptTokenList, unknown1, unknown2);
}

EXPORT int UPC_ShowBrowserUrl(intptr_t inContext, intptr_t inBrowserUrlUtf8)
{
    GET_PROXY_FUNC(UPC_ShowBrowserUrl);
    return proxyFunc(inContext, inBrowserUrlUtf8);
}

EXPORT int UPC_StorageFileClose(intptr_t inContext, intptr_t inHandle)
{
    GET_PROXY_FUNC(UPC_StorageFileClose);
    return proxyFunc(inContext, inHandle);
}

EXPORT int UPC_StorageFileDelete(intptr_t inContext, intptr_t inFileNameUtf8)
{
    GET_PROXY_FUNC(UPC_StorageFileDelete);
    return proxyFunc(inContext, inFileNameUtf8);
}

EXPORT int UPC_StorageFileListFree(intptr_t inContext, intptr_t inStorageFileList)
{
    GET_PROXY_FUNC(UPC_StorageFileListFree);
    return proxyFunc(inContext, inStorageFileList);
}

EXPORT int UPC_StorageFileListGet(intptr_t inContext, intptr_t outStorageFileList)
{
    GET_PROXY_FUNC(UPC_StorageFileListGet);
    return proxyFunc(inContext, outStorageFileList);
}

EXPORT int UPC_StorageFileOpen(intptr_t inContext, intptr_t inFileNameUtf8, unsigned inFlags, intptr_t outHandle)
{
    GET_PROXY_FUNC(UPC_StorageFileOpen);
    return proxyFunc(inContext, inFileNameUtf8, inFlags, outHandle);
}

EXPORT int UPC_StorageFileRead(intptr_t inContext, intptr_t inHandle, unsigned inBytesToRead, unsigned inBytesReadOffset, intptr_t outData, intptr_t outBytesRead, intptr_t inCallback, intptr_t inCallbackData)
{
    GET_PROXY_FUNC(UPC_StorageFileRead);
    return proxyFunc(inContext, inHandle, inBytesToRead, inBytesReadOffset, outData, outBytesRead, inCallback, inCallbackData);
}

EXPORT int UPC_StorageFileWrite(intptr_t inContext, intptr_t inHandle, intptr_t inData, unsigned inSize, intptr_t inCallback, intptr_t inCallbackData)
{
    GET_PROXY_FUNC(UPC_StorageFileWrite);
    return proxyFunc(inContext, inHandle, inData, inSize, inCallback, inCallbackData);
}

EXPORT int UPC_StoreCheckout(intptr_t inContext, unsigned inId)
{
    GET_PROXY_FUNC(UPC_StoreCheckout);
    return proxyFunc(inContext, inId);
}

EXPORT int UPC_StoreIsEnabled(intptr_t inContext)
{
    GET_PROXY_FUNC(UPC_StoreIsEnabled);
    return proxyFunc(inContext);
}

EXPORT int UPC_StoreIsEnabled_Extended(intptr_t inContext, intptr_t outEnabled)
{
    GET_PROXY_FUNC(UPC_StoreIsEnabled_Extended);
    return proxyFunc(inContext, outEnabled);
}

EXPORT int UPC_StoreLanguageSet(intptr_t inContext, intptr_t inLanguageCountryCode)
{
    GET_PROXY_FUNC(UPC_StoreLanguageSet);
    return proxyFunc(inContext, inLanguageCountryCode);
}

EXPORT int UPC_StorePartnerGet(intptr_t inContext)
{
    GET_PROXY_FUNC(UPC_StorePartnerGet);
    return proxyFunc(inContext);
}

EXPORT int UPC_StorePartnerGet_Extended(intptr_t inContext, intptr_t storePartner)
{
    GET_PROXY_FUNC(UPC_StorePartnerGet_Extended);
    return proxyFunc(inContext, storePartner);
}

EXPORT int UPC_StoreProductDetailsShow(intptr_t inContext, unsigned inId)
{
    GET_PROXY_FUNC(UPC_StoreProductDetailsShow);
    return proxyFunc(inContext, inId);
}

EXPORT int UPC_StoreProductListFree(intptr_t inContext, intptr_t inProductList)
{
    GET_PROXY_FUNC(UPC_StoreProductListFree);
    return proxyFunc(inContext, inProductList);
}

EXPORT int UPC_StoreProductListGet(intptr_t inContext, intptr_t outProductList, intptr_t inCallback, intptr_t inCallbackData)
{
    GET_PROXY_FUNC(UPC_StoreProductListGet);
    return proxyFunc(inContext, outProductList, inCallback, inCallbackData);
}

EXPORT int UPC_StoreProductsShow(intptr_t inContext, intptr_t inTagsList)
{
    GET_PROXY_FUNC(UPC_StoreProductsShow);
    return proxyFunc(inContext, inTagsList);
}

EXPORT int UPC_StreamingCurrentUserCountryFree(intptr_t inContext, intptr_t inUtf8Country)
{
    GET_PROXY_FUNC(UPC_StreamingCurrentUserCountryFree);
    return proxyFunc(inContext, inUtf8Country);
}

EXPORT int UPC_StreamingCurrentUserCountryGet(intptr_t inContext, intptr_t outUtf8Country, intptr_t inCallback, intptr_t inCallbackData)
{
    GET_PROXY_FUNC(UPC_StreamingCurrentUserCountryGet);
    return proxyFunc(inContext, outUtf8Country, inCallback, inCallbackData);
}

EXPORT int UPC_StreamingDeviceTypeGet(intptr_t inContext, intptr_t outType, intptr_t inCallback, intptr_t inCallbackData)
{
    GET_PROXY_FUNC(UPC_StreamingDeviceTypeGet);
    return proxyFunc(inContext, outType, inCallback, inCallbackData);
}

EXPORT int UPC_StreamingInputGamepadTypeGet(intptr_t inContext, intptr_t outType, intptr_t inCallback, intptr_t inCallbackData)
{
    GET_PROXY_FUNC(UPC_StreamingInputGamepadTypeGet);
    return proxyFunc(inContext, outType, inCallback, inCallbackData);
}

EXPORT int UPC_StreamingInputTypeGet(intptr_t inContext, intptr_t outType, intptr_t inCallback, intptr_t inCallbackData)
{
    GET_PROXY_FUNC(UPC_StreamingInputTypeGet);
    return proxyFunc(inContext, outType, inCallback, inCallbackData);
}

EXPORT int UPC_StreamingNetworkDelayForInputGet(intptr_t inContext, intptr_t outDelayMs, intptr_t inCallback, intptr_t inCallbackData)
{
    GET_PROXY_FUNC(UPC_StreamingNetworkDelayForInputGet);
    return proxyFunc(inContext, outDelayMs, inCallback, inCallbackData);
}

EXPORT int UPC_StreamingNetworkDelayForVideoGet(intptr_t inContext, intptr_t outDelayMs, intptr_t inCallback, intptr_t inCallbackData)
{
    GET_PROXY_FUNC(UPC_StreamingNetworkDelayForVideoGet);
    return proxyFunc(inContext, outDelayMs, inCallback, inCallbackData);
}

EXPORT int UPC_StreamingNetworkDelayRoundtripGet(intptr_t inContext, intptr_t outDelayMs, intptr_t inCallback, intptr_t inCallbackData)
{
    GET_PROXY_FUNC(UPC_StreamingNetworkDelayRoundtripGet);
    return proxyFunc(inContext, outDelayMs, inCallback, inCallbackData);
}

EXPORT int UPC_StreamingResolutionFree(intptr_t inContext, intptr_t inResolution)
{
    GET_PROXY_FUNC(UPC_StreamingResolutionFree);
    return proxyFunc(inContext, inResolution);
}

EXPORT int UPC_StreamingResolutionGet(intptr_t inContext, intptr_t outResolution, intptr_t inCallback, intptr_t inCallbackData)
{
    GET_PROXY_FUNC(UPC_StreamingResolutionGet);
    return proxyFunc(inContext, outResolution, inCallback, inCallbackData);
}

EXPORT int UPC_StreamingTypeGet(intptr_t inContext, intptr_t outType, intptr_t inCallback, intptr_t inCallbackData)
{
    GET_PROXY_FUNC(UPC_StreamingTypeGet);
    return proxyFunc(inContext, outType, inCallback, inCallbackData);
}

EXPORT int UPC_TicketGet_Extended(intptr_t inContext, intptr_t ticket)
{
    GET_PROXY_FUNC(UPC_TicketGet_Extended);
    return proxyFunc(inContext, ticket);
}

EXPORT int UPC_Update(intptr_t inContext)
{
    GET_PROXY_FUNC(UPC_Update);
    return proxyFunc(inContext);
}

EXPORT int UPC_UserFree(intptr_t inContext, intptr_t inUser)
{
    GET_PROXY_FUNC(UPC_UserFree);
    return proxyFunc(inContext, inUser);
}

EXPORT int UPC_UserGet(intptr_t inContext, intptr_t inOptUserIdUtf8, intptr_t outUser, intptr_t inCallback, intptr_t inCallbackData)
{
    GET_PROXY_FUNC(UPC_UserGet);
    return proxyFunc(inContext, inOptUserIdUtf8, outUser, inCallback, inCallbackData);
}

EXPORT int UPC_UserPlayedWithAdd(intptr_t inContext, intptr_t inUserIdUtf8List, unsigned inListLength)
{
    GET_PROXY_FUNC(UPC_UserPlayedWithAdd);
    return proxyFunc(inContext, inUserIdUtf8List, inListLength);
}

EXPORT int UPC_UserPlayedWithAdd_Extended(intptr_t inContext, intptr_t inUserIdUtf8List, unsigned inListLength, intptr_t unknown1, intptr_t unknown2)
{
    GET_PROXY_FUNC(UPC_UserPlayedWithAdd_Extended);
    return proxyFunc(inContext, inUserIdUtf8List, inListLength, unknown1, unknown2);
}

#pragma endregion
