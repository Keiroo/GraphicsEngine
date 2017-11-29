#include "Core.h"

int main()
{
	Core* core = new Core();
	if (!core->Start())
	{
		glfwTerminate();
		return -1;
	}
	core->Update();
	glfwTerminate();
	TwTerminate();
	return 0;
}