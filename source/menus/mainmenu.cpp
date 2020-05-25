#include "mainmenu.hpp"

MainMenu::MainMenu(m3d::Screen* screen) :
	Menu(screen)
{
	StartupText = new m3dCI::Text("Press Start and Select to Exit\nPress L and R to open/close Console.");
	StartupText->setFontSize(0.5);
	StartupText->setFontWeight(0.5);

}

void MainMenu::OnUpdate()
{
	if(!util->IsConsoleDrawn())
	{
		scr->drawTop(*StartupText, RenderContext::Mode::Flat);
	}
}

void MainMenu::Destroy()
{
	
}

MainMenu::~MainMenu()
{
	delete(StartupText);
}