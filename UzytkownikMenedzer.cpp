#include "UzytkownikMenedzer.h"

void UzytkownikMenedzer::rejestracjaUzytkownika() {
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);

    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << "\nKonto zalozono pomyslnie!";
    Sleep(1000);
    cin.ignore();
}

Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika() {
    Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    string login;
    do {
        cout << "\nPodaj login: ";
        cin >> login;
        uzytkownik.ustawLogin(login);
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    string haslo;
    cout << "Podaj haslo: ";
    cin >> haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}

int UzytkownikMenedzer::pobierzIdNowegoUzytkownika() {
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId()+ 1;
}

bool UzytkownikMenedzer::czyIstniejeLogin(string login) {

    for (long long unsigned int i = 0; i < uzytkownicy.size(); i++) {

        if(uzytkownicy[i].pobierzLogin() == login) {
            cout << "\nIstnieje uzytkownik o takim loginie.\n";
            return true;
        }
    }
    return false;
}

void UzytkownikMenedzer::wypiszWszystkichUzytkownikow() {
    for (long long unsigned int i = 0; i < uzytkownicy.size(); i++) {

        cout << uzytkownicy[i].pobierzId() << endl;
        cout << uzytkownicy[i].pobierzLogin() << endl;
        cout << uzytkownicy[i].pobierzHaslo() << endl;
    }

}

int UzytkownikMenedzer::logowanieUzytkownika() {
    string login = "", haslo = "";

    cout << "\nPodaj login: ";
    login = MetodyPomocnicze::wczytajLinie();

    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end()) {
        if (itr -> pobierzLogin() == login) {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--) {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = MetodyPomocnicze::wczytajLinie();

                if (itr -> pobierzHaslo() == haslo) {
                    cout << endl << "Zalogowales sie! Przechodze do Menu Uzytkownika.";
                    Sleep(1500);
                    idZalogowanegoUzytkownika = itr -> pobierzId();
                    return idZalogowanegoUzytkownika;

                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            idZalogowanegoUzytkownika = 0;
            return idZalogowanegoUzytkownika;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    idZalogowanegoUzytkownika = 0;
    return idZalogowanegoUzytkownika;
}

void UzytkownikMenedzer::wylogowanieUzytkownika() {
    idZalogowanegoUzytkownika = 0;
}

void UzytkownikMenedzer::zmianaHaslaZalogowanegoUzytkownika() {
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    noweHaslo = MetodyPomocnicze::wczytajLinie();

    for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++) {
        if (itr -> pobierzId() == idZalogowanegoUzytkownika) {
            itr -> ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}

int UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika() {
    return idZalogowanegoUzytkownika;
}

void UzytkownikMenedzer::ustawIdZalogowanegoUzytkownika(int noweId) {
    idZalogowanegoUzytkownika = noweId;
}

bool UzytkownikMenedzer::czyUzytkownikJestZalogowany(){
    if(idZalogowanegoUzytkownika > 0){
        return true;
    }else{
        return false;
    }
}
