#include "pozycja.h"
void Pozycja::Nowapozycja(int xx, int yy) {
	x = xx;
	y = yy;
}
void Pozycja::Getter(int& xx,int& yy) {
	xx = x;
	yy = y;
}