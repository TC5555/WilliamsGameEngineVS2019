#pragma once

#include "Engine/GameEngine.h"
#include "BigMeteor.h"

class BigMeteorSpawner : public GameObject
{
public:
	void update(sf::Time& elapsed);
private:
	int timer_ = 0;
};

typedef std::shared_ptr<BigMeteorSpawner> BigMeteorSpawnerPtr;
