#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <m3dia.hpp>

#include "../ObjectManager.hpp"
#include "../gameManager.hpp"
#include "../inputManager.hpp"
#include "../sceneManager.hpp"
#include "../resources.h"
#include "scene.hpp"

#include <sstream>

#define DEBUG

#define THREAD_HALT     1
#define THREAD_RUNNING  0
#define THREAD_CLOSE   -1

#define setObjectName(name, id) executeInSandbox("name_table[\"" name "\"] = " + std::to_string(id))

class Minigame : public Scene
{
	private:
        m3d::Thread* m_sandboxThread;
        m3d::Mutex  m_mutex_execution, m_mutex_sandbox, m_mutex_threadState;
        int m_sandboxThreadState = THREAD_RUNNING;
        std::string* m_luaChunk = nullptr;

		ButtonMenuItem* AddButton = nullptr,
			*EditButton = nullptr,
			*RemoveButton = nullptr,
			*closeButton = nullptr,
			*submitButton = nullptr;
		m3dCI::CodeEditor* codeEditor = nullptr;
		m3dCI::CommandLister* commandLister = nullptr;
		m3dCI::CommandEditor* commandEditor = nullptr;

		std::function<void(std::vector<CommandObject*>)> submitFunction = nullptr;

		bool showCommandLister = false, showCommandEditor = false;

		void sandboxRuntime(m3d::Parameter param);        

	protected:
		static bool winCond;
		
		void executeInSandbox(std::string chunk);
		void setThreadState(int state);

		virtual void onExecutionBegin();
		virtual void onExecutionEnd();

	public:
		//virtual void initialize() = 0;
		//virtual void update() = 0;
		virtual bool checkWinCond() {};

		void toggleWinCond();

		Minigame();
        virtual ~Minigame();

		void AddCommand(CommandObject* command);
		void AddStartCommands(std::vector<CommandObject*> obj);
		void ClearCommands();

		void SetSubmitFunction(std::function<void(std::vector<CommandObject*>)> callbackFunction);

		void AddButton_OnClick();
		void EditButton_OnClick();
		void DeleteButton_OnClick();
		void SubmitButton_OnClick();
		void CloseButton_OnClick();

		// origScene is the new default scene when the player loses
		// returns true if successful, otherwise false 
		/*bool reset(Scene *origScene)
		{
			if (!winCond)
			{
				 m_currentScene = origScene;
				 m_currentScene->initialize();
				 return true;
			}

			return false; 
		}*/

		virtual void loadScene() {};
		virtual void loadWinScr() {};
		virtual void loadLoseScr() {};
		virtual void requestUI() {};
		virtual void closeGame() {};
	//from scene
		virtual void initialize() {};
		virtual void load() {};
		virtual void unload() {};
		virtual void update();
		virtual void draw() {};

		virtual void onEnter() {};

		virtual void onExit() {};

	
	

};





