#pragma once
#include "pozycja.h"
#include "mapa.h"
class Gracz {
public:
	Gracz(char,int,int);
	char wyglad;
	Pozycja pozycja;
	int x, y;
	virtual void Kierunek(int, int);
	virtual void Ruch(Map&, int&);
	void UstawAvatar(Map&);
};