#include "headers/Menu.h"
#include "MenuLink.h"
#include "Page.h"
#include "windows.h"
Menu::Menu(std::string title, std::string msg, std::vector<std::string> choices, int cols, int rows, int maxChoiceLen) : title(title), msg(msg), choices(choices),
cols(cols), rows(rows), maxChoiceLen(maxChoiceLen){
	page = new Page((rows*cols), choices);
}

std::string Menu::formatChoice(std::string choice, bool selected){
	if(choice.length() > maxChoiceLen) choice.resize(maxChoiceLen);
	if(selected) {
		choice.insert(0,1,'[');
		choice.append(1, ']');
	}
	else {
		choice.insert(0,1,' ');
		choice.append(1, ' ');
	}
	int spaceAmnt = maxChoiceLen+2-choice.length();
	
	choice.append(spaceAmnt, ' ');
	
	return choice;
}

void Menu::print(){
	for(int i = 0; i < page->getPage().size(); i++){
		if(i%cols == 0 && i != 0) std::cout<<std::endl;
		
		
		bool selected = (i == selectedIndex);
		std::string choice = page->getPage()[i];

		choice = formatChoice(choice, selected);
		std::cout<<choice;
	}
	std::cout<<std::endl;
}
		
void Menu::addPageIndex(int index){
	int newIndex = page->index + index;
	if(newIndex < 0) newIndex = page->maxIndex;
	else if(newIndex > page->maxIndex) newIndex = 0;

	page->index = newIndex;
}

void Menu::addSelectedIndex(int index){
	selectedIndex += index;
	
	if(selectedIndex < 0) selectedIndex = page->getPage().size()-1;
	else if(selectedIndex > (page->getPage().size()-1)) selectedIndex = 0;
	
	selectedChoice = choices[selectedIndex];
}

void Menu::turnPage(int pageIndex){
	int index = page->index+1;
	if(index < 0) index = page->maxIndex;
	else if(index > page->maxIndex) index = 0;

	page->index = index;
}

void Menu::addSubMenu(Menu* subMenu, int choiceIndex){
	subMenu->parent = this;
	this->children.push_back(this);
	this->menuLinks.push_back(new MenuLink{choiceIndex, subMenu});
}

void Menu::addSubMenu(std::vector<Menu*> subMenus){
	for(int i = 0; i < subMenus.size(); i++) addSubMenu(subMenus[i], i);
}

Menu* Menu::getSubMenu(){
	if(selectedIndex > menuLinks.size()) return nullptr;
	return menuLinks[selectedIndex]->menu;
}

Menu* Menu::getSubMenu(int choiceIndex){
	if(choiceIndex > menuLinks.size()) return nullptr;
	return menuLinks[choiceIndex]->menu;
}
