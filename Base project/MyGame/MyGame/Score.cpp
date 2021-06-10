#include "Score.h"
#include "GameScene.h"
#include <sstream>

Score::Score(sf::Vector2f pos)
{
	text_.setFont(GAME.getFont("Resources/Orbitron-VariableFont_wght.ttf"));
	text_.setPosition(pos);
	text_.setCharacterSize(24);
	text_.setFillColor(sf::Color::White);
	assignTag("score");
}
void Score::draw()
{
	GAME.getRenderWindow().draw(text_);
}
void Score::update(sf::Time& elapsed) {
	GameScene& scene = (GameScene&)GAME.getCurrentScene();
	std::stringstream stream;
	stream << "Score: " << scene.getScore() << "\tLives: " << scene.getLives();
	text_.setString(stream.str());
}