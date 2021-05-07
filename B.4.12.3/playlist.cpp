#include "playlist.h"
#include <string>
#include <iostream>
#include <fstream>
#define SAVEFILE "template.txt"
using namespace std;

/*Titel zu der verketteten Liste hinzufuegen*/
void playlist::TitelEinfuegen(string Name, string Interpret, mkat Kategorie)
{
    struct titel *ptr;
    // Speicherplatz fuer neues Element der Liste vom Heap reservieren
    if ((ptr = new titel) == NULL)
    {
        cout << "kein Speicherplatz mehr vorhanden";
        return;
    }
    else
    {
        // Daten in das Element einkopierem
        ptr->name = Name;
        ptr->interpret = Interpret;
        ptr->kategorie = Kategorie;

        // neues Element an Anfang der verketteten Liste einfuegen
        ptr->next = start_pointer;
        start_pointer = ptr;
        return;
    }
}

bool playlist::TitelLoeschen(string Name)
{
    // nach der Titel mit dem eingegebenen Namen suchen und loeschen
    struct titel *ptr{start_pointer}, *vorgaenger{start_pointer};

    // nachschauen, ob der Titel in der verketteten Liste vorhanden ist
    while (ptr != NULL && (ptr->name != Name))
    {
        vorgaenger = ptr;
        ptr = ptr->next;
    }

    // der gesuchte Titel wurde nicht gefunden
    if (ptr == NULL)
    {
        return false;
    }
    else
    {
        // der gesuchte Titel ist der erste in der Liste
        if (ptr == start_pointer)
        {
            // das naechste Element wird das erste in der Liste
            start_pointer = ptr->next;
        }
        else
        {
            /*der next-Zeiger des Elementes vor dem zu loeschenden Element wird auf das dem zu loeschenden folgende Element gesetzt*/
            vorgaenger->next = ptr->next;
        }
        // der gefundene Titel wird geloescht
        delete ptr;
        return true;
    }
}

const char* playlist::enumkat_in_string(enum mkat input){
    switch(input){
        case KLASSIK:  return "KLASSIK";
        case POP:  return "POP";
        case ROCK:  return "ROCK";
        case JUNGLE:  return "JUNGLE";
        case HIPHOP:  return "HIPHOP";
        case JAZZ:  return "JAZZ";
        default: return "NONE";
    }
}

bool int_in_enummkat(int eingabe, enum mkat &ausgabe){
    switch(eingabe){
        case 1:  ausgabe = KLASSIK;break;
        case 2:  ausgabe = POP;break;
        case 3:  ausgabe = ROCK;break;
        case 4:  ausgabe = JUNGLE;break;
        case 5:  ausgabe = HIPHOP;break;
        case 6:  ausgabe = JAZZ;break;
        default: return false;
    }
    return true;
}

void playlist::AlleTitelAnzeigen()
{
    // ptr wird auf den Anfang der Liste gesetzt
    struct titel *ptr = start_pointer;
    system("cls");
    cout << "\nPlaylist" << name << endl<< endl;

    if (ptr == NULL)
    {
        cout << "DiePlaylististleer.\n";
        system("pause");
    }

    while (ptr != NULL)
    {
        // Ausgabe der playlist*/
        cout << ptr->name << "," << ptr->interpret << ",";
        cout << enumkat_in_string(ptr->kategorie) << endl;

        // pointer auf das naechste Element setzen
        ptr = ptr->next;
    }

    cout << "\n";
    system("pause");
}

void playlist::AlleTitelLoeschen()
{

    struct titel *ptr;
    struct titel *ptr_;

    // loesche die verkettete Liste
    ptr = start_pointer;

    while (ptr != NULL)
    {

        ptr_ = ptr->next;

        // Platz auf dem Heap freigeben

        delete ptr;

        ptr = ptr_;
    }

        start_pointer = NULL;
}

void playlist::PlaylistLaden(){
    fstream f;
    int firstSemicolon;
    string text;
    string token;
    f.open(SAVEFILE);
    getline(f,text);
    while (token.compare(name)!= 0 && token.back() != EOF){
        for (int i = 0; i> stoi(text.substr(firstSemicolon+1,-1));i++){
            getline(f,text);
        }
        getline(f,text);
        firstSemicolon = text.find(';');
        token = text.substr(0,firstSemicolon);
    }
}

void playlist::PlaylistUmdrehen(){
    titel * last = NULL;
    titel * pointer = start_pointer;
    titel * next;
    while((next = start_pointer->next)!=NULL){
        pointer->next = last;
        last = pointer;
        pointer = next;
    }

}

void allePlaylistsLaden(string file){
    //loaded data must have at least one playlist.
    fstream f;
    string text;
    string token;
    string name;
    string interpret;
    mkat kategorie;
    int playlistsAmount;
    int firstSemicolon = 0;
    int secondSemicolon;
    int playlistNb = 0;
    int playlistLength;
    
    f.open(file,ios::in);
    getline(f,text);
    playlistsAmount = stoi(text);
    playlist * storedPlaylists  = new playlist[playlistsAmount] ;

    for (int i = 0; i< playlistsAmount; i++){
        getline(f,text);
        firstSemicolon = text.find(';');
        token = text.substr(0,firstSemicolon);
        storedPlaylists[i].set_name(token);
        string test = text.substr(firstSemicolon+1,-1);
        playlistLength = stoi(text.substr(firstSemicolon+1,-1)); //read 'til \n

        for (int j = 0; j< playlistLength;j++){
            getline(f,text);
            firstSemicolon = text.find(';');
            secondSemicolon = text.find(';',firstSemicolon+1);
            name = text.substr(0,firstSemicolon);
            interpret = text.substr(firstSemicolon+1,secondSemicolon-firstSemicolon-1);
            test = text.substr(secondSemicolon+1,-1);
            if (int_in_enummkat(stoi(text.substr(secondSemicolon+1,-1)),kategorie)){
                storedPlaylists[i].TitelEinfuegen(name,interpret,kategorie);
            }
        }
        cout << storedPlaylists[i].get_name()<<endl;
    }
    f.close();
}