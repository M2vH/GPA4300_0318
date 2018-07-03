#pragma once

#pragma region system include
#include <SDL.h>
#pragma endregion


#pragma region project include
#include "Engine.h"
#pragma endregion

/// <summary>
/// pure virtual scene class
/// </summary>
class CScene
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pEngine">engine pointer</param>
	CScene(CEngine* _pEngine) : m_pEngine(_pEngine) {}
#pragma endregion

#pragma region public function
	/// <summary>
	/// initialize scene
	/// </summary>
	/// <param name="_pRenderer">renderer</param>
	virtual void Init(SDL_Renderer* _pRenderer) = 0;

	/// <summary>
	/// cleaning up scene
	/// </summary>
	virtual void Clean() = 0;
#pragma endregion

protected:
#pragma region protected variable
	/// <summary>
	/// engine reference
	/// </summary>
	CEngine* m_pEngine;
#pragma endregion
};