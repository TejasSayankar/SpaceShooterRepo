#pragma once
#include "Character.h"
class Player : public Character
{
	
	
public:
	bool isDied;
	bool isDisabled;
	Player();
	virtual void begin() override;
	virtual void update() override;

	virtual void movement() override;

	void disable();
	sf::Clock DyingClock;
};

