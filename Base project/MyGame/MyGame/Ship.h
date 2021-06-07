#pragma once
#include "Engine/GameEngine.h"
class Ship : public GameObject
{
public:
	// Creates our ship.
	Ship();
	// Functions overridden from GameObject:
	void draw();
	void update(sf::Time& elapsed);
	sf::FloatRect getCollisionRect();
	void updateDamageLevel(int damageLevel);
private:
	sf::Sprite sprite_;
	int fireTimer_ = 0;
	int damageLevel_ = 0;
};
typedef std::shared_ptr<Ship> ShipPtr;
