#include "Player.h"


#include <iostream>

Player::Player()
{
}

Player::~Player()
{
}


void Player::render()
{
	std::cout << "Rendering player at " << x() << "," << y() << std::endl;
}