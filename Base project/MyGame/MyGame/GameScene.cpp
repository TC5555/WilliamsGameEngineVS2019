#include "GameScene.h"
#include "Ship.h"
#include "Score.h"
#include "MeteorSpawner.h"
#include "HealthPackSpawner.h"
#include "GameOverScene.h"
#include "BigMeteorSpawner.h"
#include "ScrollingBackground.h"
GameScene::GameScene()
{
	ScrollingBackgroundPtr scrollingbackgroundSpawner = std::make_shared<ScrollingBackground>();
	addGameObject(scrollingbackgroundSpawner);

	ShipPtr ship = std::make_shared<Ship>();
	addGameObject(ship);

	MeteorSpawnerPtr meteorSpawner = std::make_shared<MeteorSpawner>();
	addGameObject(meteorSpawner);

	ScorePtr score = std::make_shared<Score>(sf::Vector2f(10.0f, 10.0f));
	addGameObject(score);
}

void GameScene::BigMeteorUnlock()
{
	BigMeteorSpawnerPtr bigmeteorSpawner = std::make_shared<BigMeteorSpawner>();
	addGameObject(bigmeteorSpawner);
}

void GameScene::HealthPackUnlock()
{
	HealthPackSpawnerPtr healthpackspawner = std::make_shared<HealthPackSpawner>();
	addGameObject(healthpackspawner);
}

int GameScene::getScore()
{
	return score_;
}
void GameScene::increaseScore()
{
	++score_;
}

void GameScene::increaseScorebig()
{
	score_ += 5;
}


int GameScene::getLives()
{
		return lives_;
}
void GameScene::decreaseLives()
{
	--lives_;
	if (lives_ == 0)
	{
		GameOverScenePtr gameOverScene = std::make_shared<GameOverScene>(score_);
		GAME.setScene(gameOverScene);
	}
}

void GameScene::increaseLives()
{
	if (lives_ < 5)
	{
		++lives_;
	}
}
