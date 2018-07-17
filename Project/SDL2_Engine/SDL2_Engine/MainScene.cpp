#pragma region project include
#include "MainScene.h"
#include "Player.h"
#include "ContentManagement.h"
#pragma endregion

#pragma region public override function
// initialize scene
void GMainScene::Init()
{
	// create textured object
	GPlayer* pObj = new GPlayer(SVector2(0, 0), SVector2(1280, 720),
		CEngine::Get()->GetRenderer(), "Texture/Background/T_backg_L1_1280x720.png");

	pObj->SetSpeed(2.0f);

	// add object to cm
	CEngine::Get()->GetCM()->AddPersistantObject(pObj);

	// create 2nd player object
	GPlayer* pObj2 = new GPlayer(SVector2(0, 0), SVector2(1280, 720),
		CEngine::Get()->GetRenderer(), "Texture/Background/T_backg_L0_1280x720.png");

	pObj2->SetSpeed(1.0f);

	// add object to cm
	CEngine::Get()->GetCM()->AddPersistantObject(pObj2);
}

// cleaning up scene
void GMainScene::Clean()
{

}
#pragma endregion