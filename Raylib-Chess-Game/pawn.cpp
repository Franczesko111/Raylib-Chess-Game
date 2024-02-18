#include <raylib.h>
#include "pawn.hpp"

#include <iostream>
using namespace std;

Pawn::Pawn()
{
	for (int i = 0; i < 16; i++)
	{
		pawns[i].x = i % 8;
		pawns[i].y = (i / 8) + 6;
		pawns[i].type = 0;
	}
}

Pawn::~Pawn()
{

}

void Pawn::Draw(int id)
{
	DrawCircle((pawns[id].x * GRID_SIZE) + OFFSET_X + 40, (pawns[id].y * GRID_SIZE) + OFFSET_Y + 40, 30, PURPLE);
}

void Pawn::Update()
{

}