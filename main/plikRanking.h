#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "ranking.h"
#include <sstream>
using namespace std;
class Plik{
private:
	string NazwaPliku;
public:
	Plik(string);
	void Zapis(const Ranking);
	void Odczyt(vector<Ranking>&);
	void View(const vector<Ranking>);
};
