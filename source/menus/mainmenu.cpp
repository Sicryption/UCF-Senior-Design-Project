#include "mainmenu.hpp"

MainMenu::MainMenu(m3d::Screen* screen) :
	Menu(screen)
{
	exitText = new m3dCI::Text("Press Start and Select to Exit\nPress L and R to open/close Console.");
	exitText->setFontSize(0.5);
	exitText->setFontWeight(0.5);
}

void MainMenu::OnUpdate()
{
	if(!util->IsConsoleDrawn())
		scr->drawTop(*exitText, RenderContext::Mode::Flat);
}

void MainMenu::Destroy()
{
	
}

MainMenu::~MainMenu()
{
	delete(exitText);
}