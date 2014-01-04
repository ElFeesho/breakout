#include "paddle.hpp"

#include "engine.hpp"
#include <SDL/SDL.h>

Paddle::Paddle()
{
	Y(SDL_GetVideoSurface()->h-24);
	X(SDL_GetVideoSurface()->w/2-32);
}

Paddle::~Paddle()
{

}

bool Paddle::update()
{
	Uint8 *keys = SDL_GetKeyState(NULL);
	if(keys[SDLK_LEFT])
	{
		X(X()-3);
	}
	else if(keys[SDLK_RIGHT])
	{
		X(X()+3);
	}

	if(X()<0)
	{
		X(0);
	}
	else if(X()>SDL_GetVideoSurface()->w-64)
	{
		X(SDL_GetVideoSurface()->w-64);
	}

	return isAlive();
}

bool Paddle::render()
{
	SDL_Rect paddle = { X(), Y(), 64, 16 };
	SDL_FillRect(SDL_GetVideoSurface(), &paddle, 0xffffffff);
	return isAlive();
}

void Paddle::entityAdded()
{
	Engine::getInstance()->getActiveScene()->addRenderable(this);
}

void Paddle::entityRemoved()
{
	Engine::getInstance()->getActiveScene()->removeRenderable(this);
}

int Paddle::getId()
{
	return 0;
}