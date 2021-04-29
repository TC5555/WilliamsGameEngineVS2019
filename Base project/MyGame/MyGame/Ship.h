#pragma once
#include "Engine/GameEngine.h"
class Ship : public GameObject
{
public:
	// Creates our ship.
	Ship();
	// Functions overridden from GameObject:
	void draw();
private:
	sf::Sprite sprite_;
};
typedefstd::shared_ptr<Ship> ShipPtr;