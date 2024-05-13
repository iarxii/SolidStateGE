#pragma once

#ifdef SLD_PLATFORM_WINDOWS

extern SolidState::Application* SolidState::CreateApplication();

int main(int argc, char** argv) 
{
    const char* asciiArt = R"(
 _____       _ _     _ _____ _        _         _____ _____ 
/  ___|     | (_)   | /  ___| |      | |       |  __ |  ___|
\ `--.  ___ | |_  __| \ `--.| |_ __ _| |_ ___  | |  \| |__  
 `--. \/ _ \| | |/ _` |`--. | __/ _` | __/ _ \ | | __|  __| 
/\__/ | (_) | | | (_| /\__/ | || (_| | ||  __/ | |_\ | |___ 
\____/ \___/|_|_|\__,_\____/ \__\__,_|\__\___|  \____\____/ 
                                                        
Welcome to the SolidState Game Engine. >>> Version 0.01 <<<
															
)";

	printf("%s", asciiArt);

	SolidState::Log::Init();
	//SolidState::Log::GetCoreLogger()->warn("Initialized Log!"); // use micro instead below
	SLD_CORE_WARN("Initialized Log!");

	//SolidState::Log::GetClientLogger()->info("Hello!"); // use micro instead below
	int a = 5;
	SLD_INFO("Hello! Var={0}", a);

	auto app = SolidState::CreateApplication();
	app->Run();
	delete app;
}

#endif // SLD_PLATFORM_WINDOWS
