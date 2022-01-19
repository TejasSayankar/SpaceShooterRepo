#pragma once
#include "EnemyBase.h"
class Shooter2 : public EnemyBase
{
public:

	Shooter2();

	virtual void begin() override;
	virtual void update() override;
	virtual void movement() override;
	virtual void delayFire(float t);
};

