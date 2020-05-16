#include "ObjectManager.hpp"

using namespace m3d;

//Set default instance of this class to 0, to notify that the instance hasn't been created
ObjectManager *ObjectManager::instance = 0;

/*
	This Class is a singleton. 
	Meaning, only one instance of this class may ever exist.
	This allows for all classes to access this object through the use of this instance value.
	An initial instantiation must occur with proper vaules passed into getInstance
	All further attempts to accesss this class can use dummy values for all parameters of getInstance
*/
ObjectManager* ObjectManager::getInstance(Screen* screen)
{
	if (instance == 0)
	{
		instance = new ObjectManager(screen);
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
	
	util = Util::getInstance(nullptr, nullptr);
}

//The function which is called on every game frame.
void ObjectManager::OnUpdate()
{
	int touchedThisFrame = hidKeysDown() & KEY_TOUCH,
		touchReleasedThisFrame = hidKeysUp() & KEY_TOUCH,
		touchx = m3d::touch::getXPosition(),
		touchy = m3d::touch::getYPosition();
	
	for(uint i = 0; i < arr.size(); i++)
	{
		//Draw all buttons
		/*
			TODO: Implement ability to change screen based off button configuration
		*/
		scr->drawBottom(*arr[i], RenderContext::Mode::Flat);
		
		
		//Check for touch event on Button
		/*
			TODO: This is called once per game frame, resulting in the OnClick function being called multiple times.
			Should only be called once and OnTouchRelease rather than OnTouch
		*/

		
		if(touchedThisFrame)
		{
			if(arr[i]->OnTouch != nullptr && arr[i]->PointIntersects(touchx, touchy))
				(arr[i]->OnTouch)(arr[i]);
		}
		else if(touchReleasedThisFrame)
		{
			if(arr[i]->OnRelease != nullptr && arr[i]->PointIntersects(lastFrameTouchX, lastFrameTouchY))
				(arr[i]->OnRelease)(arr[i]);
		}
		else
		{
			if(arr[i]->OnHeld != nullptr && arr[i]->PointIntersects(touchx, touchy))
				(arr[i]->OnHeld)(arr[i]);
		}
	}
	
	lastFrameTouchX = touchx;
	lastFrameTouchY = touchy;
}

//Rectangle button creation. Adds button to array of active buttons.
m3dCI::Button* ObjectManager::CreateButton(int x, int y, int w, int h, m3d::Color color)
{
	m3dCI::Button* newButton = new m3dCI::Button(x, y, w, h, color);
	
	arr.push_back(newButton);
	
	return newButton;
}

//Circular button creation. Adds button to array of active buttons.
m3dCI::Button* ObjectManager::CreateButton(int x, int y, int radius, m3d::Color color)
{
	m3dCI::Button* newButton = new m3dCI::Button(x, y, radius, color);
	
	arr.push_back(newButton);
	
	return newButton;
}