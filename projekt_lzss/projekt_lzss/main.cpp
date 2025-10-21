/** @file */
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "sprawdzenie_poprawnosci.h"
#include "program.h"
#include "struktura.h"

int main(int argc, char* argv[]) {
	std::string plik_wejsciowy;
	std::string plik_wyjsciowy;
	std::string tryb; //kompresja czy dekompresja
	std::string rozmiar_bufora_wejsciowego_s; //maks. d³ugoœæ dopasywania, to po prawej       jeszcze w stringu
	std::string rozmiar_bufora_historii_s; //to po lewej, inaczej s³ownik					jeszcze w stringu

	uruchomienie(argc, argv, plik_wejsciowy, plik_wyjsciowy, tryb, rozmiar_bufora_wejsciowego_s, rozmiar_bufora_historii_s);

	std::stringstream ss1(rozmiar_bufora_wejsciowego_s); //do int
	std::stringstream ss2(rozmiar_bufora_historii_s);
	int rozmiar_bufora_wejsciowego_i, rozmiar_bufora_historii_i;
	ss1 >> rozmiar_bufora_wejsciowego_i;
	ss2 >> rozmiar_bufora_historii_i;
	std::stringstream ss3(rozmiar_bufora_wejsciowego_s); //do unsigned int
	std::stringstream ss4(rozmiar_bufora_historii_s);

	sprawdzenie_poprawnosci(plik_wejsciowy, plik_wyjsciowy, tryb, rozmiar_bufora_wejsciowego_i, rozmiar_bufora_historii_i);

	unsigned int rozmiar_bufora_wejsciowego, rozmiar_bufora_historii;
	ss3 >> rozmiar_bufora_wejsciowego;
	ss4 >> rozmiar_bufora_historii;

	konfiguracja config = { plik_wejsciowy, plik_wyjsciowy, tryb, rozmiar_bufora_wejsciowego, rozmiar_bufora_historii };
	
	kompresja_dekompresja(config);

	std::cout << "Operacja wykonana pomyœlnie!";
	return 0;
}