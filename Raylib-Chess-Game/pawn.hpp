#pragma once
#include <raylib.h>
#include "data.hpp"

struct PAWN_DATA
{
	bool active;

	int x;
	int y;
	int type;
};

class Pawn
{
	public:
		Pawn();
		~Pawn();
		void Draw(int id);
		void Update();

		PAWN_DATA pawns[GRID_AMOUNT * GRID_AMOUNT];

	private:
};