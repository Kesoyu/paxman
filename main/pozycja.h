#pragma once
struct Pozycja {
	Pozycja() : x(0), y(0){}
	Pozycja(int x, int y): x(x), y(y){}
	int x, y;
	void Nowapozycja(int, int);
	void Getter(int&, int&);
};