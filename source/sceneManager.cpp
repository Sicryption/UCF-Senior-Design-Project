#include "sceneManager.hpp"


Scene* SceneManager::m_nextScene = nullptr;
Scene* SceneManager::m_currentScene = nullptr; 

Scene* SceneManager::getScene()
{    
    return m_currentScene;
}

void  SceneManager::transitionTo(Scene* t_next)
{

    if(t_next == nullptr)
    {
        m_currentScene->unload();
        m_currentScene->onExit();
        m_currentScene = nullptr;
        m_nextScene = nullptr;
        return;
    }

    m_nextScene = t_next;
    m_nextScene->initialize();


    
    if(m_currentScene != nullptr)
    {
        m_currentScene->unload();
        m_currentScene->onExit();
    }

    m_nextScene->load();
    
    //  TODO: swap scenes
    delete(m_currentScene);
    m_currentScene = m_nextScene;
    m_nextScene = nullptr;

}

void  SceneManager::OnInitialize()
{
    m_nextScene = nullptr;
    m_currentScene = nullptr;   
}

void  SceneManager::OnUpdate()
{
    if(m_currentScene != nullptr)
    {
        m_currentScene->update();
    }
}

void SceneManager::OnDraw()
{
    if(m_currentScene != nullptr)
    {
        m_currentScene->draw();
    }
}

void SceneManager::AddCommand(CommandObject *com)
{
	if (com == nullptr || m_currentScene == nullptr)
		return;

	Minigame* minigame = static_cast<Minigame*>(m_currentScene);

	if (minigame != nullptr)
	{
		minigame->AddCommand(com);
	}
}

void SceneManager::RequestUserCode(std::vector<CommandObject*> commands, std::function<void(std::vector<CommandObject*>)> callbackFunction)
{
	Minigame* minigame = static_cast<Minigame*>(m_currentScene);

	if (minigame != nullptr)
	{
		minigame->ClearCommands();

		minigame->AddStartCommands(commands);

		minigame->SetSubmitFunction(callbackFunction);
	}
}