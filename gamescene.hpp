#ifndef __GAMESCENE_HPP__
#define __GAMESCENE_HPP__

#include <vector>

#include "scene.hpp"
#include "ball.hpp"
#include "paddle.hpp"
#include "block.hpp"

class GameScene : public Scene
{
public:
	GameScene();
	~GameScene();

	void update();

private:
	Paddle *paddle;
	Ball *ball;
	std::vector<Block*> blocks;
};

#endif