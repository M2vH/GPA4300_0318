#pragma once

#pragma region system include
#include <iostream>
#pragma endregion

#pragma region using
using namespace std;
#pragma endregion

/// <summary>
/// main animal class
/// </summary>
class Animal
{
public:
#pragma region public constructor
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_name">name of animal</param>
	Animal(const char* _name) : m_name(_name) {};
#pragma endregion

#pragma region public function
	/// <summary>
	/// eat function
	/// </summary>
	virtual void Eat() = 0;

	/// <summary>
	/// make noise function
	/// </summary>
	virtual void MakeNoise() = 0;
#pragma endregion

protected:
#pragma region protected primitive variable
	/// <summary>
	/// name of animal
	/// </summary>
	const char* m_name;
#pragma endregion
};