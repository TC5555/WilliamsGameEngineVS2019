#pragma once
#include "Engine/GameEngine.h"
class BigMeteor : public GameObject
{
public:
	// Creates our Meteor.
	BigMeteor(sf::Vector2f pos);
	// Functions overridden from GameObject:
	void draw();
	void update(sf::Time& elapsed);
	sf::FloatRect getCollisionRect();
	void handleCollision(GameObject& otherGameObject);

private:
	sf::Sprite sprite_;
	bool ranrot;
	int health = 5;
	float SPEED1 = (float)((rand() % 10) / 100.f);
	float speedrot = (float)((rand() % 150) / 200.f);
};
typedef std::shared_ptr<BigMeteor> BigMeteorPtr;
