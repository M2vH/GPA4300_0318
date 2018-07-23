#pragma region project include
#include "MainScene.h"
#include "World.h"
#include "ContentManagement.h"
#include "TextDisplay.h"
#pragma endregion

#pragma region public override function
// initialize scene
void GMainScene::Init()
{
	// create world
	m_pWorld = new GWorld(CEngine::Get()->GetRenderer(), "Texture/World/T_WorldSide.png");
	m_pWorld->Init();

	CTextDisplay* m_pCanvas = new CTextDisplay(
		SVector2(0, 50),
		"Hello World!  ",
		CEngine::Get()->GetRenderer());

	CEngine::Get()->GetCM()->AddUIObject(m_pCanvas);

}

// cleaning up scene
void GMainScene::Clean()
{
	// delete world
	// delete m_pWorld;
}
#pragma endregion