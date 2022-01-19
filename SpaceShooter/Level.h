#pragma once
#include "Game.h"
class Level
{
public:
	class EnemyBase* enemy[15];
	class Player* player;
	class Particle* particle[10];
	Level();
	void initialize();
	void Levelloop();
	sf::Clock levelClock;
	sf::Clock spawningClock;
	sf::Clock particleSpawningClock;
	int timePassed;
	int score;

	void delaySpawn(float seconds);
	float enemySpeed;
	float enemyProjectileSpeed;

	void spawnEnemy(int value);
	void spawnParticle(float seconds);
};

