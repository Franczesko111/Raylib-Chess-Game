#include <raylib.h>
#include "grid.hpp"

#include <iostream>
using namespace std;

Grid::Grid()
{
	tile_x = tile_y = 0;
	click_position = Vector2{ 0, 0 };

	offset_x = GetScreenWidth() / 2 - (GRID_AMOUNT / 2) * GRID_SIZE;
	offset_y = GetScreenHeight() / 2 - (GRID_AMOUNT / 2) * GRID_SIZE;

	for (int i = 0; i < 64; i++)
	{
		grid[i].x = (i % 8);
		grid[i].y = (i / 8);
		grid[i].color = red;
	}
}

Grid::~Grid()
{

}

void Grid::Draw(int id)
{
	tile_x = (grid[id].x * GRID_SIZE) + offset_x;
	tile_y = (grid[id].y * GRID_SIZE) + offset_y;

	DrawRectangle(tile_x, tile_y, GRID_SIZE, GRID_SIZE, grid[id].color);

	DrawText(TextFormat("%i", grid[id].x), tile_x, tile_y, 30, RED);
	DrawText(TextFormat("%i", grid[id].y), tile_x, tile_y + 40, 30, BLUE);

	DrawText(TextFormat("Selected: %.0f, %.0f", click_position.x, click_position.y), 0, 40, 40, BLACK);

	DrawRectangleLines(tile_x, tile_y, GRID_SIZE, GRID_SIZE, BLACK);
}

void Grid::Update(int id)
{
	tile_x = (grid[id].x * GRID_SIZE) + offset_x;
	tile_y = (grid[id].y * GRID_SIZE) + offset_y;

	Collision(id, tile_x, tile_y);
}

void Grid::Collision(int id, int x, int y)
{
	if (GetMouseX() > x && GetMouseX() < x + GRID_SIZE && GetMouseY() > y && GetMouseY() < y + GRID_SIZE)
	{
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		{
			grid[id].color = green;
			click_position = Vector2{ (float) grid[id].x, (float) grid[id].y };
		}
		else {
			grid[id].color = yellow;
		}
	} else {
		grid[id].color = red;
	}
}