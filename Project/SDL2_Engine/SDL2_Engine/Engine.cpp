#pragma region system include
#include <iostream>
#include <SDL.h>
#include <SDL_events.h>
#pragma endregion

#pragma region project include
#include "Engine.h"
#include "Renderer.h"
#include "ContentManagement.h"
#include "Game.h"
#include "Scene.h"
#pragma endregion

#pragma region constructor
CEngine::CEngine()
{
}

CEngine::~CEngine()
{
}
#pragma endregion

#pragma region public function
// initialize sdl
bool CEngine::Init()
{
	// initialize sdl
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		// error message
		LOG_ERROR("SDL not initialized!", SDL_GetError());

		return false;
	}

	// sdl initialized
	else
	{
		// create window
		m_pWindow = SDL_CreateWindow(
			"Natural Engine",			// name of window
			SDL_WINDOWPOS_CENTERED,		// position x of screen
			SDL_WINDOWPOS_CENTERED,		// position y of screen
			SCREEN_WIDTH,				// width
			SCREEN_HEIGHT,				// height
			SDL_WINDOW_SHOWN);			// flags

		// if window not created
		if (!m_pWindow)
		{
			// error message
			LOG_ERROR("Window could not be created!", SDL_GetError());

			return false;
		}

		// get surface from window
		m_pSurface = SDL_GetWindowSurface(m_pWindow);

		// if surface not created
		if (!m_pSurface)
		{
			// error message
			LOG_ERROR("Surface could not be created!", SDL_GetError());

			return false;
		}

		// initialize renderer
		m_pRenderer = new CRenderer(m_pWindow);

		// if renderer not created
		if (!m_pRenderer)
		{
			// error message
			LOG_ERROR("Renderer could not be created!", SDL_GetError());

			return false;
		}

		// create content management system
		m_pCM = new CContentManagement();

		// if content management system not created
		if (!m_pCM)
		{
			// error message
			LOG_ERROR("Content Management System could not be created!", SDL_GetError());

			return false;
		}

		// engine is running
		m_isRunning = true;

		return true;
	}
}

// load content
bool CEngine::Load()
{
	// create game
	GGame::Get()->Init();

	return true;
}

// running engine
void CEngine::Run()
{
	// as long as engine running
	while (m_isRunning)
	{
#pragma region m2vh
		// catching the QUIT event
		SDL_Event m_MyEvent;

		SDL_PollEvent(&m_MyEvent);
		switch (m_MyEvent.type)
		{
			case SDL_QUIT:
			{
				m_isRunning = false;
				break;
			}
		}
#pragma endregion


		Update();

		Render();
	}
}

// cleaning up
void CEngine::Clean()
{
	// clean current scene
	if (m_pScene)
		m_pScene->Clean();

	// delete scene
	delete m_pScene;

	// delete renderer
	delete m_pRenderer;

	// free sdl components
	SDL_FreeSurface(m_pSurface);
	SDL_DestroyWindow(m_pWindow);
}

// change active scene
void CEngine::ChangeScene(CScene * _pScene)
{
	// if new scene nullptr return
	if (!_pScene)
		return;

	// if old scene valid
	if (m_pScene)
	{
		// clean and delete scene
		m_pScene->Clean();
		delete m_pScene;
	}

	// set new scene
	m_pScene = _pScene;

	// initialize new scene
	m_pScene->Init();
}
#pragma endregion

#pragma region private function
// update every frame
void CEngine::Update()
{
	// update content
	m_pCM->Update();
}

// render every frame
void CEngine::Render()
{
	// clear current screen
	m_pRenderer->ClearScreen();

	// render content
	m_pCM->Render(m_pRenderer);

	// present rendered image
	m_pRenderer->Present();
}
#pragma endregion