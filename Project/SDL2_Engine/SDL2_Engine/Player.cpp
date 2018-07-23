#pragma region project include
#include "Player.h"
#include "Input.h"
#include "Engine.h"
#include "Renderer.h"
#pragma endregion

#pragma region public override function
// update every frame
void GPlayer::Update()
{
	if (CInput::GetKey(SDL_SCANCODE_W))
	{
		m_movement.Y = -1.0f;
	}

	else if (CInput::GetKey(SDL_SCANCODE_S))
	{
		m_movement.Y = 1.0f;
	}

	else
	{
		m_movement.Y = 0.0f;
	}

	if (CInput::GetKey(SDL_SCANCODE_A))
	{
		m_movement.X = -1.0f;
		m_mirror.X = 1.0f;
	}

	else if (CInput::GetKey(SDL_SCANCODE_D))
	{
		m_movement.X = 1.0f;
		m_mirror.X = 0.0f;
	}

	else
	{
		m_movement.X = 0.0f;
	}

	// update parent
	CMoveObject::Update();

	// set position of camera
	CEngine::Get()->GetRenderer()->SetCamera(
		SVector2(m_position.X + PLAYER_WIDTH / 2, m_position.Y + PLAYER_HEIGHT / 2)
	);
}

// render every frame
void GPlayer::Render(CRenderer * _pRenderer)
{
	CMoveObject::Render(_pRenderer);
}
#pragma endregion