#include "Projectile.h"
#include <iostream>

Projectile::Projectile()
{
	size = sf::Vector2f(60, 20);
	position = sf::Vector2f(0, -(size.y / 2));
	rotation = 0;
	begin();
	isFired = false;
	speed = 30;
	direction = 1;
	//dimentions = spriteTexture.getSize();
}

void Projectile::begin()
{
	//shape.setSize(size);
	spriteTexture.loadFromFile("Assets/enemy_laser.png");
	dimentions = spriteTexture.getSize();
	position = sf::Vector2f(0, -((float)(dimentions.y / 2)));
	sprite.setPosition(position);
	sprite.setTexture(spriteTexture);
	center = sf::Vector2f(position.x + (size.x / 2), position.y + (size.y / 2));
}

void Projectile::update()
{
	projectileMovement();

	if (position.x < -(int)(dimentions.x) || position.x > WINDOW_WIDTH)
	{
		
		disable();
	}
}

void Projectile::disable()
{
	isFired = false;
	position = sf::Vector2f(0, -(size.y / 2));
	center = sf::Vector2f(position.x + (size.x / 2), position.y + (size.y / 2));
}

void Projectile::projectileMovement()
{
	//shape.move(sf::Vector2f(speed * direction, 0));
	sprite.move(sf::Vector2f(speed * direction, 0));
	position = sprite.getPosition();
	center = sf::Vector2f(position.x + (size.x / 2), position.y + (size.y / 2));
}

void Projectile::enable()
{
	isFired = true;
}

void Projectile::collision()
{

}

bool Projectile::setPosition(sf::Vector2f Position)
{
	position += Position;
	//shape.setPosition(position);
	sprite.setPosition(position);
	//shape.setFillColor(sf::Color::Blue);
	return true;
}

bool Projectile::setRotation(float Rotation)
{
	return false;
}





