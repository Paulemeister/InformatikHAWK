#pragma once
#include <string>

using namespace std;

class Transportmittel
{
private:
    double hoehe;
    double breite;
public:
    Transportmittel(double hoehe,double breite);
    ~Transportmittel();
    void bewegen(string Richtung);
    double getHoehe();
    double getBreite();
};

class LandTransportmittel: public Transportmittel
{
private:
    int radzahl;
public:
    LandTransportmittel(double hoehe,double breite,int radzahl);
    ~LandTransportmittel();
    void fahren(double km);
    void schieben(double km);
    int getRadzahl();
};

class WasserTransportmittel: public Transportmittel
{
private:
    double bruttoregistertonnen;
public:
    WasserTransportmittel(double hoehe,double breite,double bruttoregistertonnen);
    ~WasserTransportmittel();
    void anlegen (string Anlegehafen);
    void ablegen (string Ablegehafen);
    double getBruttoregistertonnen();
};

class Fahrrad: public LandTransportmittel
{
private:
    int anzahlgaenge;
public:
    Fahrrad(double hoehe,double breite,int radzahl,int anzahlgaenge);
    ~Fahrrad();
    void freihaendigfahren ( string name);
    int getAnzahlgaenge();
    void schieben(double km);
};

class Rikscha: public LandTransportmittel
{
private:
    string farbe;
public:
    Rikscha(double hoehe,double breite,int radzahl,string farbe);
    ~Rikscha();
    void ziehen(int anzahlpersonen);
    void schieben(double km);
    string getFarbe();
};

class Auto: public LandTransportmittel
{
private:
    double spritverbrauch;
public:
    Auto(double hoehe,double breite,int radzahl,double spritverbrauch);
    ~Auto();
    void tanken(int liter);
    void fahren(double km);
    double getSpritverbrauch();
};
