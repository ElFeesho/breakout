#ifndef __BLOCK_HPP__
#define __BLOCK_HPP__

#include "entity.hpp"
#include "renderable.hpp"

class Block : public Entity, public Renderable
{
public:
	Block();
	~Block();

	bool render();
	bool update();

	int getId();

	void entityAdded();
	void entityRemoved();
};

#endif