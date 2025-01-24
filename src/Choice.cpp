#include "headers/Choice.h"
#include "headers/Menu.h"

Choice::Choice(std::string name, int menuIndex) : name(name), menuIndex(menuIndex) {
    linkedMenu = nullptr;
}
//Choice::Choice(std::string name, int menuIndex, Menu* linkedMenu) : name(name), menuIndex(menuIndex), linkedMenu(linkedMenu) {}

void Choice::setLinkedMenu(Menu* linkedMenu){
    this->linkedMenu = linkedMenu;
}