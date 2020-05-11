#include <citro2d.h>
#include <m3dia.hpp>
#include "ObjectManager.hpp"
#include "m3diaLibCI/button.hpp" 
#include "m3diaLibCI/console.hpp"
#include "util.hpp"

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
	
	util = Util::getInstance(nullptr, nullptr);
}

//The function which is called on every game frame.
void ObjectManager::OnUpdate()
{
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
		
		int touchx = m3d::touch::getXPosition();
		int touchy = m3d::touch::getYPosition();

		if(arr[i]->getBoundingBox().intersects(m3d::BoundingBox(touchx, touchy, 1, 1)))
		{
			//Call OnClick function once it has been touched and the function isn't null.
			if(arr[i]->OnClick != nullptr)
				(arr[i]->OnClick)(arr[i]);
		}
	}
}

//Creates a Button and loads the object into the ObjectManager array.
m3dCI::Button* ObjectManager::CreateButton(int x, int y, int w, int h, m3d::Color color, void (*function)(m3dCI::Button*))
{
	m3dCI::Button* newButton = new m3dCI::Button(x, y, w, h, color, function);
	
	arr.push_back(newButton);
	
	return newButton;
}