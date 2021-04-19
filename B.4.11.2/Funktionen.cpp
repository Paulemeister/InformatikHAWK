#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include "getch.cpp"
#include "kafffeautomat.h"
using namespace std;

bool UI(bool *pbkaffee, bool *pbmilch, bool *pbzucker, bool *pbespresso, bool *pbservice, daten kaffee)
{
    char input;
    *pbkaffee = *pbmilch = *pbzucker = *pbespresso = *pbservice = 0;

    system("clear");
    PRINTSTRING("DEBUG MODE");
    cout << "Herzlich Willkommen beim Kaffee-Automaten!\n\nPreis pro Tasse :\n";
    cout << "Kaffee oder Espresso: 1 Euro\n";
    cout << "Milch oder Zucker 0.1 Euro\n\n";
    cout << "Bitte wählen sie aus:\n";
    cout << "(k) Kaffee \n(e) Espresso\n(s) Service-Mode\n";

    input = _getch();

    if (input == 's')
    {
        *pbservice = 1;
        cout << "Sie haben sich für die Auswahl Service-Mode entschieden.\n";
        SI(kaffee);
        char c;
        c = _getch();
        if (c == '!')
        {
            return 1;
        }
    }
    else if (input == 'k')
    {
        cout << "Sie haben sich für die Auswahl Kaffee entschieden.\n";
        UI_zusaetze_kaffee(1, pbmilch, pbzucker);
        *pbkaffee = 1;
    }
    else if (input == 'e')
    {
        cout << "Sie haben sich für die Auswahl Espresso entschieden.\n";
        UI_zusaetze_kaffee(0, pbmilch, pbzucker);
        *pbespresso = 1;
    }

    return 0;
}

void UI_zusaetze_kaffee(bool beide, bool *pbmilch, bool *pbzucker)
{
    char input;
    cout << "Möchten Sie Zucker (j/n)?\n";
    input = _getch();
    if (input == 'j')
    {
        *pbzucker = 1;
    }
    else if (input != 'n')
    {
        cout << "Falsche Eingabe...\nDrücken Sie eine beliebige Taste\n";
        //return 0; Fehler Abfangen
    }
    if (beide)
    {
        cout << "Möchten Sie Milch (j/n)?\n";
        input = _getch();
        if (input == 'j')
        {
            *pbmilch = 1;
        }
        else if (input != 'n')
        {
            cout << "Falsche Eingabe...\nDrücken Sie eine beliebige Taste\n";
            //return 0; Fehler Abfangen
        }
    }
    //return 1;
}

void SI(daten kaffee)
{
    //Unsichere Passwortabfrage, da Länge des Passworts = 6 (Warum kein String?)
    string input;
    char c;
    bool correct= 1;
    system("clear");
    cout << "Bitte geben Sie das Passwort ein: ";
    while ((c =_getch()) != 10){
        if (c != 127){
            input += c;
            cout << '*';
        }
        else if (!input.empty()) {
            input.pop_back();
            cout << "\b \b";
        }
    }
    cout << endl;
    if (input.length() > 6) correct = 0;
    for (int i = 0; i < 6; i ++){
        correct &= (input[i]== kaffee.passwort[i]);
    }
    if (correct){
        system("clear");
        cout << "Service Interface\n-------------------------------------------\n";
        cout << "Noch vorhandene Mengen:\n";
        cout << setw(25) << left << "Kaffe:" << setw(6) << right << kaffee.vorrat_kaffee << " g ";
        cout << setw(25) << left << "Milch:" << setw(6) << right << kaffee.vorrat_milch << " ml \n";
        cout << setw(25) << left << "Espresso:" << setw(6) << right << kaffee.vorrat_espresso << " g ";
        cout << setw(25) << left << "Wasser:" << setw(6) << right << kaffee.vorrat_wasser << " ml \n";
        cout << setw(25) << left << "Zucker:" << setw(6) << right << kaffee.vorrat_zucker << " g \n";
        cout << "\n-------------------------------------------\n\nMengen pro Tasse:\n";
        cout << setw(25) << left << "Kaffe:" << setw(6) << right << kaffee.menge_kaffee_pro_tasse << " g ";
        cout << setw(25) << left << "Milch:" << setw(6) << right << kaffee.menge_milch_pro_tasse << " ml \n";
        cout << setw(25) << left << "Espresso:" << setw(6) << right << kaffee.menge_espresso_pro_tasse << " g ";
        cout << setw(25) << left << "Wasser für Kaffe:"  << setw(6) << right << kaffee.wasser_pro_tasse_kaffee << " ml \n";
        cout << setw(25) << left << "Zucker:" << setw(6) << right << kaffee.menge_zucker_pro_tasse << " g ";
        cout << setw(25) << left << "Wasser für Espresso:" << setw(6) << right << kaffee.wasser_pro_tasse_espresso << " ml \n";
        cout << "\n-------------------------------------------\n\nDrücken Sie eine beliebige Taste...";
    }
    else{
        cout << "Falsches Passwort! Zugang zum Service-Interface verweigert!\nDrücken Sie eine beliebige Taste . . .\n";
    }
}

float preis_berechnen(bool bkaffee, bool bmilch, bool bzucker, bool bespresso, daten kaffee)
{
    return kaffee.preis_pro_tasse + kaffee.preis_zutaten_pro_tasse * (bmilch + bzucker);
}

void mengen_aktualisieren(bool bkaffee, bool bmilch, bool bzucker, bool bespresso, daten *pkaffee)
{
    pkaffee->vorrat_kaffee -= bkaffee * pkaffee->menge_kaffee_pro_tasse;
    pkaffee->vorrat_espresso -= bespresso * pkaffee->menge_espresso_pro_tasse;
    pkaffee->vorrat_milch -= bmilch * pkaffee->menge_milch_pro_tasse;
    pkaffee->vorrat_zucker -= bzucker * pkaffee->menge_zucker_pro_tasse;
}