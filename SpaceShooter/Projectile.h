#include "Game.h"
#pragma once
class Projectile
{
public:
	//sf::RectangleShape shape;

	sf::Sprite sprite;
	sf::Texture spriteTexture;
	sf::Vector2u dimentions;

	sf::Vector2f position;
	float rotation;

	sf::Vector2f size;

	sf::Vector2f center;
	bool isFired;
	float speed;

	bool setPosition(sf::Vector2f Position);
	bool setRotation(float Rotation);

	float direction;

	Projectile();
	void begin();
	void update();
	void disable();
	void projectileMovement();
	void enable();

	void collision();


	
};

