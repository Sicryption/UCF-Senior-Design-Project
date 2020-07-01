#pragma once
#include "scene.hpp"

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


};
