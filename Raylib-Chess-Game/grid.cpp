#include <raylib.h>

#include "grid.hpp"
#include "data.hpp"

Grid::Grid()
{
	tile_x = tile_y = spot_x = spot_y = 0;
	click_position = Vector2{ 0, 0 };
	selected_pawn = false;

	for (int i = 0; i < GRID_AMOUNT * GRID_AMOUNT; i++)
	{
		grid[i].x = (i % GRID_AMOUNT);
		grid[i].y = (i / GRID_AMOUNT);
		grid[i].color = red;
	}

	for (int i = 0; i < 2; i++)
	{
		free_spots[i].x = 0;
		free_spots[i].y = 0;
	}
}

Grid::~Grid()
{

}

void Grid::Draw(int id)
{
	tile_x = (grid[id].x * GRID_SIZE) + OFFSET_X;
	tile_y = (grid[id].y * GRID_SIZE) + OFFSET_Y;

	//draws the grid stuff
	DrawRectangle(tile_x, tile_y, GRID_SIZE, GRID_SIZE, grid[id].color);

	DrawText(TextFormat("%i", grid[id].x), tile_x, tile_y, 30, RED);
	DrawText(TextFormat("%i", grid[id].y), tile_x, tile_y + 40, 30, BLUE);

	DrawText(TextFormat("Selected: %.0f, %.0f", click_position.x, click_position.y), 0, 40, 40, BLACK);

	DrawRectangleLines(tile_x, tile_y, GRID_SIZE, GRID_SIZE, BLACK);

	if (selected_pawn)
	{
		for (int i = 0; i < 2; i++)
		{
			spot_x = (free_spots[i].x * GRID_SIZE) + OFFSET_X + 40;
			spot_y = (free_spots[i].y * GRID_SIZE) + OFFSET_Y + 40;
			DrawCircle(spot_x, spot_y, 20, LIGHTGRAY);
		}
	}
}

void Grid::Update(int id)
{
	tile_x = (grid[id].x * GRID_SIZE) + OFFSET_X;
	tile_y = (grid[id].y * GRID_SIZE) + OFFSET_Y;

	Collision(id, tile_x, tile_y);
}

void Grid::Collision(int id, int x, int y)
{
	float id_x = (float)grid[id].x;
	float id_y = (float)grid[id].y;

	if (GetMouseX() > x && GetMouseX() < x + GRID_SIZE && GetMouseY() > y && GetMouseY() < y + GRID_SIZE)
	{
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		{
			if (selected_pawn == false)
			{
				for (int i = 0; i < 16; i++)
				{
					if (pawn.pawns[i].x == id_x && pawn.pawns[i].y == id_y)
					{
						grid[id].color = green;
						click_position = Vector2{ id_x, id_y };
						selected_pawn = true;

						for (int j = 0; j < 2; j++)
						{
							free_spots[j].x = id_x;
							free_spots[j].y = id_y - (j + 1);
						}

						break;
					}
				}
			} else {
				//code code code
			}
		}
		else {
			grid[id].color = yellow;
		}
	} else {
		grid[id].color = red;
	}
}