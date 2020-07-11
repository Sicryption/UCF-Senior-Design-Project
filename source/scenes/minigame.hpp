/**
 *  @file minigame.hpp
 *  @brief Defines the minigame inherited class
 */
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <m3dia.hpp>
#include <sstream>

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
	m3d::Mutex  m_mutex_execution, m_mutex_sandbox, m_mutex_threadState, m_mutex_lua;
	int m_sandboxThreadState = THREAD_RUNNING;
	std::string* m_luaChunk = nullptr;
	LuaSandbox* m_sandbox = nullptr;

	ButtonMenuItem* AddButton = nullptr,
		*EditButton = nullptr,
		*RemoveButton = nullptr,
		*closeButton = nullptr,
		*submitButton = nullptr;
	CodeEditorMenuItem* codeEditor = nullptr;
	CommandListerMenuItem* commandLister = nullptr;
	CommandEditorMenuItem* commandEditor = nullptr;

	std::function<void(std::vector<CommandObject*>)> submitFunction = nullptr;

	bool showCommandLister = false, showCommandEditor = false;

	/**
	 * @brief Sandbox thread's main  function.
	 * Only called by the minigameclass to initialize the sandboxThread
	 * @param param m3d::Parameter, recieves a pointer to the threadState variable
	 */
	void sandboxRuntime(m3d::Parameter param);

protected:
	static bool winCond;

	/**
	* @brief Send code to the sandbox thread.
	* @param chunk valid lua code.
	*/
	void executeInSandbox(std::string chunk);

	/**
	*  @brief Set the state of the sandbox thread.
	*  Sets the state within both the native and lua environment
	*  @param state state to set
	*/
	void setThreadState(int state);

	/**
	 *  @brief Get the state of the sandbox thread
	 */
	int getThreadState();

	/**
	 *  @brief Function called before a sandbox execution
	 *  onExecutionBegin is called right before the sandbox executes a chunk
	 */
	virtual void onExecutionBegin();

	/**
	 *  @brief Function called before a sandbox execution
	 *  onExecutionEnd is called right after the sandbox executes a chunk.
	 */
	virtual void onExecutionEnd();

public:
	void toggleWinCond();

	/**
	 *  @brief Default Constructor, should be inherited by child class constructors
	 */

	Minigame();
	/**
	 *  @brief Default Destructor, should be inherited by child class destructor
	 */
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

	virtual bool checkWinCond() {};


	virtual void loadScene() {};
	virtual void loadWinScr() {};
	virtual void loadLoseScr() {};
	virtual void requestUI() {};
	virtual void closeGame() {};

	virtual void initialize() {};
	virtual void load() {};
	virtual void unload() {};
	virtual void update();
	virtual void draw() {};

	virtual void onEnter() {};
	virtual void onExit() {};
};
