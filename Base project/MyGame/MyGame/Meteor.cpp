#include "Meteor.h"
#include "GameScene.h"
#include "Explosion.h"
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
	if (otherGameObject.hasTag("ship"))
	{
		sf::Vector2f pos = sprite_.getPosition();
		float x = pos.x;
		float y = pos.y;
		sf::FloatRect bounds = sprite_.getGlobalBounds();
		float explosionX;
		float explosionY;
		ExplosionPtr explosion;
		explosionX = x + bounds.width;
		explosionY = y + (bounds.height / 2.0f);
		explosion = std::make_shared<Explosion>(sf::Vector2f(explosionX, explosionY));
		GAME.getCurrentScene().addGameObject(explosion);
		GameScene& scene = (GameScene&)GAME.getCurrentScene();
		scene.decreaseLives();
	}
	if (otherGameObject.hasTag("laser"))
	{
		sf::Vector2f pos = sprite_.getPosition();
		float x = pos.x;
		float y = pos.y;
		sf::FloatRect bounds = sprite_.getGlobalBounds();
		float explosionX;
		float explosionY;
		ExplosionPtr explosion;
		explosionX = x + bounds.width;
		explosionY = y + (bounds.height / 2.0f);
		explosion = std::make_shared<Explosion>(sf::Vector2f(explosionX, explosionY));
		GAME.getCurrentScene().addGameObject(explosion);
		GameScene& scene = (GameScene&)GAME.getCurrentScene();
		scene.increaseScore();
		otherGameObject.makeDead();
	}
	makeDead();
}