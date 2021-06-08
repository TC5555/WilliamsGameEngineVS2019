#include "HealthPackSpawner.h"
// The number of milliseconds between meteor spawns.
const int SPAWN_DELAY = (float)(rand() % 20000) + 20000;
void HealthPackSpawner::update(sf::Time& elapsed) {
	// Determine how much time has passed and adjust our timer.
	int msElapsed = elapsed.asMilliseconds();
	timer_ -= msElapsed;
	// If our timer has elapsed, reset it and spawn a meteor.
	if (timer_ <= 0)
	{
		timer_ = SPAWN_DELAY;
		sf::Vector2u size = GAME.getRenderWindow().getSize();
		// Create a meteor and add it to the scene
		HealthPackPtr healthpack = std::make_shared<HealthPack>(sf::Vector2f(size.x, size.y /2));
		GAME.getCurrentScene().addGameObject(healthpack);
	}
}
