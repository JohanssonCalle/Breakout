//main.cpp


#include "Engine.h"

int main(int argc, char* argv[])
{
	Engine engine;

	if(engine.Init())
	{
		engine.Run();
		engine.CleanUp();
	}
	else 
	return 8;

	return 0;
}