#pragma once
#include "gracz.h"
#include <vector>

class Przeciwncy{
public:
	Przeciwncy(char, int, int, int);
	char wyglad;
	Pozycja pozycja;
	int x, y, i;
	int RodzajKierunku, numer;
	void Kierunek(vector<Pozycja>);
	void Ruch(Map&, vector<Pozycja>,int&);
	void UstawAvatar(Map&);
};