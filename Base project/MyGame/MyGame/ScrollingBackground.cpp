#include "ScrollingBackground.h"
#include "GameScene.h"

ScrollingBackground::ScrollingBackground(sf::Vector2f pos)
{
	sprite_.setTexture(GAME.getTexture("Resources/background.png"));
	sprite_.setPosition(pos);
	assignTag("background");
}
void ScrollingBackground::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}
void ScrollingBackground::update(sf::Time& elapsed) {
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