#include "minigame.hpp"

void Minigame::sandboxRuntime(m3d::Parameter param)
{
	m_mutex_sandbox.lock();
	//Util::PrintLine("sandbox: start sandbox thread");

	LuaSandbox* sandbox = new LuaSandbox();
	int* state = param.get<int*>();
	if (state == NULL)
	{
		Util::PrintLine("Error: threadstate not defined, sandbox thread closing.");
		return;
	}

	while (true)
	{
		//Util::PrintLine("sandbox: check thread state");
		//  Lock access to Thread State
		m_mutex_threadState.lock();
		if (*state == THREAD_CLOSE)
		{   //  close Thread
			break;
		}
		else if (*state == THREAD_HALT)
		{
			m_mutex_threadState.unlock();
			continue;
		}
		m_mutex_threadState.unlock();

		// lock sandbox
		m_mutex_sandbox.lock();

		if (m_luaChunk != nullptr)
		{

			onExecutionBegin();
			//  TODO: Disable Command Menu
			sandbox->executeString(*m_luaChunk);
			m_luaChunk = nullptr;
			onExecutionBegin();

		}

		m_mutex_execution.unlock();
		m3d::Thread::sleep(100);
	}
	//m_mutex_threadState.unlock();
}

void Minigame::executeInSandbox(std::string chunk)
{

	//  Wait for any sandbox executions to complete
	m_mutex_execution.lock();

	if (m_luaChunk == nullptr)
	{
		m_luaChunk = new std::string(chunk);
	}
	else
	{
		m_luaChunk->assign(chunk);
	}

	//  Allow sandbox thread to continue execution
	m_mutex_sandbox.unlock();

}

void Minigame::setThreadState(int state)
{
	//  Wait for thread state access
	m3d::Lock lock(m_mutex_threadState);
	m_sandboxThreadState = state;

}

void Minigame::onExecutionBegin()
{

}

void Minigame::onExecutionEnd()
{

}

void Minigame::toggleWinCond()
{
	winCond = !winCond;
}

Minigame::Minigame()
{
	m3d::Screen * screen = GameManager::getScreen();
	ObjectManager* om = ObjectManager::getInstance();

	m_sandboxThread = new m3d::Thread([this](m3d::Parameter p) {sandboxRuntime(p); }, &m_sandboxThreadState);
#ifdef DEBUG
	std::stringstream t_debug;
	t_debug << "new sandbox thread: " << m_sandboxThread;
	Util::PrintLine(t_debug.str());
#endif
	m_sandboxThread->start();

	int margin = 5;

	codeEditor = om->CreateCodeEditor(margin, (BOTTOMSCREEN_WIDTH * 0.75) - (margin * 2), 1);

	codeEditor->SetActive(true);

	int buttonWidth = BOTTOMSCREEN_WIDTH * 0.25 - (margin * 2);
	int buttonHeight = (BOTTOMSCREEN_HEIGHT - buttonWidth - (margin * 2)) / 3;

	AddButton = new ButtonMenuItem(BOTTOMSCREEN_WIDTH * 0.75 + margin, margin, buttonWidth, buttonHeight, m3d::Color(255, 255, 255), m3d::Color(0, 0, 0), 1);
	AddButton->SetText("ADD");
	AddButton->SetOnRelease([this]() { this->AddButton_OnClick(); });

	EditButton = new ButtonMenuItem(BOTTOMSCREEN_WIDTH * 0.75 + margin, margin + buttonHeight, buttonWidth, buttonHeight, m3d::Color(255, 255, 255), m3d::Color(0, 0, 0), 1);
	EditButton->SetText("EDIT");
	EditButton->SetOnRelease([this]() { this->EditButton_OnClick(); });

	RemoveButton = new ButtonMenuItem(BOTTOMSCREEN_WIDTH * 0.75 + margin, margin + buttonHeight * 2, buttonWidth, buttonHeight, m3d::Color(255, 255, 255), m3d::Color(0, 0, 0), 1);
	RemoveButton->SetText("DEL");
	RemoveButton->SetOnRelease([this]() { this->DeleteButton_OnClick(); });

	closeButton = new ButtonMenuItem(48 + BOTTOMSCREEN_WIDTH * 0.5, 0, new m3dCI::Sprite(*ResourceManager::getSprite("tabClose.png")));
	closeButton->SetOnRelease([this]() { this->CloseButton_OnClick(); });
	closeButton->SetActive(false);

	submitButton = new ButtonMenuItem(BOTTOMSCREEN_WIDTH * 0.75 + margin, margin + buttonHeight * 3, buttonWidth, buttonWidth, m3d::Color(255, 255, 255), m3d::Color(0, 0, 0), 1);
	submitButton->SetText("Run");
	submitButton->SetOnRelease([this]() { this->SubmitButton_OnClick(); });
	
	menu->AddItem(submitButton);
	menu->AddItem(closeButton);
	menu->AddItem(EditButton);
	menu->AddItem(RemoveButton);
	menu->AddItem(AddButton);

	commandLister = om->CreateCommandLister(this);
}

Minigame::~Minigame()
{
	ObjectManager* om = ObjectManager::getInstance();

	m3d::Lock lock(m_mutex_threadState);
	m_sandboxThreadState = THREAD_CLOSE;
	m_sandboxThread->join();

	/*om->DeleteCodeEditor(codeEditor);
	om->DeleteCommandLister(commandLister);*/
}

void Minigame::update()
{
	m3d::Screen * scr = GameManager::getScreen();
	ObjectManager* om = ObjectManager::getInstance();

	if (Util::IsConsoleDrawn())
		return;

	if (commandEditor != nullptr && showCommandEditor)
	{
		if (commandEditor->getComplete())
		{
			showCommandEditor = false;

			om->DeleteCommandEditor(commandEditor);

			commandLister->SetActive(false);
			codeEditor->SetActive(true);
			AddButton->SetActive(true);
			EditButton->SetActive(true);
			RemoveButton->SetActive(true);
			submitButton->SetActive(true);
		}
		else
		{
			scr->drawBottom(*commandEditor);

			if (closeButton != nullptr)
			{
				closeButton->setPosition(BOTTOMSCREEN_WIDTH - 37, 0);
				scr->drawBottom(*closeButton);
			}
		}
	}

	if (codeEditor != nullptr)
	{
		if (showCommandLister)
			scr->drawTop(*codeEditor);
		else if (!showCommandEditor)
		{
			scr->drawBottom(*codeEditor);
			AddButton->SetActive(codeEditor->canAdd());
			EditButton->SetActive(codeEditor->canEdit());
			RemoveButton->SetActive(codeEditor->canRemove());
		}
	}

	if (commandLister != nullptr && showCommandLister)
	{
		scr->drawBottom(*commandLister);

		if (closeButton != nullptr)
		{
			closeButton->setPosition(48 + BOTTOMSCREEN_WIDTH * 0.5, 0);
			scr->drawBottom(*closeButton);
		}
	}

	if (!showCommandEditor)
	{
		if (AddButton != nullptr)
			scr->drawBottom(*AddButton);

		if (EditButton != nullptr)
			scr->drawBottom(*EditButton);

		if (RemoveButton != nullptr)
			scr->drawBottom(*RemoveButton);

		if (submitButton != nullptr)
			scr->drawBottom(*submitButton);
	}
}

void Minigame::AddButton_OnClick()
{
	showCommandLister = true;
	commandLister->SetActive(true);
	codeEditor->SetActive(false);
	AddButton->SetActive(false);
	EditButton->SetActive(false);
	RemoveButton->SetActive(false);
	closeButton->SetActive(true);
	submitButton->SetActive(false);

	codeEditor->ShiftToTop();
}

void Minigame::SubmitButton_OnClick()
{
	if (submitFunction != nullptr)
		submitFunction(codeEditor->GetCommands());
}

void Minigame::EditButton_OnClick()
{
	ObjectManager* om = ObjectManager::getInstance();
	if (codeEditor == nullptr || codeEditor->getSelectedObject() == nullptr)
		return;

	commandEditor = om->CreateCommandEditor(codeEditor->getSelectedObject());

	commandLister->SetActive(false);
	codeEditor->SetActive(false);
	AddButton->SetActive(false);
	EditButton->SetActive(false);
	RemoveButton->SetActive(false);
	closeButton->SetActive(true);
	submitButton->SetActive(false);

	showCommandEditor = true;
}

void Minigame::DeleteButton_OnClick()
{
	codeEditor->removeCommand();
}

void Minigame::CloseButton_OnClick()
{
	m3d::Screen * scr = GameManager::getScreen();
	ObjectManager* om = ObjectManager::getInstance();

	commandLister->SetActive(false);
	codeEditor->SetActive(true);
	codeEditor->ShiftToBottom();
	AddButton->SetActive(true);
	EditButton->SetActive(true);
	RemoveButton->SetActive(true);
	closeButton->SetActive(false);
	submitButton->SetActive(true);

	scr->clear();

	if (showCommandEditor)
	{
		om->DeleteCommandEditor(commandEditor);
		showCommandEditor = false;
	}
	showCommandLister = false;
}

void Minigame::AddStartCommands(std::vector<CommandObject*> commands)
{
	for (unsigned int i = 0; i < commands.size(); i++)
		codeEditor->addCommand(commands[i]);
}

void Minigame::AddCommand(CommandObject* command)
{
	m3d::Screen * scr = GameManager::getScreen();

	codeEditor->addCommand(command);
	commandLister->SetActive(false);
	codeEditor->SetActive(true);
	codeEditor->ShiftToBottom();
	AddButton->SetActive(true);
	EditButton->SetActive(true);
	RemoveButton->SetActive(true);
	closeButton->SetActive(false);
	submitButton->SetActive(true);

	scr->clear();

	showCommandLister = false;
}

void Minigame::ClearCommands()
{
	codeEditor->ClearCommands();
}

void Minigame::SetSubmitFunction(std::function<void(std::vector<CommandObject*>)> callbackFunction)
{
	submitFunction = callbackFunction;
}