#include <raylib.h>

int main()
{
	InitWindow(1280, 720, "Chess Not Chess");
	SetTargetFPS(60);

	while (WindowShouldClose() == false)
	{
		BeginDrawing();

		ClearBackground(LIGHTGRAY);

		EndDrawing();
	}

	CloseWindow();
	return 0;
}