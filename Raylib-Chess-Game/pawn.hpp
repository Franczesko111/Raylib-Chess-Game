#pragma once
#include <raylib.h>
#include "data.hpp"

struct PAWN_DATA
{
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

		PAWN_DATA pawns[16];

	private:
};