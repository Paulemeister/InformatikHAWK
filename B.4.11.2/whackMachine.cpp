//#define DEBUG

#include "kafffeautomat.h"
#include "Funktionen.cpp"

using namespace std;



int main(int argc, char const *argv[])
{
    
    bool bkaffee, bmilch, bzucker, bespresso, bservice;
    float rueckgeld, preis, input;
    daten kaffee{1000, 1000, 500, 1000, 5000, 5, 5, 125, 25, 3, 30, 1, 0.1};

    while (!UI(&bkaffee, &bmilch, &bzucker, &bespresso, &bservice, kaffee))
    {
        rueckgeld = preis = input = 0;
        if (bservice == bkaffee == bespresso == 0)
        {
            _getch();
        }
        else if (!bservice)
        {
            preis = preis_berechnen(bkaffee, bmilch, bzucker, bespresso, kaffee);
            cout << "Bitte " << preis << " Euro eingeben und ENTER drücken:\n";
            cin >> input;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            rueckgeld = input - preis;
            if (rueckgeld < 0)
            {
                cout << "Zu wenig Geld, Bestellung abgebrochen\nDrücken Sie ein beliebige Taste...\n";
                _getch();
            }
            else
            {
                cout << "Ihr Getraenk wird zubereitet.....\nBitte ";
                if (rueckgeld != 0)
                {
                    cout << rueckgeld << " Euro Rückgeld und ";
                }
                cout << "das Getränk entnehmen -:) und eine Taste drücken\n";

                mengen_aktualisieren(bkaffee, bmilch, bzucker, bespresso, &kaffee);
                _getch();
            }
        }
    }

    return 0;
}

