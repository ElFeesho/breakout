#include "ball.hpp"

#include "engine.hpp"

#include <SDL/SDL.h>

Ball::Ball() : xspeed(1), yspeed(1)
{

}

Ball::~Ball()
{

}

void Ball::entityAdded()
{
	Engine::getInstance()->getActiveScene()->addRenderable(this);
}

void Ball::entityRemoved()
{
	Engine::getInstance()->getActiveScene()->removeRenderable(this);	
}

int Ball::getId()
{
	return 1;
}

bool Ball::update()
{
	X(X()+xspeed);
	Y(Y()+yspeed);

	if(xspeed > 0)
	{
		if(X()>SDL_GetVideoSurface()->w-16)
		{
			X(SDL_GetVideoSurface()->w-16);
			xspeed *= -1;
		}
	}
	else
	{
		if(X()<0)
		{
			X(0);
			xspeed *= -1;
		}
	}

	if(yspeed > 0)
	{
		if(Y()>SDL_GetVideoSurface()->h-16)
		{
			Y(SDL_GetVideoSurface()->h-16);
			yspeed *= -1;
		}
	}
	else
	{
		if(Y()<0)
		{
			Y(0);
			yspeed *= -1;
		}
	}


	return isAlive();
}

bool Ball::render()
{
	SDL_Rect rect = { X(), Y(), 16, 16 };
	SDL_FillRect(SDL_GetVideoSurface(), &rect, 0xffffffff);
	return isAlive();
}

void Ball::deflect(double offset)
{
	xspeed = -2*offset;
	yspeed *= -1;
}

void Ball::xdeflect()
{
	xspeed *= -1;
}

void Ball::ydeflect()
{
	yspeed *= -1;
}