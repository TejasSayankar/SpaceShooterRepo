#pragma once
#include "EnemyBase.h"
class MovingEnemy : public EnemyBase
{
public:

	MovingEnemy();

	virtual void begin() override;
	virtual void update() override;
	virtual void movement() override;
};

