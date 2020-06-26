#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <m3dia.hpp>
#include "scene.hpp"


class Minigame : public Scene
{
	
	private:
		static bool winCond;
		static Scene* m_currentScene;

	public:
		//virtual void initialize() = 0;
		//virtual void update() = 0;
		virtual bool checkWinCond() = 0;

		void toggleWinCond()
		{
			winCond = !winCond; 
		}

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

		virtual void loadScene() = 0;
		virtual void loadWinScr() = 0;
		virtual void loadLoseScr() = 0;
		virtual void requestUI() = 0;
		virtual void closeGame() = 0;
	//from scene
		virtual void initialize()=0;
		virtual void load()=0;
		virtual void unload()=0;
		virtual void update()=0;
		virtual void draw()=0;

		virtual void onEnter()=0;

		virtual void onExit()=0;

	
	

};





