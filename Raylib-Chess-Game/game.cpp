#include <raylib.h>
#include "game.hpp"

Game::Game()
{

}

Game::~Game()
{

}

void Game::Draw()
{
	for (int i = 0; i < GRID_AMOUNT * GRID_AMOUNT; i++) grid.Draw(i);
	for (int i = 0; i < 16; i++) pawn.Draw(i);
	DrawFPS(0, 0);
}

void Game::Update()
{
	for (int i = 0; i < GRID_AMOUNT * GRID_AMOUNT; i++) grid.Update(i);
}