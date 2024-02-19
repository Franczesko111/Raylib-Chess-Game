#include <raylib.h>
#include "grid.hpp"

Grid::Grid()
{
	tile_x = tile_y = 0;
	click_position = Vector2{ 0, 0 };

	for (int i = 0; i < GRID_AMOUNT * GRID_AMOUNT; i++)
	{
		grid[i].x = (i % GRID_AMOUNT);
		grid[i].y = (i / GRID_AMOUNT);
		grid[i].color = red;

		empty_spots[i].x = (i % GRID_AMOUNT);
		empty_spots[i].y = (i / GRID_AMOUNT);
	}
	
	ResetEmptySpots();
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

	//draw empty spots
	if (empty_spots[id].active) DrawCircle((pawn.pawns[id].x * GRID_SIZE) + OFFSET_X + 40, pawn.pawns[id].y * GRID_SIZE + OFFSET_Y + 40, 20, LIGHTGRAY);
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
		//int pawn_x = pawn.pawns[id].x;
		//int pawn_y = pawn.pawns[id].y;
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		{
			for (int i = 0; i < GRID_AMOUNT * GRID_AMOUNT; i++)
			{
				if (pawn.pawns[i].x == id_x && pawn.pawns[i].y == id_y && pawn.pawns[i].active)
				{
					grid[id].color = green;
					click_position = Vector2{ id_x, id_y };
					ResetEmptySpots();
					AddNewEmptySpots(i, pawn.pawns[i].type);
				}
			}
		} else {
			grid[id].color = yellow;
		}
	} else {
		grid[id].color = red;
	}
}

void Grid::ResetEmptySpots() { for (int i = 0; i < GRID_AMOUNT * GRID_AMOUNT; i++) empty_spots[i].active = false; }

void Grid::AddNewEmptySpots(int id, int type)
{
	switch (type)
	{
		case 0:
		{
			//Move Forward Code for Regular Pawn
			if (pawn.pawns[id - 8].active == false)
			{
				if (id > 7)
				{
					for (int i = 0; i < 2; i++)
					{
						if (id - ((i + 1) * 8) > 7)
						{
							empty_spots[id - ((i + 1) * 8)].active = true;
						}
					}
				}
			}
		}
	}
}