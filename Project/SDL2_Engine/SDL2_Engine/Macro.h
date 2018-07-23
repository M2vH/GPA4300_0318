#pragma once

#pragma region value macro
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define PLAYER_SPEED 10.0f
#define PLAYER_WIDTH 68
#define PLAYER_HEIGHT 92
#define PLAYER_MIRROR SVector2(1.0f, 0.0f)
#define WORLD_BLOCK_ATLAS_WIDTH 26
#define WORLD_BLOCK_ATLAS_HEIGHT 26
#define WORLD_BLOCK_WIDTH 48
#define WORLD_BLOCK_HEIGHT 48
#pragma endregion

#pragma region function macro
#define LOG_ERROR(TEXT, ERROR)		\
	std::cout << TEXT;				\
	std::cout << " Error: ";		\
	std::cout << ERROR;				\
	std::cout << std::endl;
#pragma endregion