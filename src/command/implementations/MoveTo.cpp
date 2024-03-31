#include "MoveTo.h"
#include <iostream>

MoveTo::MoveTo(Entity* entity, int x,int y) : entity_(entity), x_(x), y_(y), prevX_(x), prevY_(y)
{
}

MoveTo::~MoveTo()
{
}

void MoveTo::execute()
{
	prevX_ = entity_->x();
	prevY_ = entity_->y();
	entity_->moveTo(x_, y_);
}

void MoveTo::undo()
{
	entity_->moveTo(prevX_, prevY_);
}

