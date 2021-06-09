#include "StartMessage.h"
#include "GameScene.h"
#include <sstream>
StartMessage::StartMessage()
{
	text_.setFont(GAME.getFont("Resources/Courneuf-Regular.ttf"));
	text_.setPosition(sf::Vector2f(50.0f, 50.0f));
	text_.setCharacterSize(48);
	text_.setFillColor(sf::Color::Yellow);
	std::stringstream stream;
	stream << "BLASTER!!!\n\nPRESS ENTER TO BEGIN";
	text_.setString(stream.str());
}
void StartMessage::draw()
{
	GAME.getRenderWindow().draw(text_);
}
void StartMessage::update(sf::Time& time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		GameScenePtr scene = std::make_shared<GameScene>();
		GAME.setScene(scene);
		return;
	}
}