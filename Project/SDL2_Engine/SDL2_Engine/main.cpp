#pragma region project include
#include "Engine.h"
#pragma endregion

/// <summary>
/// entry point of application
/// </summary>
/// <param name="argc">count of parameter</param>
/// <param name="argv">parameter</param>
/// <returns>code of shut down</returns>
int main(int argc, char* argv[])
{
	// create engine
	CEngine engine;

	// init engine and load images
	if (engine.Init() && engine.Load())
	{
		// run engine
		engine.Run();
	}

	// not initialized or loaded
	else
	{
		return 1;
	}

	// clean engine
	engine.Clean();

	// shutdown correctly
	return 0;
}