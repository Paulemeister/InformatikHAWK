#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class komplex
{
	double re;
	double im;

public:
	komplex(float Re, float Im) : re{Re}, im{Im} {} //allgemeiner Konstruktor

	float get_re() { return re; }
	float get_im() { return im; }
	void set_re(float Re) { re = Re; }
	void set_im(float Im) { im = Im; } //Getter und Setter Methoden

	komplex operator+(komplex &A1) //Übergabe der Referenz der Klass
	{							   //NeuDefenition von +
		return komplex(re + A1.re, im + A1.im);
	}

	komplex operator-(komplex &A1)
	{
		return komplex(re - A1.re, im - A1.im);
	}

	komplex operator/(komplex &A1)
	{
		try //Falls nachfolgende Funktion einen Fehelr auftritt, wird ein Fehler ausgeworfen, der von der catch funktion aufgefangen werden sollte.
		{
			if (A1.re == 0 && A1.im == 0)
			{
				throw invalid_argument("Division durch 0");
			}

			return komplex((re * A1.re + im * A1.im) / (pow(A1.re, 2) + pow(A1.im, 2)),
						   (im * A1.re - re * A1.im) / ((pow(A1.re, 2) + pow(A1.im, 2))));
		}

		catch (invalid_argument &e) //auffangen des fehlers invalid argument
		{
			cout << e.what() << endl; //hier sollte dann stehen, was passiert ist
		}
	}
};

ostream &operator<<(ostream &s, komplex &A1)
{
	s << A1.get_re() << " + " << A1.get_im() << "*i";
	return s;
}

istream &operator>>(istream &s, komplex &A1)
{
	float temp;
	cout << "Re: ";
	s >> temp;
	A1.set_re(temp);
	cout << "Im: ";
	s >> temp;
	A1.set_im(temp);
	return s;
}

int main()
{
	komplex A1{1, 2}; //Aufruf Allgemeiner Konstruktor

	komplex B1{3, 4};
	komplex F1{0, 0};
	komplex H1{7, 8};
	komplex C1 = A1 + B1;
	komplex D1 = B1 - A1;
	komplex E1 = A1 / B1;
	komplex G1 = H1 / F1;

	cout << A1 << endl;
	cout << B1 << endl;
	cout << C1 << endl;
	cout << D1 << endl;
	cout << E1 << endl;

	cin >> C1;
	cout << C1 << endl;

	return 0;
}