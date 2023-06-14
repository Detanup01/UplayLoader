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
    InstallPath = InstallPath + "\\upc_164.dll";
#else
    InstallPath = InstallPath + "\\upc_1.dll";
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
#pragma region Uplay Proxy Functions
EXPORT bool UPLAY_ACH_EarnAchievement(unsigned aAchivementId, intptr_t aOverlapped)
{
    GET_PROXY_FUNC(UPLAY_ACH_EarnAchievement);
    return proxyFunc(aAchivementId, aOverlapped);
}

EXPORT bool UPLAY_ACH_GetAchievementImage(unsigned aId, intptr_t aOutImage, intptr_t aOverlapped)
{
    GET_PROXY_FUNC(UPLAY_ACH_GetAchievementImage);
    return proxyFunc(aId, aOutImage, aOverlapped);
}

EXPORT bool UPLAY_ACH_GetAchievements(unsigned aFilter, intptr_t aAccountIdUtf8OrNULLIfCurrentUser, intptr_t aOutAchievementList, intptr_t aOverlapped)
{
    GET_PROXY_FUNC(UPLAY_ACH_GetAchievements);
    return proxyFunc(aFilter, aAccountIdUtf8OrNULLIfCurrentUser, aOutAchievementList, aOverlapped);
}

EXPORT bool UPLAY_ACH_ReleaseAchievementImage(intptr_t aImage)
{
    GET_PROXY_FUNC(UPLAY_ACH_ReleaseAchievementImage);
    return proxyFunc(aImage);
}

EXPORT bool UPLAY_ACH_ReleaseAchievementList(intptr_t aList)
{
    GET_PROXY_FUNC(UPLAY_ACH_ReleaseAchievementList);
    return proxyFunc(aList);
}

EXPORT bool UPLAY_ACH_Write(intptr_t aAchievement)
{
    GET_PROXY_FUNC(UPLAY_ACH_Write);
    return proxyFunc(aAchievement);
}

EXPORT bool UPLAY_AVATAR_GetBitmap(intptr_t aAvatarId, int aAvatarSize, intptr_t aOutRGBA, intptr_t aOverlapped)
{
    GET_PROXY_FUNC(UPLAY_AVATAR_GetBitmap);
    return proxyFunc(aAvatarId, aAvatarSize, aOutRGBA, aOverlapped);
}

EXPORT bool UPLAY_AVATAR_GetAvatarIdForCurrentUser(intptr_t aOutAvatarId, intptr_t aOverlapped)
{
    GET_PROXY_FUNC(UPLAY_AVATAR_GetAvatarIdForCurrentUser);
    return proxyFunc(aOutAvatarId, aOverlapped);
}

EXPORT bool UPLAY_AVATAR_Get(intptr_t aAccountIdUtf8, int aAvatarSize, intptr_t aOutRGBA, intptr_t aOverlapped)
{
    GET_PROXY_FUNC(UPLAY_AVATAR_Get);
    return proxyFunc(aAccountIdUtf8, aAvatarSize, aOutRGBA, aOverlapped);
}

EXPORT bool UPLAY_AVATAR_Release(intptr_t aRGBA)
{
    GET_PROXY_FUNC(UPLAY_AVATAR_Release);
    return proxyFunc(aRGBA);
}

EXPORT bool UPLAY_CHAT_GetHistory(intptr_t aAccountIdUtf8, unsigned aMaxNumberOfMessages, intptr_t aOutHistoryList, intptr_t aOverlapped)
{
    GET_PROXY_FUNC(UPLAY_CHAT_GetHistory);
    return proxyFunc(aAccountIdUtf8, aMaxNumberOfMessages, aOutHistoryList, aOverlapped);
}

EXPORT bool UPLAY_CHAT_Init(int aFlags)
{
    GET_PROXY_FUNC(UPLAY_CHAT_Init);
    return proxyFunc(aFlags);
}

EXPORT bool UPLAY_CHAT_ReleaseHistoryList(intptr_t aHistoryList)
{
    GET_PROXY_FUNC(UPLAY_CHAT_ReleaseHistoryList);
    return proxyFunc(aHistoryList);
}

EXPORT bool UPLAY_CHAT_SendMessage(intptr_t aAccountIdUtf8, intptr_t aMessageUtf8, intptr_t aData)
{
    GET_PROXY_FUNC(UPLAY_CHAT_SendMessage);
    return proxyFunc(aAccountIdUtf8, aMessageUtf8, aData);
}

EXPORT bool UPLAY_CHAT_SetMessagesRead(intptr_t aAccountIdUtf8)
{
    GET_PROXY_FUNC(UPLAY_CHAT_SetMessagesRead);
    return proxyFunc(aAccountIdUtf8);
}

EXPORT bool UPLAY_ClearGameSession()
{
    GET_PROXY_FUNC(UPLAY_ClearGameSession);
    return proxyFunc();
}

EXPORT bool UPLAY_FRIENDS_AddPlayedWith(intptr_t aDescriptionUtf8, intptr_t aAccountIdListUtf8, unsigned aAccountIdListLength)
{
    GET_PROXY_FUNC(UPLAY_FRIENDS_AddPlayedWith);
    return proxyFunc(aDescriptionUtf8, aAccountIdListUtf8, aAccountIdListLength);
}

EXPORT bool UPLAY_FRIENDS_AddToBlackList(intptr_t aAccountIdUtf8, intptr_t aOverlapped)
{
    GET_PROXY_FUNC(UPLAY_FRIENDS_AddToBlackList);
    return proxyFunc(aAccountIdUtf8, aOverlapped);
}

EXPORT bool UPLAY_FRIENDS_DisableFriendMenuItem(unsigned aId)
{
    GET_PROXY_FUNC(UPLAY_FRIENDS_DisableFriendMenuItem);
    return proxyFunc(aId);
}

EXPORT bool UPLAY_FRIENDS_EnableFriendMenuItem(unsigned aId, unsigned aMenuItemMode, unsigned aFilter)
{
    GET_PROXY_FUNC(UPLAY_FRIENDS_EnableFriendMenuItem);
    return proxyFunc(aId, aMenuItemMode, aFilter);
}

EXPORT bool UPLAY_FRIENDS_GetFriendList(unsigned aFriendListFilter, intptr_t aOutFriendList)
{
    GET_PROXY_FUNC(UPLAY_FRIENDS_GetFriendList);
    return proxyFunc(aFriendListFilter, aOutFriendList);
}

EXPORT bool UPLAY_FRIENDS_Init(unsigned aFlags)
{
    GET_PROXY_FUNC(UPLAY_FRIENDS_Init);
    return proxyFunc(aFlags);
}

EXPORT bool UPLAY_FRIENDS_InviteToGame(intptr_t aAccountIdUtf8, intptr_t aOverlapped)
{
    GET_PROXY_FUNC(UPLAY_FRIENDS_InviteToGame);
    return proxyFunc(aAccountIdUtf8, aOverlapped);
}

EXPORT bool UPLAY_FRIENDS_IsBlackListed(intptr_t aAccountIdUtf8)
{
    GET_PROXY_FUNC(UPLAY_FRIENDS_IsBlackListed);
    return proxyFunc(aAccountIdUtf8);
}

EXPORT bool UPLAY_FRIENDS_IsFriend(intptr_t aAccountIdUtf8)
{
    GET_PROXY_FUNC(UPLAY_FRIENDS_IsFriend);
    return proxyFunc(aAccountIdUtf8);
}

EXPORT bool UPLAY_FRIENDS_RemoveFriendship(intptr_t aAccountIdUtf8, intptr_t aOverlapped)
{
    GET_PROXY_FUNC(UPLAY_FRIENDS_RemoveFriendship);
    return proxyFunc(aAccountIdUtf8, aOverlapped);
}

EXPORT bool UPLAY_FRIENDS_RemoveFromBlackList(intptr_t aAccountIdUtf8, intptr_t aOverlapped)
{
    GET_PROXY_FUNC(UPLAY_FRIENDS_RemoveFromBlackList);
    return proxyFunc(aAccountIdUtf8, aOverlapped);
}

EXPORT bool UPLAY_FRIENDS_RequestFriendship(intptr_t aSearchStringUtf8, intptr_t aOverlapped)
{
    GET_PROXY_FUNC(UPLAY_FRIENDS_RequestFriendship);
    return proxyFunc(aSearchStringUtf8, aOverlapped);
}

EXPORT bool UPLAY_FRIENDS_RespondToGameInvite(unsigned aInvitationId, intptr_t aAccept)
{
    GET_PROXY_FUNC(UPLAY_FRIENDS_RespondToGameInvite);
    return proxyFunc(aInvitationId, aAccept);
}

EXPORT bool UPLAY_FRIENDS_ShowFriendSelectionUI(intptr_t aAccountIdFilterListUTF8, unsigned aAccountIdFilterListLength, intptr_t aOverlapped, intptr_t aOutResult)
{
    GET_PROXY_FUNC(UPLAY_FRIENDS_ShowFriendSelectionUI);
    return proxyFunc(aAccountIdFilterListUTF8, aAccountIdFilterListLength, aOverlapped, aOutResult);
}

EXPORT bool UPLAY_FRIENDS_ShowInviteFriendsToGameUI(intptr_t aAccountIdFilterListUtf8, unsigned aAccountIdFilterListLength)
{
    GET_PROXY_FUNC(UPLAY_FRIENDS_ShowInviteFriendsToGameUI);
    return proxyFunc(aAccountIdFilterListUtf8, aAccountIdFilterListLength);
}

EXPORT bool UPLAY_GetLastError(intptr_t aOutErrorString)
{
    GET_PROXY_FUNC(UPLAY_GetLastError);
    return proxyFunc(aOutErrorString);
}

EXPORT bool UPLAY_GetNextEvent(intptr_t aEvent)
{
    GET_PROXY_FUNC(UPLAY_GetNextEvent);
    return proxyFunc(aEvent);
}

EXPORT bool UPLAY_GetOverlappedOperationResult(intptr_t aOverlapped, intptr_t aOutResult)
{
    GET_PROXY_FUNC(UPLAY_GetOverlappedOperationResult);
    return proxyFunc(aOverlapped, aOutResult);
}

EXPORT bool UPLAY_HasOverlappedOperationCompleted(intptr_t aOverlapped)
{
    GET_PROXY_FUNC(UPLAY_HasOverlappedOperationCompleted);
    return proxyFunc(aOverlapped);
}

EXPORT bool UPLAY_INSTALLER_AreChunksInstalled(intptr_t aChunkIds, unsigned aChunkCount)
{
    GET_PROXY_FUNC(UPLAY_INSTALLER_AreChunksInstalled);
    return proxyFunc(aChunkIds, aChunkCount);
}

EXPORT bool UPLAY_INSTALLER_GetChunkIdsFromTag(intptr_t aTagUtf8, intptr_t aOutChunkIdList)
{
    GET_PROXY_FUNC(UPLAY_INSTALLER_GetChunkIdsFromTag);
    return proxyFunc(aTagUtf8, aOutChunkIdList);
}

EXPORT bool UPLAY_INSTALLER_GetChunks(intptr_t aOutChunkIdList)
{
    GET_PROXY_FUNC(UPLAY_INSTALLER_GetChunks);
    return proxyFunc(aOutChunkIdList);
}

EXPORT intptr_t UPLAY_INSTALLER_GetLanguageUtf8()
{
    GET_PROXY_FUNC(UPLAY_INSTALLER_GetLanguageUtf8);
    return proxyFunc();
}

EXPORT bool UPLAY_INSTALLER_Init(unsigned aFlags)
{
    GET_PROXY_FUNC(UPLAY_INSTALLER_Init);
    return proxyFunc(aFlags);
}

EXPORT bool UPLAY_INSTALLER_ReleaseChunkIdList(intptr_t aChunkIdList)
{
    GET_PROXY_FUNC(UPLAY_INSTALLER_ReleaseChunkIdList);
    return proxyFunc(aChunkIdList);
}

EXPORT bool UPLAY_INSTALLER_UpdateInstallOrder(intptr_t aChunkIds, unsigned aChunkCount)
{
    GET_PROXY_FUNC(UPLAY_INSTALLER_UpdateInstallOrder);
    return proxyFunc(aChunkIds, aChunkCount);
}

EXPORT bool UPLAY_Init()
{
    GET_PROXY_FUNC(UPLAY_Init);
    return proxyFunc();
}

EXPORT bool UPLAY_METADATA_ClearContinuousTag(intptr_t aStringNameUtf8)
{
    GET_PROXY_FUNC(UPLAY_METADATA_ClearContinuousTag);
    return proxyFunc(aStringNameUtf8);
}

EXPORT bool UPLAY_METADATA_SetContinuousTag(intptr_t aStringNameUtf8, intptr_t aStringValueUtf8)
{
    GET_PROXY_FUNC(UPLAY_METADATA_SetContinuousTag);
    return proxyFunc(aStringNameUtf8, aStringValueUtf8);
}

EXPORT bool UPLAY_METADATA_SetSingleEventTag(intptr_t aStringNameUtf8, intptr_t aStringValueUtf8)
{
    GET_PROXY_FUNC(UPLAY_METADATA_SetSingleEventTag);
    return proxyFunc(aStringNameUtf8, aStringValueUtf8);
}

EXPORT bool UPLAY_OPTIONS_Apply(intptr_t aFileHandle, intptr_t aKeyValueList, intptr_t aOverlapped)
{
    GET_PROXY_FUNC(UPLAY_OPTIONS_Apply);
    return proxyFunc(aFileHandle, aKeyValueList, aOverlapped);
}

EXPORT bool UPLAY_OPTIONS_Close(intptr_t aFileHandle)
{
    GET_PROXY_FUNC(UPLAY_OPTIONS_Close);
    return proxyFunc(aFileHandle);
}

EXPORT bool UPLAY_OPTIONS_Enumerate(intptr_t aFileHandle, intptr_t aOutKeyValueList, intptr_t aOverlapped)
{
    GET_PROXY_FUNC(UPLAY_OPTIONS_Enumerate);
    return proxyFunc(aFileHandle, aOutKeyValueList, aOverlapped);
}

EXPORT bool UPLAY_OPTIONS_Get(intptr_t aKeyValueList, intptr_t aKey)
{
    GET_PROXY_FUNC(UPLAY_OPTIONS_Get);
    return proxyFunc(aKeyValueList, aKey);
}

EXPORT bool UPLAY_OPTIONS_Open(intptr_t aName)
{
    GET_PROXY_FUNC(UPLAY_OPTIONS_Open);
    return proxyFunc(aName);
}

EXPORT bool UPLAY_OPTIONS_ReleaseKeyValueList(intptr_t aKeyValueList)
{
    GET_PROXY_FUNC(UPLAY_OPTIONS_ReleaseKeyValueList);
    return proxyFunc(aKeyValueList);
}

EXPORT bool UPLAY_OPTIONS_Set(intptr_t aKeyValueList, intptr_t aKey, intptr_t aValue)
{
    GET_PROXY_FUNC(UPLAY_OPTIONS_Set);
    return proxyFunc(aKeyValueList, aKey, aValue);
}

EXPORT bool UPLAY_OPTIONS_SetInGameState(unsigned aFlags)
{
    GET_PROXY_FUNC(UPLAY_OPTIONS_SetInGameState);
    return proxyFunc(aFlags);
}

EXPORT bool UPLAY_OVERLAY_SetShopUrl(intptr_t aUrl, intptr_t aOverlapped)
{
    GET_PROXY_FUNC(UPLAY_OVERLAY_SetShopUrl);
    return proxyFunc(aUrl, aOverlapped);
}

EXPORT bool UPLAY_OVERLAY_Show(intptr_t aOverlaySection, intptr_t aOverlapped)
{
    GET_PROXY_FUNC(UPLAY_OVERLAY_Show);
    return proxyFunc(aOverlaySection, aOverlapped);
}

EXPORT bool UPLAY_OVERLAY_ShowBrowserUrl(intptr_t aUrlUtf8)
{
    GET_PROXY_FUNC(UPLAY_OVERLAY_ShowBrowserUrl);
    return proxyFunc(aUrlUtf8);
}

EXPORT bool UPLAY_OVERLAY_ShowFacebookAuthentication(intptr_t aFacebookAppId, intptr_t aRedirectUri, intptr_t aOverlapped)
{
    GET_PROXY_FUNC(UPLAY_OVERLAY_ShowFacebookAuthentication);
    return proxyFunc(aFacebookAppId, aRedirectUri, aOverlapped);
}

EXPORT bool UPLAY_OVERLAY_ShowMicroApp(intptr_t aAppName, intptr_t aMicroAppParamList, intptr_t aOverlapped)
{
    GET_PROXY_FUNC(UPLAY_OVERLAY_ShowMicroApp);
    return proxyFunc(aAppName, aMicroAppParamList, aOverlapped);
}

EXPORT bool UPLAY_OVERLAY_ShowNotification(unsigned aNotificationId)
{
    GET_PROXY_FUNC(UPLAY_OVERLAY_ShowNotification);
    return proxyFunc(aNotificationId);
}

EXPORT bool UPLAY_OVERLAY_ShowShopUrl(intptr_t aUrlUtf8)
{
    GET_PROXY_FUNC(UPLAY_OVERLAY_ShowShopUrl);
    return proxyFunc(aUrlUtf8);
}

EXPORT bool UPLAY_PARTY_DisablePartyMemberMenuItem()
{
    GET_PROXY_FUNC(UPLAY_PARTY_DisablePartyMemberMenuItem);
    return proxyFunc();
}

EXPORT bool UPLAY_PARTY_EnablePartyMemberMenuItem()
{
    GET_PROXY_FUNC(UPLAY_PARTY_EnablePartyMemberMenuItem);
    return proxyFunc();
}

EXPORT bool UPLAY_PARTY_GetFullMemberList(intptr_t aOutMemberList)
{
    GET_PROXY_FUNC(UPLAY_PARTY_GetFullMemberList);
    return proxyFunc(aOutMemberList);
}

EXPORT int UPLAY_PARTY_GetId()
{
    GET_PROXY_FUNC(UPLAY_PARTY_GetId);
    return proxyFunc();
}

EXPORT bool UPLAY_PARTY_GetInGameMemberList(intptr_t aOutMemberList)
{
    GET_PROXY_FUNC(UPLAY_PARTY_GetInGameMemberList);
    return proxyFunc(aOutMemberList);
}

EXPORT bool UPLAY_PARTY_Init(unsigned aFlags)
{
    GET_PROXY_FUNC(UPLAY_PARTY_Init);
    return proxyFunc(aFlags);
}

EXPORT bool UPLAY_PARTY_InvitePartyToGame(intptr_t aOverlapped)
{
    GET_PROXY_FUNC(UPLAY_PARTY_InvitePartyToGame);
    return proxyFunc(aOverlapped);
}

EXPORT bool UPLAY_PARTY_InviteToParty(intptr_t aAccountIdUtf8, intptr_t aOverlapped)
{
    GET_PROXY_FUNC(UPLAY_PARTY_InviteToParty);
    return proxyFunc(aAccountIdUtf8, aOverlapped);
}

EXPORT bool UPLAY_PARTY_IsInParty(intptr_t aAccountIdUtf8)
{
    GET_PROXY_FUNC(UPLAY_PARTY_IsInParty);
    return proxyFunc(aAccountIdUtf8);
}

EXPORT bool UPLAY_PARTY_IsPartyLeader(intptr_t aAccountIdUtf8)
{
    GET_PROXY_FUNC(UPLAY_PARTY_IsPartyLeader);
    return proxyFunc(aAccountIdUtf8);
}

EXPORT bool UPLAY_PARTY_PromoteToLeader(intptr_t aAccountIdUtf8, intptr_t aOverlapped)
{
    GET_PROXY_FUNC(UPLAY_PARTY_PromoteToLeader);
    return proxyFunc(aAccountIdUtf8, aOverlapped);
}

EXPORT bool UPLAY_PARTY_RespondToGameInvite(unsigned aInvitationId, bool aAccept)
{
    GET_PROXY_FUNC(UPLAY_PARTY_RespondToGameInvite);
    return proxyFunc(aInvitationId, aAccept);
}

EXPORT bool UPLAY_PARTY_SetGuest(intptr_t guestId, intptr_t aOverlapped)
{
    GET_PROXY_FUNC(UPLAY_PARTY_SetGuest);
    return proxyFunc(guestId, aOverlapped);
}

EXPORT bool UPLAY_PARTY_SetUserData(intptr_t aDataBlob)
{
    GET_PROXY_FUNC(UPLAY_PARTY_SetUserData);
    return proxyFunc(aDataBlob);
}

EXPORT bool UPLAY_PARTY_ShowGameInviteOverlayUI(unsigned aInvitationId)
{
    GET_PROXY_FUNC(UPLAY_PARTY_ShowGameInviteOverlayUI);
    return proxyFunc(aInvitationId);
}

EXPORT bool UPLAY_PRESENCE_SetPresence(unsigned presenceId, intptr_t tokens)
{
    GET_PROXY_FUNC(UPLAY_PRESENCE_SetPresence);
    return proxyFunc(presenceId, tokens);
}

EXPORT bool UPLAY_PRODUCT_GetProductList(intptr_t aOverlapped, intptr_t aOutProductList)
{
    GET_PROXY_FUNC(UPLAY_PRODUCT_GetProductList);
    return proxyFunc(aOverlapped, aOutProductList);
}

EXPORT bool UPLAY_PRODUCT_ReleaseProductList(intptr_t aProductList)
{
    GET_PROXY_FUNC(UPLAY_PRODUCT_ReleaseProductList);
    return proxyFunc(aProductList);
}

EXPORT bool UPLAY_PeekNextEvent()
{
    GET_PROXY_FUNC(UPLAY_PeekNextEvent);
    return proxyFunc();
}

EXPORT bool UPLAY_Quit()
{
    GET_PROXY_FUNC(UPLAY_Quit);
    return proxyFunc();
}

EXPORT bool UPLAY_Release(intptr_t aPointer)
{
    GET_PROXY_FUNC(UPLAY_Release);
    return proxyFunc(aPointer);
}

EXPORT bool UPLAY_SAVE_Close(intptr_t aOutSaveHandle)
{
    GET_PROXY_FUNC(UPLAY_SAVE_Close);
    return proxyFunc(aOutSaveHandle);
}

EXPORT bool UPLAY_SAVE_GetSavegames(intptr_t aOutGamesList, intptr_t  aOverlapped)
{
    GET_PROXY_FUNC(UPLAY_SAVE_GetSavegames);
    return proxyFunc(aOutGamesList, aOverlapped);
}

EXPORT bool UPLAY_SAVE_Open(unsigned aSlotId, unsigned aMode, intptr_t aOutSaveHandle, intptr_t  aOverlapped)
{
    GET_PROXY_FUNC(UPLAY_SAVE_Open);
    return proxyFunc(aSlotId, aMode, aOutSaveHandle, aOverlapped);
}

EXPORT bool UPLAY_SAVE_Read(intptr_t aSaveHandle, unsigned aNumOfBytesToRead, unsigned aOffset, intptr_t  aOutBuffer, unsigned aOutNumOfBytesRead, intptr_t  aOverlapped)
{
    GET_PROXY_FUNC(UPLAY_SAVE_Read);
    return proxyFunc(aSaveHandle, aNumOfBytesToRead, aOffset, aOutBuffer, aOutNumOfBytesRead, aOverlapped);
}

EXPORT bool UPLAY_SAVE_ReleaseGameList(intptr_t aGamesList)
{
    GET_PROXY_FUNC(UPLAY_SAVE_ReleaseGameList);
    return proxyFunc(aGamesList);
}

EXPORT bool UPLAY_SAVE_Remove(unsigned aSlotId, intptr_t aOverlapped)
{
    GET_PROXY_FUNC(UPLAY_SAVE_Remove);
    return proxyFunc(aSlotId, aOverlapped);
}

EXPORT bool UPLAY_SAVE_SetName(intptr_t aSaveHandle, intptr_t aNameUtf8)
{
    GET_PROXY_FUNC(UPLAY_SAVE_SetName);
    return proxyFunc(aSaveHandle, aNameUtf8);
}

EXPORT bool UPLAY_SAVE_Write(intptr_t aSaveHandle, unsigned aNumOfBytesToWrite, intptr_t aBuffer, intptr_t aOverlapped)
{
    GET_PROXY_FUNC(UPLAY_SAVE_Write);
    return proxyFunc(aSaveHandle, aNumOfBytesToWrite, aBuffer, aOverlapped);
}

EXPORT bool UPLAY_STORE_Checkout(unsigned aId)
{
    GET_PROXY_FUNC(UPLAY_STORE_Checkout);
    return proxyFunc(aId);
}

EXPORT bool UPLAY_STORE_GetPartner()
{
    GET_PROXY_FUNC(UPLAY_STORE_GetPartner);
    return proxyFunc();
}

EXPORT bool UPLAY_STORE_GetProducts(intptr_t aOverlapped, intptr_t aOutProductList)
{
    GET_PROXY_FUNC(UPLAY_STORE_GetProducts);
    return proxyFunc(aOverlapped, aOutProductList);
}

EXPORT bool UPLAY_STORE_IsEnabled()
{
    GET_PROXY_FUNC(UPLAY_STORE_IsEnabled);
    return proxyFunc();
}

EXPORT bool UPLAY_STORE_ReleaseProductsList(intptr_t aProductList)
{
    GET_PROXY_FUNC(UPLAY_STORE_ReleaseProductsList);
    return proxyFunc(aProductList);
}

EXPORT bool UPLAY_STORE_ShowProductDetails(unsigned aId)
{
    GET_PROXY_FUNC(UPLAY_STORE_ShowProductDetails);
    return proxyFunc(aId);
}

EXPORT bool UPLAY_STORE_ShowProducts(unsigned aTags)
{
    GET_PROXY_FUNC(UPLAY_STORE_ShowProducts);
    return proxyFunc(aTags);
}

EXPORT bool UPLAY_SetGameSession(intptr_t aGameSessionIdentifier, intptr_t aSessionData, unsigned aFlags)
{
    GET_PROXY_FUNC(UPLAY_SetGameSession);
    return proxyFunc(aGameSessionIdentifier, aSessionData, aFlags);
}

EXPORT bool UPLAY_SetLanguage(intptr_t aLanguageCountryCode)
{
    GET_PROXY_FUNC(UPLAY_SetLanguage);
    return proxyFunc(aLanguageCountryCode);
}

EXPORT bool UPLAY_Start(unsigned aUplayId, unsigned aFlags)
{
    GET_PROXY_FUNC(UPLAY_Start);
    return proxyFunc(aUplayId, aFlags);
}

EXPORT bool UPLAY_Startup(unsigned aUplayId, unsigned aGameVersion, intptr_t aLanguageCountryCodeUtf8)
{
    GET_PROXY_FUNC(UPLAY_Startup);
    return proxyFunc(aUplayId, aGameVersion, aLanguageCountryCodeUtf8);
}

EXPORT bool UPLAY_USER_ClearGameSession()
{
    GET_PROXY_FUNC(UPLAY_USER_ClearGameSession);
    return proxyFunc();
}

EXPORT bool UPLAY_USER_ConsumeItem(intptr_t aTransactionIdUtf8, unsigned aUplayId, unsigned aQuantity, intptr_t aSignatureUtf8, intptr_t aOverlapped, intptr_t aOutResult)
{
    GET_PROXY_FUNC(UPLAY_USER_ConsumeItem);
    return proxyFunc(aTransactionIdUtf8, aUplayId, aQuantity, aSignatureUtf8, aOverlapped, aOutResult);
}

EXPORT const char* UPLAY_USER_GetAccountId(intptr_t aOutAccountId)
{
    GET_PROXY_FUNC(UPLAY_USER_GetAccountId);
    return proxyFunc(aOutAccountId);
}

EXPORT const char* UPLAY_USER_GetAccountIdUtf8()
{
    GET_PROXY_FUNC(UPLAY_USER_GetAccountIdUtf8);
    return proxyFunc();
}

EXPORT bool UPLAY_USER_GetCPUScore(intptr_t aOutCpuScore)
{
    GET_PROXY_FUNC(UPLAY_USER_GetCPUScore);
    return proxyFunc(aOutCpuScore);
}

EXPORT const char* UPLAY_USER_GetCdKeyUtf8(unsigned aUplayId)
{
    GET_PROXY_FUNC(UPLAY_USER_GetCdKeyUtf8);
    return proxyFunc(aUplayId);
}

EXPORT bool UPLAY_USER_GetCdKeys(intptr_t aOutCdKeyList, intptr_t aOverlapped)
{
    GET_PROXY_FUNC(UPLAY_USER_GetCdKeys);
    return proxyFunc(aOutCdKeyList, aOverlapped);
}

EXPORT bool UPLAY_USER_GetConsumableItems(intptr_t aOutConsumableItemsList)
{
    GET_PROXY_FUNC(UPLAY_USER_GetConsumableItems);
    return proxyFunc(aOutConsumableItemsList);
}

EXPORT bool UPLAY_USER_GetCredentials(intptr_t aOutUserCredentials, intptr_t aOverlapped)
{
    GET_PROXY_FUNC(UPLAY_USER_GetCredentials);
    return proxyFunc(aOutUserCredentials, aOverlapped);
}

EXPORT const char* UPLAY_USER_GetEmail(intptr_t aOutEmail)
{
    GET_PROXY_FUNC(UPLAY_USER_GetEmail);
    return proxyFunc(aOutEmail);
}

EXPORT const char* UPLAY_USER_GetEmailUtf8()
{
    GET_PROXY_FUNC(UPLAY_USER_GetEmailUtf8);
    return proxyFunc();
}

EXPORT bool UPLAY_USER_GetGPUScore(intptr_t aOutGpuScore)
{
    GET_PROXY_FUNC(UPLAY_USER_GetGPUScore);
    return proxyFunc(aOutGpuScore);
}

EXPORT bool UPLAY_USER_GetGPUScoreConfidenceLevel(intptr_t aOutConfidenceLevel)
{
    GET_PROXY_FUNC(UPLAY_USER_GetGPUScoreConfidenceLevel);
    return proxyFunc(aOutConfidenceLevel);
}

EXPORT const char* UPLAY_USER_GetNameUtf8()
{
    GET_PROXY_FUNC(UPLAY_USER_GetNameUtf8);
    return proxyFunc();
}

EXPORT const char* UPLAY_USER_GetPassword(intptr_t aOutPassword)
{
    GET_PROXY_FUNC(UPLAY_USER_GetPassword);
    return proxyFunc(aOutPassword);
}

EXPORT const char* UPLAY_USER_GetPasswordUtf8()
{
    GET_PROXY_FUNC(UPLAY_USER_GetPasswordUtf8);
    return proxyFunc();
}

EXPORT bool UPLAY_USER_GetProfile(intptr_t aAccountIdUtf8, intptr_t aOverlapped, intptr_t aOutProfile)
{
    GET_PROXY_FUNC(UPLAY_USER_GetProfile);
    return proxyFunc(aAccountIdUtf8, aOverlapped, aOutProfile);
}

EXPORT const char* UPLAY_USER_GetTicketUtf8()
{
    GET_PROXY_FUNC(UPLAY_USER_GetTicketUtf8);
    return proxyFunc();
}

EXPORT const char* UPLAY_USER_GetUsername(intptr_t aOutUsername)
{
    GET_PROXY_FUNC(UPLAY_USER_GetUsername);
    return proxyFunc(aOutUsername);
}

EXPORT const char* UPLAY_USER_GetUsernameUtf8()
{
    GET_PROXY_FUNC(UPLAY_USER_GetUsernameUtf8);
    return proxyFunc();
}

EXPORT bool UPLAY_USER_IsConnected()
{
    GET_PROXY_FUNC(UPLAY_USER_IsConnected);
    return proxyFunc();
}

EXPORT bool UPLAY_USER_IsInOfflineMode()
{
    GET_PROXY_FUNC(UPLAY_USER_IsInOfflineMode);
    return proxyFunc();
}

EXPORT bool UPLAY_USER_IsOwned(unsigned aUplayId)
{
    GET_PROXY_FUNC(UPLAY_USER_IsOwned);
    return proxyFunc(aUplayId);
}

EXPORT bool UPLAY_USER_ReleaseCdKeyList(intptr_t aCdKeyList)
{
    GET_PROXY_FUNC(UPLAY_USER_ReleaseCdKeyList);
    return proxyFunc(aCdKeyList);
}

EXPORT bool UPLAY_USER_ReleaseConsumeItemResult(intptr_t aConsumeItemResult)
{
    GET_PROXY_FUNC(UPLAY_USER_ReleaseConsumeItemResult);
    return proxyFunc(aConsumeItemResult);
}

EXPORT bool UPLAY_USER_ReleaseProfile(intptr_t aOutProfile)
{
    GET_PROXY_FUNC(UPLAY_USER_ReleaseProfile);
    return proxyFunc(aOutProfile);
}

EXPORT bool UPLAY_USER_SetGameSession(intptr_t aGameSessionIdentifier, intptr_t aSessionData, unsigned aFlags)
{
    GET_PROXY_FUNC(UPLAY_USER_SetGameSession);
    return proxyFunc(aGameSessionIdentifier, aSessionData, aFlags);
}

EXPORT bool UPLAY_Update()
{
    GET_PROXY_FUNC(UPLAY_Update);
    return proxyFunc();
}

EXPORT bool UPLAY_WIN_GetActions(intptr_t aOutActionList, intptr_t aOverlapped)
{
    GET_PROXY_FUNC(UPLAY_WIN_GetActions);
    return proxyFunc(aOutActionList, aOverlapped);
}

EXPORT bool UPLAY_WIN_GetRewards(intptr_t aOutRewardList, intptr_t aOverlapped)
{
    GET_PROXY_FUNC(UPLAY_WIN_GetRewards);
    return proxyFunc(aOutRewardList, aOverlapped);
}

EXPORT bool UPLAY_WIN_GetUnitBalance(int aOutBalance, intptr_t aOverlapped)
{
    GET_PROXY_FUNC(UPLAY_WIN_GetUnitBalance);
    return proxyFunc(aOutBalance, aOverlapped);
}

EXPORT bool UPLAY_WIN_RefreshActions()
{
    GET_PROXY_FUNC(UPLAY_WIN_RefreshActions);
    return proxyFunc();
}

EXPORT bool UPLAY_WIN_ReleaseActionList(intptr_t aActionList)
{
    GET_PROXY_FUNC(UPLAY_WIN_ReleaseActionList);
    return proxyFunc(aActionList);
}

EXPORT bool UPLAY_WIN_ReleaseRewardList(intptr_t aRewardList)
{
    GET_PROXY_FUNC(UPLAY_WIN_ReleaseRewardList);
    return proxyFunc(aRewardList);
}

EXPORT bool UPLAY_WIN_SetActionsCompleted(intptr_t aActionIdsUtf8, unsigned aActionIdsCount, intptr_t aOverlapped)
{
    GET_PROXY_FUNC(UPLAY_WIN_SetActionsCompleted);
    return proxyFunc(aActionIdsUtf8, aActionIdsCount, aOverlapped);
}
#pragma endregion


