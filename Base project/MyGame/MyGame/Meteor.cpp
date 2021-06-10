#include "Meteor.h"
#include "GameScene.h"
#include "Explosion.h"
//added to update ship sprite
#include "Ship.h"
//added to update laser
#include "Laser.h"
Meteor::Meteor(sf::Vector2f pos)
{
	setCollisionCheckEnabled(true);
	sprite_.setTexture(GAME.getTexture("Resources/meteor.png"));
	sprite_.setPosition(pos);

	sf::FloatRect bounds = sprite_.getGlobalBounds();
	sprite_.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
	
	sprite_.setRotation(rand() % 360);

	if (rand() % 100 > 50)
	{
		ranrot = true;
	}
	else ranrot = false;

	assignTag("bigmeteor");
}
void Meteor::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}
void Meteor::update(sf::Time& elapsed) {
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();
	GameScene& scene = (GameScene&)GAME.getCurrentScene();

	float SPEED = .1 + scene.getScore() / 200.f + SPEED1;

	float rotation = sprite_.getRotation();
	if (ranrot == true)
	{
		rotation += speedrot;
	}
	else rotation -= speedrot;
	sprite_.setRotation(rotation);

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

		GameScene& scene = (GameScene&)GAME.getCurrentScene();
		scene.decreaseLives();
		
		// Added to Update the damage level of the ship to show a more damages show on next update.
		((Ship&)otherGameObject).updateDamageLevel(scene.getLives());
		makeDead();
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
		explosionX = x + (bounds.width / 2.0f);
		explosionY = y + (bounds.height / 2.0f);
		explosion = std::make_shared<Explosion>(sf::Vector2f(explosionX, explosionY));
		GAME.getCurrentScene().addGameObject(explosion);
		GameScene& scene = (GameScene&)GAME.getCurrentScene();
		scene.increaseScore();
		otherGameObject.makeDead();
		makeDead();

		if (scene.getScore() == 20)
		{
			scene.BigMeteorUnlock();
		}
		
 		if (scene.getScore() == 50)
		{
			scene.HealthPackUnlock();
		}
	}
}