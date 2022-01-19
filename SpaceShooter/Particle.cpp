#include "Game.h"
#include "Particle.h"
#include <iostream>

Particle::Particle()
{
	particleSpeed = 0;
	begin();
}

void Particle::begin()
{
	//shape.setSize(size);
	shape.setRadius(5);
	shape.setPointCount(4);
	
	srand((unsigned)time(0));
	position = sf::Vector2f(1000, ((rand() % 9) + 1) * (WINDOW_HEIGHT / 9));
	shape.setPosition(position);
	particleSpeed = 2;
	isSpawned = false;
	LeftVector = sf::Vector2f(-particleSpeed, 0);
	//enable();
	shape.setFillColor(sf::Color(86, 135, 144, 255));
}

void Particle::update()
{
	movement();
	if (position.x < -100)
	{
		enable();
	}
}

void Particle::movement()
{
	//shape.move(sf::Vector2f(speed * direction, 0));
	shape.move(LeftVector);
	position = shape.getPosition();
	//std::cout <<position.x << " " << position.y << std::endl;
}

void Particle::enable()
{
	srand((unsigned)time(0));
	position = sf::Vector2f(WINDOW_WIDTH + 10, ((rand() % 20) + 1) * (WINDOW_HEIGHT / 20));
	shape.setPosition(position);
	isSpawned = true;
	/*srand((unsigned)time(0));
	particleSpeed = (rand() % 4) + 1;*/
}


bool Particle::setPosition()
{
	//shape.setPosition(position);
	shape.setPosition(position);
	//shape.setFillColor(sf::Color::Blue);
	return true;
}

