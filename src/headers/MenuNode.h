#pragma once
#include <vector>

class Menu;

struct MenuNode {
	int id;
	MenuNode* parent;
	Menu* data;
	std::vector<MenuNode*> subNodes;
};	
