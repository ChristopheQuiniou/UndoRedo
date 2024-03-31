#pragma once
class Entity
{
	public:
		Entity();
		~Entity();
		void moveTo(int x, int y);
		virtual void render();
		int x();
		int y();

	protected:
		int x_;
		int y_;
};

