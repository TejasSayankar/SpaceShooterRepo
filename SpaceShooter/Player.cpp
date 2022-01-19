#include "Player.h"
#include "Projectile.h"
#include <iostream>



Player::Player()
{
	//position = sf::Vector2<float>((float)(WINDOW_WIDTH / 2), (float)(WINDOW_HEIGHT / 2));
	//radius = 60.0;
	//position = sf::Vector2f((2 * radius + 10), (WINDOW_HEIGHT / 2 - radius));
	
	

	
	begin();
}

void Player::begin()
{
	//charShape.setRadius(radius);
	//charShape.setPointCount(3);
	//charShape.setPosition(position);
	spriteTexture.loadFromFile("Assets/player_ship.png");
	dimentions = spriteTexture.getSize();
	position = sf::Vector2f(50, (WINDOW_HEIGHT / 2 - (dimentions.y / 2)));
	muzzlePosition = sf::Vector2f(position.x + dimentions.x + 10, position.y + dimentions.y / 2);
	sprite.setPosition(position);
	sprite.setTexture(spriteTexture);
	speed = 8;
	//setRotation(90);
	setCollisionVolume();
	isDied = false;
	isDisabled = false;
	//std::cout << "Character: " << x1 << " " << y1 << "   " << x2 << " " << y2 << std::endl << std::endl;
}



void Player::update()
{
	movement();
	for (int i = 0; i < 10; i++)
	{
		if (projectile[i]->isFired)
		{
			projectile[i]->update();
		}
	}
}

void Player::movement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		//charShape.move(UpVector * speed);
		//position = charShape.getPosition();
		//muzzlePosition = sf::Vector2f(position.x + radius * 2, position.y + radius);
		sprite.move(UpVector * speed);
		position = sprite.getPosition();
		muzzlePosition = sf::Vector2f(position.x + dimentions.x + 10, position.y + dimentions.y / 2);
		setCollisionVolume();
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		/*charShape.move(DownVector * speed);
		position = charShape.getPosition();
		muzzlePosition = sf::Vector2f(position.x + radius * 2, position.y + radius);*/
		sprite.move(DownVector * speed);
		position = sprite.getPosition();
		muzzlePosition = sf::Vector2f(position.x + dimentions.x + 10, position.y + dimentions.y / 2);
		setCollisionVolume();
	}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	//{
	//	/*charShape.move(LeftVector * speed);
	//	position = charShape.getPosition();
	//	muzzlePosition = sf::Vector2f(position.x + radius * 2, position.y + radius);*/
	//	sprite.move(LeftVector * speed);
	//	position = sprite.getPosition();
	//	muzzlePosition = sf::Vector2f(position.x + dimentions.x + 10, position.y + dimentions.y / 2);
	//}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	//{
	//	/*charShape.move(RightVector * speed);
	//	position = charShape.getPosition();
	//	muzzlePosition = sf::Vector2f(position.x + radius * 2, position.y + radius);*/
	//	sprite.move(RightVector * speed);
	//	position = sprite.getPosition();
	//	muzzlePosition = sf::Vector2f(position.x + dimentions.x + 10, position.y + dimentions.y / 2);
	//}
	
}

void Player::disable()
{
	isDisabled = true;
}




