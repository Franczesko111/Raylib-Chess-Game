#include <raylib.h>
#include "grid.hpp"

#include <iostream>
using namespace std;

Grid::Grid()
{
	for (int i = 0; i < 64; i++)
	{
		grid[i].x = (i % 8) * GRID_SIZE + GetScreenWidth() / 2 - (GRID_AMOUNT / 2) * GRID_SIZE;
		grid[i].y = (i / 8) * GRID_SIZE + GetScreenHeight() / 2 - (GRID_AMOUNT / 2) * GRID_SIZE;
		grid[i].color = red;
	}
}

Grid::~Grid()
{

}

void Grid::Draw(int id)
{
	DrawRectangle(grid[id].x, grid[id].y, GRID_SIZE, GRID_SIZE, grid[id].color);
	DrawRectangleLines(grid[id].x, grid[id].y, GRID_SIZE, GRID_SIZE, BLACK);
}

void Grid::Update(int id)
{
	if (GetMouseX() > grid[id].x && GetMouseX() < grid[id].x + GRID_SIZE && GetMouseY() > grid[id].y && GetMouseY() < grid[id].y + GRID_SIZE)
	{
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
			grid[id].color = green;
		else
			grid[id].color = yellow;
	} else {
		grid[id].color = red;
	}
}