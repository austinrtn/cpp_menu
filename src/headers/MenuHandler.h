#pragma once
#include <vector>


struct MenuNode;
class Menu;

class MenuHandler{
	private:
	std::vector<MenuNode*> nodes;
	Menu* currentMenu;
	
	public:
	MenuHandler();
	
	void setCurrentMenu(Menu* menu);
	void addMenu(Menu* menu, Menu* parent);
	
	Menu* getCurrentMenu(){return currentMenu;}
	
};