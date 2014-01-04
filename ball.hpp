#ifndef __BALL_HPP__
#define __BALL_HPP__

#include "entity.hpp"
#include "renderable.hpp"

class Ball : public Entity, public Renderable
{
public:
	Ball();
	~Ball();

	bool update();
	bool render();

	int getId();

	void entityAdded();
	void entityRemoved();

	void deflect(double offset);

	void xdeflect();
	void ydeflect();
private:
	double xspeed;
	double yspeed;
};

#endif