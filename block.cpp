#include "block.hpp"

#include "engine.hpp"
#include <SDL/SDL.h>

Block::Block()
{

}

Block::~Block()
{

}

void Block::entityAdded()
{
	Engine::getInstance()->getActiveScene()->addRenderable(this);
}

void Block::entityRemoved()
{
	Engine::getInstance()->getActiveScene()->removeRenderable(this);
}

bool Block::update()
{
	return isAlive();
}

bool Block::render()
{
	SDL_Rect rect = { X(), Y(), 48, 16 };
	SDL_FillRect(SDL_GetVideoSurface(), &rect, 0xffff0000);
	return isAlive();
}

int Block::getId()
{
	return 2;
}