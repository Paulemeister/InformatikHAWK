#include <iostream>
#include "transportmittel.cpp"

int main(int argc, char const *argv[])
{
    Transportmittel tpm {2,1};
    LandTransportmittel ltpm {2,1,4};
    WasserTransportmittel wtpm {2,1,1.23};
    Fahrrad frd {1,0.2,2,30};
    Rikscha rks {1,1,3,"schwarz"};
    Auto aut {4,2,4,8};
    
    cout << "Transportmittel:\n";
    tpm.setHoehe(1);
    tpm.setBreite(0.2);
    tpm.bewegen("Norden");
    cout << "Höhe: " <<tpm.getHoehe() << "\tBreite: " << tpm.getBreite() << endl << endl;

    cout << "LandTransportmittel:\n";
    ltpm.fahren(30);
    ltpm.schieben(2);
    cout << "Radzahl: " << ltpm.getRadzahl() << endl << endl;

    cout << "WasserTransportmittel:\n";
    wtpm.ablegen("Rotterdam");
    wtpm.anlegen("Hamburg");
    cout << "Bruttoregistertonnen: " << wtpm.getBruttoregistertonnen() << endl << endl;

    cout << "Fahrrad:\n";
    frd.freihaendigfahren("Juhu");
    frd.schieben(1);
    cout << "Gänge: " << frd.getAnzahlgaenge() << endl << endl;

    cout << "Rikscha:\n";
    rks.schieben(3);
    cout << "Farbe: " << rks.getFarbe() << endl << endl;

    cout << "Auto:\n";
    aut.tanken(50);
    aut.fahren(100);
    cout << "Spritverbrauch: " << aut.getSpritverbrauch() << endl << endl;

    return 0;
}
