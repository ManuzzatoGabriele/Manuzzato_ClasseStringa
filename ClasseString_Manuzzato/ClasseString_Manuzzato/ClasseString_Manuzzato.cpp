#include <iostream>
#include "Stringa.h"
using namespace std;

int main()
{
    cout << "Inserire stringa da creare:\n";
	char buffer[1000];
	cin.getline(buffer, 1000);
	Stringa str(buffer);
	cout << "Stringa creata: ";
	str.Stampa();
	cout << "\nDimensione: " << str.CalcolaDimensione() << endl;
	cout << "Stringa invertita: ";
	Stringa rev = str.Reverse();
	rev.Stampa();
	cout << "Stringa con maiuscole/minuscole invertite: ";
	Stringa flip = str.Flip();
	flip.Stampa();
	cout << "La stringa e' palindroma? " << (str.Palindroma() ? "Si" : "No") << endl;
	return 0;
}
