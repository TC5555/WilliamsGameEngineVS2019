#include "BigMeteorSpawner.h"
// The number of milliseconds between meteor spawns.
const int SPAWN_DELAY = (float)(rand() % 15000) + 4600;
void BigMeteorSpawner::update(sf::Time& elapsed) {
	// Determine how much time has passed and adjust our timer.
	int msElapsed = elapsed.asMilliseconds();
	timer_ -= msElapsed;
	// If our timer has elapsed, reset it and spawn a meteor.
	if (timer_ <= 0)
	{
		timer_ = SPAWN_DELAY;
		sf::Vector2u size = GAME.getRenderWindow().getSize();
		// Spawn the meteor off the right side of the screen.
		// We're assuming the meteor isn't more than 100 pixels wide.
		float meteorX = (float)(size.x + 100);
		// Spawn the meteor somewhere along the height of window, randomly.
		float meteorY = (float)(rand() % size.y - 42) + 42;
		// Create a meteor and add it to the scene
		BigMeteorPtr bigmeteor = std::make_shared<BigMeteor>(sf::Vector2f(meteorX, meteorY));
		GAME.getCurrentScene().addGameObject(bigmeteor);

	}
}
