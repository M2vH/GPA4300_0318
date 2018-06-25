#pragma region project include
#include "Cat.h"
#include "Dog.h"
#pragma endregion

/// <summary>
/// entry point of application
/// </summary>
/// <returns>code of shut down</returns>
int main() 
{
	Cat kitty = Cat("Kitty");

	kitty.Eat();

	Dog paul = Dog("Paul");

	paul.MakeNoise();

	int neu;
	cin >> neu;

	// app shut down correctly
	return 0;
}