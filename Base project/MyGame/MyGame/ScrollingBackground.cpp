#include "ScrollingBackground.h"
#include "GameScene.h"

ScrollingBackground::ScrollingBackground()
{
	sprite_1.setTexture(GAME.getTexture("Resources/background.png"));
	sprite_1.setPosition(sf::Vector2f(800, 0));
	sprite_2.setTexture(GAME.getTexture("Resources/background.png"));
	sprite_2.setPosition(sf::Vector2f(0, 0));
	assignTag("background");
}
void ScrollingBackground::draw()
{
	GAME.getRenderWindow().draw(sprite_1);
	GAME.getRenderWindow().draw(sprite_2);
}
void ScrollingBackground::update(sf::Time& elapsed) {
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos1 = sprite_1.getPosition();
	sf::Vector2f pos2 = sprite_2.getPosition();
	GameScene& scene = (GameScene&)GAME.getCurrentScene();

	float SPEED = .5;

	if (pos1.x < sprite_1.getGlobalBounds().width * -1)
	{
		sprite_1.setPosition(sf::Vector2f(800, 0));
	}
	else
	{
		sprite_1.setPosition(sf::Vector2f(pos1.x - SPEED * msElapsed, pos1.y));
	}
	
	if (pos2.x < sprite_2.getGlobalBounds().width * -1)
	{
		sprite_2.setPosition(sf::Vector2f(800, 0));
	}
	else
	{
		sprite_2.setPosition(sf::Vector2f(pos2.x - SPEED * msElapsed, pos2.y));
	}
}