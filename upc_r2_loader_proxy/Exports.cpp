#include "pch.h"
#include "UPC_Enums.h"
#pragma warning(disable : 4996).

EXPORT Result UPC_Init(unsigned inVersion, unsigned inProductId)
{
	PRINT_DEBUG("%s (Before): %u %u\n", __FUNCTION__, inVersion, inProductId);
	GET_PROXY_FUNC(UPC_Init);
	auto result = proxyFunc(inVersion, inProductId);
	PRINT_DEBUG("%s (After): %u \n", __FUNCTION__, result);
	return result;
}