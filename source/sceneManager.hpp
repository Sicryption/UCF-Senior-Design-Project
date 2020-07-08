#pragma once
#include "scenes/scene.hpp"
#include "scenes/minigame.hpp"

#include "commands/commands.h"

class SceneManager
{
private:

    static Scene* m_nextScene;
    static Scene* m_currentScene;

    //static SceneManager* m_instance;
    //static SceneManager* getInstance();

public:

    static Scene* getScene();
    static void transitionTo(Scene*);

    static void OnInitialize();
    static void OnUpdate();
    static void OnDraw();

	static void AddCommand(CommandObject *command);
	static void RequestUserCode(std::vector<CommandObject*> commands, std::function<void(std::vector<CommandObject*>)> callbackFunction);
};
