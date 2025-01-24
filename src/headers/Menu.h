#pragma once
#include <iostream>
#include <string>
#include <vector>

class Choice;

class Menu{
private:
	std::string title;
	std::string msg;
	int selectedIndex = 0;
	Choice* selectedChoice;

	std::vector<Choice*> choices;
	
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
	//void setParent(Menu* parent);
	//void addChild(Menu* child);
	
	std::string getMsg(){return msg;}
	int getSelectedIndex(){return selectedIndex;}
	Choice* getSelectedChoice(){return selectedChoice;}

	Menu* getParent(){return parent;}
	
	void addSubMenu(Menu* subMenu, int choiceIndex);
};