#pragma once
#include "Engine/GameEngine.h"
class HealthPack : public GameObject
{
public:
	// Creates our HealthPack.
	HealthPack(sf::Vector2f pos);
	// Functions overridden from GameObject:
	void draw();
	void update(sf::Time& elapsed);
	sf::FloatRect getCollisionRect();
	void handleCollision(GameObject& otherGameObject);

private:
	sf::Sprite sprite_;
};
typedef std::shared_ptr<HealthPack> HealthPackPtr;