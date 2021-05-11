/*======================================================*/
/* Dateiname:	playlisttest.cpp                        */
/* Inhalt:		Benutzung der Klasse plylist           	*/
/* Author:		Bernd Stock								*/
/* Erstellt am: Maerz 2019								*/
/* Geaendert:	Mai 2021 (Lösen der Aufgabe)            */
/*						                      		    */
/*======================================================*/



// Original ohne PlaylistLaden 
#include "playlist.cpp"
// Neue Funktionen
#include "aufgabe.cpp"

// Platformspezifische Funktionen wurden durch Makros ersetzt
// Der Restliche Code dieser Datei ist bis auf case 5 unverändert

using namespace std;


/*=================*/
int menue(string);
/*=================*/

int main(void)
{
	playlist my_playlist;
	string Titel;
	string Interpret;
	mkat Kategorie;
	string temp{};

	int eingabe = -1;
	do {
		eingabe = menue(my_playlist.get_name());
		switch (eingabe) {
		case 1:
			my_playlist.BenutzerdatenEingeben(Titel, Interpret, Kategorie);
			/* einen neuen Titel in die Liste einfuegen */
			my_playlist.TitelEinfuegen(Titel, Interpret, Kategorie);
			break;
		case 2:
			// einen Titel aus der Liste loeschen 
			my_playlist.ZeileEingeben("Bitte den zu löschenden Titel eingeben:",
				Titel);
			if (my_playlist.TitelLoeschen(Titel) == false)
			{
				cout << "\nDer Titel \"" << Titel << "\" wurde nicht gefunden und konnte daher nicht gelöscht werden\n";
				PAUSE();
			}
			else
			{
				cout << "\nTitel \"" << Titel << "\" wurde gelöscht.\n";
				PAUSE();
			}
			break;
		case 3:
			 /* Ausgabe der kompletten Liste */
			my_playlist.AlleTitelAnzeigen ();
			break;
		case 4:
			 // einen Titel suchen und anzeigen
			my_playlist.ZeileEingeben ("Bitte den gesuchten Titel der Playlist eingeben:", 
			Titel);
			if (my_playlist.TitelSuchenundAnzeigen(Titel, Interpret, Kategorie) == false)
			{
				cout << "\nDer gesuchte Titel \"" << Titel << "\" wurde nicht gefunden\n";
				PAUSE();
			}
			else
			{
				cout << Titel << "," << Interpret << ",";
				cout << my_playlist.enumkat_in_string(Kategorie) << endl;
				PAUSE();
			}
			break;
		case 5:
			// Playlist abspielen
			my_playlist.Abspielen();
			break;
		case 6:
			 // Playlist speichern */
			my_playlist.ZeileEingeben("Bitte den Namen der Playlist eingeben:", temp);
			my_playlist.set_name(temp);
			my_playlist.PlaylistSpeichern ();
			break;
		case 7:
			 // Playlist laden */
			my_playlist.ZeileEingeben ("Bitte den Namen der Playlist eingeben:", 
			temp);
			my_playlist.set_name(temp);
			my_playlist.PlaylistLaden ();
			break;
		case 8:
			break;
		default:
			cout << "\nFalsche Eingabe!!!\n";
			PAUSE();
			break;
		}
   } while (eingabe != 8);

	return 1;
 }

/*=====================*/
  int menue (string pl)
/*=====================*/

  {
	//int eingabe = -10;;
	// Bildschirm l�schen
	CLEAR();
	// �:\x8e �:\x84 �:\x99 �:\x94 �:\x9A �:\x81 �:e1
	// Menu anzeigen
	cout << "\nPlaylisten verwalten " << "\n====================\n\n";
	cout << "Name der aktuellen Playlist: " << pl << endl;
	cout << "Sie haben die folgende Auswahl:\n\n";
	cout << "Neuen Titel einfügen........1\n";
	cout << "Titel löschen...............2\n";
	cout << "Alle Titel auflisten........3\n";
	cout << "Titel suchen und anzeigen...4\n";
	cout << "Playlist abspielen..........5\n";
	cout << "Playlist speichern..........6\n";
	cout << "Playlist laden..............7\n";
	cout << "Programm beenden............8\n";
	cout << "\nBitte geben Sie eine Zahl ein:";
	// Eingabepuffer leeren
	cin.seekg(0,std::ios::end);
	cin.clear();	
	char eingabe{ 'n' };
	//cin >> eingabe;
	char input[2];
	input[0] = _getche();
	input[1] = '\0';
	CLEAR();
	return atoi(input);
  }
