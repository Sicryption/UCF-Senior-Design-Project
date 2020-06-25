#include "../minigame.hpp"
#include "../gameManager.hpp"

class MazeMinigame : public minigame
{
  private:
    MazeScene *mazeScene;
    m3d::Texture *texture;
		m3d::Rectangle *bwallpaper;
    m3d::Color *colorRec;
		m3d::Color *colorText;
    //name = "maze"

  public:
    MazeMinigame()
    {

    }
    void initialize()
    {
      mazeScene = new MazeScene();
      mazeScene->initialize();
      colorRec = new m3d::Color(150,150,150);
      colorText = new m3d::Color(0,0,0);
      bwallpaper = new m3d::Rectangle(0,0,400,240,*colorRec);
      prompt = new m3d::Text("Congratulations",*colorText);
    }
		void update()
    {
      mazeScene->update();
    }
		bool checkWinState()
    {
      if()
    }
		void loadSetting()
    {
    }
		void loadWinScreen()
    {

    }
		void loadLoseScreen()
    {
      //not at end of maze
    }
		void requestUserInput()
    {

    }
		void closeGame()
    {

    }
};
