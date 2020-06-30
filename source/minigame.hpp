#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <m3dia.hpp>
#include "scene.hpp"

#define THREAD_HALT     1
#define THREAD_RUNNING  0
#define THREAD_CLOSE    -1

class Minigame : public Scene
{
	private:
        m3d::Thread* m_sandboxThread;
        m3d::Mutex  m_mutex_execution, m_mutex_sandbox, m_mutex_threadState;
        int m_sandboxThreadState;
        std::string* m_luaChunk;

	protected:
		static bool winCond;
		
        void sandboxRuntime(m3d::Parameter param)
        {
            LuaSandbox* sandbox = new LuaSandbox();
            int* state = param.get<int*>();
            
            while(true)
            {
                //  Lock access to Thread State
                m_mutex_threadState.lock();
                if(*state == THREAD_CLOSE)
                {   //  close Thread
                    break;
                }else if(*state == THREAD_HALT)
                {   
                    m_mutex_threadState.unlock();
                    continue;
                }                
                m_mutex_threadState.unlock();

                // lock sandbox
                m3d::Lock lock(m_mutex_sandbox);

                sandbox->executeString(*m_luaChunk);

                m_mutex_execution.unlock();
            }
            m_mutex_threadState.unlock();
        }

        void executeInSandbox(std::string chunk)
        {
            //  Wait for any sandbox executions to complete
            m_mutex_execution.lock();
            
            if(m_luaChunk == nullptr)
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

        void setThreadState(int state)
        {
            //  Wait for thread state access
            m3d::Lock lock(m_mutex_threadState);
            m_sandboxThreadState = state;
            
        }

	public:
		//virtual void initialize() = 0;
		//virtual void update() = 0;
		virtual bool checkWinCond() = 0;

		void toggleWinCond()
		{
			winCond = !winCond; 
		}

        Minigame()
        {

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
		virtual void initialize()
        {
            m_sandboxThread = new m3d::Thread( sandboxRuntime, &m_sandboxThreadState, true, false);
        }

		virtual void load()=0;
		virtual void unload()=0;
		virtual void update()=0;
		virtual void draw()=0;

		virtual void onEnter()=0;

		virtual void onExit()=0;

	
	

};





