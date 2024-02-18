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

struct FREE_SPOTS
{
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
		int tile_x, tile_y, spot_x, spot_y;
		Vector2 click_position;

		bool selected_pawn;

		void Collision(int id, int x, int y);

		GRID_DATA grid[GRID_AMOUNT * GRID_AMOUNT];
		FREE_SPOTS free_spots[2];

		Color red = Color{ 255, 141, 133, 255 };
		Color yellow = Color{ 255, 241, 133, 255 };
		Color green = Color{ 157, 255, 133, 255 };
};