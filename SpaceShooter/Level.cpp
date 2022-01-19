#include "Level.h"
#include "EnemyBase.h"
#include "MovingEnemy.h"
#include "Shooter1.h"
#include "Shooter2.h"
#include "Player.h"
#include "Projectile.h"
#include "Particle.h"
#include <iostream>

Level::Level()
{
	for (int i = 0; i < 10; i++)
	{
		particle[i] = new Particle();
	}
	player = new Player();

	for (int i = 0; i < 5; i++)
	{
		enemy[i] = new MovingEnemy();
	}
	for (int i = 5; i < 10; i++)
	{
		enemy[i] = new Shooter1();
	}
	for (int i = 10; i < 15; i++)
	{
		enemy[i] = new Shooter2();
	}
	initialize();
}

void Level::initialize()
{
	
	enemySpeed = enemy[0]->speed;
	enemyProjectileSpeed = enemy[0]->projectileSpeed;
	levelClock.restart();
	score = 0;
}

void Level::Levelloop()
{
	if (!player->isDisabled)
	{
		timePassed = levelClock.getElapsedTime().asSeconds();
	}
	else
	{
		for (int i = 0; i < 5; i++)
		{
			enemy[i]->disable();
		}
		for (int i = 5; i < 10; i++)
		{
			enemy[i]->disable();
		}
		for (int i = 10; i < 15; i++)
		{
			enemy[i]->disable();
		}
	}
	for (int i = 0; i < 10; i++)
	{
		if (particle[i]->isSpawned) {
			//std::cout << i << " " << particle[i]->position.x << " " << particle[i]->position.y << std::endl;
			particle[i]->update();
		}
		
	}
	if (levelClock.getElapsedTime().asSeconds() < 60)
	{
		srand((unsigned)time(0));
		float n = rand() % 10 + 10.0;
		spawnParticle((float)(n / 10.0));
	}
	if (levelClock.getElapsedTime().asSeconds() < 60)
	{
		srand((unsigned)time(0));
		float n = rand() % 10 + 46.0;
		delaySpawn((float)(n / 10.0));
	}
	else if (levelClock.getElapsedTime().asSeconds() < 120)
	{
		srand((unsigned)time(0));
		float n = rand() % 10 + 26.0;
		delaySpawn((float)(n / 10.0));
	}
	else if (levelClock.getElapsedTime().asSeconds() < 240)
	{
		srand((unsigned)time(0));
		float n = rand() % 10 + 16.0;
		delaySpawn((float)(n / 10.0));

	}
	else if (levelClock.getElapsedTime().asSeconds() < 360)
	{
		srand((unsigned)time(0));
		float n = rand() % 10 + 11.0;
		delaySpawn((float)(n / 10.0));
	}
	else if (levelClock.getElapsedTime().asSeconds() < 480)
	{
		srand((unsigned)time(0));
		float n = rand() % 10 + 6.0;
		delaySpawn((float)(n / 10.0));
		delaySpawn((float)(n / 10.0 / 2.0));

	}
	else
	{
		srand((unsigned)time(0));
		float n = rand() % 5 + 4.0;
		delaySpawn((float)(n / 10.0));
	}

	player->update();

	

	for (int i = 0; i < 15; i++)
	{
		if (enemy[i]->isSpawned)
		{
			enemy[i]->update();
			for (int j = 0; j < 10; j++)
			{
				if (player->projectile[j]->isFired)
				{

					if (enemy[i]->checkCollided(player->projectile[j]->center))
					{
						enemy[i]->disable();
						score += enemy[i]->points;
						player->projectile[j]->disable();
					}
				}
				if (enemy[i]->projectile[j]->isFired)
				{
					/*std::cout << "Projectile: " << enemy[i]->projectile[j]->position.x << " " << enemy[i]->projectile[j]->position.y << std::endl;
					std::cout << "Player: " << player->x1 << " " << player->y1 << "   " << player->x2 << " " << player->y2 << std::endl << std::endl;*/
					if (player->checkCollided(enemy[i]->projectile[j]->center))
					{
						player->disable();
						enemy[i]->projectile[j]->disable();
						levelClock.restart();
					}
				}

			}

			/*std::cout << "Projectile: " << enemy[i]->projectile[j]->position.x << " " << enemy[i]->projectile[j]->position.y << std::endl;
			std::cout << "Player: " << player->x1 << " " << player->y1 << "   " << player->x2 << " " << player->y2 << std::endl << std::endl;*/
			if (enemy[i]->checkCollidedWithPlayer(player->x1, player->y1, player->x2, player->y2))
			{
				player->disable();
				enemy[i]->disable();
				levelClock.restart();
			}
		}
	}
}

//void Level::delaySpawn(float seconds)
//{
//	sf::Time elapsed = spawningClock.getElapsedTime();
//	if (elapsed.asSeconds() >= seconds)
//	{
//		
//		for (int i = 0; i < 10; i++)
//		{
//			if (!enemy[i]->isSpawned)
//			{
//				enemy[i]->enable();
//				if (levelClock.getElapsedTime().asSeconds() < 120)
//				{
//					
//					enemy[i]->speed = enemySpeed;
//					enemySpeed = enemySpeed + 0.05;
//					enemy[i]->projectileSpeed = enemyProjectileSpeed;
//					enemyProjectileSpeed = enemyProjectileSpeed + 0.1;
//				}
//				else if (levelClock.getElapsedTime().asSeconds() < 240)
//				{
//					
//					enemy[i]->speed = enemySpeed;
//					enemySpeed = enemySpeed + 0.04;
//					enemy[i]->projectileSpeed = enemyProjectileSpeed;
//					enemyProjectileSpeed = enemyProjectileSpeed + 0.08;
//				}
//				else if (levelClock.getElapsedTime().asSeconds() < 300)
//				{
//					
//					enemy[i]->speed = enemySpeed;
//					enemySpeed = enemySpeed + 0.03;
//					enemy[i]->projectileSpeed = enemyProjectileSpeed;
//					enemyProjectileSpeed = enemyProjectileSpeed + 0.06;
//				}
//				else
//				{
//					enemy[i]->speed = enemySpeed;
//					enemySpeed = enemySpeed + 0.02;
//					enemy[i]->projectileSpeed = enemyProjectileSpeed;
//					enemyProjectileSpeed = enemyProjectileSpeed + 0.04;
//				}
//				
//				spawningClock.restart();
//				return;
//			}
//		}
//		
//	}
//}

void Level::delaySpawn(float seconds)
{
	sf::Time elapsed = spawningClock.getElapsedTime();
	if (elapsed.asSeconds() >= seconds)
	{
		if (levelClock.getElapsedTime().asSeconds() < 120)
		{

			//enemy[i]->speed = enemySpeed;
			enemySpeed = enemySpeed + 0.05;
			//enemy[i]->projectileSpeed = enemyProjectileSpeed;
			enemyProjectileSpeed = enemyProjectileSpeed + 0.1;
			spawnEnemy(0);
		}
		else if (levelClock.getElapsedTime().asSeconds() < 240)
		{

			//enemy[i]->speed = enemySpeed;
			enemySpeed = enemySpeed + 0.04;
			//enemy[i]->projectileSpeed = enemyProjectileSpeed;
			enemyProjectileSpeed = enemyProjectileSpeed + 0.08;
			srand((unsigned)time(0));
			int n = rand() % 2;
			spawnEnemy(n);
		}
		else if (levelClock.getElapsedTime().asSeconds() < 300)
		{

			//enemy[i]->speed = enemySpeed;
			enemySpeed = enemySpeed + 0.03;
			//enemy[i]->projectileSpeed = enemyProjectileSpeed;
			enemyProjectileSpeed = enemyProjectileSpeed + 0.06;
			srand((unsigned)time(0));
			int n = rand() % 2;
			spawnEnemy(n);
		}
		else
		{

			//enemy[i]->speed = enemySpeed;
			enemySpeed = enemySpeed + 0.02;
			//enemy[i]->projectileSpeed = enemyProjectileSpeed;
			enemyProjectileSpeed = enemyProjectileSpeed + 0.04;

			srand((unsigned)time(0));
			int n = rand() % 2 + 1;
			spawnEnemy(n);
		}

		spawningClock.restart();
		return;
	}
}

void Level::spawnEnemy(int value)
{
	for (int i = 5 * value; i < 5 * (value + 1); i++)
	{
		if (!enemy[i]->isSpawned)
		{
			enemy[i]->enable();
			//std::cout << "spawned" << std::endl;
			enemy[i]->speed = enemySpeed;
			enemy[i]->projectileSpeed = enemyProjectileSpeed;
			return;
		}
	}
}

void Level::spawnParticle(float seconds)
{
	sf::Time elapsed = particleSpawningClock.getElapsedTime();
	if (elapsed.asSeconds() >= seconds)
	{
		for (int i = 0; i < 10; i++)
		{
			if (!particle[i]->isSpawned)
			{
				particle[i]->enable();
				particleSpawningClock.restart();
				return;
			}
		}
		
	}
}

