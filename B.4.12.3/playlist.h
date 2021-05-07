#pragma once
#include <string>
using namespace std;

// Aufzaehlung der in der Playlist verwalteten Musikstile
enum mkat
{
    KLASSIK = 1,
    POP,
    ROCK,
    JUNGLE,
    HIPHOP,
    JAZZ
};

// Struktur zur Haltung der Daten der einzelnen Titel der Playlist
// in einer verketteten Liste
struct titel
{
    titel *next;
    string name;
    string interpret;
    mkat kategorie;
};

string enumkat_in_string(enum mkat);

class playlist

{

    // private Attribute und Methoden

private:
    // Anker der verketteten Liste

    struct titel *start_pointer;

    // Name der Playlist

    string name;

    // Methoden, die nur innerhalb der

    // Klasse benutzt werden

    void AlleTitelLoeschen();

    bool int_in_enummkat(int eingabe, enum mkat &ausgabe);

    // oeffentliche Schnittstelle

public:
    // Standardkonstruktor

    playlist()
    {
        start_pointer = NULL;
        name = "mylist";
    }

    // Destruktor

    ~playlist() { AlleTitelLoeschen(); }

    // Setter und Getter des Attributes name

    void set_name(string n) { name = n; }

    string get_name() const { return name; }

    void TitelEinfuegen(string Name, string Interpret, mkat Kategorie);

    bool TitelLoeschen(string Name);

    void TitelSuchenundAnzeigen(string Name);

    void AlleTitelAnzeigen();

    void PlaylistSpeichern();

    void PlaylistLaden();

    // Hilfsmethoden

    void BenutzerdatenEingeben(string &titel, string &interpret,mkat &CD_kategorie);

    const char *enumkat_in_string(mkat eingabe);

    void ZeileEingeben(string befehlszeile, string &text);

    void PlaylistUmdrehen();
};