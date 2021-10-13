#include <iostream>
#include "gracz.h"
#include "plikKordy.h"
#include "plikRanking.h"
#include "przeciwnicy.h"
#include <conio.h>
#include <cstdlib>
#include <vector>
#include <Windows.h>

int main()
{
    vector<Ranking> RankingLista;
    Plik Lista("ranking.txt");
    int a=1;
    while (a == 1) {
        cout << "Zobacz ranking(wcisnij r)\tZagraj(wcisnij g)" << endl;
       switch (_getch())
       {
       case 'r':
           system("cls");
           Lista.Odczyt(RankingLista);
           Lista.View(RankingLista);
           cout << "Dalej(enter)" << endl;
           _getch();
           system("cls");
           a = 0;
           break;
       case 'g':
           cout << "Powodzenia" << endl;
           Sleep(1000);
           system("cls");
           a = 0;
           break;
       default:
           system("cls");
           a=1;
       }
    }
    int gra=1;
    vector<Pozycja> PozycjePotworow;
    PlikKordy plik("p1.txt");
    plik.Odczyt(PozycjePotworow);
    Przeciwncy p1('$', 9, 12, 0);
    Przeciwncy p2('$', 9, 12, 0);
    Przeciwncy p3('$', 9, 12, 2);
    Przeciwncy p4('$', 9, 12, 2);
    p1.Kierunek(PozycjePotworow);
    p2.Kierunek(PozycjePotworow);
    p3.Kierunek(PozycjePotworow);
    p4.Kierunek(PozycjePotworow);
    cout << PozycjePotworow[0].x << PozycjePotworow[0].y << PozycjePotworow[1].x << PozycjePotworow[1].y << PozycjePotworow[2].x << PozycjePotworow[2].y << PozycjePotworow[3].x << PozycjePotworow[3].y << endl;
    Map mapa;
    Gracz gracz('@',1,1);
    gracz.UstawAvatar(mapa);
    p1.UstawAvatar(mapa);
    mapa.WyswietlMape();
    bool gamerunning = true;
    while (gamerunning == true)
    {
        if (_kbhit())
        {
            switch (_getch())
            {
            case 'a':
                gracz.Kierunek(0, -1);
                break;
            case 'w':
                gracz.Kierunek(-1, 0);
                break;
            case 'd':
                gracz.Kierunek(0, 1);
                break;
            case 's':
                gracz.Kierunek(1, 0);
                break;
            default:
                break;
            }
        }
        gracz.Ruch(mapa, gra);
        p1.Ruch(mapa, PozycjePotworow, gra);
        p2.Ruch(mapa, PozycjePotworow, gra);
        p3.Ruch(mapa, PozycjePotworow, gra);
        p4.Ruch(mapa, PozycjePotworow, gra);
        Sleep(100);
        system("cls");
        mapa.WyswietlMape();
        if (mapa.Score() == 241) {
            Sleep(1000);
            system("cls");
            cout << "Wow wygrales(enter)" << endl;
            _getch();
            gra = 2;
        }
        if (gra == 0) {
            system("cls");
            cout << "Przegrales(enter)" << endl;
            _getch();
            gra = 2;
        }
        if (gra == 2) {
            system("cls");
            string nick;
            cout << "Prosze podac swoj nick" << endl;
            cin >> nick;
            system("cls");
            Ranking winner(mapa.Score(), nick);
            Lista.Zapis(winner);
            a = 1;
            while (a == 1) {
                cout << "Zobacz ranking(wcisnij r)\tWyjdz(wcisnij w)" << endl;
                switch (_getch())
                {
                case 'r':
                    system("cls");
                    Lista.Odczyt(RankingLista);
                    Lista.View(RankingLista);
                    cout << "Dalej(enter)" << endl;
                    _getch();
                    system("cls");
                    a = 0;
                    break;
                case 'w':
                    system("cls");
                    cout << "BAYO" << endl;
                    Sleep(1000);
                    system("cls");
                    a = 0;
                    break;
                default:
                    a = 1;
                }
            }
            exit(0);
        }
        cout << mapa.Score();
    }
}
