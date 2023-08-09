#pragma once

namespace ProxyFunc
{
	typedef void (*UplayCallback)(unsigned long, void*);

	struct CallbackContainer
	{
		void* context = NULL;
		UplayCallback originalCallback = NULL;
		void* callbackData = NULL;
	};

	void init();
	void shutdown();
}