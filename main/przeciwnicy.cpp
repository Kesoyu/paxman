#include "przeciwnicy.h"

Przeciwncy::Przeciwncy(char znak, int xx, int yy, int nn) {
	wyglad = znak;
	pozycja.Nowapozycja(xx, yy);
	x = 0;
	y = 0;
	i = 0;
	numer = nn;
	RodzajKierunku = 0;
}

void Przeciwncy::Ruch(Map& mapa, vector<Pozycja> kierunki,int& gra)
{
	int a, b;
	a = pozycja.x;
	b = pozycja.y;
	mapa.MoveE(a, b, wyglad, x, y, numer, i, gra);
	pozycja.Nowapozycja(a, b);
	Kierunek(kierunki);
}

void Przeciwncy::Kierunek(vector<Pozycja> kierunki) {
	x = kierunki[numer].x;
	y = kierunki[numer].y;
}

void Przeciwncy::UstawAvatar(Map& mapa) {
	mapa.Ustaw(pozycja.x, pozycja.y, wyglad);
}
