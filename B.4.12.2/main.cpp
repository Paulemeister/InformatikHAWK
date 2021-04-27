#include <iostream>
#include <string>

using namespace std;

class Datum {
    int tag;
    int monat;
    int  jahr;
    int nummer;
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


    static int IstSchaltjahr(int irgendeinJahr){
        //if ((((irgendeinJahr%4) == 0)&& ((irgendeinJahr%100) != 0)) ||(  (irgendeinJahr %400) == 0)) {
        
        if (irgendeinJahr%4== 0){
            if (irgendeinJahr%100== 0){
                if (irgendeinJahr%400 == 0){
                    return 1;
                }
            }
            else{
                return 1;
            }
        }
        return  0;
    }
    static void Plappern(bool flag){
        plappern = flag;
    }

    int TagDesJahres(){
        if (plappern){
            cout << "Tag des Jahres von Instanz Nr. " << nummer << " aufgerufen\n";
        }
        int gerade, ungerade;
        gerade = ungerade = (monat-1)/2;
        if ((monat-1)%2!=0){ungerade++;};
        int tage = ungerade*31+gerade*30;
        if (monat> 2){
            tage -= 2-IstSchaltjahr(jahr);            
        }
        tage += tag;
        return tage;
    }
};

int Datum::instanzen {0};
bool Datum::plappern {false};

void tests(){
    const int amount = 12;
    bool allgood = true;
    int tage[amount] =      {1,20,15,1,13,12,30,20,30,31,5,2};
    int monate[amount] =    {1,2,3,4,5,6,7,8,9,10,11,12};
    int jahre[amount] =     {2020,2021,1,200,400,12,4,1999,1990,2022,2222,1996};
    int ergebnisse[amount] = {1,51,74,91,134,164,212,232,273,304,309,337};
    bool schaltjahr[amount] = {true,false,false,false,true,true,true,false,false,false,false,true};
    Datum *pointer[amount] ;
    int temp;
    cout << Datum::IstSchaltjahr(2222) << endl;
    for (int i = 0;i< 12 ; i++){
        pointer[i] = new Datum(tage[i],monate[i],jahre[i]);
        cout << "Nr. " << i << "\t:"; 
        cout << "Tag des Jahres: " << (temp = pointer[i]->TagDesJahres()) << " - "<<((temp==ergebnisse[i])?"richtig":"falsch") << endl;
        cout << "Schaltjahr: " << (temp = Datum::IstSchaltjahr(jahre[i])) << " - " << ((temp==schaltjahr[i])?"richtig":"falsch") << endl;
    }
}

int main(int argc, char const *argv[])
{
    tests();

    return 0;
}
