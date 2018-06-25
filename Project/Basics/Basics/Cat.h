#pragma once

#pragma region project include
#include "Animal.h"
#pragma endregion

/// <summary>
/// cat class
/// </summary>
class Cat : public Animal
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_name">name of cat</param>
	Cat(const char* _name) : Animal(_name) {}
#pragma endregion

#pragma region public override function
	/// <summary>
	/// eat function
	/// </summary>
	void Eat() override;

	/// <summary>
	/// make noise function
	/// </summary>
	void MakeNoise() override;
#pragma endregion
};