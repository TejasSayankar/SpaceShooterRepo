#include "Shooter1.h"
#include "Projectile.h"


Shooter1::Shooter1()
{
	speed = 5;
	isWaiting = false;
	isSpawned = false;
	begin();
	projectileSpeed = 10;
	canFire = true;
}

void Shooter1::begin()
{
	spriteTexture.loadFromFile("Assets/enemy_2.png");
	dimentions = spriteTexture.getSize();
	selectRandomPosition();
	muzzlePosition = sf::Vector2f(position.x - dimentions.x - 10, position.y + dimentions.y / 2);
	setCollisionVolume();
	points = 300;
}

void Shooter1::update()
{
	movement();
	//std::cout << position.x << " " << position.y;
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

void Shooter1::delayFire(float t)
{
	sf::Time elapsed = clock.getElapsedTime();
	if (elapsed.asSeconds() >= t)
	{
		clock.restart();
		fire();
	}
}

void Shooter1::movement()
{
	//charShape.move(LeftVector);
	sprite.move(LeftVector * speed);
	//position = charShape.getPosition();
	position = sprite.getPosition();
	//muzzlePosition = sf::Vector2f(position.x - radius * 2, position.y - radius);
	muzzlePosition = sf::Vector2f(position.x - 50, position.y + dimentions.y / 2);
	setCollisionVolume();
}
