#pragma once
#include <raylib.h>

#include "data.hpp"
#include "pawn.hpp"

struct GRID_DATA
{
	int x;
	int y;
	Color color;
};

struct EMPTY_SPOTS
{
	bool active;
	int x;
	int y;
};

class Grid
{
	public:
		Grid();
		~Grid();
		void Draw(int id);
		void Update(int id);

		Pawn pawn;

	private:
		int tile_x, tile_y;
		Vector2 click_position;

		void Collision(int id, int x, int y);
		void ResetEmptySpots();
		void AddNewEmptySpots(int id, int type);

		EMPTY_SPOTS empty_spots[GRID_AMOUNT * GRID_AMOUNT];
		GRID_DATA grid[GRID_AMOUNT * GRID_AMOUNT];

		Color red = Color{ 255, 141, 133, 255 };
		Color yellow = Color{ 255, 241, 133, 255 };
		Color green = Color{ 157, 255, 133, 255 };
};