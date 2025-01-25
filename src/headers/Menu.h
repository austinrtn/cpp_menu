#pragma once
#include <iostream>
#include <string>
#include <vector>

struct Page;
struct MenuLink;

class Menu{
private:
	std::string title;
	std::string msg;
	int selectedIndex = 0;

	std::string selectedChoice;
	Page* page;

	std::vector<std::string> choices;
	std::vector<MenuLink*> menuLinks;

	int cols;
	int rows;
	int maxChoiceLen;
	
	Menu* parent = nullptr;
	std::vector<Menu*> children;
	
	std::string formatChoice(std::string choice, bool selected);
	
public:	
	Menu(std::string title, std::string msg, std::vector<std::string> choices, int cols, 
	int rows, int maxChoiceLen);
	
	void print();
	
	void addSelectedIndex(int index);
	void addPageIndex(int index);
	void addSubMenu(Menu* subMenu, int choiceIndex);
	void addSubMenu(std::vector<Menu*> subMenus);
	void turnPage(int pageIndex);

	std::string getMsg(){return msg;}
	int getSelectedIndex(){return selectedIndex;}
	std::string getSelectedChoice(){return selectedChoice;}
	Menu* getParent(){return parent;}
	Menu* getSubMenu();
	Menu* getSubMenu(int choiceIndex);
};