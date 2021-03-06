#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika() {
    uzytkownikMenedzer.logowanieUzytkownika();
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {
        adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }
}

void KsiazkaAdresowa::wylogowanieUzytkownika() {
    uzytkownikMenedzer.wylogowanieUzytkownika();
    delete adresatMenedzer;
    adresatMenedzer = NULL;
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika() {

    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {
        uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
    } else {
        cout << "Aby zmienic haslo uzytkownika nalezy najpierw sie zalogowac\n.";
        Sleep(1500);
    }
}

void KsiazkaAdresowa::dodajAdresata() {
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {
        adresatMenedzer->dodajAdresata();
    } else {
        cout << "Aby dodac adresata nalezy najpierw sie zalogowac\n.";
        Sleep(1500);
    }
}


void KsiazkaAdresowa::wypiszWszystkichAdresatow() {
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {
        adresatMenedzer->wypiszWszystkichAdresatow();
    } else {
        cout << "Aby wypisac adresatow nalezy najpierw sie zalogowac\n.";
        Sleep(1500);
    }

}

int KsiazkaAdresowa::pobierzIdZalogowanegoUzytkownika() {
    return uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wyszukajPoImieniu() {
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {
        adresatMenedzer->wyszukajPoImieniu();
    } else {
        cout << "Aby wyszukac adresatow nalezy najpierw sie zalogowac\n.";
        Sleep(1500);
    }
}

void KsiazkaAdresowa::wyszukajPoNazwisku() {
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {
        adresatMenedzer->wyszukajPoNazwisku();
    } else {
        cout << "Aby wyszukac adresatow nalezy najpierw sie zalogowac\n.";
        Sleep(1500);
    }
}

void KsiazkaAdresowa::usunAdresata() {
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {
        adresatMenedzer->usunAdresata();
    } else {
        cout << "Aby usunac adresatow nalezy najpierw sie zalogowac\n.";
        Sleep(1500);
    }
}

void KsiazkaAdresowa::edytujAdresata() {
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {
        adresatMenedzer->edytujAdresata();
    } else {
        cout << "Aby edytowac adresatow nalezy najpierw sie zalogowac\n.";
        Sleep(1500);
    }
}
char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego() {
    char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}
char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika() {
    char wybor;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}
