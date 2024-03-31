#include "InputHandler.h"


InputHandler::InputHandler(Entity* entity) : entity_(entity)
{
}


Command* InputHandler::handleInput()
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		return new MoveTo(entity_,entity_->x() - 1, entity_->y());
	}
	else if (GetAsyncKeyState(VK_UP))
	{
		return new MoveTo(entity_, entity_->x(), entity_->y() - 1);
	}
	else if (GetAsyncKeyState(VK_RIGHT))
	{
		return new MoveTo(entity_, entity_->x() + 1, entity_->y());
	}
	else if (GetAsyncKeyState(VK_DOWN))
	{
		return new MoveTo(entity_, entity_->x(), entity_->y() + 1 );
	}

	return nullptr;
}