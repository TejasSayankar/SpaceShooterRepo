#include "Shooter2.h"
#include "Projectile.h"

Shooter2::Shooter2()
{
	speed = 5;
	isWaiting = false;
	isSpawned = false;
	begin();
	projectileSpeed = 10;
	canFire = true;
}

void Shooter2::begin()
{
	spriteTexture.loadFromFile("Assets/enemy_3.png");
	dimentions = spriteTexture.getSize();
	selectRandomPosition();
	setCollisionVolume();
	points = 500;
}

void Shooter2::update()
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
	
	delayFire(1);
	if (position.x < -(int)(dimentions.x))
	{
		disable();
	}
}

void Shooter2::movement()
{
	//charShape.move(LeftVector);
	sprite.move(LeftVector * speed);
	//position = charShape.getPosition();
	position = sprite.getPosition();
	//muzzlePosition = sf::Vector2f(position.x - radius * 2, position.y - radius);
	muzzlePosition = sf::Vector2f(position.x - 50, position.y + dimentions.y / 2);
	setCollisionVolume();
}

void Shooter2::delayFire(float t)
{
	sf::Time elapsed = clock.getElapsedTime();
	if (elapsed.asSeconds() >= t)
	{
		clock.restart();
		fire();
	}
}
