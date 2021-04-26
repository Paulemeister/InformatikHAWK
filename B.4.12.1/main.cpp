#include <string>
#include <iostream>
class Auto {
    private:

    int radzahl;
    std::string farbe;
    float ps;
    int anzahl_sitze;
    float spritverbrauch; //in l/100km
    float tankinhalt;
    float tankgroesse;
    
    public:

    Auto(){
        radzahl = 4;
        farbe = "Schwarz";
        ps = 200;
        anzahl_sitze = 5;
        spritverbrauch = 8;
        tankgroesse = 80;
        tankinhalt = tankgroesse;
    }

    Auto(int init_radzahl,std::string init_farbe,float init_ps,int init_anzahl_sitze,float init_spritverbrauch, float init_tankinhalt,float init_tankgroesse):
        radzahl{init_radzahl}, farbe{init_farbe}, ps{init_ps}, anzahl_sitze{init_anzahl_sitze}, spritverbrauch{init_spritverbrauch},tankinhalt{init_tankinhalt},tankgroesse{init_tankgroesse}{
    }

    Auto(const Auto & a): radzahl{a.radzahl},farbe{a.farbe}, ps{a.ps},anzahl_sitze{a.anzahl_sitze}, spritverbrauch{a.spritverbrauch}, tankinhalt{a.tankinhalt},tankgroesse{a.tankgroesse}
    {
    }

    ~Auto(){}

    float fahren (float strecke){
        float sprit = strecke * spritverbrauch /100; 

        if (sprit > tankinhalt){
            strecke = 100*tankinhalt/spritverbrauch;
            tankinhalt = 0;
            return strecke;
        }
        tankinhalt -= sprit;
        return strecke;
    }

    int get_radzahl(){return radzahl;}

    std::string get_farbe(){return farbe;}

    float get_ps(){return ps;}

    int get_anzahl_sitze(){return anzahl_sitze;}

    float get_spritverbrauch(){return spritverbrauch;}

    float get_tankinhalt(){return tankinhalt;}

    float get_tankgroesse(){return tankgroesse;}

    void set_tankinhalt(float amount){
        float temp_inhalt = tankinhalt+amount;
        if (temp_inhalt > tankgroesse){
            tankinhalt = tankgroesse;
        }
        else{
            tankinhalt = temp_inhalt;
        }
        return;
    }
};

Auto globalesAuto;

Auto test7 = Auto();
Auto test8(6,"Rot",100,8,10,50,100);
Auto test9 = test8;

bool testClassValues(Auto * testClass,int radzahl,std::string farbe,float ps,int anzahl_sitze,float spritverbrauch,float tankinhalt,float tankgroesse){
    bool allgood = true;
    bool testOk;
    allgood &= (testOk=(testClass->get_radzahl()==radzahl));
    std::cout <<(testOk?"":"\033[38;5;1mradzahl falsch\033[m\n");
    allgood &= (testOk=(testClass->get_farbe()== farbe));
    std::cout <<(testOk?"":"\033[38;5;1mfarbe falsch\033[m\n");
    allgood &= (testOk=(testClass->get_ps()==ps));
    std::cout <<(testOk?"":"\033[38;5;1mps falsch\033[m\n");
    allgood &= (testOk=(testClass->get_anzahl_sitze()==anzahl_sitze));
    std::cout <<(testOk?"":"\033[38;5;1manzahl_sitze falsch\033[m\n");
    allgood &= (testOk=(testClass->get_spritverbrauch()==spritverbrauch));
    std::cout <<(testOk?"":"\033[38;5;1mspritverbrauch falsch\033[m\n");
    allgood &= (testOk=(testClass->get_tankinhalt()==tankinhalt));
    std::cout <<(testOk?"":"\033[38;5;1mtankinhalt falsch\033[m\n");
    allgood &= (testOk=(testClass->get_tankgroesse()==tankgroesse));
    std::cout <<(testOk?"":"\033[38;5;1mtankgroesse falsch\033[m\n");

    return allgood;
}

void tests(){
    
    bool allgood = true;
    bool testOk;
    bool subTestOk;
    int testNb= 0;

    int radzahl_l[] = {4,6,4,4,6,4,4};
    std::string farbe_l[] ={"Schwarz","Rot","Schwarz","Schwarz","Rot","Schwarz","Schwarz"};
    float ps_l[] ={200,100,200,200,100,200,200};
    int anzahl_sitze_l[] ={5,8,5,5,8,5,5};
    float spritverbrauch_l[] ={8,10,8,8,10,8,8};
    float tankinhalt_l[] ={80,50,40,0,50,30,80};
    float tankgroesse_l[] ={80,100,80,80,100,80,80};

    
    
    Auto test1 = Auto();
    allgood &= testOk = testClassValues(&test1,radzahl_l[testNb],farbe_l[testNb],ps_l[testNb],anzahl_sitze_l[testNb],spritverbrauch_l[testNb],tankinhalt_l[testNb],tankgroesse_l[testNb]);
    std::cout <<"Standard Konstruktor: " <<(testOk?"\033[38;5;2mpassed\033[m":"\033[38;5;1mfailed\033[m") << std::endl <<std::endl;

    ++testNb;
    Auto test2(6,"Rot",100,8,10,50,100);
    allgood &= testOk = testClassValues(&test2,radzahl_l[testNb],farbe_l[testNb],ps_l[testNb],anzahl_sitze_l[testNb],spritverbrauch_l[testNb],tankinhalt_l[testNb],tankgroesse_l[testNb]);
    std::cout <<"Allgemeiner Konstruktor: " <<(testOk?"\033[38;5;2mpassed\033[m":"\033[38;5;1mfailed\033[m") << std::endl << std::endl;

    ++testNb;
    allgood &= testOk = subTestOk =  test1.fahren(500)== 500;
    std::cout <<(subTestOk?"":"\033[38;5;1mfahren() return mit genug sprit falsch\033[m\n");
    allgood &= testOk &= subTestOk = testClassValues(&test1,radzahl_l[testNb],farbe_l[testNb],ps_l[testNb],anzahl_sitze_l[testNb],spritverbrauch_l[testNb],tankinhalt_l[testNb],tankgroesse_l[testNb]);
    ++testNb;
    allgood &= testOk &= subTestOk =  test1.fahren(1000)== 500;
    std::cout <<(subTestOk?"":"\033[38;5;1mfahren() return mit zu wenig sprit falsch\033[m\n");
    allgood &= testOk &= subTestOk = testClassValues(&test1,radzahl_l[testNb],farbe_l[testNb],ps_l[testNb],anzahl_sitze_l[testNb],spritverbrauch_l[testNb],tankinhalt_l[testNb],tankgroesse_l[testNb]);
    std::cout <<"fahren(): " <<(testOk?"\033[38;5;2mpassed\033[m":"\033[38;5;1mfailed\033[m") << std::endl << std::endl;

    ++testNb;
    Auto test3 = test2;
    allgood &= testOk = testClassValues(&test3,radzahl_l[testNb],farbe_l[testNb],ps_l[testNb],anzahl_sitze_l[testNb],spritverbrauch_l[testNb],tankinhalt_l[testNb],tankgroesse_l[testNb]);
    std::cout <<"Kopierkonstruktor: " <<(testOk?"\033[38;5;2mpassed\033[m":"\033[38;5;1mfailed\033[m") << std::endl << std::endl;

    ++testNb;
    test1.set_tankinhalt(30);
    allgood &= testOk = subTestOk = testClassValues(&test1,radzahl_l[testNb],farbe_l[testNb],ps_l[testNb],anzahl_sitze_l[testNb],spritverbrauch_l[testNb],tankinhalt_l[testNb],tankgroesse_l[testNb]);
    std::cout <<(subTestOk?"":"\033[38;5;1mset_tankinhalt() kleiner als tankgroesse falsch\033[m\n");
    ++testNb;
    test1.set_tankinhalt(300);
    allgood &= testOk &= subTestOk = testClassValues(&test1,radzahl_l[testNb],farbe_l[testNb],ps_l[testNb],anzahl_sitze_l[testNb],spritverbrauch_l[testNb],tankinhalt_l[testNb],tankgroesse_l[testNb]);
    std::cout <<(subTestOk?"":"\033[38;5;1mset_tankinhalt() größer als tankgroesse falsch\033[m\n");
    std::cout <<"set_tankinhalt(): " <<(testOk?"\033[38;5;2mpassed\033[m":"\033[38;5;1mfailed\033[m") << std::endl << std::endl;

    //Heap
    testNb= 0;
    Auto *test4 = new Auto();
    allgood &= testOk = testClassValues(test4,radzahl_l[testNb],farbe_l[testNb],ps_l[testNb],anzahl_sitze_l[testNb],spritverbrauch_l[testNb],tankinhalt_l[testNb],tankgroesse_l[testNb]);
    std::cout <<"Standard Konstruktor Heap: " <<(testOk?"\033[38;5;2mpassed\033[m":"\033[38;5;1mfailed\033[m") << std::endl <<std::endl;

    ++testNb;
    Auto *test5 = new Auto(6,"Rot",100,8,10,50,100);
    allgood &= testOk = testClassValues(test5,radzahl_l[testNb],farbe_l[testNb],ps_l[testNb],anzahl_sitze_l[testNb],spritverbrauch_l[testNb],tankinhalt_l[testNb],tankgroesse_l[testNb]);
    std::cout <<"Allgemeiner Konstruktor Heap: " <<(testOk?"\033[38;5;2mpassed\033[m":"\033[38;5;1mfailed\033[m") << std::endl << std::endl;

    ++testNb;
    allgood &= testOk = subTestOk =  test4->fahren(500)== 500;
    std::cout <<(subTestOk?"":"\033[38;5;1mfahren() return mit genug sprit falsch\033[m\n");
    allgood &= testOk &= subTestOk = testClassValues(test4,radzahl_l[testNb],farbe_l[testNb],ps_l[testNb],anzahl_sitze_l[testNb],spritverbrauch_l[testNb],tankinhalt_l[testNb],tankgroesse_l[testNb]);
    ++testNb;
    allgood &= testOk &= subTestOk =  test4->fahren(1000)== 500;
    std::cout <<(subTestOk?"":"\033[38;5;1mfahren() return mit zu wenig sprit falsch\033[m\n");
    allgood &= testOk &= subTestOk = testClassValues(test4,radzahl_l[testNb],farbe_l[testNb],ps_l[testNb],anzahl_sitze_l[testNb],spritverbrauch_l[testNb],tankinhalt_l[testNb],tankgroesse_l[testNb]);
    std::cout <<"fahren() Heap: " <<(testOk?"\033[38;5;2mpassed\033[m":"\033[38;5;1mfailed\033[m") << std::endl << std::endl;

    ++testNb;
    Auto * test6 = new Auto(*test5);
    allgood &= testOk = testClassValues(test6,radzahl_l[testNb],farbe_l[testNb],ps_l[testNb],anzahl_sitze_l[testNb],spritverbrauch_l[testNb],tankinhalt_l[testNb],tankgroesse_l[testNb]);
    std::cout <<"Kopierkonstruktor Heap: " <<(testOk?"\033[38;5;2mpassed\033[m":"\033[38;5;1mfailed\033[m") << std::endl << std::endl;

    ++testNb;
    test4->set_tankinhalt(30);
    allgood &= testOk = subTestOk = testClassValues(test4,radzahl_l[testNb],farbe_l[testNb],ps_l[testNb],anzahl_sitze_l[testNb],spritverbrauch_l[testNb],tankinhalt_l[testNb],tankgroesse_l[testNb]);
    std::cout <<(subTestOk?"":"\033[38;5;1mset_tankinhalt() kleiner als tankgroesse falsch\033[m\n");
    ++testNb;
    test4->set_tankinhalt(300);
    allgood &= testOk &= subTestOk = testClassValues(test4,radzahl_l[testNb],farbe_l[testNb],ps_l[testNb],anzahl_sitze_l[testNb],spritverbrauch_l[testNb],tankinhalt_l[testNb],tankgroesse_l[testNb]);
    std::cout <<(subTestOk?"":"\033[38;5;1mset_tankinhalt() größer als tankgroesse falsch\033[m\n");
    std::cout <<"set_tankinhalt() Heap: " <<(testOk?"\033[38;5;2mpassed\033[m":"\033[38;5;1mfailed\033[m") << std::endl << std::endl;

    delete test4;
    delete test5;
    delete test6;

    //Global bzw Datensegment

    testNb = 0;

    allgood &= testOk = testClassValues(&test7,radzahl_l[testNb],farbe_l[testNb],ps_l[testNb],anzahl_sitze_l[testNb],spritverbrauch_l[testNb],tankinhalt_l[testNb],tankgroesse_l[testNb]);
    std::cout <<"Standard Konstruktor Global: " <<(testOk?"\033[38;5;2mpassed\033[m":"\033[38;5;1mfailed\033[m") << std::endl <<std::endl;

    ++testNb;
    allgood &= testOk = testClassValues(&test8,radzahl_l[testNb],farbe_l[testNb],ps_l[testNb],anzahl_sitze_l[testNb],spritverbrauch_l[testNb],tankinhalt_l[testNb],tankgroesse_l[testNb]);
    std::cout <<"Allgemeiner Konstruktor Global: " <<(testOk?"\033[38;5;2mpassed\033[m":"\033[38;5;1mfailed\033[m") << std::endl << std::endl;

    ++testNb;
    allgood &= testOk = subTestOk =  test7.fahren(500)== 500;
    std::cout <<(subTestOk?"":"\033[38;5;1mfahren() return mit genug sprit falsch\033[m\n");
    allgood &= testOk &= subTestOk = testClassValues(&test7,radzahl_l[testNb],farbe_l[testNb],ps_l[testNb],anzahl_sitze_l[testNb],spritverbrauch_l[testNb],tankinhalt_l[testNb],tankgroesse_l[testNb]);
    ++testNb;
    allgood &= testOk &= subTestOk =  test7.fahren(1000)== 500;
    std::cout <<(subTestOk?"":"\033[38;5;1mfahren() return mit zu wenig sprit falsch\033[m\n");
    allgood &= testOk &= subTestOk = testClassValues(&test7,radzahl_l[testNb],farbe_l[testNb],ps_l[testNb],anzahl_sitze_l[testNb],spritverbrauch_l[testNb],tankinhalt_l[testNb],tankgroesse_l[testNb]);
    std::cout <<"fahren() Global: " <<(testOk?"\033[38;5;2mpassed\033[m":"\033[38;5;1mfailed\033[m") << std::endl << std::endl;

    ++testNb;
    allgood &= testOk = testClassValues(&test9,radzahl_l[testNb],farbe_l[testNb],ps_l[testNb],anzahl_sitze_l[testNb],spritverbrauch_l[testNb],tankinhalt_l[testNb],tankgroesse_l[testNb]);
    std::cout <<"Kopierkonstruktor Global: " <<(testOk?"\033[38;5;2mpassed\033[m":"\033[38;5;1mfailed\033[m") << std::endl << std::endl;

    ++testNb;
    test7.set_tankinhalt(30);
    allgood &= testOk = subTestOk = testClassValues(&test7,radzahl_l[testNb],farbe_l[testNb],ps_l[testNb],anzahl_sitze_l[testNb],spritverbrauch_l[testNb],tankinhalt_l[testNb],tankgroesse_l[testNb]);
    std::cout <<(subTestOk?"":"\033[38;5;1mset_tankinhalt() kleiner als tankgroesse falsch\033[m\n");
    ++testNb;
    test7.set_tankinhalt(300);
    allgood &= testOk &= subTestOk = testClassValues(&test7,radzahl_l[testNb],farbe_l[testNb],ps_l[testNb],anzahl_sitze_l[testNb],spritverbrauch_l[testNb],tankinhalt_l[testNb],tankgroesse_l[testNb]);
    std::cout <<(subTestOk?"":"\033[38;5;1mset_tankinhalt() größer als tankgroesse falsch\033[m\n");
    std::cout <<"set_tankinhalt() Global: " <<(testOk?"\033[38;5;2mpassed\033[m":"\033[38;5;1mfailed\033[m") << std::endl << std::endl;


    std::cout <<(allgood?"\033[38;5;2mTests passed\033[m":"\033[38;5;1mTests failed\033[m") << std::endl;


}

int main(int argc, char const *argv[])
{
    tests();
    return 0;
}
