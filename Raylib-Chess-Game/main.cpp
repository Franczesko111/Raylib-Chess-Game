#include <raylib.h>
#include "game.hpp"

const int SCREEN_WIDTH = 1280, SCREEN_HEIGHT = 800, GAME_FPS = 60;
const char* GAME_TITLE = "Chess Not Chess";

int main()
{
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_TITLE);
	SetTargetFPS(GAME_FPS);

	Game game;

	while (WindowShouldClose() == false)
	{
		BeginDrawing();

		game.Update();

		ClearBackground(LIGHTGRAY);

		game.Draw();

		EndDrawing();
	}

	CloseWindow();
	return 0;
}