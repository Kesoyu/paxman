#include "plikRanking.h"
#include <cstdlib>
#include <algorithm>

Plik::Plik(string Nazwa) {
	NazwaPliku = Nazwa;
}

void Plik::Zapis(Ranking osoba) {
	fstream plik;
	plik.open(NazwaPliku, ios::app);
	plik << osoba.Nazwa << "\t" << osoba.Score << "\t";
	plik.close();
}

void Plik::Odczyt(vector<Ranking>& osoby) {
	osoby.clear();
	ifstream plik;
	vector<string>schowek;
	Ranking osoba;
	plik.open(NazwaPliku);
	const char delimeter = '\t';
	string obiekt;
	while (getline(plik, obiekt, delimeter)) {
		schowek.push_back(obiekt);
	}
	for (int i = 0; i < schowek.size(); i += 2) {
		osoba.Dane(schowek[i], atoi(schowek[i + 1].c_str()));
		osoby.push_back(osoba);
	}
	plik.close();
}

void Plik::View(const vector<Ranking> osoby) {
	for (int i = 0; i < osoby.size();i++) {
		cout << "Nick: " << osoby[i].Nazwa << "\tPunkty: " << osoby[i].Score << endl;
	}
}
