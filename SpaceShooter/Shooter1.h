#pragma once
#include "EnemyBase.h"
class Shooter1 : public EnemyBase
{
public:

	Shooter1();

	virtual void begin() override;
	virtual void update() override;

	virtual void delayFire(float t);
	virtual void movement() override;
};

