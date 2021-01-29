#ifndef _menu_h
#define _menu_h
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include "score.h"
using namespace std;

void chooseMenu();
vector <Score> getScore(ifstream file);

void menu() {
	cout << setw(10) << "GUESS IT" << endl;
	cout << "0) New game" << endl;
	cout << "1) High score" << endl;
	cout << "2) Exit game" << endl;
	cout << endl;
	chooseMenu();
}

void scoreMenu() {
	cout << "Name" << setw(20) << "Range" << setw(10) << "Count" << setw(10) << "Point" << endl;
	ifstream file("score.txt");
	if (file.is_open()) {
		vector <Score> scoreList = getScore();
		for (int i = 0; i < scoreList.size() - 1; i++) {
			cout << scoreList[i];
		}
		cout << endl;
	}
	else {
		cout << "score file not found" << endl;
		cout << endl;
	}
	menu();
}

void chooseMenu() {
	cout << "Choose: ";
	string choose;
	cin >> choose;
	cout << endl;
	switch (choose[0]) {
	case '0': {
		playGame();
		break;
	}
	case '1': {
		scoreMenu();
		break;
	}
	case '2': {
		break;
	}
	default: {
		chooseMenu();
	}
	}
}

#endif