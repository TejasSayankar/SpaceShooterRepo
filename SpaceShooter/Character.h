#include "Game.h"
#pragma once
class Character
{
public:
	Character();
	sf::Vector2f position;
	float rotation;

	//float radius;
	//sf::CircleShape charShape;

	sf::Sprite sprite;
	sf::Texture spriteTexture;
	sf::Vector2u dimentions;
	/*float sizeX;
	float sizeY;*/


	class Projectile* projectile[10];
	sf::Vector2f muzzlePosition;
	sf::Vector2f UpVector;
	sf::Vector2f DownVector;
	sf::Vector2f LeftVector;
	sf::Vector2f RightVector;
	float speed;

	int x1, x2, y1, y2;

	

	bool setPosition(sf::Vector2f Position);
	bool setRotation(float Rotation);
	bool setScale(sf::Vector2f Scale);

	virtual void begin() = 0;
	virtual void update() = 0;

	virtual void movement() = 0;
	void fire();

	void setCollisionVolume();

	bool checkCollided(sf::Vector2f value);
};

