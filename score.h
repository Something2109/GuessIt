#ifndef _score_h
#define _score_h
#include <iostream>
#include <iomanip>
using namespace std;

void pointCount(int& guessCount, int& point) {
	guessCount++;
	switch (guessCount) {
	case 1: case 2: {
		point -= 100;
		break;
	}
	default:{
		point = point - 2 * (100 - guessCount);
	}
	}
}

void printScore(int guessCount, int point) {
	cout << "Your try: " << guessCount << setw(20) << "Your score: " << point << endl;
}

#endif
