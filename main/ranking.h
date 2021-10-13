#pragma once
#include <string>
using namespace std;

struct Ranking {
	Ranking() : Score(1), Nazwa("Brak") {}
	Ranking(int x, string y) : Score(x), Nazwa(y) {}
	int Score;
	string Nazwa;
	void Dane(string, int);
};