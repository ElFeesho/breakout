#include "gamescene.hpp"

#include "paddle.hpp"
#include "ball.hpp"

GameScene::GameScene()
{
	paddle = new Paddle();
	ball = new Ball();
	addEntity(paddle);
	addEntity(ball);

	for(int i = 0; i < 12; i++)
	{
		for(int k = 0; k < 5; k++)
		{
			Block *block = new Block();
			block->X(i*52 + 10);
			block->Y(k*20 + 10);
			addEntity(block);
			blocks.push_back(block);
		}
	}
}

GameScene::~GameScene()
{

}

void GameScene::update()
{
	Scene::update();
	// Calculate collision detection for paddle and ball
	if(ball->Y()+16>=paddle->Y())
	{
		double br = ball->X()+16;
		double bl = ball->X();
		if(br>paddle->X() && bl < paddle->X()+64)
		{
			// COLLIDED
			double pm = 32;
			double bm = ball->X()+8 - paddle->X();
			double offset = pm-bm;
			ball->deflect(offset/32.0);
			ball->Y(paddle->Y()-16);
		}
	}

	// Check collision between ball and blocks

	for(int i = 0; i<blocks.size(); i++)
	{
		if(ball->X()>blocks[i]->X() && ball->X()+16 < blocks[i]->X()+48)
		{
			// Collision in the middle
			if(ball->Y()+16 > blocks[i]->Y() && ball->Y()<blocks[i]->Y())
			{
				// Collision from top	
				blocks[i]->kill();
				blocks.erase(blocks.begin()+i);
				ball->ydeflect();
			}
			else if(ball->Y() < blocks[i]->Y()+16 && ball->Y()+16>blocks[i]->Y()+16)
			{
				// Collision from bottom	
				blocks[i]->kill();
				blocks.erase(blocks.begin()+i);
				ball->ydeflect();
			}
		}
		else if(ball->X() < blocks[i]->X())
		{
			if(ball->X()+16 > blocks[i]->X())
			{
				// Possible collision from the left
				if((ball->Y()>blocks[i]->Y() && ball->Y()+16<blocks[i]->Y()+32) || (ball->Y()+16>blocks[i]->Y() && ball->Y()+16 < blocks[i]->Y()+16))
				{
					blocks[i]->kill();
					blocks.erase(blocks.begin()+i);
					ball->xdeflect();
				}
			}
		}
		else if(ball->X()+16>blocks[i]->X()+48)
		{
			if(ball->X() < blocks[i]->X()+48)
			{
				// Possible collision from the right
				if((ball->Y()>blocks[i]->Y() && ball->Y()+16<blocks[i]->Y()+32) || (ball->Y()+16>blocks[i]->Y() && ball->Y()+16 < blocks[i]->Y()+16))
				{
					blocks[i]->kill();
					blocks.erase(blocks.begin()+i);
					ball->xdeflect();
				}
			}
		}
	
	}
} 