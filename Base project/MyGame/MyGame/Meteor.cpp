#include "Meteor.h"
const float SPEED = (float)(rand() % 1) + .3f;
Meteor::Meteor(sf::Vector2f pos)
{
	setCollisionCheckEnabled(true);
	sprite_.setTexture(GAME.getTexture("Resources/meteor.png"));
	sprite_.setPosition(pos);
	assignTag("meteor");
}
void Meteor::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}
void Meteor::update(sf::Time& elapsed) {
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();
	if (pos.x < sprite_.getGlobalBounds().width * -1)
	{
		makeDead();
	}
	else
	{
		sprite_.setPosition(sf::Vector2f(pos.x - SPEED * msElapsed, pos.y));
	}
}

sf::FloatRect Meteor::getCollisionRect()
{
	return sprite_.getGlobalBounds(); 
}
void Meteor::handleCollision(GameObject& otherGameObject)
{
	if (otherGameObject.hasTag("laser"))
	{
		sf::Vector2f pos = sprite_.getPosition();
		float explosionX;
		float explosionY;
		ExplosionPtr laser;
		explosionX = x + bounds.width;
		explosionY = y + (bounds.height / 2.0f);
		explosion = std::make_shared<Laser>(sf::Vector2f(laserX, laserY));
		GAME.getCurrentScene().addGameObject();
		otherGameObject.makeDead();
	}
	makeDead();
}