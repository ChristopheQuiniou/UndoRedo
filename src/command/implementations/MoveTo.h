#pragma once
#include "../Command.h"
#include "../../entity/Entity.h"

class MoveTo : public Command
{
	public:
		MoveTo(Entity* entity,int x,int y);
		~MoveTo();
		void execute() override;
		void undo() override;

	private:
		Entity* entity_;
		int x_;
		int y_;
		int prevX_;
		int prevY_;
};

