
#include "datum.h"

void tests(){
    const int amount = 12;
    int tage[amount] =      {1,20,15,1,13,12,30,20,30,31,5,2};
    int monate[amount] =    {1,2,3,4,5,6,7,8,9,10,11,12};
    int jahre[amount] =     {2020,2021,1,200,400,12,4,1999,1990,2022,2222,1996};
    int ergebnisse[amount] = {1,51,74,91,134,164,212,232,273,304,309,337};
    bool schaltjahr[amount] = {true,false,false,false,true,true,true,false,false,false,false,true};
    Datum *pointer[amount] ;
    int temp = 0;
    bool allgood = true;
    for (int i = 0;i< 12 ; i++){
        pointer[i] = new Datum(tage[i],monate[i],jahre[i]);
        cout << tage[i] << "." << monate[i] << "." << jahre[i]<< ":\n"; 
        cout << "Tag des Jahres: " << (temp = pointer[i]->TagDesJahres()) << " - ";
        cout <<((temp==ergebnisse[i])?"richtig":"falsch") << endl;
        allgood&= temp==ergebnisse[i];
        cout << "Schaltjahr: " << (temp = Datum::IstSchaltjahr(jahre[i])) << " - ";
        cout << ((temp==schaltjahr[i])?"richtig":"falsch") << endl <<endl;
        allgood&= temp==schaltjahr[i];
    }
    cout << "Tests " << (allgood?"passed":"failed") << endl;

    for (int i = 0; i< amount; i++){
        delete pointer[i];
    }
}