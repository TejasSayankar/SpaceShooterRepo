#pragma once
#include "Character.h"
class EnemyBase : public Character
{
public:
	EnemyBase();

	sf::Clock clock;
	bool isWaiting;
	bool isSpawned;
	float projectileSpeed;
	float canFire;
	int points;

	virtual void begin() override;
	virtual void update() override;
	void fireWithTime();
	virtual void movement() override;

	virtual void delayFire(float t);
	void selectRandomPosition();

	virtual void enable();
	virtual void disable();
	
	bool checkCollidedWithPlayer(int x1, int y1, int x2, int y2);
	
};

