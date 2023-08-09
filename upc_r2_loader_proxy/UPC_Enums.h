#pragma once
#include "pch.h"

enum Test : unsigned
{

};
DEFINE_ENUM_FLAG_OPERATORS(Test);

enum ContextSubsystem : unsigned
{
	None = 0U,
	Achievement = 1U,
	Product = 2U,
	Install = 4U,
	Storage = 8U,
	Overlay = 16U,
	Friend = 32U,
	Multiplayer = 64U,
	Store = 128U
};
DEFINE_ENUM_FLAG_OPERATORS(ContextSubsystem);

enum AvatarSize : unsigned
{
	AvatarSize_64x64,
	AvatarSize_128x128,
	AvatarSize_256x256
};

enum EventType : unsigned
{
	FriendAdded,
	FriendNameUpdated,
	FriendPresenceUpdated,
	FriendRemoved,
	MultiplayerSessionCleared = 1000U,
	MultiplayerSessionUpdated,
	MultiplayerInviteReceived,
	MultiplayerInviteAccepted,
	MultiplayerInviteDeclined,
	MultiplayerJoiningRequested,
	OverlayShown = 2000U,
	OverlayHidden,
	ProductAdded = 3000U,
	ProductOwnershipUpdated,
	ProductStateUpdated,
	ProductBalanceUpdated,
	InstallChunkInstalled = 4000U,
	InstallChunkProgress,
	InstallProgress,
	UpdateAvailable,
	StoreProductsListUpdated = 5000U,
	StoreStatusUpdated,
	StoreCheckoutStarted,
	StoreCheckoutFinished,
	UserShutdown = 6000U
};

enum FileOpenMode : unsigned
{
	Read = 1U,
	Write
};

enum InitResult : unsigned
{
	Ok,
	Failed,
	IncompatibleApiVersion,
	ExitProcessRequired,
	InstallationError,
	DesktopInteractionRequired,
	AlreadyInitialized
};

enum MultiplayerSessionJoinability : unsigned
{
	Closed = 1U,
	InviteOnly,
	FriendsOnly,
	Open
};

enum OnlineStatus : unsigned
{
	Offline = 1U,
	DoNotDisturb,
	Away = 4U,
	Online = 8U
};

enum OverlaySection : unsigned
{
	OverlaySection_None,
	OverlaySection_Home,
	OverlaySection_Achievements,
	OverlaySection_Actions,
	OverlaySection_Chat,
	OverlaySection_Friends,
	OverlaySection_Party,
	OverlaySection_Rewards,
	OverlaySection_Shop,
	OverlaySection_ProductActivation,
	OverlaySection_PendingGameInvites,
	OverlaySection_Challenges,
	OverlaySection_GameOptions
};

enum ProductActivation : unsigned
{
	Purchased = 1U,
	Trial,
	Subscription
};

enum ProductOwnership : unsigned
{
	Owned = 1U,
	Preordered,
	Suspended,
	Revoked,
	Locked
};

enum ProductState : unsigned
{
	Visible = 1U,
	Installable,
	Playable,
	Expired
};

enum ProductType : unsigned
{
	Game = 1U,
	Addon = 2U,
	Package = 3U,
	Consumable = 4U,
	ConsumablePack = 5U,
	Bundle = 6U
};
DEFINE_ENUM_FLAG_OPERATORS(ProductType);

enum Relationship : unsigned
{
	Relationship_None,
	Relationship_RequestSent,
	Relationship_RequestReceived,
	Relationship_Friends
};

enum Result
{
	Result_Ok,
	Result_Declined = -1,
	Result_InvalidArgs = -2,
	Result_UninitializedSubsystem = -3,
	Result_CommunicationError = -4,
	Result_MemoryError = -5,
	Result_NotFound = -6,
	Result_EOF = -7,
	Result_LimitReached = -8,
	Result_UnauthorizedAction = -9,
	Result_InternalError = -10,
	Result_Aborted = -11,
	Result_Unknown = -12,
	Result_FailedPrecondition = -13,
	Result_Unavailable = -14
};

enum StorePartner : unsigned
{
	StorePartner_None = 0U,
	StorePartner_EpicGames = 1U
};
DEFINE_ENUM_FLAG_OPERATORS(StorePartner);

enum StoreTag : unsigned
{
	DLCs,
	Skins,
	Currencies,
	Bundles,
	SeasonPass,
	ULCs,
	Sets
};

enum UserShutdownReason
{
	AccountSharing = 1
};