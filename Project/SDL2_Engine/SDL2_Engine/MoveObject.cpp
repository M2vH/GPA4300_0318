#pragma region project include
#include "MoveObject.h"
#include "Engine.h"
#include "ContentManagement.h"
#include "Physic.h"
#pragma endregion

#pragma region public override function
// update every frame
void CMoveObject::Update()
{
	// moveable default true
	bool moveable = true;

	// next position
	SVector2 nextPos = m_position + m_movement * m_speed;

	// next rect
	SRect nextRect = m_rect;
	nextRect.x = nextPos.X;
	nextRect.y = nextPos.Y;

	// through all scene objects
	for (CObject* pObj : CEngine::Get()->GetCM()->GetSceneObjects())
	{
		// if current object is self continue
		if ((CMoveObject*)pObj && pObj == this)
			continue;

		// if collision type none
		if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::NONE)
			continue;

		// set moveable by checking collision
		moveable = !CPhysic::RectRectCollision(nextRect, ((CTexturedObject*)pObj)->GetRect());

		// if not moveable cancel collision check
		if (!moveable)
			break;
	}

	// if not moveable return
	if (!moveable)
		return;

	// through all persistant objects
	for (CObject* pObj : CEngine::Get()->GetCM()->GetPersistantObjects())
	{
		// if current object is self continue
		if ((CMoveObject*)pObj && pObj == this)
			continue;

		// if collision type none
		if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::NONE)
			continue;

		// set moveable by checking collision
		moveable = !CPhysic::RectRectCollision(nextRect, ((CTexturedObject*)pObj)->GetRect());

		// if not moveable cancel collision check
		if (!moveable)
			break;
	}

	// if not moveable return
	if (!moveable)
		return;

	// add position by movement * speed
	m_position = nextPos;

	// set position of rect
	m_rect.x = m_position.X;
	m_rect.y = m_position.Y;
}

// render every frame
void CMoveObject::Render(CRenderer * _pRenderer)
{
	CTexturedObject::Render(_pRenderer);
}
#pragma endregion