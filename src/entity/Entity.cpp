#include "Entity.h"


Entity::Entity() : x_(0), y_(0)
{
}

Entity::~Entity()
{
}

void Entity::moveTo(int x, int y)
{
	x_ = x;
	y_ = y;
}

void Entity::render()
{
}

int Entity::x()
{
	return x_;
}

int Entity::y()
{
	return y_;
}