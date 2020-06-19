#include "../gameManager.hpp"
#include "../sceneManager.hpp"
#include "../scene.hpp"
#include "../resources.h"

class MazeScene : public Scene
{
	private:
		m3d::Sprite *wallpaper;
		m3d::Texture *texture;
		//m3d::Rectangle *wallpaper;
		m3d::Rectangle *bwallpaper;
		m3d::Color *colorRec;
		m3d::Color *colorText;
		m3d::Text *prompt;
    TerminalObject *runner;
    int x;
		int y;
    bool walls[24][40] ={ { 1, 0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1},
            { 1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1},
            { 1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1},
            { 1, 0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  0,  1,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  0,  1},
            { 1, 0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  1},
            { 1, 0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  1},
            { 1, 0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  0,  1,  0,  0,  1},
            { 1, 0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  1},
            { 1, 1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  1},
            { 1, 0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  0,  1},
            { 1, 0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1},
            { 1, 0,  0,  1,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1},
            { 1, 0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1},
            { 1, 0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  1,  0,  0,  1,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  1},
            { 1, 0,  0,  1,  1,  1,  1,  1,  1,  1,  0,  0,  1,  0,  0,  1,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  1},
            { 1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  1,  0,  0,  1,  0,  0,  1,  0,  0,  1,  0,  0,  1,  1,  1,  1,  1,  1,  1,  0,  0,  1,  0,  0,  1},
            { 1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  1,  0,  0,  1,  0,  0,  1,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  1,  0,  0,  1},
            { 1, 0,  0,  1,  1,  1,  1,  1,  1,  1,  0,  0,  1,  0,  0,  1,  0,  0,  1,  0,  0,  1,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  1,  0,  0,  1},
            { 1, 0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  1,  0,  0,  1,  0,  0,  1,  1,  1,  1,  1,  1,  1,  0,  0,  1,  0,  0,  1,  0,  0,  1},
            { 1, 0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  1,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  1,  0,  0,  1,  0,  0,  1},
            { 1, 0,  0,  1,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  1,  0,  0,  1,  0,  0,  1},
            { 1, 0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  0,  0,  0,  0,  1,  0,  0,  1},
            { 1, 0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  0,  0,  0,  0,  1,  0,  0,  1},
            { 1, 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  0,  1}};

	public:
		MazeScene()
		{
			x = 1.0;
			y = 0.0;
		}
		void initialize(){
       texture = ResourceManager::loadTexture("gfx/Maze.png");
			 texture = ResourceManager::getTexture("gfx/Maze.png");
       runner = new TerminalObject();
       runner->initialize();
			 colorRec = new m3d::Color(150,150,150);
			 colorText = new m3d::Color(0,0,0);
			 bwallpaper = new m3d::Rectangle(0,0,320,240,*colorRec);
			 //wallpaper = new m3d::Rectangle(0,0,400,240,*colorRec);
			 prompt = new m3d::Text("Maze",*colorText);
			 prompt->setPosition(160,120);
			 wallpaper = new m3d::Sprite();
		   wallpaper->setTexture(*texture);
		   wallpaper->setCenter(0,0);
		   wallpaper->setScale(10,10);

		}
		void draw(){
			m3d::Screen * screen = GameManager::getScreen();

		    wallpaper->setPosition(0,0);
				screen->drawBottom(*bwallpaper);
				screen->drawBottom(*prompt);
        screen->drawTop(*wallpaper);
        runner->draw();

		}
    void load(){};
    void unload(){};
    void update(){

      if(m3d::buttons::buttonPressed(m3d::buttons::Right))
      {
          if(walls[y][x+1] == 0){
            x++;
            runner->update();
          }
      }
      if(m3d::buttons::buttonPressed(m3d::buttons::Left))
      {
        if(walls[y][x-1] == 0){
          x--;
          runner->update();
        }
      }
      if(m3d::buttons::buttonPressed(m3d::buttons::Up))
      {
        if(walls[y-1][x] == 0){
          if(y>0)
            y--;

          runner->update();
        }
      }
      if(m3d::buttons::buttonPressed(m3d::buttons::Down))
      {
        if(walls[y+1][x] == 0){
          if(y<24)
            y++;
          runner->update();
        }
      }/*
      if(m3d::buttons::buttonDown(m3d::buttons::Right))
      {
          if(walls[y][x+1] == 0){
            x += 1 * GameManager::getDeltaTime();
            runner->update();
          }
      }
      if(m3d::buttons::buttonDown(m3d::buttons::Left))
      {
        if(walls[y][x-1] == 0){
          x -= 1 * GameManager::getDeltaTime();
          runner->update();
        }
      }
      if(m3d::buttons::buttonDown(m3d::buttons::Up))
      {
        if(walls[y-1][x] == 0){
          y -= 1 * GameManager::getDeltaTime();
          runner->update();
        }
      }
      if(m3d::buttons::buttonDown(m3d::buttons::Down))
      {
        if(walls[y+1][x] == 0){
          y += 1 * GameManager::getDeltaTime();
          runner->update();
        }
      }*/
    };
    void onEnter(){};
    void onExit(){};
};
