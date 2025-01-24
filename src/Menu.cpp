#include "headers/Menu.h"
#include "headers/Choice.h"

Menu::Menu(std::string title, std::string msg, std::vector<std::string> choices, int cols, int rows, int maxChoiceLen) : title(title), msg(msg), 
cols(cols), rows(rows), maxChoiceLen(maxChoiceLen){
	for(int i = 0; i < choices.size(); i++) this->choices.push_back(new Choice(choices[i], i));

	selectedChoice = this->choices[selectedIndex];
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
	int choiceIndex = 0;
	std::cout<<msg<<std::endl<<std::endl;
	
	for(int i = 0; i < cols; i++){
		std::vector<std::string> row;
		
		for(int k = 0; k < rows; k++){
			bool selected = (choiceIndex == selectedIndex);
			
			std::string choice = choices[choiceIndex]->getName();
			choice = formatChoice(choice, selected);
			row.push_back(choice);
			
			std::cout<<choice;
			choiceIndex++;
		}
		std::cout << '\n';
	}
}

void Menu::addSelectedIndex(int index){
	selectedIndex += index;
	
	if(selectedIndex < 0) selectedIndex = choices.size()-1;
	else if(selectedIndex > (choices.size()-1)) selectedIndex = 0;
	
	selectedChoice = choices[selectedIndex];
}

void Menu::addSubMenu(Menu* subMenu, int choiceIndex){
	choices[choiceIndex]->setLinkedMenu(subMenu);
}