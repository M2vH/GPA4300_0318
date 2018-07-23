#include <iostream>	///TODO: DELETE
#include <string>	///TODO: DELETE

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
	// movement up
	if (CInput::GetKey(SDL_SCANCODE_W))
		m_movement.Y = -1.0f;

	// movement down
	else if (CInput::GetKey(SDL_SCANCODE_S))
		m_movement.Y = 1.0f;

	// no movement up and down
	else
		m_movement.Y = 0.0f;

	// movement left
	if (CInput::GetKey(SDL_SCANCODE_A))
	{
		// set movement and mirror
		m_movement.X = -1.0f;
		m_mirror.X = 1.0f;
	}

	// movement right
	else if (CInput::GetKey(SDL_SCANCODE_D))
	{
		// set movemenet and mirror
		m_movement.X = 1.0f;
		m_mirror.X = 0.0f;
	}

	// no movement left or right
	else
		m_movement.X = 0.0f;

	// update parent
	CMoveObject::Update();

	// set position of camera
	CEngine::Get()->GetRenderer()->SetCamera(
		SVector2(m_position.X + PLAYER_WIDTH / 2, m_position.Y + PLAYER_HEIGHT / 2)
	);

	/// <summary>
	/// TODO: DELETE
	/// </summary>
	// print player position
	std::string s = "Player position: X: ";
	s += std::to_string(m_position.X);
	s += ", Y: ";
	s += std::to_string(m_position.Y);
	LOG_ERROR("", s.c_str());
}

// render every frame
void GPlayer::Render(CRenderer * _pRenderer)
{
	CMoveObject::Render(_pRenderer);
}
#pragma endregion