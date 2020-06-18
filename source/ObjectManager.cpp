#include "ObjectManager.hpp"

using namespace m3d;

//Set default instance of this class to 0, to notify that the instance hasn't been created
ObjectManager *ObjectManager::instance = 0;

/*
	This Class is a singleton. 
	Meaning, only one instance of this class may ever exist.
	This allows for all classes to access this object through the use of this instance value.
	An initial instantiation must occur with proper values passed into createInstance
	All further attempts to accesss this class can use dummy values for all parameters of getInstance
*/
ObjectManager* ObjectManager::createInstance(Screen* screen)
{
	if (instance == 0)
	{
		instance = new ObjectManager(screen);
	}
	
	return instance;
}

/*
	This Class is a singleton. 
	Meaning, only one instance of this class may ever exist.
	This allows for all classes to access this object through the use of this instance value.
	An initial instantiation must occur with proper values passed into createInstance
	All further attempts to accesss this class can use dummy values for all parameters of getInstance
*/
ObjectManager* ObjectManager::getInstance()
{
	if (instance == 0)
	{
		return nullptr;
	}
	
	return instance;
}

//Initialize the Util class.
//Only ever called once.
/*
	This class requires an existing:
		Screen
		
	And must handle:
		Button creation
*/
ObjectManager::ObjectManager(Screen* screen)
{
	scr = screen;
	
	lastFrameTouchX = -1;
	lastFrameTouchY = -1;
	
	util = Util::getInstance();
}

//Destructor: Objects that must be deleted when this object is deleted. Delete(nullptr) is fail-safe.
ObjectManager::~ObjectManager()
{

}

//The function which is called on every game frame.
void ObjectManager::OnUpdate()
{
	int touchedThisFrame = hidKeysDown() & KEY_TOUCH,
		touchReleasedThisFrame = hidKeysUp() & KEY_TOUCH,
		touchx = m3d::touch::getXPosition(),
		touchy = m3d::touch::getYPosition();

	if (touchedThisFrame)
	{
		for (unsigned int i = 0; i < codeEditors.size(); i++)
		{
			//only fires if point is actually inside the code editor
			codeEditors[i]->SelectCommand(touchx, touchy);
		}
	}

	if (touchReleasedThisFrame)
	{
		for (unsigned int i = 0; i < commandListers.size(); i++)
		{
			//only fires if point is actually inside the command lister
			commandListers[i]->SelectPoint(lastFrameTouchX, lastFrameTouchY);
		}
	}
	
	for (unsigned int i = 0; i < buttons.size(); i++)
	{
		if (buttons[i] == nullptr)
			continue;

		//Check for touch event on Button
		if (touchedThisFrame)
		{
			if (buttons[i]->OnTouch != nullptr && buttons[i]->PointIntersects(touchx, touchy))
				(buttons[i]->OnTouch)(buttons[i]);
		}
		else if (touchReleasedThisFrame)
		{
			if (buttons[i]->OnRelease != nullptr && buttons[i]->PointIntersects(lastFrameTouchX, lastFrameTouchY))
				(buttons[i]->OnRelease)(buttons[i]);
		}
		else
		{
			if (buttons[i]->OnHeld != nullptr && buttons[i]->PointIntersects(touchx, touchy))
				(buttons[i]->OnHeld)(buttons[i]);
		}
	}
	
	lastFrameTouchX = touchx;
	lastFrameTouchY = touchy;
}

//Rectangle button creation. Adds button to array of active buttons.
m3dCI::Button* ObjectManager::CreateButton(int x, int y, int w, int h, m3d::Color color, m3d::Color borderColor, int borderWidth = 3)
{
	m3dCI::Button* newButton = new m3dCI::Button(x, y, w, h, color, borderColor, borderWidth);
	
	buttons.push_back(newButton);
	
	return newButton;
}

//Circular button creation. Adds button to array of active buttons.
m3dCI::Button* ObjectManager::CreateButton(int x, int y, int radius, m3d::Color color, m3d::Color borderColor, int borderWidth = 3)
{
	m3dCI::Button* newButton = new m3dCI::Button(x, y, radius, color, borderColor, borderWidth);
	
	buttons.push_back(newButton);
	
	return newButton;
}

//Circular button creation. Adds button to array of active buttons.
m3dCI::Button* ObjectManager::CreateButton(int x, int y, m3d::Texture& t_texture)
{
	m3dCI::Button* newButton = new m3dCI::Button(x, y, t_texture);

	buttons.push_back(newButton);

	return newButton;
}

//Circular button creation. Adds button to array of active buttons.
m3dCI::Button* ObjectManager::CreateButton(int x, int y, const std::string& t_spriteSheet, int t_imageId = 0)
{
	m3dCI::Button* newButton = new m3dCI::Button(x, y, t_spriteSheet, t_imageId);

	buttons.push_back(newButton);

	return newButton;
}

void ObjectManager::DeleteButton(m3dCI::Button* button)
{
	int index = -1;

	for (unsigned int i = 0; i < buttons.size(); i++)
		if (buttons[i] == button)
			index = i;

	if (index != -1)
	{
		delete(buttons[index]);
		buttons.erase(buttons.begin() + index);
	}
}

m3dCI::CodeEditor* ObjectManager::CreateCodeEditor(int x, int y, int w, int h, int borderWidth)
{
	m3dCI::CodeEditor* ce = new m3dCI::CodeEditor(x, y, w, h, borderWidth);

	codeEditors.push_back(ce);

	return ce;
}

void ObjectManager::DeleteCodeEditor(m3dCI::CodeEditor* ce)
{
	int index = -1;

	for (unsigned int i = 0; i < codeEditors.size(); i++)
		if (codeEditors[i] == ce)
			index = i;

	if (index != -1)
	{
		delete(codeEditors[index]);
		codeEditors.erase(codeEditors.begin() + index);
	}
}

m3dCI::CommandLister* ObjectManager::CreateCommandLister()
{
	m3dCI::CommandLister* cl = new m3dCI::CommandLister();

	commandListers.push_back(cl);

	return cl;
}

void ObjectManager::DeleteCommandLister(m3dCI::CommandLister* cl)
{
	int index = -1;

	for (unsigned int i = 0; i < commandListers.size(); i++)
		if (commandListers[i] == cl)
			index = i;

	if (index != -1)
	{
		delete(commandListers[index]);
		commandListers.erase(commandListers.begin() + index);
	}
}