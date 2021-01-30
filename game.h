#ifndef  _game_h_
#define _game_h_ 
#include <iostream>
#include <cmath>
#include "score.h"
using namespace std;

void menu();
void chooseRange(int& range, int& firstRangeNum);
int generateRandomNumber(int range, int firstRangeNum);
int getPlayerGuess(int range, int firstRangeNum, int& guessPoint, int& point);
void printAnswer(int secretNumber, int guess, int guessCount, int point);

void playGame() {
	int range, firstRangeNum;
	chooseRange(range, firstRangeNum);
	int secretNumber = generateRandomNumber(range, firstRangeNum);
	int guess;
	int guessCount = 0;
	int point = 10100;
	do {
		guess = getPlayerGuess(range, firstRangeNum, guessCount, point);
		printAnswer(secretNumber, guess, guessCount, point);
	} while (guess != secretNumber && guessCount < 101);
	printToFile(range, guessCount, point);
	menu();
}

void chooseRange(int& range, int& firstRangeNum) {
	int firstNum, lastNum;
	cout << "Choose a number range (contain at least 100 numbers): " << endl;
	cout << "First number: ";
	cin >> firstNum;
	cout << "Last number: ";
	cin >> lastNum;
	cout << endl;
	while (lastNum == firstNum || abs(lastNum - firstNum + 1) < 100) {
		if (lastNum == firstNum) {
			cout << "Don't choose 2 equal numbers: " << endl;
		}
		else {
			cout << "Your range is less than 100, choose again: " << endl;
		}
		cout << "First number: ";
		cin >> firstNum;
		cout << "Last number: ";
		cin >> lastNum;
		cout << endl;
	}
	range = abs(lastNum - firstNum);
	firstRangeNum = min(firstNum, lastNum);
}

int generateRandomNumber(int range, int firstRangeNum) {
	int secretNumber = rand() % range + firstRangeNum;
	return secretNumber;
}

int getPlayerGuess(int range, int firstRangeNum, int& guessCount, int& point) {
	int guess;
	cout << "Guess a number: ";
	cin >> guess;
	pointCount(guessCount, point);
	while (guess > (firstRangeNum + range) || guess < firstRangeNum) {
		if (guess > (firstRangeNum + range)) {
			cout << "Guess a number equal or less than " << (firstRangeNum + range) << " pls" << endl;
			printScore(guessCount, point);
			cout << endl;
			cout << "Guess a number: ";
			cin >> guess;
			pointCount(guessCount, point);
		}
		else {
			cout << "Guess a number equal or more than " << firstRangeNum << " pls" << endl;
			printScore(guessCount, point);
			cout << endl;
			cout << "Guess a number: ";
			cin >> guess;
			pointCount(guessCount, point);
		}
	}
	return guess;
}

void printAnswer(int secretNumber, int guess, int guessCount, int point) {
	if (secretNumber == guess) {
		cout << "Correct!" << endl;
	}
	else {
		if (guessCount == 101) {
			cout << "You lose!" << endl;
		}
		else {
			if (secretNumber > guess) {
				cout << "more than " << guess << " pls" << endl;
			}
			else {
				if (secretNumber < guess) {
					cout << "less than " << guess << " pls" << endl;
				}
			}
		}
	}
	printScore(guessCount, point);
	cout << endl;
}

#endif