#pragma once
#include <Windows.h>
#include "../command/Command.h"
#include "../entity/Entity.h"
#include "../command/implementations/MoveTo.h"

class InputHandler
{
	public:
		InputHandler(Entity* entity);
		Command* handleInput();

	private:
		Entity* entity_;
		Command* leftArrow_;
		Command* upArrow_;
		Command* rightArrow_;
		Command* downArrow_;
		

};

