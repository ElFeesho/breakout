#ifndef __PADDLE_HPP__
#define __PADDLE_HPP__

#include "entity.hpp"
#include "renderable.hpp"

class Paddle : public Entity, public Renderable
{
public:
	Paddle();
	~Paddle();

	void entityAdded();
	void entityRemoved();

	bool update();
	bool render();

	int getId();
};

#endif