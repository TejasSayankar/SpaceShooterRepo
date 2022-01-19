#include "MovingEnemy.h"
#include "Projectile.h"
#include <iostream>

MovingEnemy::MovingEnemy()
{
	speed = 5;
	isWaiting = false;
	isSpawned = false;
	begin();
	//canFire = true;
}

void MovingEnemy::begin()
{
	spriteTexture.loadFromFile("Assets/enemy_1.png");
	dimentions = spriteTexture.getSize();
	selectRandomPosition();
	setCollisionVolume();
	//std::cout << "Character: " << x1 << " " << y1 << "   " << x2 << " " << y2 << std::endl << std::endl;
	points = 100;
}

void MovingEnemy::update()
{
	movement();
	//std::cout << position.x << " " << position.y;
	/*for (int i = 0; i < 10; i++)
	{
		if (projectile[i]->isFired)
		{
			projectile[i]->update();
			projectile[i]->direction = -1;
			projectile[i]->speed = projectileSpeed;
		}
	}*/
	
	if (position.x < -(int)(dimentions.x))
	{
		disable();
	}
	//delayFire(1);
}

void MovingEnemy::movement()
{
	//charShape.move(LeftVector);
	sprite.move(LeftVector * speed);
	//position = charShape.getPosition();
	position = sprite.getPosition();
	//muzzlePosition = sf::Vector2f(position.x - radius * 2, position.y - radius);
	muzzlePosition = sf::Vector2f(position.x - 50, position.y + dimentions.y / 2);
	setCollisionVolume();
}
