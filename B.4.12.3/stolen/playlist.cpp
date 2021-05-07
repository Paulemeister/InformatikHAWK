/*======================================================*/
/* Dateiname:	playlist.cpp                            */
/* Inhalt:		Implemenation der Klasse playlist    	*/
/* Author:		Bernd Stock								*/
/* Erstellt am: Maerz 2019								*/
/* Geaendert:	                                        */
/*						                      		    */
/*======================================================*/
#if defined(_WIN32) || defined(__CYGWIN__)
	#include<conio.h>
	#include <windows.h> 
	#define CLEAR() system("cls")
	#define PAUSE() system("pause")
	#define SLEEP(X) Sleep(X)
#else

	#include "getch.cpp"
	#include <unistd.h>
	#define CLEAR() system("clear")
	#define PAUSE() cout<<"Press any key to continue...";_getch()
	#define SLEEP(X) sleep(X/1000)
#endif

#include <iostream>
#include <string>
#include "playlist.h"
#include <fstream>

using namespace std;

// Hilfsmethode zur EIngabe eines Titels
void playlist::BenutzerdatenEingeben (string &titel, string &interpret, mkat & kategorie)
{

	char tmp;

	while (1)
	{
		// �:\x8e �:\x84 �:\x99 �:\x94 �:\x9A �:\x81 �:\xe1
		CLEAR();
		cout << "\nGeben Sie den Namen des Titels ein: ";
		// Eingabepuffer leeren
		cin.seekg(0,std::ios::end);
		cin.clear();	
		getline (cin, titel); 
		cout << "\nName des/der Interpreten: ";
		getline (cin, interpret);

		cout << "\nZu welcher Musikkategorie gehört der Titel: "<< endl <<
		"(k=Klassik, p=Pop, r=Rock, j=Jungle, h=HipHop, z=Jazz):";
		cin >> tmp;

		if (false == int_in_enummkat (tmp, kategorie))
		{
			CLEAR();
			cout << "Ungültige Kategorie eingegeben!!";
			PAUSE();
		// verlassen der Endlosschleife
		} else
			break;
	}
}

// Hilfsfunktion:
// Umwandlung eines Integerwertes in den Datentyp enum mkat
// R�ckgabe true, wenn die Umwandlung funktioniert hat, sonst false
/*================================================================*/
  bool playlist::int_in_enummkat (int eingabe, enum mkat &ausgabe)
/*================================================================*/
{
	switch (eingabe)
	{
	case 'k':
	case 'K':
		ausgabe = KLASSIK;
		break;
	case 'p':
	case 'P':
		ausgabe = POP;
		break;
	case 'r':
	case 'R':
		ausgabe = ROCK;
		break;
	case 'j':
	case 'J':
		ausgabe = JUNGLE;
		break;
	case 'h':
	case 'H':
		ausgabe = HIPHOP;
		break;
	case 'z':
	case 'Z':
		ausgabe = JAZZ;
		break;
	default:
		return false;
	}
	return true;

}

// Hilfsfunktion:
// Ausgabe von Befehlszeile �ber cout und Einlesen der Benutzereingabe in text

/*==============================================================================================*/
  void playlist::ZeileEingeben (string befehlszeile, string &text)
/*==============================================================================================*/
{

	CLEAR();
	cout << "\n" << befehlszeile;
	// Eingabepuffer leeren
	cin.seekg(0,std::ios::end);
	cin.clear();	
	/* getline liest bis zum n�chsten Carriage Return ein */
	getline (cin, text); 

}

// Hilfsfunktion: Umwandlung des Aufz�hlungstyps enum mkat
// in einen C-string zur Ausgabe
/*=============================================================*/
  const char * playlist::enumkat_in_string(mkat eingabe)
	  /*=============================================================*/
  {
	  static const char * kategorie[] = {
		  "KLASSIK", "POP","ROCK", "JUNGLE", "HIPHOP", "JAZZ", "UNBEKANNTE_KATEGORIE" };

	  switch (eingabe)
	  {
	  case KLASSIK:
		  return kategorie[0];
	  case POP:
		  return kategorie[1];
	  case ROCK:
		  return kategorie[2];
	  case JUNGLE:
		  return kategorie[3];
	  case HIPHOP:
		  return kategorie[4];
	  case JAZZ:
		  return kategorie[5];
	  default:
		  return kategorie[6];
	  }
	  return NULL;
  }

/*=====================================================================================*/
  void playlist::TitelEinfuegen (string Name, string Interpret, mkat Kategorie)
/*=====================================================================================*/

{
	/* Titel zu der verketteten Liste hinzuf�gen */
   struct titel * ptr;

   if ((ptr = new titel) == NULL) {
      CLEAR();
	  cout << "kein Speicherplatz mehr vorhanden";
	  PAUSE();
	  return;
   }else {
      ptr->name = Name;
      ptr->interpret = Interpret;
      ptr->kategorie = Kategorie;
      ptr->next = start_pointer;
      start_pointer = ptr;
      return;
   }

 }


/*===========================================*/
   bool playlist::TitelLoeschen (string Name)
/*===========================================*/

 {
	// nach der Titel mit dem eingegebenen Namen suchen und loeschen
	   struct titel * ptr{ start_pointer }, *vorgaenger{ start_pointer };

   // nachschauen, ob der Titel in der verketteten Liste vorhanden ist 
   while (ptr != NULL && (ptr->name != Name))
   {
      vorgaenger = ptr;
      ptr = ptr->next;
   }

   // der gesuchte Titel wurde nicht gefunden 
   if (ptr == NULL) {
	   return false;
   } else {
		// der gesuchte Titel ist der erste in der Liste 
		if (ptr == start_pointer)
			/* das n�chste Element wird das erste in der Liste */
			start_pointer = ptr->next;
		else
			/* der next-Zeiger des Elementes vor dem zu loeschenden Element
			   wird auf das dem zu loeschenden folgende Element gesetzt */
			vorgaenger->next = ptr->next;
		// der gefundene Titel wird geloescht
		delete ptr;
		return true;
	}
 }

/*=====================================*/
  void playlist::AlleTitelAnzeigen ()
/*=====================================*/

{
	/* ptr wird auf den Anfang der Liste gesetzt */
	struct titel * ptr = start_pointer;
	
	CLEAR();
	cout << "\n Playlist " << name << endl << endl;

	if (ptr==NULL){
		cout << "Die Playlist ist leer.\n";
	}

	while (ptr != NULL)
	{
		/* Ausgabe der playlist */
		cout << ptr->name <<",";
		cout << ptr->interpret <<"," ;
		cout << enumkat_in_string (ptr->kategorie) << endl;
		/* pointer auf das n�chste Element setzen */
		ptr = ptr->next;
	}
	cout << "\n";
	PAUSE();
}


/*=========================================================================*/
   bool playlist::TitelSuchenundAnzeigen (string Name, string &i, mkat &k )
/*=========================================================================*/

 {
	// nach dem Titel mit dem eingegebenen Namen suchen und anzeigen

   struct titel * ptr = start_pointer;

   /* nachschauen, ob der Titel in der verketteten Liste vorhanden ist */
   while (ptr != NULL && (ptr->name != Name))
      ptr = ptr->next;

   // der gesuchte Titel wurde nicht gefunden 
   if (ptr == NULL) {
	   return false;
   } else {
		// Ausgabe des Titels
	   i = ptr->interpret;
	   k = ptr->kategorie;
	   return true;
	}
 }


/*========================================*/
   void playlist::AlleTitelLoeschen (void)
/*========================================*/

{
	struct titel * ptr;
	struct titel * ptr_2;
	// loesche die verkettete Liste
	ptr = start_pointer;
	while (ptr != NULL)
	{
		ptr_2 = ptr->next;
		/* Platz auf dem Heap freigeben */
		delete ptr;
		ptr = ptr_2;
	}
	start_pointer = NULL;
}

/*====================================================*/
   void playlist::PlaylistSpeichern () 
/*====================================================*/   
   {
	/* ptr wird auf den Anfang der Liste gesetzt */
	struct titel * ptr = start_pointer;
	
	if (ptr==NULL){
		cout << "Die Playlist ist leer!\n";
		PAUSE();
	}
	   
	ofstream Ziel;
	string full_name{ name };
	full_name += ".txt";
    Ziel.open(full_name.c_str(), ios_base::out);

    if (!Ziel) {
        cerr << "Datei kann nicht geöffnet werden!\n";
        PAUSE();
		return;
    }

	// schreiben
	while (ptr != NULL)
	{
		/* schreiben eines Titels der Playlist */
		Ziel << ptr->name << endl;
		Ziel << ptr->interpret << endl;
		Ziel << static_cast<int>(ptr->kategorie) << endl;
		ptr = ptr->next;
	}

	Ziel.close ();
}  






