
#include <iostream>
#include <string>
#include "playlist.h"
#include <fstream>

using namespace std;

/*====================================================*/
   void playlist::PlaylistLaden () 
/*====================================================*/   
 {	   

	titel tmp;	   
	ifstream Quelle;
	string hilfe{name};
	
	hilfe += ".txt";

	Quelle.open(hilfe.c_str(), ios_base::in);

    if (!Quelle) {
        cerr << "Playlyist \"" << name <<"\" kann nicht geöffnet werden!\n";
        PAUSE();
		return;
    }

	// aktuelle Daten loeschen
	AlleTitelLoeschen ();
	
	while (!Quelle.eof())   
	{
		struct titel * ptr;
        struct titel *last;
		getline(Quelle, hilfe);
		if (hilfe.length() == 0)
			break;
		if ((ptr = new titel) == NULL) {
			CLEAR();
			cout << "kein Speicherplatz mehr vorhanden";
			PAUSE();
			return;
		}else {
            ptr->next = NULL;
			ptr->name = hilfe;
			getline (Quelle, ptr->interpret);
			getline (Quelle, hilfe);
			ptr->kategorie = static_cast<mkat> (atoi(hilfe.c_str())); // "3"
            if(start_pointer == NULL){
                start_pointer = ptr;
            }
            else{
                last->next = ptr;
            }
            last = ptr;
		}
	}
	Quelle.close ();
}

void playlist::Abspielen(){
    struct titel * ptr = start_pointer;

    CLEAR();
    while(ptr != NULL){
        cout << "Spiele " << ptr->name << "\nvon: " << ptr->interpret << endl;
        cout << "Genre: " << playlist::enumkat_in_string(ptr->kategorie) << endl;
        cout << '\a';
        CLEAR();
        ptr = ptr->next;
    }
}