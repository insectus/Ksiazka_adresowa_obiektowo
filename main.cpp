#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main() {
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt","Adresaci.txt");

    char wybor;
    while (true) {
        if(ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika()==0) {

            wybor = ksiazkaAdresowa.wybierzOpcjeZMenuGlownego();

            switch(wybor) {
            case '1':
                ksiazkaAdresowa.rejestracjaUzytkownika();
                break;
            case '2':
                ksiazkaAdresowa.logowanieUzytkownika();
                break;
            case '9':
                exit(0);
            default:
                cout << "\nNie ma takiej opcji w menu.\n\n";
                system("pause");
                break;
            }
        } else {

            wybor = ksiazkaAdresowa.wybierzOpcjeZMenuUzytkownika();

            switch(wybor) {
            case '1':
                ksiazkaAdresowa.dodajAdresata();
                break;
            case '2':
                ksiazkaAdresowa.wyszukajPoImieniu();
                break;
            case '3':
                ksiazkaAdresowa.wyszukajPoNazwisku();
                break;
            case '4':
                ksiazkaAdresowa.wypiszWszystkichAdresatow();
                break;
            case '5':
                ksiazkaAdresowa.usunAdresata();
                break;
            case '6':
                ksiazkaAdresowa.edytujAdresata();
                break;
            case '7':
                ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                ksiazkaAdresowa.wylogowanieUzytkownika();
                break;
            }
        }
    }
    return 0;
}
