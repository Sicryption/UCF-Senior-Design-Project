#include "sceneManager.hpp"



//SceneManager * m_instance = nullptr;
Scene* SceneManager::m_nextScene = nullptr;
Scene* SceneManager::m_currentScene = nullptr; 


Scene* SceneManager::getScene()
{
    
    return m_currentScene;
}

void  SceneManager::transitionTo(Scene* t_next)
{

    if(t_next == nullptr){return;}

    m_nextScene = t_next;
    //  TODO: asynchronously init and load next scene.

    if(m_currentScene != nullptr)
    {
        //  TODO: Unload objects
        //  TODO: Call scene's exit
    }

    //  TODO: swap scenes


}

void  SceneManager::initialize(){
    //  m_currentScene = tester;
    //tester->initialize();
   
    //m_currentScene = new startScene();
}

void  SceneManager::update()
{
    if(m_currentScene != nullptr)
    {
        m_currentScene->update();
    }
}

void  SceneManager::draw()
{
    if(m_currentScene != nullptr)
    {
        m_currentScene->draw();
    }
}

