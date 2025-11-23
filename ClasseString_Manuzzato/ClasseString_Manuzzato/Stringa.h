#pragma once
#include <iostream>
using namespace std;
#include "Struttura.h"

class Stringa : public Struttura
{
	private:
		char* contenuto;
	public:
		Stringa(const char* str);
		Stringa();
		int CalcolaDimensione() override;
		~Stringa();
		void Stampa();
		Stringa Reverse();
		Stringa Flip();
		bool Palindroma();

		bool operator==(const Stringa& other);
		Stringa operator+(const Stringa& other);
		
};






