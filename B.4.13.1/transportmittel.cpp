#include "transportmittel.h"
#include <iostream>
using namespace std;

// Transportmittel

Transportmittel::Transportmittel(double newHoehe,double newBreite)
:hoehe{newHoehe}, breite{newBreite}
{

}
Transportmittel::~Transportmittel()
{

}
void Transportmittel::bewegen(string Richtung)
{
    cout << "in Richtung " << Richtung << " bewegen\n";
}
double Transportmittel::getHoehe()
{
    return hoehe;
}
double Transportmittel::getBreite()
{
    return breite;
}
void Transportmittel::setHoehe(double newHohe)
{
    hoehe = newHohe;
}
void Transportmittel::setBreite(double newBreite)
{
    breite = newBreite;
}

//LandTransportmittel


LandTransportmittel::LandTransportmittel(double hoehe,double breite,int newRadzahl)
:Transportmittel(hoehe,breite), radzahl{newRadzahl}
{

}
LandTransportmittel::~LandTransportmittel()
{

}
void LandTransportmittel::fahren(double km)
{
    cout << km << " km fahren\n";
}
void LandTransportmittel::schieben(double km)
{
    cout << km << " km schieben\n";
}
int LandTransportmittel::getRadzahl()
{
    return radzahl;
}

// WasserTransportmittel

WasserTransportmittel::WasserTransportmittel(double hoehe,double breite,double newBruttoregistertonnen)
:Transportmittel(hoehe,breite), bruttoregistertonnen{newBruttoregistertonnen}
{

}
WasserTransportmittel::~WasserTransportmittel()
{

}
void WasserTransportmittel::anlegen (string Anlegehafen)
{
    cout << "An " << Anlegehafen << " anlegen\n";
}
void WasserTransportmittel::ablegen (string Ablegehafen)
{
    cout << "Von " << Ablegehafen << " ablegen\n";
}
double WasserTransportmittel::getBruttoregistertonnen()
{
    return bruttoregistertonnen;
}

// Fahrrad

Fahrrad::Fahrrad(double hoehe,double breite,int radzahl,int newAnzahlgaenge)
:LandTransportmittel(hoehe,breite,radzahl), anzahlgaenge{newAnzahlgaenge}
{

}
Fahrrad::~Fahrrad()
{

}
void Fahrrad::freihaendigfahren ( string name)
{
    cout << "Freihändig fahren: " << name << endl;
}
int Fahrrad::getAnzahlgaenge()
{
    return anzahlgaenge;
}
void Fahrrad::schieben(double km)
{
    cout << "Fahrrad " << km << " km schieben\n";
}

// Rikscha

Rikscha::Rikscha(double hoehe,double breite,int radzahl,string newFarbe)
:LandTransportmittel(hoehe,breite,radzahl), farbe{newFarbe}
{

}
Rikscha::~Rikscha()
{

}
void Rikscha::schieben(double km)
{
    cout << "Rikscha " << km << " km schieben\n";
}
string Rikscha::getFarbe()
{
    return farbe;
}

// Auto

Auto::Auto(double hoehe,double breite,int radzahl,double newSpritverbrauch)
: LandTransportmittel(hoehe,breite,radzahl), spritverbrauch{newSpritverbrauch}
{

}
Auto::~Auto()
{

}
void Auto::tanken(int liter)
{
    cout << "Tanke " << liter << " l\n";
}
void Auto::fahren(double km)
{
    cout << km << " km Auto fahren\n";
}
double Auto::getSpritverbrauch()
{
    return spritverbrauch;
}