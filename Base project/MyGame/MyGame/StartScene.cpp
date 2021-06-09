#include "StartScene.h"
#include "StartMessage.h"
StartScene::StartScene()
{
	StartMessagePtr startmessage = std::make_shared<StartMessage>();
	addGameObject(startmessage);
}