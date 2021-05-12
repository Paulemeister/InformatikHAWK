#include <iostream>
#include "transportmittel.cpp"

int main(int argc, char const *argv[])
{
    Transportmittel tpm {2,4};
    LandTransportmittel ltpm {2,1,4};
    WasserTransportmittel wtpm {2,1,1.23};
    Fahrrad frd {1,0.2,2,30};
    Rikscha rks {1,1,3,"schwarz"};
    Auto aut {4,2,4,8};
    
    cout << "Transportmittel:\n";
    tpm.bewegen("Norden");
    cout << "Höhe: " <<tpm.getHoehe() << "\tBreite: " << tpm.getBreite() << endl << endl;

    cout << "LandTransportmittel:\n";
    ltpm.bewegen("Süden");
    ltpm.fahren(30);
    ltpm.schieben(2);
    cout << "Höhe: " <<tpm.getHoehe() << "\tBreite: " << tpm.getBreite() << endl;
    cout << "Radzahl: " << ltpm.getRadzahl() << endl << endl;

    cout << "WasserTransportmittel:\n";
    wtpm.bewegen("Osten");
    wtpm.ablegen("Rotterdam");
    wtpm.anlegen("Hamburg");
    cout << "Höhe: " <<wtpm.getHoehe() << "\tBreite: " << wtpm.getBreite() << endl;
    cout << "Bruttoregistertonnen: " << wtpm.getBruttoregistertonnen() << endl << endl;

    cout << "Fahrrad:\n";
    frd.freihaendigfahren("Juhu");
    frd.schieben(1);
    frd.bewegen("Westen");
    frd.fahren(4);
    cout << "Höhe: " <<frd.getHoehe() << "\tBreite: " << frd.getBreite() << endl;
    cout << "Radzahl: "<< frd.getRadzahl() <<endl;
    cout << "Gänge: " << frd.getAnzahlgaenge() << endl << endl;

    cout << "Rikscha:\n";
    rks.schieben(3);
    rks.ziehen(4);
    rks.fahren(3);
    rks.bewegen("Südwest");
    cout << "Höhe: " <<rks.getHoehe() << "\tBreite: " << rks.getBreite() << endl;
    cout << "Radzahl: "<< rks.getRadzahl() <<endl;
    cout << "Farbe: " << rks.getFarbe() << endl << endl;

    cout << "Auto:\n";
    aut.bewegen("Nordwest");
    aut.tanken(50);
    aut.fahren(100);
    aut.schieben(1);
    cout << "Radzahl: "<< aut.getRadzahl() <<endl;
    cout << "Höhe: " <<aut.getHoehe() << "\tBreite: " << aut.getBreite() << endl;
    cout << "Spritverbrauch: " << aut.getSpritverbrauch() << endl << endl;

    return 0;
}
