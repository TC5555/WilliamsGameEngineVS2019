#pragma once

#include "Engine/GameEngine.h"
#include "ScrollingBackground.h"
class ScrollingBackgroundSpawner : public GameObject
{
public:
	void update(sf::Time& elapsed);
private:
	int timer_ = 0;
};

typedef std::shared_ptr<ScrollingBackgroundSpawner> ScrollingBackgroundSpawnerPtr;