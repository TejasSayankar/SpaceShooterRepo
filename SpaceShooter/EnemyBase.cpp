#include "EnemyBase.h"
#include "Projectile.h"
#include <cstdlib>
#include <iostream>



EnemyBase::EnemyBase()
{
	//radius = 60.0;
	//srand((unsigned)time(0));
	/*position = sf::Vector2f(WINDOW_WIDTH + radius + 10, ((std::rand() % 5) + 1) * (WINDOW_HEIGHT / 6));
	muzzlePosition = sf::Vector2f(position.x - radius * 2, position.y + radius);*/
	
	points = 0;
	speed = 5;
	isWaiting = false;
	isSpawned = false;
	projectileSpeed = 10;
}

void EnemyBase::begin()
{
	
}

void EnemyBase::update()
{
	movement();
	for (int i = 0; i < 10; i++)
	{
		if (projectile[i]->isFired)
		{
			projectile[i]->update();
			projectile[i]->direction = -1;
			projectile[i]->speed = projectileSpeed;
		}
	}
	/*if (!isWaiting)
	{
		fireWithTime();
	}*/
	delayFire(2);
	if (position.x < -(int)(dimentions.x))
	{
		disable();
	}
	
}

void EnemyBase::fireWithTime()
{
	isWaiting = true;
	delayFire(2);
	//fire();
	isWaiting = false;
}



void EnemyBase::movement()
{
	//charShape.move(LeftVector);
	sprite.move(LeftVector * speed);
	//position = charShape.getPosition();
	position = sprite.getPosition();
	//muzzlePosition = sf::Vector2f(position.x - radius * 2, position.y - radius);
	muzzlePosition = sf::Vector2f(position.x - 50, position.y + dimentions.y / 2);
}



void EnemyBase::delayFire(float t)
{
	
	sf::Time elapsed = clock.getElapsedTime();
	if (elapsed.asSeconds() >= t)
	{
		clock.restart();
		fire();
	}
}

void EnemyBase::selectRandomPosition()
{
	srand((unsigned)time(0));
	position = sf::Vector2f(WINDOW_WIDTH + 10, ((rand() % 5) + 1) * (WINDOW_HEIGHT / 6));
	muzzlePosition = sf::Vector2f(position.x - dimentions.x - 10, position.y + dimentions.y / 2);
	sprite.setPosition(position);
	sprite.setTexture(spriteTexture);
}

void EnemyBase::enable()
{
	isSpawned = true;
	selectRandomPosition();
}

void EnemyBase::disable()
{
	isSpawned = false;
	for (int i = 0; i < 10; i++)
	{
		projectile[i]->disable();
	}
}

bool EnemyBase::checkCollidedWithPlayer(int px1, int py1, int px2, int py2)
{
	if (px1 < x1 + ((x2 - x1) / 2) && px2 > x1 + ((x2 - x1) / 2) && ((py1 <= y1 && py2 >= y1) || (py1 <= y2 && py2 >= y1)))
	{
		/*std::cout << "After Colliding" << std::endl;
		std::cout << "Player: " << px1 << " " << py1 << "   " << px2 << " " << py2 << std::endl << std::endl;
		std::cout << "Enemy: " << x1 << " " << y1 << "   " << x2 << " " << y2 << std::endl << std::endl;*/
		return true;
	}
	return false;
}


