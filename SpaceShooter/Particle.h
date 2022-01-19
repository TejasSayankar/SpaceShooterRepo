#pragma once
#include "Game.h"
class Particle
{
public:
	sf::CircleShape shape;

	sf::Vector2f position;

	sf::Vector2f size;
	float radius;
	bool isSpawned;
	float particleSpeed;

	Particle();

	bool setPosition();

	void begin();
	void update();
	void movement();
	void enable();

	sf::Vector2f LeftVector;
};

