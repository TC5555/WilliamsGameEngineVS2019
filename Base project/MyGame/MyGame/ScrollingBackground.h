#pragma once
#include "Engine/GameEngine.h"
class ScrollingBackground : public GameObject
{
public:
	// Creates our HealthPack.
	ScrollingBackground(sf::Vector2f pos);
	// Functions overridden from GameObject:
	void draw();
	void update(sf::Time& elapsed);
private:
	sf::Sprite sprite_;
};
typedef std::shared_ptr<ScrollingBackground> ScrollingBackgroundPtr;
