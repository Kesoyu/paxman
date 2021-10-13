#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "pozycja.h"
#include <sstream>
using namespace std;
class PlikKordy {
protected:
	string NazwaPliku;
public:
	PlikKordy(string);
	void Odczyt(vector<Pozycja>&);
};
