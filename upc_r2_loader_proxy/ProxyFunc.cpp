#include "pch.h"
#include "ProxyFunc.h"
#include "UPC_Enums.h"
#pragma warning(disable : 4996).
using namespace ProxyFunc;

HMODULE originalDLL = nullptr;

#define GET_PROXY_FUNC(FUNC) \
	static auto proxyFunc = FnCast(GetProcAddress(originalDLL, #FUNC), FUNC);

void ProxyFunc::init()
{
	originalDLL = LoadLibrary(ORIG_DLL);
	if (originalDLL)
	{
		PRINT_DEBUG("Successfully loaded original DLL\n");
	}
	else
	{
		PRINT_DEBUG("Failed to load original DLL. Error code: %ld\n", GetLastError());
		exit(1);
	}
}

void ProxyFunc::shutdown()
{
	PRINT_DEBUG("Shutting down\n");
	FreeLibrary(originalDLL);
}

#pragma region All Function
EXPORT int UPC_AchievementImageFree(void* inContext, void* inImageRGBA)
{
    PRINT_DEBUG("%s (Before): %p %p \n", __FUNCTION__, inContext, inImageRGBA);
    GET_PROXY_FUNC(UPC_AchievementImageFree);
    auto result = proxyFunc(inContext, inImageRGBA);
    PRINT_DEBUG("%s (After): %i  %p %p \n", __FUNCTION__, result, inContext, inImageRGBA);
    return result;
}

EXPORT int UPC_AchievementImageGet(void* inContext, unsigned inId, void* outImageRGBA, void* inCallback, void* inCallbackData)
{
    PRINT_DEBUG("%s (Before): %p %u %p %p %p \n", __FUNCTION__, inContext, inId, outImageRGBA, inCallback, inCallbackData);
    GET_PROXY_FUNC(UPC_AchievementImageGet);
    auto result = proxyFunc(inContext, inId, outImageRGBA, inCallback, inCallbackData);
    PRINT_DEBUG("%s (After): %i  %p %u %p %p %p \n", __FUNCTION__, result, inContext, inId, outImageRGBA, inCallback, inCallbackData);
    return result;
}

EXPORT int UPC_AchievementListFree(void* inContext, void* inAchievementList)
{
    PRINT_DEBUG("%s (Before): %p %p \n", __FUNCTION__, inContext, inAchievementList);
    GET_PROXY_FUNC(UPC_AchievementListFree);
    auto result = proxyFunc(inContext, inAchievementList);
    PRINT_DEBUG("%s (After): %i  %p %p \n", __FUNCTION__, result, inContext, inAchievementList);
    return result;
}

EXPORT int UPC_AchievementListGet(void* inContext, const char* inOptUserIdUtf8, unsigned inFilter, void* outAchievementList, void* inCallback, void* inCallbackData)
{
    PRINT_DEBUG("%s (Before): %p %s %u %p %p %p \n", __FUNCTION__, inContext, inOptUserIdUtf8, inFilter, outAchievementList, inCallback, inCallbackData);
    GET_PROXY_FUNC(UPC_AchievementListGet);
    auto result = proxyFunc(inContext, inOptUserIdUtf8, inFilter, outAchievementList, inCallback, inCallbackData);
    PRINT_DEBUG("%s (After): %i  %p %s %u %p %p %p \n", __FUNCTION__, result, inContext, inOptUserIdUtf8, inFilter, outAchievementList, inCallback, inCallbackData);
    return result;
}

EXPORT int UPC_AchievementUnlock(void* inContext, unsigned inId, void* inOptCallback, void* inOptCallbackData)
{
    PRINT_DEBUG("%s (Before): %p %u %p %p \n", __FUNCTION__, inContext, inId, inOptCallback, inOptCallbackData);
    GET_PROXY_FUNC(UPC_AchievementUnlock);
    auto result = proxyFunc(inContext, inId, inOptCallback, inOptCallbackData);
    PRINT_DEBUG("%s (After): %i  %p %u %p %p \n", __FUNCTION__, result, inContext, inId, inOptCallback, inOptCallbackData);
    return result;
}

EXPORT int UPC_ApplicationIdGet(void* inContext, const char** appID)
{
    PRINT_DEBUG("%s (Before): %p %p \n", __FUNCTION__, inContext, appID);
    GET_PROXY_FUNC(UPC_ApplicationIdGet);
    auto result = proxyFunc(inContext, appID);
    PRINT_DEBUG("%s (After): %i  %p %s \n", __FUNCTION__, result, inContext, *appID);
    return result;
}

EXPORT int UPC_AvatarFree(void* inContext, void* inImageRGBA)
{
    PRINT_DEBUG("%s (Before): %p %p \n", __FUNCTION__, inContext, inImageRGBA);
    GET_PROXY_FUNC(UPC_AvatarFree);
    auto result = proxyFunc(inContext, inImageRGBA);
    PRINT_DEBUG("%s (After): %i  %p %p \n", __FUNCTION__, result, inContext, inImageRGBA);
    return result;
}

EXPORT int UPC_AvatarGet(void* inContext, const char* inOptUserIdUtf8, unsigned inSize, void* outImageRGBA, void* inCallback, void* inCallbackData)
{
    PRINT_DEBUG("%s (Before): %p %s %u %p %p %p \n", __FUNCTION__, inContext, inOptUserIdUtf8, inSize, outImageRGBA, inCallback, inCallbackData);
    GET_PROXY_FUNC(UPC_AvatarGet);
    auto result = proxyFunc(inContext, inOptUserIdUtf8, inSize, outImageRGBA, inCallback, inCallbackData);
    PRINT_DEBUG("%s (After): %i  %p %s %u %p %p %p \n", __FUNCTION__, result, inContext, inOptUserIdUtf8, inSize, outImageRGBA, inCallback, inCallbackData);
    return result;
}

EXPORT int UPC_BlacklistAdd(void* inContext, const char* inUserIdUtf8, void* inOptCallback, void* inOptCallbackData)
{
    PRINT_DEBUG("%s (Before): %p %s %p %p \n", __FUNCTION__, inContext, inUserIdUtf8, inOptCallback, inOptCallbackData);
    GET_PROXY_FUNC(UPC_BlacklistAdd);
    auto result = proxyFunc(inContext, inUserIdUtf8, inOptCallback, inOptCallbackData);
    PRINT_DEBUG("%s (After): %i  %p %s %p %p \n", __FUNCTION__, result, inContext, inUserIdUtf8, inOptCallback, inOptCallbackData);
    return result;
}

EXPORT bool UPC_BlacklistHas(void* inContext, const char* inUserIdUtf8)
{
    PRINT_DEBUG("%s (Before): %p %s \n", __FUNCTION__, inContext, inUserIdUtf8);
    GET_PROXY_FUNC(UPC_BlacklistHas);
    auto result = proxyFunc(inContext, inUserIdUtf8);
    PRINT_DEBUG("%s (After): %d  %p %s \n", __FUNCTION__, result, inContext, inUserIdUtf8);
    return result;
}

EXPORT int UPC_BlacklistHas_Extended(void* inContext, const char* inUserIdUtf8, bool* outIsBlacklisted)
{
    PRINT_DEBUG("%s (Before): %p %s %d \n", __FUNCTION__, inContext, inUserIdUtf8, *outIsBlacklisted);
    GET_PROXY_FUNC(UPC_BlacklistHas_Extended);
    auto result = proxyFunc(inContext, inUserIdUtf8, outIsBlacklisted);
    PRINT_DEBUG("%s (After): %i  %p %s %d \n", __FUNCTION__, result, inContext, inUserIdUtf8, *outIsBlacklisted);
    return result;
}

EXPORT int UPC_CPUScoreGet(void* inContext, unsigned* outScore)
{
    PRINT_DEBUG("%s (Before): %p %u \n", __FUNCTION__, inContext, *outScore);
    GET_PROXY_FUNC(UPC_CPUScoreGet);
    auto result = proxyFunc(inContext, outScore);
    PRINT_DEBUG("%s (After): %i  %p %u \n", __FUNCTION__, result, inContext, *outScore);
    return result;
}

EXPORT void UPC_Cancel(void* inContext, int inHandle)
{
    PRINT_DEBUG("%s %p %i \n", __FUNCTION__, inContext, inHandle);
    GET_PROXY_FUNC(UPC_Cancel);
    proxyFunc(inContext, inHandle);
}

EXPORT void* UPC_ContextCreate(unsigned inVersion, void* inOptSettings)
{
    PRINT_DEBUG("%s (Before): %u %p \n", __FUNCTION__, inVersion, inOptSettings);
    GET_PROXY_FUNC(UPC_ContextCreate);
    auto result = proxyFunc(inVersion, inOptSettings);
    PRINT_DEBUG("%s (After): %p  %u %p \n", __FUNCTION__, result, inVersion, inOptSettings);
    return result;
}

EXPORT int UPC_ContextFree(void* inContext)
{
    PRINT_DEBUG("%s (Before): %p \n", __FUNCTION__, inContext);
    GET_PROXY_FUNC(UPC_ContextFree);
    auto result = proxyFunc(inContext);
    PRINT_DEBUG("%s (After): %p\n", __FUNCTION__, result);
    return result;
}

EXPORT const char* UPC_EmailGet(void* inContext)
{
    PRINT_DEBUG("%s (Before): %p \n", __FUNCTION__, inContext);
    GET_PROXY_FUNC(UPC_EmailGet);
    auto result = proxyFunc(inContext);
    PRINT_DEBUG("%s (After): %s\n", __FUNCTION__, result);
    return result;
}

EXPORT int UPC_EmailGet_Extended(void* inContext, const char** outEmail)
{
    PRINT_DEBUG("%s (Before): %p %s \n", __FUNCTION__, inContext, *outEmail);
    GET_PROXY_FUNC(UPC_EmailGet_Extended);
    auto result = proxyFunc(inContext, outEmail);
    PRINT_DEBUG("%s (After): %i  %p %s \n", __FUNCTION__, result, inContext, *outEmail);
    return result;
}

EXPORT const char* UPC_ErrorToString(int inError)
{
    PRINT_DEBUG("%s (Before): %i \n", __FUNCTION__, inError);
    GET_PROXY_FUNC(UPC_ErrorToString);
    auto result = proxyFunc(inError);
    PRINT_DEBUG("%s (After): %s\n", __FUNCTION__, result);
    return result;
}

EXPORT int UPC_EventNextPeek(void* inContext, void* outEvent)
{
    PRINT_DEBUG("%s (Before): %p %p \n", __FUNCTION__, inContext, outEvent);
    GET_PROXY_FUNC(UPC_EventNextPeek);
    auto result = proxyFunc(inContext, outEvent);
    PRINT_DEBUG("%s (After): %i  %p %p \n", __FUNCTION__, result, inContext, outEvent);
    return result;
}

EXPORT int UPC_EventNextPoll(void* inContext, void* outEvent)
{
    PRINT_DEBUG("%s (Before): %p %p \n", __FUNCTION__, inContext, outEvent);
    GET_PROXY_FUNC(UPC_EventNextPoll);
    auto result = proxyFunc(inContext, outEvent);
    PRINT_DEBUG("%s (After): %i  %p %p \n", __FUNCTION__, result, inContext, outEvent);
    return result;
}

EXPORT int UPC_EventRegisterHandler(void* inContext, unsigned inType, void* inHandler, void* inOptData)
{
    PRINT_DEBUG("%s (Before): %p %u %p %p \n", __FUNCTION__, inContext, inType, inHandler, inOptData);
    GET_PROXY_FUNC(UPC_EventRegisterHandler);
    auto result = proxyFunc(inContext, inType, inHandler, inOptData);
    PRINT_DEBUG("%s (After): %i  %p %u %p %p \n", __FUNCTION__, result, inContext, inType, inHandler, inOptData);
    return result;
}

EXPORT int UPC_EventUnegisterHandler(void* inContext, unsigned inType)
{
    PRINT_DEBUG("%s (Before): %p %u \n", __FUNCTION__, inContext, inType);
    GET_PROXY_FUNC(UPC_EventUnegisterHandler);
    auto result = proxyFunc(inContext, inType);
    PRINT_DEBUG("%s (After): %i  %p %u \n", __FUNCTION__, result, inContext, inType);
    return result;
}

EXPORT int UPC_FriendAdd(void* inContext, const char* inSearchStringUtf8, void* inOptCallback, void* inOptCallbackData)
{
    PRINT_DEBUG("%s (Before): %p %s %p %p \n", __FUNCTION__, inContext, inSearchStringUtf8, inOptCallback, inOptCallbackData);
    GET_PROXY_FUNC(UPC_FriendAdd);
    auto result = proxyFunc(inContext, inSearchStringUtf8, inOptCallback, inOptCallbackData);
    PRINT_DEBUG("%s (After): %i  %p %s %p %p \n", __FUNCTION__, result, inContext, inSearchStringUtf8, inOptCallback, inOptCallbackData);
    return result;
}

EXPORT bool UPC_FriendCheck(void* inContext, const char* inUserIdUtf8)
{
    PRINT_DEBUG("%s (Before): %p %s \n", __FUNCTION__, inContext, inUserIdUtf8);
    GET_PROXY_FUNC(UPC_FriendCheck);
    auto result = proxyFunc(inContext, inUserIdUtf8);
    PRINT_DEBUG("%s (After): %d  %p %s \n", __FUNCTION__, result, inContext, inUserIdUtf8);
    return result;
}

EXPORT int UPC_FriendCheck_Extended(void* inContext, const char* inUserIdUtf8, bool* outIsFriend)
{
    PRINT_DEBUG("%s (Before): %p %s %d \n", __FUNCTION__, inContext, inUserIdUtf8, *outIsFriend);
    GET_PROXY_FUNC(UPC_FriendCheck_Extended);
    auto result = proxyFunc(inContext, inUserIdUtf8, outIsFriend);
    PRINT_DEBUG("%s (After): %i  %p %s %d \n", __FUNCTION__, result, inContext, inUserIdUtf8, *outIsFriend);
    return result;
}

EXPORT int UPC_FriendListFree(void* inContext, void* inFriendList)
{
    PRINT_DEBUG("%s (Before): %p %p \n", __FUNCTION__, inContext, inFriendList);
    GET_PROXY_FUNC(UPC_FriendListFree);
    auto result = proxyFunc(inContext, inFriendList);
    PRINT_DEBUG("%s (After): %i  %p %p \n", __FUNCTION__, result, inContext, inFriendList);
    return result;
}

EXPORT int UPC_FriendListGet(void* inContext, unsigned inOptOnlineStatusFilter, void* outFriendList, void* inCallback, void* inOptCallbackData)
{
    PRINT_DEBUG("%s (Before): %p %u %p %p %p \n", __FUNCTION__, inContext, inOptOnlineStatusFilter, outFriendList, inCallback, inOptCallbackData);
    GET_PROXY_FUNC(UPC_FriendListGet);
    auto result = proxyFunc(inContext, inOptOnlineStatusFilter, outFriendList, inCallback, inOptCallbackData);
    PRINT_DEBUG("%s (After): %i  %p %u %p %p %p \n", __FUNCTION__, result, inContext, inOptOnlineStatusFilter, outFriendList, inCallback, inOptCallbackData);
    return result;
}

EXPORT int UPC_FriendRemove(void* inContext, const char* inUserIdUtf8, void* inOptCallback, void* inOptCallbackData)
{
    PRINT_DEBUG("%s (Before): %p %s %p %p \n", __FUNCTION__, inContext, inUserIdUtf8, inOptCallback, inOptCallbackData);
    GET_PROXY_FUNC(UPC_FriendRemove);
    auto result = proxyFunc(inContext, inUserIdUtf8, inOptCallback, inOptCallbackData);
    PRINT_DEBUG("%s (After): %i  %p %s %p %p \n", __FUNCTION__, result, inContext, inUserIdUtf8, inOptCallback, inOptCallbackData);
    return result;
}

EXPORT int UPC_GPUScoreGet(void* inContext, unsigned* outScore, float* outConfidenceLevel)
{
    PRINT_DEBUG("%s (Before): %p %u %g \n", __FUNCTION__, inContext, *outScore, *outConfidenceLevel);
    GET_PROXY_FUNC(UPC_GPUScoreGet);
    auto result = proxyFunc(inContext, outScore, outConfidenceLevel);
    PRINT_DEBUG("%s (After): %i  %p %u %g \n", __FUNCTION__, result, inContext, *outScore, *outConfidenceLevel);
    return result;
}

EXPORT const char* UPC_IdGet(void* inContext)
{
    PRINT_DEBUG("%s (Before): %p \n", __FUNCTION__, inContext);
    GET_PROXY_FUNC(UPC_IdGet);
    auto result = proxyFunc(inContext);
    PRINT_DEBUG("%s (After): %s\n", __FUNCTION__, result);
    return result;
}

EXPORT int UPC_IdGet_Extended(void* inContext, const char* outId)
{
    PRINT_DEBUG("%s (Before): %p %p \n", __FUNCTION__, inContext, outId);
    GET_PROXY_FUNC(UPC_IdGet_Extended);
    auto result = proxyFunc(inContext, outId);
    PRINT_DEBUG("%s (After): %i  %p %p \n", __FUNCTION__, result, inContext, outId);
    return result;
}

EXPORT int UPC_Init(unsigned inVersion, unsigned inProductId)
{
    PRINT_DEBUG("%s (Before): %u %u \n", __FUNCTION__, inVersion, inProductId);
    GET_PROXY_FUNC(UPC_Init);
    auto result = proxyFunc(inVersion, inProductId);
    PRINT_DEBUG("%s (After): %i  %u %u \n", __FUNCTION__, result, inVersion, inProductId);
    return result;
}

EXPORT int UPC_InstallChunkListFree(void* inContext, void* inChunkList)
{
    PRINT_DEBUG("%s (Before): %p %p \n", __FUNCTION__, inContext, inChunkList);
    GET_PROXY_FUNC(UPC_InstallChunkListFree);
    auto result = proxyFunc(inContext, inChunkList);
    PRINT_DEBUG("%s (After): %i  %p %p \n", __FUNCTION__, result, inContext, inChunkList);
    return result;
}

EXPORT int UPC_InstallChunkListGet(void* inContext, void* outChunkList)
{
    PRINT_DEBUG("%s (Before): %p %p \n", __FUNCTION__, inContext, outChunkList);
    GET_PROXY_FUNC(UPC_InstallChunkListGet);
    auto result = proxyFunc(inContext, outChunkList);
    PRINT_DEBUG("%s (After): %i  %p %p \n", __FUNCTION__, result, inContext, outChunkList);
    return result;
}

EXPORT int UPC_InstallChunksOrderUpdate(void* inContext, void* inChunkIds, unsigned inChunkCount)
{
    PRINT_DEBUG("%s (Before): %p %p %u \n", __FUNCTION__, inContext, inChunkIds, inChunkCount);
    GET_PROXY_FUNC(UPC_InstallChunksOrderUpdate);
    auto result = proxyFunc(inContext, inChunkIds, inChunkCount);
    PRINT_DEBUG("%s (After): %i  %p %p %u \n", __FUNCTION__, result, inContext, inChunkIds, inChunkCount);
    return result;
}

EXPORT int UPC_InstallChunksOrderUpdate_Extended(void* inContext, void* inChunkIds, unsigned inChunkCount, void* unknown1, void* unknown2)
{
    PRINT_DEBUG("%s (Before): %p %p %u %p %p \n", __FUNCTION__, inContext, inChunkIds, inChunkCount, unknown1, unknown2);
    GET_PROXY_FUNC(UPC_InstallChunksOrderUpdate_Extended);
    auto result = proxyFunc(inContext, inChunkIds, inChunkCount, unknown1, unknown2);
    PRINT_DEBUG("%s (After): %i  %p %p %u %p %p \n", __FUNCTION__, result, inContext, inChunkIds, inChunkCount, unknown1, unknown2);
    return result;
}

EXPORT bool UPC_InstallChunksPresenceCheck(void* inContext, void* inChunkIds, unsigned inChunkCount)
{
    PRINT_DEBUG("%s (Before): %p %p %u \n", __FUNCTION__, inContext, inChunkIds, inChunkCount);
    GET_PROXY_FUNC(UPC_InstallChunksPresenceCheck);
    auto result = proxyFunc(inContext, inChunkIds, inChunkCount);
    PRINT_DEBUG("%s (After): %d  %p %p %u \n", __FUNCTION__, result, inContext, inChunkIds, inChunkCount);
    return result;
}

EXPORT const char* UPC_InstallLanguageGet(void* inContext)
{
    PRINT_DEBUG("%s (Before): %p \n", __FUNCTION__, inContext);
    GET_PROXY_FUNC(UPC_InstallLanguageGet);
    auto result = proxyFunc(inContext);
    PRINT_DEBUG("%s (After): %s\n", __FUNCTION__, result);
    return result;
}

EXPORT int UPC_InstallLanguageGet_Extended(void* inContext, const char** outInstallLanguage)
{
    PRINT_DEBUG("%s (Before): %p %s \n", __FUNCTION__, inContext, *outInstallLanguage);
    GET_PROXY_FUNC(UPC_InstallLanguageGet_Extended);
    auto result = proxyFunc(inContext, outInstallLanguage);
    PRINT_DEBUG("%s (After): %i  %p %s \n", __FUNCTION__, result, inContext, *outInstallLanguage);
    return result;
}

EXPORT int UPC_LaunchApp(void* inContext, unsigned inProductId, void* MustBeZero)
{
    PRINT_DEBUG("%s (Before): %p %u %p \n", __FUNCTION__, inContext, inProductId, MustBeZero);
    GET_PROXY_FUNC(UPC_LaunchApp);
    auto result = proxyFunc(inContext, inProductId, MustBeZero);
    PRINT_DEBUG("%s (After): %i  %p %u %p \n", __FUNCTION__, result, inContext, inProductId, MustBeZero);
    return result;
}

EXPORT int UPC_MultiplayerInvite(void* inContext, const char* inUserIdUtf8, void* inOptCallback, void* inOptCallbackData)
{
    PRINT_DEBUG("%s (Before): %p %s %p %p \n", __FUNCTION__, inContext, inUserIdUtf8, inOptCallback, inOptCallbackData);
    GET_PROXY_FUNC(UPC_MultiplayerInvite);
    auto result = proxyFunc(inContext, inUserIdUtf8, inOptCallback, inOptCallbackData);
    PRINT_DEBUG("%s (After): %i  %p %s %p %p \n", __FUNCTION__, result, inContext, inUserIdUtf8, inOptCallback, inOptCallbackData);
    return result;
}

EXPORT int UPC_MultiplayerInviteAnswer(void* inContext, const char* inSenderIdUtf8, int inIsAccepted, void* inOptCallback, void* inOptCallbackData)
{
    PRINT_DEBUG("%s (Before): %p %s %i %p %p \n", __FUNCTION__, inContext, inSenderIdUtf8, inIsAccepted, inOptCallback, inOptCallbackData);
    GET_PROXY_FUNC(UPC_MultiplayerInviteAnswer);
    auto result = proxyFunc(inContext, inSenderIdUtf8, inIsAccepted, inOptCallback, inOptCallbackData);
    PRINT_DEBUG("%s (After): %i  %p %s %i %p %p \n", __FUNCTION__, result, inContext, inSenderIdUtf8, inIsAccepted, inOptCallback, inOptCallbackData);
    return result;
}

EXPORT int UPC_MultiplayerSessionClear(void* inContext)
{
    PRINT_DEBUG("%s (Before): %p \n", __FUNCTION__, inContext);
    GET_PROXY_FUNC(UPC_MultiplayerSessionClear);
    auto result = proxyFunc(inContext);
    PRINT_DEBUG("%s (After): %i\n", __FUNCTION__, result);
    return result;
}

EXPORT int UPC_MultiplayerSessionClear_Extended(void* inContext, void* unknown1, void* unknown2)
{
    PRINT_DEBUG("%s (Before): %p %p %p \n", __FUNCTION__, inContext, unknown1, unknown2);
    GET_PROXY_FUNC(UPC_MultiplayerSessionClear_Extended);
    auto result = proxyFunc(inContext, unknown1, unknown2);
    PRINT_DEBUG("%s (After): %i  %p %p %p \n", __FUNCTION__, result, inContext, unknown1, unknown2);
    return result;
}

EXPORT int UPC_MultiplayerSessionFree(void* inContext, void* inMultiplayerSession)
{
    PRINT_DEBUG("%s (Before): %p %p \n", __FUNCTION__, inContext, inMultiplayerSession);
    GET_PROXY_FUNC(UPC_MultiplayerSessionFree);
    auto result = proxyFunc(inContext, inMultiplayerSession);
    PRINT_DEBUG("%s (After): %i  %p %p \n", __FUNCTION__, result, inContext, inMultiplayerSession);
    return result;
}

EXPORT int UPC_MultiplayerSessionGet(void* inContext, void* outMultiplayerSession)
{
    PRINT_DEBUG("%s (Before): %p %p \n", __FUNCTION__, inContext, outMultiplayerSession);
    GET_PROXY_FUNC(UPC_MultiplayerSessionGet);
    auto result = proxyFunc(inContext, outMultiplayerSession);
    PRINT_DEBUG("%s (After): %i  %p %p \n", __FUNCTION__, result, inContext, outMultiplayerSession);
    return result;
}

EXPORT int UPC_MultiplayerSessionSet(void* inContext, void* inMultiplayerSession)
{
    PRINT_DEBUG("%s (Before): %p %p \n", __FUNCTION__, inContext, inMultiplayerSession);
    GET_PROXY_FUNC(UPC_MultiplayerSessionSet);
    auto result = proxyFunc(inContext, inMultiplayerSession);
    PRINT_DEBUG("%s (After): %i  %p %p \n", __FUNCTION__, result, inContext, inMultiplayerSession);
    return result;
}

EXPORT int UPC_MultiplayerSessionSet_Extended(void* inContext, void* inMultiplayerSession, void* unknown1, void* unknown2)
{
    PRINT_DEBUG("%s (Before): %p %p %p %p \n", __FUNCTION__, inContext, inMultiplayerSession, unknown1, unknown2);
    GET_PROXY_FUNC(UPC_MultiplayerSessionSet_Extended);
    auto result = proxyFunc(inContext, inMultiplayerSession, unknown1, unknown2);
    PRINT_DEBUG("%s (After): %i  %p %p %p %p \n", __FUNCTION__, result, inContext, inMultiplayerSession, unknown1, unknown2);
    return result;
}

EXPORT const char* UPC_NameGet(void* inContext)
{
    PRINT_DEBUG("%s (Before): %p \n", __FUNCTION__, inContext);
    GET_PROXY_FUNC(UPC_NameGet);
    auto result = proxyFunc(inContext);
    PRINT_DEBUG("%s (After): %s\n", __FUNCTION__, result);
    return result;
}

EXPORT int UPC_NameGet_Extended(void* inContext, const char** userName)
{
    PRINT_DEBUG("%s (Before): %p %s \n", __FUNCTION__, inContext, *userName);
    GET_PROXY_FUNC(UPC_NameGet_Extended);
    auto result = proxyFunc(inContext, userName);
    PRINT_DEBUG("%s (After): %i  %p %s \n", __FUNCTION__, result, inContext, *userName);
    return result;
}

EXPORT int UPC_OverlayBrowserUrlShow(void* inContext, const char* inBrowserUrlUtf8, void* inOptCallback, void* inOptCallbackData)
{
    PRINT_DEBUG("%s (Before): %p %s %p %p \n", __FUNCTION__, inContext, inBrowserUrlUtf8, inOptCallback, inOptCallbackData);
    GET_PROXY_FUNC(UPC_OverlayBrowserUrlShow);
    auto result = proxyFunc(inContext, inBrowserUrlUtf8, inOptCallback, inOptCallbackData);
    PRINT_DEBUG("%s (After): %i  %p %s %p %p \n", __FUNCTION__, result, inContext, inBrowserUrlUtf8, inOptCallback, inOptCallbackData);
    return result;
}

EXPORT int UPC_OverlayFriendInvitationShow(void* inContext, const char* inOptIdListUtf8, unsigned inOptIdListLength)
{
    PRINT_DEBUG("%s (Before): %p %s %u \n", __FUNCTION__, inContext, inOptIdListUtf8, inOptIdListLength);
    GET_PROXY_FUNC(UPC_OverlayFriendInvitationShow);
    auto result = proxyFunc(inContext, inOptIdListUtf8, inOptIdListLength);
    PRINT_DEBUG("%s (After): %i  %p %s %u \n", __FUNCTION__, result, inContext, inOptIdListUtf8, inOptIdListLength);
    return result;
}

EXPORT int UPC_OverlayFriendInvitationShow_Extended(void* inContext, const char* inOptIdListUtf8, unsigned inOptIdListLength, void* unknown1, void* unknown2)
{
    PRINT_DEBUG("%s (Before): %p %s %u %p %p \n", __FUNCTION__, inContext, inOptIdListUtf8, inOptIdListLength, unknown1, unknown2);
    GET_PROXY_FUNC(UPC_OverlayFriendInvitationShow_Extended);
    auto result = proxyFunc(inContext, inOptIdListUtf8, inOptIdListLength, unknown1, unknown2);
    PRINT_DEBUG("%s (After): %i  %p %s %u %p %p \n", __FUNCTION__, result, inContext, inOptIdListUtf8, inOptIdListLength, unknown1, unknown2);
    return result;
}

EXPORT int UPC_OverlayFriendSelectionFree(void* inContext, void* inSelectedFriends)
{
    PRINT_DEBUG("%s (Before): %p %p \n", __FUNCTION__, inContext, inSelectedFriends);
    GET_PROXY_FUNC(UPC_OverlayFriendSelectionFree);
    auto result = proxyFunc(inContext, inSelectedFriends);
    PRINT_DEBUG("%s (After): %i  %p %p \n", __FUNCTION__, result, inContext, inSelectedFriends);
    return result;
}

EXPORT int UPC_OverlayFriendSelectionShow(void* inContext, const char* inIdListUtf8, unsigned inIdListLength, void* outSelectedFriends, void* inCallback, void* inCallbackData)
{
    PRINT_DEBUG("%s (Before): %p %s %u %p %p %p \n", __FUNCTION__, inContext, inIdListUtf8, inIdListLength, outSelectedFriends, inCallback, inCallbackData);
    GET_PROXY_FUNC(UPC_OverlayFriendSelectionShow);
    auto result = proxyFunc(inContext, inIdListUtf8, inIdListLength, outSelectedFriends, inCallback, inCallbackData);
    PRINT_DEBUG("%s (After): %i  %p %s %u %p %p %p \n", __FUNCTION__, result, inContext, inIdListUtf8, inIdListLength, outSelectedFriends, inCallback, inCallbackData);
    return result;
}

EXPORT int UPC_OverlayMicroAppShow(void* inContext, void* inAppName, void* inOptMicroAppParamList, void* inOptCallback, void* inOptCallbackData)
{
    PRINT_DEBUG("%s (Before): %p %p %p %p %p \n", __FUNCTION__, inContext, inAppName, inOptMicroAppParamList, inOptCallback, inOptCallbackData);
    GET_PROXY_FUNC(UPC_OverlayMicroAppShow);
    auto result = proxyFunc(inContext, inAppName, inOptMicroAppParamList, inOptCallback, inOptCallbackData);
    PRINT_DEBUG("%s (After): %i  %p %p %p %p %p \n", __FUNCTION__, result, inContext, inAppName, inOptMicroAppParamList, inOptCallback, inOptCallbackData);
    return result;
}

EXPORT int UPC_OverlayNotificationShow(void* inContext, unsigned inId)
{
    PRINT_DEBUG("%s (Before): %p %u \n", __FUNCTION__, inContext, inId);
    GET_PROXY_FUNC(UPC_OverlayNotificationShow);
    auto result = proxyFunc(inContext, inId);
    PRINT_DEBUG("%s (After): %i  %p %u \n", __FUNCTION__, result, inContext, inId);
    return result;
}

EXPORT int UPC_OverlayNotificationShow_Extended(void* inContext, unsigned inId, void* unknown1, void* unknown2)
{
    PRINT_DEBUG("%s (Before): %p %u %p %p \n", __FUNCTION__, inContext, inId, unknown1, unknown2);
    GET_PROXY_FUNC(UPC_OverlayNotificationShow_Extended);
    auto result = proxyFunc(inContext, inId, unknown1, unknown2);
    PRINT_DEBUG("%s (After): %i  %p %u %p %p \n", __FUNCTION__, result, inContext, inId, unknown1, unknown2);
    return result;
}

EXPORT int UPC_OverlayShow(void* inContext, unsigned inSection, void* inOptCallback, void* inOptCallbackData)
{
    PRINT_DEBUG("%s (Before): %p %u %p %p \n", __FUNCTION__, inContext, inSection, inOptCallback, inOptCallbackData);
    GET_PROXY_FUNC(UPC_OverlayShow);
    auto result = proxyFunc(inContext, inSection, inOptCallback, inOptCallbackData);
    PRINT_DEBUG("%s (After): %i  %p %u %p %p \n", __FUNCTION__, result, inContext, inSection, inOptCallback, inOptCallbackData);
    return result;
}

EXPORT int UPC_ProductConsume(void* inContext, unsigned inProductId, unsigned inQuantity, const char* inTransactionIdUtf8, const char* inSignatureUtf8, const char* outResponseSignatureUtf8, void* inCallback, void* inOptCallbackData)
{
    PRINT_DEBUG("%s (Before): %p %u %u %s %s %s %p %p \n", __FUNCTION__, inContext, inProductId, inQuantity, inTransactionIdUtf8, inSignatureUtf8, outResponseSignatureUtf8, inCallback, inOptCallbackData);
    GET_PROXY_FUNC(UPC_ProductConsume);
    auto result = proxyFunc(inContext, inProductId, inQuantity, inTransactionIdUtf8, inSignatureUtf8, outResponseSignatureUtf8, inCallback, inOptCallbackData);
    PRINT_DEBUG("%s (After): %i  %p %u %u %s %s %s %p %p \n", __FUNCTION__, result, inContext, inProductId, inQuantity, inTransactionIdUtf8, inSignatureUtf8, outResponseSignatureUtf8, inCallback, inOptCallbackData);
    return result;
}

EXPORT int UPC_ProductConsumeSignatureFree(void* inContext, void* inResponseSignature)
{
    PRINT_DEBUG("%s (Before): %p %p \n", __FUNCTION__, inContext, inResponseSignature);
    GET_PROXY_FUNC(UPC_ProductConsumeSignatureFree);
    auto result = proxyFunc(inContext, inResponseSignature);
    PRINT_DEBUG("%s (After): %i  %p %p \n", __FUNCTION__, result, inContext, inResponseSignature);
    return result;
}

EXPORT int UPC_ProductListFree(void* inContext, void* inProductList)
{
    PRINT_DEBUG("%s (Before): %p %p \n", __FUNCTION__, inContext, inProductList);
    GET_PROXY_FUNC(UPC_ProductListFree);
    auto result = proxyFunc(inContext, inProductList);
    PRINT_DEBUG("%s (After): %i  %p %p \n", __FUNCTION__, result, inContext, inProductList);
    return result;
}

EXPORT int UPC_ProductListGet(void* inContext, const char* inOptUserIdUtf8, unsigned inFilter, void* outProductList, void* inCallback, void* inOptCallbackData)
{
    PRINT_DEBUG("%s (Before): %p %s %u %p %p %p \n", __FUNCTION__, inContext, inOptUserIdUtf8, inFilter, outProductList, inCallback, inOptCallbackData);
    GET_PROXY_FUNC(UPC_ProductListGet);
    auto result = proxyFunc(inContext, inOptUserIdUtf8, inFilter, outProductList, inCallback, inOptCallbackData);
    PRINT_DEBUG("%s (After): %i  %p %s %u %p %p %p \n", __FUNCTION__, result, inContext, inOptUserIdUtf8, inFilter, outProductList, inCallback, inOptCallbackData);
    return result;
}

EXPORT int UPC_RichPresenceSet(void* inContext, unsigned inId, void* inOptTokenList)
{
    PRINT_DEBUG("%s (Before): %p %u %p \n", __FUNCTION__, inContext, inId, inOptTokenList);
    GET_PROXY_FUNC(UPC_RichPresenceSet);
    auto result = proxyFunc(inContext, inId, inOptTokenList);
    PRINT_DEBUG("%s (After): %i  %p %u %p \n", __FUNCTION__, result, inContext, inId, inOptTokenList);
    return result;
}

EXPORT int UPC_RichPresenceSet_Extended(void* inContext, unsigned inId, void* inOptTokenList, void* unknown1, void* unknown2)
{
    PRINT_DEBUG("%s (Before): %p %u %p %p %p \n", __FUNCTION__, inContext, inId, inOptTokenList, unknown1, unknown2);
    GET_PROXY_FUNC(UPC_RichPresenceSet_Extended);
    auto result = proxyFunc(inContext, inId, inOptTokenList, unknown1, unknown2);
    PRINT_DEBUG("%s (After): %i  %p %u %p %p %p \n", __FUNCTION__, result, inContext, inId, inOptTokenList, unknown1, unknown2);
    return result;
}

EXPORT int UPC_ShowBrowserUrl(void* inContext, const char* inBrowserUrlUtf8)
{
    PRINT_DEBUG("%s (Before): %p %s \n", __FUNCTION__, inContext, inBrowserUrlUtf8);
    GET_PROXY_FUNC(UPC_ShowBrowserUrl);
    auto result = proxyFunc(inContext, inBrowserUrlUtf8);
    PRINT_DEBUG("%s (After): %i  %p %s \n", __FUNCTION__, result, inContext, inBrowserUrlUtf8);
    return result;
}

EXPORT int UPC_StorageFileClose(void* inContext, void* inHandle)
{
    PRINT_DEBUG("%s (Before): %p %p \n", __FUNCTION__, inContext, inHandle);
    GET_PROXY_FUNC(UPC_StorageFileClose);
    auto result = proxyFunc(inContext, inHandle);
    PRINT_DEBUG("%s (After): %i  %p %p \n", __FUNCTION__, result, inContext, inHandle);
    return result;
}

EXPORT int UPC_StorageFileDelete(void* inContext, const char* inFileNameUtf8)
{
    PRINT_DEBUG("%s (Before): %p %s \n", __FUNCTION__, inContext, inFileNameUtf8);
    GET_PROXY_FUNC(UPC_StorageFileDelete);
    auto result = proxyFunc(inContext, inFileNameUtf8);
    PRINT_DEBUG("%s (After): %i  %p %s \n", __FUNCTION__, result, inContext, inFileNameUtf8);
    return result;
}

EXPORT int UPC_StorageFileListFree(void* inContext, void* inStorageFileList)
{
    PRINT_DEBUG("%s (Before): %p %p \n", __FUNCTION__, inContext, inStorageFileList);
    GET_PROXY_FUNC(UPC_StorageFileListFree);
    auto result = proxyFunc(inContext, inStorageFileList);
    PRINT_DEBUG("%s (After): %i  %p %p \n", __FUNCTION__, result, inContext, inStorageFileList);
    return result;
}

EXPORT int UPC_StorageFileListGet(void* inContext, void* outStorageFileList)
{
    PRINT_DEBUG("%s (Before): %p %p \n", __FUNCTION__, inContext, outStorageFileList);
    GET_PROXY_FUNC(UPC_StorageFileListGet);
    auto result = proxyFunc(inContext, outStorageFileList);
    PRINT_DEBUG("%s (After): %i  %p %p \n", __FUNCTION__, result, inContext, outStorageFileList);
    return result;
}

EXPORT int UPC_StorageFileOpen(void* inContext, const char* inFileNameUtf8, unsigned inFlags, void* outHandle)
{
    PRINT_DEBUG("%s (Before): %p %s %u %p \n", __FUNCTION__, inContext, inFileNameUtf8, inFlags, outHandle);
    GET_PROXY_FUNC(UPC_StorageFileOpen);
    auto result = proxyFunc(inContext, inFileNameUtf8, inFlags, outHandle);
    PRINT_DEBUG("%s (After): %i  %p %s %u %p \n", __FUNCTION__, result, inContext, inFileNameUtf8, inFlags, outHandle);
    return result;
}

EXPORT int UPC_StorageFileRead(void* inContext, void* inHandle, unsigned inBytesToRead, unsigned inBytesReadOffset, void* outData, void* outBytesRead, void* inCallback, void* inCallbackData)
{
    PRINT_DEBUG("%s (Before): %p %p %u %u %p %p %p %p \n", __FUNCTION__, inContext, inHandle, inBytesToRead, inBytesReadOffset, outData, outBytesRead, inCallback, inCallbackData);
    GET_PROXY_FUNC(UPC_StorageFileRead);
    auto result = proxyFunc(inContext, inHandle, inBytesToRead, inBytesReadOffset, outData, outBytesRead, inCallback, inCallbackData);
    PRINT_DEBUG("%s (After): %i  %p %p %u %u %p %p %p %p \n", __FUNCTION__, result, inContext, inHandle, inBytesToRead, inBytesReadOffset, outData, outBytesRead, inCallback, inCallbackData);
    return result;
}

EXPORT int UPC_StorageFileWrite(void* inContext, void* inHandle, void* inData, unsigned inSize, void* inCallback, void* inCallbackData)
{
    PRINT_DEBUG("%s (Before): %p %p %p %u %p %p \n", __FUNCTION__, inContext, inHandle, inData, inSize, inCallback, inCallbackData);
    GET_PROXY_FUNC(UPC_StorageFileWrite);
    auto result = proxyFunc(inContext, inHandle, inData, inSize, inCallback, inCallbackData);
    PRINT_DEBUG("%s (After): %i  %p %p %p %u %p %p \n", __FUNCTION__, result, inContext, inHandle, inData, inSize, inCallback, inCallbackData);
    return result;
}

EXPORT int UPC_StoreCheckout(void* inContext, unsigned inId)
{
    PRINT_DEBUG("%s (Before): %p %u \n", __FUNCTION__, inContext, inId);
    GET_PROXY_FUNC(UPC_StoreCheckout);
    auto result = proxyFunc(inContext, inId);
    PRINT_DEBUG("%s (After): %i  %p %u \n", __FUNCTION__, result, inContext, inId);
    return result;
}

EXPORT bool UPC_StoreIsEnabled(void* inContext)
{
    PRINT_DEBUG("%s (Before): %p \n", __FUNCTION__, inContext);
    GET_PROXY_FUNC(UPC_StoreIsEnabled);
    auto result = proxyFunc(inContext);
    PRINT_DEBUG("%s (After): %d\n", __FUNCTION__, result);
    return result;
}

EXPORT int UPC_StoreIsEnabled_Extended(void* inContext, bool* outEnabled)
{
    PRINT_DEBUG("%s (Before): %p %d \n", __FUNCTION__, inContext, *outEnabled);
    GET_PROXY_FUNC(UPC_StoreIsEnabled_Extended);
    auto result = proxyFunc(inContext, outEnabled);
    PRINT_DEBUG("%s (After): %i  %p %d \n", __FUNCTION__, result, inContext, *outEnabled);
    return result;
}

EXPORT int UPC_StoreLanguageSet(void* inContext, void* inLanguageCountryCode)
{
    PRINT_DEBUG("%s (Before): %p %p \n", __FUNCTION__, inContext, inLanguageCountryCode);
    GET_PROXY_FUNC(UPC_StoreLanguageSet);
    auto result = proxyFunc(inContext, inLanguageCountryCode);
    PRINT_DEBUG("%s (After): %i  %p %p \n", __FUNCTION__, result, inContext, inLanguageCountryCode);
    return result;
}

EXPORT int UPC_StorePartnerGet(void* inContext)
{
    PRINT_DEBUG("%s (Before): %p \n", __FUNCTION__, inContext);
    GET_PROXY_FUNC(UPC_StorePartnerGet);
    auto result = proxyFunc(inContext);
    PRINT_DEBUG("%s (After): %i\n", __FUNCTION__, result);
    return result;
}

EXPORT int UPC_StorePartnerGet_Extended(void* inContext, void* storePartner)
{
    PRINT_DEBUG("%s (Before): %p %p \n", __FUNCTION__, inContext, storePartner);
    GET_PROXY_FUNC(UPC_StorePartnerGet_Extended);
    auto result = proxyFunc(inContext, storePartner);
    PRINT_DEBUG("%s (After): %i  %p %p \n", __FUNCTION__, result, inContext, storePartner);
    return result;
}

EXPORT int UPC_StoreProductDetailsShow(void* inContext, unsigned inId)
{
    PRINT_DEBUG("%s (Before): %p %u \n", __FUNCTION__, inContext, inId);
    GET_PROXY_FUNC(UPC_StoreProductDetailsShow);
    auto result = proxyFunc(inContext, inId);
    PRINT_DEBUG("%s (After): %i  %p %u \n", __FUNCTION__, result, inContext, inId);
    return result;
}

EXPORT int UPC_StoreProductListFree(void* inContext, void* inProductList)
{
    PRINT_DEBUG("%s (Before): %p %p \n", __FUNCTION__, inContext, inProductList);
    GET_PROXY_FUNC(UPC_StoreProductListFree);
    auto result = proxyFunc(inContext, inProductList);
    PRINT_DEBUG("%s (After): %i  %p %p \n", __FUNCTION__, result, inContext, inProductList);
    return result;
}

EXPORT int UPC_StoreProductListGet(void* inContext, void* outProductList, void* inCallback, void* inCallbackData)
{
    PRINT_DEBUG("%s (Before): %p %p %p %p \n", __FUNCTION__, inContext, outProductList, inCallback, inCallbackData);
    GET_PROXY_FUNC(UPC_StoreProductListGet);
    auto result = proxyFunc(inContext, outProductList, inCallback, inCallbackData);
    PRINT_DEBUG("%s (After): %i  %p %p %p %p \n", __FUNCTION__, result, inContext, outProductList, inCallback, inCallbackData);
    return result;
}

EXPORT int UPC_StoreProductsShow(void* inContext, void* inTagsList)
{
    PRINT_DEBUG("%s (Before): %p %p \n", __FUNCTION__, inContext, inTagsList);
    GET_PROXY_FUNC(UPC_StoreProductsShow);
    auto result = proxyFunc(inContext, inTagsList);
    PRINT_DEBUG("%s (After): %i  %p %p \n", __FUNCTION__, result, inContext, inTagsList);
    return result;
}

EXPORT int UPC_StreamingCurrentUserCountryFree(void* inContext, const char* inUtf8Country)
{
    PRINT_DEBUG("%s (Before): %p %s \n", __FUNCTION__, inContext, inUtf8Country);
    GET_PROXY_FUNC(UPC_StreamingCurrentUserCountryFree);
    auto result = proxyFunc(inContext, inUtf8Country);
    PRINT_DEBUG("%s (After): %i  %p %s \n", __FUNCTION__, result, inContext, inUtf8Country);
    return result;
}

EXPORT int UPC_StreamingCurrentUserCountryGet(void* inContext, const char* outUtf8Country, void* inCallback, void* inCallbackData)
{
    PRINT_DEBUG("%s (Before): %p %s %p %p \n", __FUNCTION__, inContext, outUtf8Country, inCallback, inCallbackData);
    GET_PROXY_FUNC(UPC_StreamingCurrentUserCountryGet);
    auto result = proxyFunc(inContext, outUtf8Country, inCallback, inCallbackData);
    PRINT_DEBUG("%s (After): %i  %p %s %p %p \n", __FUNCTION__, result, inContext, outUtf8Country, inCallback, inCallbackData);
    return result;
}

EXPORT int UPC_StreamingDeviceTypeGet(void* inContext, void* outType, void* inCallback, void* inCallbackData)
{
    PRINT_DEBUG("%s (Before): %p %p %p %p \n", __FUNCTION__, inContext, outType, inCallback, inCallbackData);
    GET_PROXY_FUNC(UPC_StreamingDeviceTypeGet);
    auto result = proxyFunc(inContext, outType, inCallback, inCallbackData);
    PRINT_DEBUG("%s (After): %i  %p %p %p %p \n", __FUNCTION__, result, inContext, outType, inCallback, inCallbackData);
    return result;
}

EXPORT int UPC_StreamingInputGamepadTypeGet(void* inContext, void* outType, void* inCallback, void* inCallbackData)
{
    PRINT_DEBUG("%s (Before): %p %p %p %p \n", __FUNCTION__, inContext, outType, inCallback, inCallbackData);
    GET_PROXY_FUNC(UPC_StreamingInputGamepadTypeGet);
    auto result = proxyFunc(inContext, outType, inCallback, inCallbackData);
    PRINT_DEBUG("%s (After): %i  %p %p %p %p \n", __FUNCTION__, result, inContext, outType, inCallback, inCallbackData);
    return result;
}

EXPORT int UPC_StreamingInputTypeGet(void* inContext, void* outType, void* inCallback, void* inCallbackData)
{
    PRINT_DEBUG("%s (Before): %p %p %p %p \n", __FUNCTION__, inContext, outType, inCallback, inCallbackData);
    GET_PROXY_FUNC(UPC_StreamingInputTypeGet);
    auto result = proxyFunc(inContext, outType, inCallback, inCallbackData);
    PRINT_DEBUG("%s (After): %i  %p %p %p %p \n", __FUNCTION__, result, inContext, outType, inCallback, inCallbackData);
    return result;
}

EXPORT int UPC_StreamingNetworkDelayForInputGet(void* inContext, void* outDelayMs, void* inCallback, void* inCallbackData)
{
    PRINT_DEBUG("%s (Before): %p %p %p %p \n", __FUNCTION__, inContext, outDelayMs, inCallback, inCallbackData);
    GET_PROXY_FUNC(UPC_StreamingNetworkDelayForInputGet);
    auto result = proxyFunc(inContext, outDelayMs, inCallback, inCallbackData);
    PRINT_DEBUG("%s (After): %i  %p %p %p %p \n", __FUNCTION__, result, inContext, outDelayMs, inCallback, inCallbackData);
    return result;
}

EXPORT int UPC_StreamingNetworkDelayForVideoGet(void* inContext, void* outDelayMs, void* inCallback, void* inCallbackData)
{
    PRINT_DEBUG("%s (Before): %p %p %p %p \n", __FUNCTION__, inContext, outDelayMs, inCallback, inCallbackData);
    GET_PROXY_FUNC(UPC_StreamingNetworkDelayForVideoGet);
    auto result = proxyFunc(inContext, outDelayMs, inCallback, inCallbackData);
    PRINT_DEBUG("%s (After): %i  %p %p %p %p \n", __FUNCTION__, result, inContext, outDelayMs, inCallback, inCallbackData);
    return result;
}

EXPORT int UPC_StreamingNetworkDelayRoundtripGet(void* inContext, void* outDelayMs, void* inCallback, void* inCallbackData)
{
    PRINT_DEBUG("%s (Before): %p %p %p %p \n", __FUNCTION__, inContext, outDelayMs, inCallback, inCallbackData);
    GET_PROXY_FUNC(UPC_StreamingNetworkDelayRoundtripGet);
    auto result = proxyFunc(inContext, outDelayMs, inCallback, inCallbackData);
    PRINT_DEBUG("%s (After): %i  %p %p %p %p \n", __FUNCTION__, result, inContext, outDelayMs, inCallback, inCallbackData);
    return result;
}

EXPORT int UPC_StreamingResolutionFree(void* inContext, void* inResolution)
{
    PRINT_DEBUG("%s (Before): %p %p \n", __FUNCTION__, inContext, inResolution);
    GET_PROXY_FUNC(UPC_StreamingResolutionFree);
    auto result = proxyFunc(inContext, inResolution);
    PRINT_DEBUG("%s (After): %i  %p %p \n", __FUNCTION__, result, inContext, inResolution);
    return result;
}

EXPORT int UPC_StreamingResolutionGet(void* inContext, void* outResolution, void* inCallback, void* inCallbackData)
{
    PRINT_DEBUG("%s (Before): %p %p %p %p \n", __FUNCTION__, inContext, outResolution, inCallback, inCallbackData);
    GET_PROXY_FUNC(UPC_StreamingResolutionGet);
    auto result = proxyFunc(inContext, outResolution, inCallback, inCallbackData);
    PRINT_DEBUG("%s (After): %i  %p %p %p %p \n", __FUNCTION__, result, inContext, outResolution, inCallback, inCallbackData);
    return result;
}

EXPORT int UPC_StreamingTypeGet(void* inContext, void* outType, void* inCallback, void* inCallbackData)
{
    PRINT_DEBUG("%s (Before): %p %p %p %p \n", __FUNCTION__, inContext, outType, inCallback, inCallbackData);
    GET_PROXY_FUNC(UPC_StreamingTypeGet);
    auto result = proxyFunc(inContext, outType, inCallback, inCallbackData);
    PRINT_DEBUG("%s (After): %i  %p %p %p %p \n", __FUNCTION__, result, inContext, outType, inCallback, inCallbackData);
    return result;
}

EXPORT const char* UPC_TicketGet(void* inContext)
{
    PRINT_DEBUG("%s (Before): %p \n", __FUNCTION__, inContext);
    GET_PROXY_FUNC(UPC_TicketGet);
    auto result = proxyFunc(inContext);
    PRINT_DEBUG("%s (After): %s\n", __FUNCTION__, result);
    return result;
}

EXPORT int UPC_TicketGet_Extended(void* inContext, const char** ticket)
{
    PRINT_DEBUG("%s (Before): %p %p \n", __FUNCTION__, inContext, ticket);
    GET_PROXY_FUNC(UPC_TicketGet_Extended);
    auto result = proxyFunc(inContext, ticket);
    PRINT_DEBUG("%s (After): %i  %p %s \n", __FUNCTION__, result, inContext, *ticket);
    return result;
}

EXPORT void UPC_Uninit()
{
    PRINT_DEBUG("%s\n", __FUNCTION__);
    GET_PROXY_FUNC(UPC_Uninit);
    proxyFunc();
}

EXPORT int UPC_Update(void* inContext)
{
    PRINT_DEBUG("%s (Before): %p \n", __FUNCTION__, inContext);
    GET_PROXY_FUNC(UPC_Update);
    auto result = proxyFunc(inContext);
    PRINT_DEBUG("%s (After): %i\n", __FUNCTION__, result);
    return result;
}

EXPORT int UPC_UserFree(void* inContext, void* inUser)
{
    PRINT_DEBUG("%s (Before): %p %p \n", __FUNCTION__, inContext, inUser);
    GET_PROXY_FUNC(UPC_UserFree);
    auto result = proxyFunc(inContext, inUser);
    PRINT_DEBUG("%s (After): %i  %p %p \n", __FUNCTION__, result, inContext, inUser);
    return result;
}

EXPORT int UPC_UserGet(void* inContext, const char* inOptUserIdUtf8, void* outUser, void* inCallback, void* inCallbackData)
{
    PRINT_DEBUG("%s (Before): %p %s %p %p %p \n", __FUNCTION__, inContext, inOptUserIdUtf8, outUser, inCallback, inCallbackData);
    GET_PROXY_FUNC(UPC_UserGet);
    auto result = proxyFunc(inContext, inOptUserIdUtf8, outUser, inCallback, inCallbackData);
    PRINT_DEBUG("%s (After): %i  %p %s %p %p %p \n", __FUNCTION__, result, inContext, inOptUserIdUtf8, outUser, inCallback, inCallbackData);
    return result;
}

EXPORT int UPC_UserPlayedWithAdd(void* inContext, const char* inUserIdUtf8List, unsigned inListLength)
{
    PRINT_DEBUG("%s (Before): %p %s %u \n", __FUNCTION__, inContext, inUserIdUtf8List, inListLength);
    GET_PROXY_FUNC(UPC_UserPlayedWithAdd);
    auto result = proxyFunc(inContext, inUserIdUtf8List, inListLength);
    PRINT_DEBUG("%s (After): %i  %p %s %u \n", __FUNCTION__, result, inContext, inUserIdUtf8List, inListLength);
    return result;
}

EXPORT int UPC_UserPlayedWithAdd_Extended(void* inContext, const char* inUserIdUtf8List, unsigned inListLength, void* unknown1, void* unknown2)
{
    PRINT_DEBUG("%s (Before): %p %s %u %p %p \n", __FUNCTION__, inContext, inUserIdUtf8List, inListLength, unknown1, unknown2);
    GET_PROXY_FUNC(UPC_UserPlayedWithAdd_Extended);
    auto result = proxyFunc(inContext, inUserIdUtf8List, inListLength, unknown1, unknown2);
    PRINT_DEBUG("%s (After): %i  %p %s %u %p %p \n", __FUNCTION__, result, inContext, inUserIdUtf8List, inListLength, unknown1, unknown2);
    return result;
}
#pragma endregion

