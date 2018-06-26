#pragma region project include
#include "Cat.h"
#include "Dog.h"
#pragma endregion

#pragma region macro
#define MAGIC_NUMBER (42)
#define SQUARE(x) (x * x)
#define PRINT(TEXT) (cout << TEXT << endl)
#define FUNC_TEST(x, y)	\
	int i = 2;			\
	i += x;				\
	PRINT(i, y)
#pragma endregion

/// <summary>
/// entry point of application
/// </summary>
/// <returns>code of shut down</returns>
int main() 
{
	cout << "Program started" << endl;

	int neu;
	cin >> neu;

	// app shut down correctly
	return 0;
}