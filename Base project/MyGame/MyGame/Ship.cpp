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