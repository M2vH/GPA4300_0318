#pragma region project include
#include "Physic.h"
#include "Rect.h"
#pragma endregion

// check collision of two rects
bool CPhysic::RectRectCollision(SRect _rectOne, SRect _rectTwo)
{
	// if first rect is right from second rect
	if (_rectOne.x > _rectTwo.x - _rectTwo.w)
		return false;

	// if first rect is left from second rect
	if (_rectOne.x + _rectOne.w < _rectTwo.x)
		return false;

	// if first rect is lower than second rect
	if (_rectOne.y > _rectTwo.y + _rectTwo.h)
		return false;

	// if first rect is higher than second rect
	if (_rectOne.y + _rectOne.h < _rectTwo.y)
		return false;

	// collision
	return true;
}