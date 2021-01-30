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
	cout << setw(22) << "GUESS IT" << endl;
	cout << setw(23) << "0) New game" << endl;
	cout << setw(25) << "1) High score" << endl;
	cout << setw(24) << "2) Exit game" << endl;
	cout << endl;
	chooseMenu();
}

void scoreMenu() {
	ifstream file("score.txt");
	if (file.is_open()) {
		cout << setw(4) << "Rank" << setw(17) << "Name" << setw(10) << "Range" << setw(10) << "Count" << setw(10) << "Point" << endl;
		vector <Score> scoreList = getScore();
		for (int i = 0; i < scoreList.size() - 1; i++) {
			cout << setw(4) << i + 1 << scoreList[i];
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
	cout<< setw(20) << "Choose: ";
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