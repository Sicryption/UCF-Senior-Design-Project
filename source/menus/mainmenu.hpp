#include "menu.hpp"

class MainMenu : public Menu
{
	private:
		m3dCI::Text* exitText;
	public:
		MainMenu(m3d::Screen* screen);
		~MainMenu();
		
		void OnUpdate();
		
		void Destroy();
};