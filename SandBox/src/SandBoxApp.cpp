#include <SolidState.h>

class SandBox : public SolidState::Application
{
public:
	SandBox()
	{

	}
	~SandBox()
	{

	}

};


SolidState::Application* SolidState::CreateApplication()
{
	return new SandBox();
}