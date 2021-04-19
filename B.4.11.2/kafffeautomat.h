#pragma once
#ifdef DEBUG
    #define PRINTVARIABLE(X) cout << endl << (#X) << "=" << (X) << endl
    #define PRINTSTRING(X) cout << endl << X << endl
#else
    #define PRINTVARIABLE(X)
    #define PRINTSTRING(X)
#endif

struct daten
{
    int vorrat_kaffee;
    int vorrat_espresso;
    int vorrat_zucker;
    int vorrat_milch;
    int vorrat_wasser;

    int menge_kaffee_pro_tasse;
    int menge_espresso_pro_tasse;
    int wasser_pro_tasse_kaffee;
    int wasser_pro_tasse_espresso;
    int menge_zucker_pro_tasse;
    int menge_milch_pro_tasse;

    float preis_pro_tasse;
    float preis_zutaten_pro_tasse;

    //Nicht gefragt:

    char passwort[6] {'p','a','s','s','w','o'};
};

//keine Abbrüche bei falschen Eingaben möglich.
void UI_zusaetze_kaffee(bool beide, bool *pbmilch, bool *pbzucker);

bool UI(bool *pbkaffee, bool *pbmilch, bool *pbzucker, bool *pbespresso, bool *pbservice, daten kaffee);

void SI(daten kaffee);

float preis_berechnen(bool bkaffee, bool bmilch, bool bzucker, bool bespresso, daten kaffee);

void mengen_aktualisieren(bool bkaffee, bool bmilch, bool bzucker, bool bespresso, daten *pkaffee);
