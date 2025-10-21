/** @file */
#ifndef PROGRAM_H
#define PROGRAM_H

#include "struktura.h"

/** Przeprowadza kompresje danych
 * @param bufor_wejsciowy zawiera wektor bufora wejsciowego
 * @param bufor_historii zawiera wektor bufora historii
 * @param ile zawiera o ile przesunac bufor wejsciowy 
 * @param config struktura glownych zmiennych konfiguracyjnych
 * @param indeks zawiera indeks bufora historii dla dekompresjii
 * @date 2025-02-01
 * @author Dyba
 *	*/
void przesun_bufor_historii(std::vector<std::string>& bufor_wejsciowy, std::vector<std::string>& bufor_historii, unsigned int ile, const konfiguracja& config, const int& indeks);

/** Przesuwa bufor wejsciowy
 * @param bufor_wejsciowy zawiera wektor bufora wejsciowego
 * @param ile zaiera o ile przesunac bufor wejsciowy 
 * @param config struktura glownych zmiennych konfiguracyjnych
 * @param licznik_znakow zawiera ile znakow z pliku wejsciowego zostalo obsluzonych
 * @date 2025-02-01
 * @author Dyba
 *	*/
void przesun_bufor_wejsciowy(std::vector<std::string>& bufor_wejsciowy, unsigned int ile, const konfiguracja& config, int& licznik_znakow);

/** Przeprowadza kompresje danych
 * @param bufor_wejsciowy zawiera wektor bufora wejsciowego
 * @param bufor_historii zawiera wektor bufora historii
 * @param config struktura glownych zmiennych konfiguracyjnych
 * @param licznik_znakow zawiera ile znakow z pliku wejsciowego zostalo obsluzonych
 * @date 2025-02-01
 * @author Dyba
 *	*/
void kompresja(std::vector<std::string>& bufor_wejsciowy, std::vector<std::string>& bufor_historii, const konfiguracja& config, int& licznik_znakow);

/** Przeprowadza kompresje danych
 * @param bufor_wejsciowy zawiera wektor bufora wejsciowego
 * @param bufor_historii zawiera wektor bufora historii
 * @param config struktura glownych zmiennych konfiguracyjnych
 * @param licznik_znakow zawiera ile znakow z pliku wejsciowego zostalo obsluzonych
 * @date 2025-02-02
 * @author Dyba
 *	*/
void dekompresja(std::vector<std::string>& bufor_wejsciowy, std::vector<std::string>& bufor_historii, const konfiguracja& config, int& licznik_znakow);

/** Przeprowadza kompresje lub dekompresje danych
 * @param config struktura glownych zmiennych konfiguracyjnych
 * @date 2025-02-01
 * @author Dyba
 *	*/
void kompresja_dekompresja(const konfiguracja& config);

//const std::string& plik_wejsciowy, const std::string& plik_wyjsciowy, const std::string& tryb, const unsigned int& rozmiar_bufora_wejsciowego, const unsigned int& rozmiar_bufora_historii
#endif