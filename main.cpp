#include <SDL/SDL.h>

#include "engine.hpp"
#include "gamescene.hpp"

int main(int argc, char **argv)
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Surface *screen = SDL_SetVideoMode(640, 320, 0, SDL_SWSURFACE);
	int done = 0;

	Engine::getInstance()->pushScene(new GameScene());
	long lastTick = SDL_GetTicks();
	while(!done)
	{
		SDL_Event ev;
		while(SDL_PollEvent(&ev))
		{
			if(ev.type == SDL_QUIT)
			{
				done = 1;
			}
		}

		SDL_FillRect(screen, NULL, 0x0);

		Engine::getInstance()->update();
		Engine::getInstance()->render();

		SDL_Flip(screen);
		long delay = (1000/60) - (SDL_GetTicks()-lastTick);
		lastTick = SDL_GetTicks();
		if(delay>0)
		{	
			SDL_Delay(delay);
		}
	}
	SDL_Quit();
	return 0;
}