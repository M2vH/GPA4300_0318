#pragma region project include
#include "MainScene.h"
#include "TexturedObject.h"
#include "ContentManagement.h"
#pragma endregion

#pragma region public override function
// initialize scene
void GMainScene::Init()
{
	// create textured object
	CTexturedObject* pObj = new CTexturedObject(SVector2(100, 45), SVector2(32, 32), 
		CEngine::Get()->GetRenderer(), "PP.png");

	// add object to cm
	CEngine::Get()->GetCM()->AddPersistantObject(pObj);
}

// cleaning up scene
void GMainScene::Clean()
{

}
#pragma endregion