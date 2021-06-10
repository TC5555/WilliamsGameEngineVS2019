#include "BigMeteor.h"
#include "GameScene.h"
#include "Explosion.h"
//added to update ship sprite
#include "Ship.h"
//added to update laser
#include "Laser.h"
BigMeteor::BigMeteor(sf::Vector2f pos)
{
	setCollisionCheckEnabled(true);
	sprite_.setTexture(GAME.getTexture("Resources/bigmeteor.png"));
	sprite_.setPosition(pos);
	sf::FloatRect bounds = sprite_.getGlobalBounds();
	sprite_.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);

	sprite_.setScale(2.5, 2.5);

	sprite_.setRotation(rand() % 360);

	if (rand() % 100 > 50)
	{
		ranrot = true;
	}
	else ranrot = false;
	assignTag("BigMeteor");
}
void BigMeteor::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}
void BigMeteor::update(sf::Time& elapsed) {
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();
	GameScene& scene = (GameScene&)GAME.getCurrentScene();
	float SPEED = .1 + scene.getScore() / 400.f + SPEED1;



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
		health = 5;
	}
	else
	{
		sprite_.setPosition(sf::Vector2f(pos.x - SPEED * msElapsed, pos.y));
	}
}

sf::FloatRect BigMeteor::getCollisionRect()
{
	return sprite_.getGlobalBounds();
}
void BigMeteor::handleCollision(GameObject& otherGameObject)
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
		health--;
		switch (health)
		{
		case 4:
			sprite_.setTexture(GAME.getTexture("Resources/bigmeteordamaged1.png"));
			break;
		case 3:
			sprite_.setTexture(GAME.getTexture("Resources/bigmeteordamaged2.png"));
			break;
		case 2:
			sprite_.setTexture(GAME.getTexture("Resources/bigmeteordamaged3.png"));
			break;
		case 1:
			sprite_.setTexture(GAME.getTexture("Resources/bigmeteordamaged4.png"));
			break;
		}
		if (health == 0)
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
			scene.increaseScorebig();
			health = 5;
			makeDead();

			switch(scene.getScore())
			{ 
			case 50:
				scene.HealthPackUnlock();
			case 51:
				scene.HealthPackUnlock();
			case 52:
				scene.HealthPackUnlock();
			case 53:
				scene.HealthPackUnlock();
			case 54:
				scene.HealthPackUnlock();
			}

		}
		otherGameObject.makeDead();
	}
}