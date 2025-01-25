#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <conio.h>
#include "headers/Menu.h"
#include "headers/Page.h"

using namespace std;

vector<string> name_list_1 = {"Alice", "Jamal", "Sophia", "Maria", "Hiroshi", "Liam", "Mei", "David", "Ayesha", "Ivan", "Grace", "Luis", "Yara", "John", "Mia", "Ahmed", "Emma", "Carlos", "Sarah", "Nathan", "Zoe", "Theo", "Priya", "Olivia", "Ethan", "Ling", "Samuel", "Leila", "Chloe", "Xavier", "Rosa", "Mark", "Ava", "Noor", "Leo", "Isabel", "Jalen", "Daniel", "Maya", "Kenji", "Ananya", "Benjamin", "Priya", "Joshua", "Keiko", "Luca", "Rachel", "Amira", "Eli", "Zoe"};
vector<string> name_list_2 = {"Jackson", "Yasmin", "Jasmine", "Liam", "Rina", "Carlos", "Caleb", "Olivia", "Santiago", "Zainab", "Ryan", "Amina", "Hector", "Gianna", "Siti", "Elijah", "Harper", "Ethan", "Aria", "Nico", "Isabella", "Gabriela", "Olivia", "Luna", "Dakota", "Kai", "Elena", "Mia", "Jonah", "Daniel", "Aidan", "Kai", "Jordan", "Stella", "Liam", "Haruto", "Sofia", "Kian", "Freya", "Emma", "Michael", "Olivia", "Matthew", "Aliyah", "Jack", "Stella", "Henry", "Mila", "Grace", "Amara", "Mason", "Lily", "Adam", "Maya", "Arjun", "Emily", "Xander", "Harper", "Vanessa", "Daniel", "Noor", "Lucas"};

vector<vector<string>> getNames(vector<string> names){
	vector<vector<string>> sorted_names;
	vector<string> a_thru_g;
	vector<string> h_thru_m;
	vector<string> n_thru_s;
	vector<string> t_thru_z; 

	sort(names.begin(), names.end());

	for(string name : names){
		int ascii_val = std::toupper(name[0]);

		if(ascii_val >= 65 && ascii_val <= 71) a_thru_g.push_back(name);
		else if(ascii_val >= 72 && ascii_val <= 77) h_thru_m.push_back(name);
		else if(ascii_val >= 78 && ascii_val <= 83) n_thru_s.push_back(name);
		else if(ascii_val >= 84 && ascii_val <= 90) t_thru_z.push_back(name);

	}

	sorted_names.insert(sorted_names.end(), {a_thru_g, h_thru_m, n_thru_s, t_thru_z});
	return sorted_names;
}

Menu* currentMenu = nullptr;
 
int main(int argc, char *argv[]){	
	vector<string> name_list = name_list_1;
	name_list.insert(name_list.end(), name_list_2.begin(), name_list_2.end());
	vector<vector<string>> sorted_names = getNames(name_list); 

	int size = 4;

	Menu* menu = new Menu(
		"MAIN", 
		"NAMES", 
		vector<string> {"A-G", "H-M", "N-S", "T-Z"}, 
		2, 
		2, 
		4
	);

	Menu* a_thru_g = new Menu(
		"A_THRU_G",
		"",
		sorted_names[0],
		size,
		size,
		8
	);
	
	Menu* h_thru_m = new Menu(
		"H_THRU_M",
		"",
		sorted_names[1],
		size,
		size,
		8
	);

	Menu* n_thru_s = new Menu(
		"N_THRU_S",
		"",
		sorted_names[2],
		size,
		size,
		8
	);

	Menu* t_thru_z = new Menu(
		"T_THRU_Z",
		"",
		sorted_names[3],
		size,
		size,
		8
	);

	currentMenu = menu;
	menu->addSubMenu(vector<Menu*>{a_thru_g, h_thru_m, n_thru_s, t_thru_z});

	while(true){
		system("cls");
		currentMenu->print();
		char input = getch();
		
		if(input == 'd') currentMenu->addSelectedIndex(1);
		else if(input=='a') currentMenu->addSelectedIndex(-1);
		else if(input == 'f') currentMenu->turnPage(1);
		else if(input == 'q' && currentMenu->getParent() != nullptr) currentMenu = currentMenu->getParent();
		else if(input == '\r' || input == '\n'){
			Menu* subMenu = currentMenu->getSubMenu();
			if(subMenu != nullptr) currentMenu = subMenu;
		}
	}
}