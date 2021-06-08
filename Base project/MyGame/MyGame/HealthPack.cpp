#include "HealthPack.h"
#include "GameScene.h"
#include "Ship.h"

HealthPack::HealthPack(sf::Vector2f pos)
{
	setCollisionCheckEnabled(true);
	sprite_.setTexture(GAME.getTexture("Resources/healthpack.png"));
	sprite_.setPosition(pos);

	assignTag("HealthPack");
}
void HealthPack::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}
void HealthPack::update(sf::Time& elapsed) {
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();
	GameScene& scene = (GameScene&)GAME.getCurrentScene();

	float SPEED = .5;

	if (pos.x < sprite_.getGlobalBounds().width * -1)
	{
		makeDead();
	}
	else
	{
		sprite_.setPosition(sf::Vector2f(pos.x - SPEED * msElapsed, pos.y));
	}
}

sf::FloatRect HealthPack::getCollisionRect()
{
	return sprite_.getGlobalBounds();
}
void HealthPack::handleCollision(GameObject& otherGameObject)
{
	if (otherGameObject.hasTag("ship"))
	{
		GameScene& scene = (GameScene&)GAME.getCurrentScene();
		scene.increaseLives();

		((Ship&)otherGameObject).updateDamageLevel(scene.getLives());
		makeDead();
	}
}