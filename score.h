#ifndef _score_h
#define _score_h
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class Score {
	string name;
	int range = 0;
	int count = 0;
	int point = 0;
public:
	void setName(string str) {
		name = str;
	}
	string getName() {
		return name;
	}
	void setRange(int n) {
		range = n;
	}
	int getRange() {
		return range;
	}
	void setCount(int n) {
		count = n;
	}
	int getCount() {
		return count;
	}
	void setPoint(int n) {
		point = n;
	}
	int getPoint() {
		return point;
	}
};

ostream& operator<< (ostream& out, Score a) {
	out << a.getName() << setw(10) << a.getRange() << setw(10) << a.getCount() << setw(10) << a.getPoint() << endl;
	return out;
}

ofstream& operator<< (ofstream& out, Score a) {
	out << a.getName() << ' ' << a.getRange() << ' ' << a.getCount() << ' ' << a.getPoint() << endl;
	return out;
}

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

void printToFile(int range, int guessCount, int point) {
	string name;
	ofstream file("score.txt", ofstream::app);
	cout << "Your name: ";
	cin >> name;
	cout << endl;
	Score save;
	save.setName(name);
	save.setRange(range);
	save.setCount(guessCount);
	save.setPoint(point);
	if (file.is_open()) {
		file << save;
	}
	else {
		cout << "score file not found" << endl;
		cout << endl;
	}
}

vector <Score> getScore() {
	ifstream file("score.txt");
	vector <Score> scoreList;
	while (!file.eof()) {
		string list;
		getline(file, list);
		Score save;
		string name;
		int range, count, point;
		stringstream ss(list);
		ss >> name >> range >> count >> point;
		save.setName(name);
		save.setRange(range);
		save.setCount(count);
		save.setPoint(point);
		scoreList.push_back(save);
	}
	return scoreList;
}
#endif
