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
	for (int i = 0; i < 64; i++) grid.Draw(i);
	DrawFPS(0, 0);
}

void Game::Update()
{
	for (int i = 0; i < 64; i++) grid.Update(i);
}