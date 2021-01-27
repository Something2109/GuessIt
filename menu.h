#ifndef _menu_h
#define _menu_h
#include <iostream>
#include <iomanip>
using namespace std;

void menu();
void chooseMenu();

void menu() {
	cout << setw(10) << "GUESS IT" << endl;
	cout << "0) New game" << endl;
	cout << "1) High score" << endl;
	cout << "2) Exit game" << endl;
	cout << endl;
	chooseMenu();
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
	case '2': {
		break;
	}
	default: {
		chooseMenu();
	}
	}
}

#endif