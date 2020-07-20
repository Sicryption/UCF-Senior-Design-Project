#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <memory>

#include "../gameObject.hpp"
#include "../sandbox.hpp"
#include "../util.hpp"
#include "../Menu/Menu.hpp"

/**
	@brief A Scene is responsible for displaying all visual elements and handling interactions.
**/
class Scene : public Updateable
{

protected:
    std::map<unsigned int, GameObject*> m_hashmap;
    unsigned int m_idCounter;
    std::string m_name;

	Menu* menu;
public:

	/**
		@brief Constructor for Scene.
		- Creates a blank Menu
		- Create a blank GameObject* list.
	**/
    Scene()
    {
        m_hashmap.empty();
        m_idCounter = 0;

		menu = new Menu();
    }
	
	/**
		@brief Deconstructor for Scene.
		- Destroy all GameObject*s added the to Scene
	**/
    virtual ~Scene()
    {
        auto it =  m_hashmap.cbegin();
        for(;it != m_hashmap.cend(); it++)
        {
            it->second->destroy();
        }

		delete(menu);
    }

	/**
		@brief Initialization of values of all MenuItems.
	**/
    virtual void initialize()=0;
	
	/**
		@brief Load Scene Data
	**/
    virtual void load()=0;
	
	/**
		@brief Unload Scene Data
	**/
    virtual void unload()=0;
	
	/**
		@brief Function responsible for determining Menu Clicks and what to do on each update cycle.
		Called each game frame.
	**/
    virtual void update()=0;
	
	/**
		@brief Function responsible for drawing the Scene
		Updates each game frame.
	**/
    virtual void draw()
    {
        for (auto objPair : m_hashmap)
        {
            if (objPair.second != nullptr)
            {
                objPair.second->draw(); 
            }
        }
        
    }

	/**
		@brief Function called when Scene is first created
	**/
    virtual void onEnter()=0;

	/**
		@brief Function called before a Scene is destroyed
	**/
    virtual void onExit()=0;

	/**
		@brief Returns the name of the Scene.
	**/
    std::string getSceneName()
    {
        return m_name;
    }

	/**
		@brief Function used to find a game object by it's hashmap ID
		@param t_id ID of the Object to find
	**/
    GameObject* findObject(int t_id)
    {
        return m_hashmap[t_id];
    }

	/**
		@brief Function used to add an object to the scene
		@param obj GameObject* to add to the scene
	**/
    unsigned int addObject(GameObject* obj)
    {
        m_hashmap[m_idCounter] = obj;
        return m_idCounter++;
    }

	/**
		@brief Function used to remove an object from the scene
		@param t_id ID of the object to be removed
	**/
    void removeObject(unsigned int t_id)
    {
        m_hashmap[t_id] = NULL;
    }
};
