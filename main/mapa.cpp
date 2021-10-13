#include "mapa.h"

Map::~Map() {

}

void Map::Ustaw(int a, int b, char wyglad) {
	map[a][b] = wyglad;
}

void Map::MoveP(int& a, int& b,const char wyglad,int x,int y, int& gra) {
	x += a;
	y += b;
	if (map[x][y] == ' ') {
		map[x][y] = wyglad;
		map[a][b] = ' ';
		a = x;
		b = y;
	}
	else if (map[x][y] == '*') {
		map[x][y] = wyglad;
		map[a][b] = ' ';
		a = x;
		b = y;
		punkty++;
	}
	else if (map[x][y] == '#' || map[x][y] == '&' || map[x][y] == wyglad) {
		map[a][b] = wyglad;
	}
	else {
		gra = 0;
	}
}

void Map::MoveE(int& a, int& b, const char wyglad, int x, int y, int& numer, int& i, int& gra) {
	x += a;
	y += b;
	if (map[x][y] == ' ') {
		map[x][y] = wyglad;
		map[a][b] = ' ';
		a = x;
		b = y;
	}
	else if (map[x][y] == '*') {
		map[x][y] = wyglad;
		map[a][b] = '*';
		a = x;
		b = y;
	}
	else if (map[x][y] == '#' || map[x][y] == '&' || map[x][y] == '$') {
		map[a][b] = wyglad;
		numer+=1;
	}
	else {
		gra = 0;
	}
	if (numer == 4) {
		numer = i;
		i--;
	}
	if (i == -1) {
		i = 3;
	}
}

void Map::WyswietlMape() {
	for (int i = 0; i < 26; i++) {
		cout << map[i] << endl;
	}
}

int Map::Score() {
	return punkty;
}
