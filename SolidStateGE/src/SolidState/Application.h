#pragma once

#include "Core.h"

namespace SolidState {
	class SOLIDSTATE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// to be defined in client
	Application* CreateApplication();
}


