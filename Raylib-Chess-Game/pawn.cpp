#include <raylib.h>
#include "pawn.hpp"

#include <iostream>
using namespace std;

Pawn::Pawn()
{
	for (int i = 0; i < GRID_AMOUNT * GRID_AMOUNT; i++)
	{
		pawns[i].x = i % GRID_AMOUNT;
		pawns[i].y = i / GRID_AMOUNT;
		pawns[i].type = 0;
		pawns[i].color = PURPLE;
		if (i / GRID_AMOUNT >= 3 && i / GRID_AMOUNT <= 4)
			pawns[i].active = true;
		else
			pawns[i].active = false;
	}
}

Pawn::~Pawn()
{

}

void Pawn::Draw(int id)
{
	if (pawns[id].active) DrawCircle((pawns[id].x * GRID_SIZE) + OFFSET_X + 40, (pawns[id].y * GRID_SIZE) + OFFSET_Y + 40, 30, pawns[id].color);
}

void Pawn::Update()
{

}