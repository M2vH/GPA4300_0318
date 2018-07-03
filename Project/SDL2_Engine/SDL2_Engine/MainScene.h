#pragma once
#pragma region project include
#include "Scene.h"
#pragma endregion

/// <summary>
/// main game scene class
/// </summary>
class GMainScene : public CScene
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pEngine">engine reference</param>
	GMainScene(CEngine* _pEngine) : CScene(_pEngine) {}
#pragma endregion

#pragma region public override function
	/// <summary>
	/// initialize scene
	/// </summary>
	/// <param name="_pRenderer">renderer</param>
	virtual void Init(SDL_Renderer* _pRenderer) override;

	/// <summary>
	/// cleaning up scene
	/// </summary>
	virtual void Clean() override;
#pragma endregion
};