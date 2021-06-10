#include "Ship.h"
#include <memory>
#include "Laser.h"

const float SPEED = 0.3f;
const int FIRE_DELAY = 200;

void Ship::update(sf::Time& elapsed) {
	sf::Vector2f pos = sprite_.getPosition();
	float x = pos.x;
	float y = pos.y;
	int msElapsed = elapsed.asMilliseconds();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) y -= SPEED * msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) y += SPEED * msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) x -= SPEED * msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) x += SPEED * msElapsed;
	sf::FloatRect bounds = sprite_.getGlobalBounds();
	if (x >= 716) x = 716;
	if (y >= 480) y = 480;
	if (x <= 0) x = 0;
	if (y <= 0) y = 0;
	sprite_.setPosition(sf::Vector2f(x, y));

	if (fireTimer_ > 0)
	{
		fireTimer_ -= msElapsed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && fireTimer_ <= 0)
	{
		fireTimer_ = FIRE_DELAY;
		sf::FloatRect bounds = sprite_.getGlobalBounds();
		float laserX;
		float laserY;
		LaserPtr laser;
		laserX = x + bounds.width;
		laserY = y + (bounds.height / 2.0f);
		laser = std::make_shared<Laser>(sf::Vector2f(laserX, laserY));
		GAME.getCurrentScene().addGameObject(laser);
	}

	switch (damageLevel_)
	{
	case 5:
		sprite_.setTexture(GAME.getTexture("Resources/ship.png"));
		break;
	case 4:
		sprite_.setTexture(GAME.getTexture("Resources/shipdamaged1.png"));
		break;
	case 3:
		sprite_.setTexture(GAME.getTexture("Resources/shipdamaged2.png"));
		break;
	case 2:
		sprite_.setTexture(GAME.getTexture("Resources/shipdamaged3.png"));
		break;
	case 1:
		sprite_.setTexture(GAME.getTexture("Resources/shipdamaged4.png"));
		break;
	}
}

void Ship::updateDamageLevel(int damageLevel) {
	damageLevel_ = damageLevel;
}

sf::FloatRect Ship::getCollisionRect()
{
	return sprite_.getGlobalBounds();
}

Ship::Ship()
{
	sprite_.setTexture(GAME.getTexture("Resources/ship.png"));
	sprite_.setPosition(sf::Vector2f(100, 100));
	assignTag("ship");
}

void Ship::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}