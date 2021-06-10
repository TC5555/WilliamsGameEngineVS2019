#include "ScrollingBackgroundSpawner.h"
// The number of milliseconds between meteor spawns.
const int SPAWN_DELAY = 1500;
void ScrollingBackgroundSpawner::update(sf::Time& elapsed) {
	// Determine how much time has passed and adjust our timer.
	int msElapsed = elapsed.asMilliseconds();
	timer_ -= msElapsed;
	// If our timer has elapsed, reset it and spawn a meteor.
	if (timer_ <= 0)
	{
		timer_ = SPAWN_DELAY;
		sf::Vector2u size = GAME.getRenderWindow().getSize();
		// Create a meteor and add it to the scene
		ScrollingBackgroundPtr scrollingbackground  = std::make_shared<ScrollingBackground>(sf::Vector2f(800, 0));
		GAME.getCurrentScene().addGameObject(scrollingbackground);
	}
}