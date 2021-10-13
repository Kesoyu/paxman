#include "plikKordy.h"
#include <cstdlib>
PlikKordy::PlikKordy(string Nazwa) {
	NazwaPliku = Nazwa;
}

void PlikKordy::Odczyt(vector<Pozycja>& pozycje) {
	ifstream plik;
	vector<string>schowek;
	Pozycja pozycja;
	plik.open(NazwaPliku);
	const char delimeter = '\t';
	string obiekt;
	while (getline(plik, obiekt, delimeter)) {
		schowek.push_back(obiekt);
	}
	for (int i = 0; i < schowek.size(); i+=2) {
		pozycja.Nowapozycja(atoi(schowek[i].c_str()),atoi(schowek[i+1].c_str()));
		pozycje.push_back(pozycja);
	}
	plik.close();
}