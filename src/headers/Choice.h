#pragma once
#include <string>
class Menu;

class Choice{
private:
	std::string name;
	int menuIndex;
	Menu* linkedMenu;

public:
    Choice(std::string name, int  menuIndex);
	//Choice(std::string name, int menuIndex, Menu* linkedMenu);
	
	void setLinkedMenu(Menu* linkedMenu);

	std::string getName(){return name;}
	Menu* getLinkedMenu(){return linkedMenu;}
};