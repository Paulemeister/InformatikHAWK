#pragma once
#include <iostream>
#include <string>

using namespace std;



class Datum {
    int tag;
    int monat;
    int  jahr;
    int nummer;
    static int monatslaenge[12];
    static int instanzen;
    static bool plappern;
    public:
    Datum(int init_tag, int init_monat, int init_jahr):
    tag{init_tag},monat{init_monat},jahr{init_jahr}{
        nummer = ++instanzen;
        if (plappern){
            cout << "Neues Datum Initialisiert: " << tag << "." << monat <<"." << jahr << endl;
        }
        if (instanzen > 10){
            cout << "Warnung: mehr als 10 Instanzen initialisiert\n";
        }
    }

    ~Datum(){
        cout << "Destruktor von " << this << endl;
    }
    static int IstSchaltjahr(int irgendeinJahr){
        if ((((irgendeinJahr%4) == 0)&& ((irgendeinJahr%100) != 0)) ||(  (irgendeinJahr %400) == 0)) {
            return 1;
        }
        /*
        if (irgendeinJahr%4== 0){
            if (irgendeinJahr%100== 0){
                if (irgendeinJahr%400 == 0){
                    return 1;
                }
            }
            else{
                return 1;
            }
        }*/
        return  0;
    }
    static void Plappern(bool flag){
        plappern = flag;
    }

    int TagDesJahres(){
        if (plappern){
            cout << "Tag des Jahres von Instanz Nr. " << nummer << " aufgerufen\n";
        }
        int tage = tag;

        for (int i = 0; i< (monat-1); i++){
            tage += monatslaenge[i];
        }
        if ((monat > 2 ) && IstSchaltjahr(jahr)){
            tage ++;
        }
        return tage;
    }
};
