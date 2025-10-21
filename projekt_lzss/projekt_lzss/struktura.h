/** @file */

#ifndef STRUKTURY_H  // zabezpieczenie przed wielokrotnym dolaczaniem pliku naglowkowego
#define STRUKTURY_H

#include <vector> 
#include <string>

/** Struktura glownych zmiennych konfiguracyjnych
 * @param plik_wejsciowy zawiera nazwe pliku wejsciowego
 * @param plik_wyjsciowy zawiera nazwe pliku wyjsciowego
 * @param tryb zawiera, czy uzytkownik chce kompresje czy dekompresje pliku
 * @param rozmiar_bufora_wejsciowego zawiera jaki rozmiar ma miec bufor wejsciowy
 * @param rozmiar_bufora_historii zawiera jaki rozmiar ma miec bufor historii
 * @date 2025-02-02
 * @author Dyba
 *	*/
struct konfiguracja {
	std::string plik_wejsciowy;
	std::string plik_wyjsciowy;
	std::string tryb; //kompresja czy dekompresja
	unsigned int rozmiar_bufora_wejsciowego; //maks. dlugosc dopasywania, to po prawej       jeszcze w stringu
	unsigned int rozmiar_bufora_historii; //to po lewej, inaczej slownik					jeszcze w stringu
};

#endif
