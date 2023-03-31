#include <iostream>
#include <fstream> 
#include <stdio.h>
#include <windows.h>
#include <string>

using namespace std;

struct album
{
	string tytul{}, wykonawca{};
	int rok_wyd{}, licz_utw{};
	double czas_nagr{};
}; 

void wprow_dane(album* wdane)
{
	cin.ignore(1000, '\n');
	cout << "Wprowadz tytul: ";
	getline(cin,wdane->tytul);
	cout << "Wprowadz wykonawce: ";
	getline(cin,wdane->wykonawca);
	cout << "Wprowadz rok wydania: ";
	cin >> wdane->rok_wyd;
	cout << "Wprowadz liczbe utworow: ";
	cin >> wdane->licz_utw;
	cout << "Wprowadz czas nagrania: ";
	cin >> wdane->czas_nagr;
}

void zapisz_wpliku(album pdane)
{
	fstream plik;
	plik.open("albumy.txt", ios::out | ios::app);
	plik << "Tytul i wykonawca: "<< pdane.tytul << " - " << pdane.wykonawca << endl;
	plik << "Rok wydania: " << pdane.rok_wyd << endl;
	plik << "Liczba utworow: " << pdane.licz_utw << endl;
	plik << "Czas trwania: " << pdane.czas_nagr << endl<<endl;
	plik.close();
}

void wypisz_zpliku()
{
	fstream plik; 

	plik.open("albumy.txt", ios::in);
	string tekst;

	if (plik.good() == false) {
		cout << "Nie mozna otworzyc pliku! Zapisz informacje, aby utworzyc plik."; system("pause > null"); exit(0);
	}
	while (!plik.eof())
	{
		getline(plik, tekst); 
		cout << tekst << endl; 
	}

	plik.close(); 
}

int main()
{
	int opcja;
	album alb;

	while (true)
	{
		cout << "===========MENU===========" << endl;
		cout << "1) Wprowadz dane i zapisz." << endl;
		cout << "2) Wyswietl wszystkie wpisane albumy." << endl;
		cout << "3) Wyjdz z programu." << endl;
		cout << "Wybierz opcje i kliknij enter: " << " ";
		cin >> opcja;

		switch (opcja)
		{
		case 1:
		{
			cout << endl;
			wprow_dane(&alb);
			zapisz_wpliku(alb);
		}
		break;
		case 2: 
		{
			cout << endl;
			wypisz_zpliku();
		}
			break;
		case 3: exit(0);
		default: cout << "Nie ma takiej opcji w menu. Wybierz jedna z dostepnych opcji." << endl;
		}
		cout << endl<< "Aby wrocic do menu, kliknij dowolny przycisk."; system("pause > null");
		system("cls");
	}
	return 0;
}