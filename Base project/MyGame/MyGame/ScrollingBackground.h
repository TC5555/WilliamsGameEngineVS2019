#pragma once
#include "Engine/GameEngine.h"
class ScrollingBackground : public GameObject
{
public:
	// Creates our HealthPack.
	ScrollingBackground();
	// Functions overridden from GameObject:
	void draw();
	void update(sf::Time& elapsed);
private:
	sf::Sprite sprite_1;
	sf::Sprite sprite_2;
};
typedef std::shared_ptr<ScrollingBackground> ScrollingBackgroundPtr;
