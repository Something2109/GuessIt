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
	Score(){
		string name;
		range = 0;
		count = 0;
		point = 0;
	}
	Score(string _name, int _range, int _count, int _point) {
		name = _name;
		range = _range;
		count = _count;
		point = _point;
	}
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
	void swap(Score& b) {
		Score a(name, range, count, point) ;
		name = b.name;
		range = b.range;
		count = b.count;
		point = b.point;
		b = a;
	}
};

ostream& operator<< (ostream& out, Score a) {
	out << setw(17) << a.getName() << setw(10) << a.getRange() << setw(10) << a.getCount() << setw(10) << a.getPoint() << endl;
	return out;
}// define outstream of Score

ofstream& operator<< (ofstream& out, Score a) {
	out << a.getName() << ' ' << a.getRange() << ' ' << a.getCount() << ' ' << a.getPoint() << endl;
	return out;
}// define out file stream of Score

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
} // print score to screen

void printToFile(int range, int guessCount, int point) {
	ofstream file("score.txt", ofstream::app);
	if (file.is_open()) {
		string name;
		do {
			cout << "Your name (pls enter equal or less than 15 character): ";
			cin >> name;
			cout << endl;
		} while (name.length() > 15);
		Score save;
		save.setName(name);
		save.setRange(range + 1);
		save.setCount(guessCount);
		save.setPoint(point);
		file << save;
	}
	else {
		cout << "score file not found" << endl;
		cout << endl;
	}
} // print in score.txt file

void rankingScoreList(vector <Score>& scoreList);

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
	rankingScoreList(scoreList);
	return scoreList;
} // get the scores from file

void rankingScoreList(vector <Score> &scoreList) {
	for (int i = 0; i < scoreList.size() - 1; i++) {
		for (int j = i + 1; j < scoreList.size() - 1; j++) {
			if (scoreList[j].getRange() > scoreList[i].getRange()) {
				scoreList[j].swap(scoreList[i]);
			}
			else {
				if (scoreList[j].getCount() < scoreList[i].getCount() && scoreList[j].getRange() == scoreList[i].getRange()) {
					scoreList[j].swap(scoreList[i]);
				}
			}
		}
	}
} // sort score list
#endif
