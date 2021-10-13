#include "gracz.h"
Gracz::Gracz(char znak,int xx ,int yy) {
	wyglad = znak;
	pozycja.Nowapozycja(xx, yy);
	x = 0;
	y = 0;
}
void Gracz::Kierunek(int xx, int yy) {
	x = xx;
	y = yy;
}

void Gracz::UstawAvatar(Map& mapa) {
	mapa.Ustaw(pozycja.x, pozycja.y, wyglad);
}

void Gracz::Ruch(Map& mapa, int& gra) {
	int a, b;
	a = pozycja.x;
	b = pozycja.y;
	mapa.MoveP(a, b, wyglad, x, y, gra);
	pozycja.Nowapozycja(a,b);
}