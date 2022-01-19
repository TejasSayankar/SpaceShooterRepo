#include "Character.h"
#include "Projectile.h"
#include <iostream>

Character::Character()
{

	for (int i = 0; i < 10; i++)
	{
		projectile[i] = new Projectile();
	}
	speed = 1;
	UpVector = sf::Vector2f(0, -speed);
	DownVector = sf::Vector2f(0, speed);
	LeftVector = sf::Vector2f(-speed, 0);
	RightVector = sf::Vector2f(speed, 0);

	x1 = 0;
	x2 = 0;
	y1 = 0;
	y2 = 0;
	//dimentions = spriteTexture.getSize();
}

void Character::fire()
{
	for (int i = 0; i < 10; i++)
	{
		if (!projectile[i]->isFired)
		{
			projectile[i]->setPosition(muzzlePosition);
			projectile[i]->enable();
			return;
		}

	}
}

bool Character::setPosition(sf::Vector2f Position)
{
	return false;
}

bool Character::setRotation(float Rotation)
{
	rotation = Rotation;
	//charShape.rotate(Rotation);
	sprite.rotate(Rotation);
	return true;
}

bool Character::setScale(sf::Vector2f Scale)
{
	return false;
}

void Character::setCollisionVolume()
{
	x1 = position.x;
	y1 = position.y;
	x2 = x1 + spriteTexture.getSize().x;
	y2 = y1 + spriteTexture.getSize().y;
}

bool Character::checkCollided(sf::Vector2f value)
{
	if (value.x > x1 && value.x < x2 && value.y >= y1 && value.y < y2)
	{
		std::cout << "After Colliding"<<std::endl;
		std::cout << "Projectile: " << value.x << " " << value.y << std::endl;
		std::cout << "Character: " << x1 << " " << y1 << "   " << x2 << " " << y2 << std::endl << std::endl;
		return true;
	}
	return false;
}