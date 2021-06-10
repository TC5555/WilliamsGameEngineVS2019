
/*
Maintenance log:
6/6/2021: Ship now changes sprite with damage level.
6/8/2021: Meteors move at different speeds, rotate. Big Meteors that take 5 hits to destroy, award 5 points, and move slowly spawn at 20 points. health packs spawn in at a random time between 20 and 40 seconds when you reach 50 points. The Game now has a title/start scene
6/9/2021: Meteors now rotate at different speeds. background scrolls but i don't understand how hierarchies work
*/

#include "Engine/GameEngine.h"
#include "GameScene.h"
#include "StartScene.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

const std::string WINDOW_TITLE = "Tyler Game";

int main()
{
	// Seed the random number generator.
	srand((int)time(NULL));

	// Initialize the game.
	GAME.initialize(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

	// Create our start screen scene.
	StartScenePtr startscene = std::make_shared<StartScene>();
	GAME.setScene(startscene);

	// Run the game loop.
	GAME.run();

	return 0;
}