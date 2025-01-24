#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <conio.h>
#include "headers/Menu.h"

//#include "MenuHandler.h"

using namespace std;

vector<vector<string>> getNames(vector<string> names){
	vector<vector<string>> sorted_names;
	vector<string> a_thru_g;
	vector<string> h_thru_m;
	vector<string> n_thru_s;
	vector<string> t_thru_z; 

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


int main(int argc, char *argv[]){	
	Menu* menu = new Menu("MAIN", 
	"MSG", 
	vector<string> {"A-G", ""}, 
	2, 
	3, 
	6);

	vector<vector<string>> sorted_names = getNames({"John", "Bob", "Jamal", "Tod", "Michael", "Austin", "Bojack", "Kayla", "Kyle", "Jerry", "Sarah", "Terrel", "Carl", "Henery", "Allisa", "Tony"}); 
	for(vector<string> list : sorted_names){
		for(string name : list) cout << name << endl;
		cout << "______________" << endl;
	}

	while(false){
		system("cls");
		menu->print();
		char input = getch();
		
		if(input == 'd') menu->addSelectedIndex(1);
		else if(input=='a') menu->addSelectedIndex(-1);
	}

	getch();
}