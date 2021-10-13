#pragma once
#include <iostream>
#include "pozycja.h"
using namespace std;

class Map {
public:
	Map() : punkty(1) {};
	~Map();
	int punkty;
	char map[26][26] = {
	"#########################",
	"#***********#***********#",
	"#*####*####*#*####*####*#",
	"#*####*####*#*####*####*#",
	"#***********************#",
	"#*####*#*#######*#*####*#",
	"#******#*#######*#******#",
	"######*#****#****#*######",
	"&&&&&#*####*#*####*#&&&&&",
	"&&&&&#*#*********#*#&&&&&",
	"&&&&&#*#*#######*#*#&&&&&",
	"######*#*#66666#*#*######",
	"&&&&&&***#66666#***&&&&&&",
	"######*#*#66666#*#*######",
	"&&&&&#*#*#######*#*#&&&&&",
	"&&&&&#*#*********#*#&&&&&",
	"&&&&&#*#*#######*#*#&&&&&",
	"######*#*#######*#*######",
	"#***********#***********#",
	"#*####*####*#*####*####*#",
	"#****#*************#****#",
	"####*#*#*#######*#*#*####",
	"#******#****#****#******#",
	"#*#########*#*#########*#",
	"#***********************#",
	"#########################",
	};
	void MoveE(int&, int&, const char, int, int, int&, int&, int&);
	void MoveP(int&, int&, const char, int, int, int&);
	void Ustaw(int, int, const char);
	void WyswietlMape();
	int Score();
};