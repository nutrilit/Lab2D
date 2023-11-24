#include "Player.h"

#pragma region Labolatorium2 - zad3
Player::Player()
{
	this->x = 10;
	this->y = 10;
	this->width = 30;
	this->height = 30;
	this->rect = { x, y, width, height };
	this->movementLeft = false;
	this->movementRight = false;
}

void Player::MoveCoordinates(int nx, int ny)
{
	this->x = nx;
	this->y = ny;
	this->rect = { x, y, width, height };
}

void Player::MoveLeft()
{
	if (x > 0) {
		x = x - 10;
		this->movementLeft = true;
	}
	this->rect = { x, y, width, height };
}

void Player::MoveRight()
{
	if (x + width < 800) {
		x = x + 10;
		this->movementRight = true;
	}
	this->rect = { x, y, width, height };
}
#pragma endregion