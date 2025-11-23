#include "Stringa.h"

Stringa::Stringa(const char* str)
{
	dimensione = 0;

	while (str[dimensione] != '\0')
		dimensione++;

	contenuto = new char[dimensione + 1];

	for (int i = 0; i < dimensione; i++)
		contenuto[i] = str[i];

	contenuto[dimensione] = '\0';
}

Stringa::Stringa()
{
	dimensione = 0;
	contenuto = new char[1];
	contenuto[0] = '\0';
}

int Stringa::CalcolaDimensione()
{
	return dimensione;
}

Stringa::~Stringa()
{
	delete[] contenuto;
}

void Stringa::Stampa()
{
	for (int i = 0; i < dimensione; i++)
		cout << contenuto[i];
	cout << endl;
}

Stringa Stringa::Reverse()
{
	char* rev = new char[dimensione + 1];
	for (int i = 0; i < dimensione; i++)
		rev[i] = contenuto[dimensione - 1 - i];

	rev[dimensione] = '\0';
	return Stringa(rev);
}

Stringa Stringa::Flip()
{
	char* flip = new char[dimensione + 1];
	for (int i = 0; i < dimensione; i++)
	{
		if (contenuto[i] >= 'a' && contenuto[i] <= 'z')
			flip[i] = contenuto[i] - ('a' - 'A');
		else if (contenuto[i] >= 'A' && contenuto[i] <= 'Z')
			flip[i] = contenuto[i] + ('a' - 'A');
		else
			flip[i] = contenuto[i];
	}

	flip[dimensione] = '\0';
	return Stringa(flip);
}

bool Stringa::Palindroma()
{
	for (int i = 0; i < dimensione / 2; i++)
	{
		if (contenuto[i] != contenuto[dimensione - 1 - i])
			return false;
	}
	return true;
}

bool Stringa::operator==(const Stringa& other)
{
	if (dimensione != other.dimensione)
		return false;
	for (int i = 0; i < dimensione; i++)
	{
		if (contenuto[i] != other.contenuto[i])
			return false;
	}
	return true;
}

Stringa Stringa::operator+(const Stringa& other)
{
	char* newStr = new char[dimensione + other.dimensione + 1];
	for (int i = 0; i < dimensione; i++)
		newStr[i] = contenuto[i];

	for (int i = 0; i < other.dimensione; i++)
		newStr[dimensione + i] = other.contenuto[i];

	newStr[dimensione + other.dimensione] = '\0';
	return Stringa(newStr);
}