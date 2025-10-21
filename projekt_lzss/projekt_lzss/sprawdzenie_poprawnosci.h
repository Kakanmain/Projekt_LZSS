/** @file */
#ifndef SPRAWDZENIE_POPRAWNOSCI_H
#define SPRAWDZENIE_POPRAWNOSCI_H


//std::string uruchomienie(int argc, char* argv[]);

/** Funkcja odczytuje przelaczniki i argumenty podane przez uzytkownika
 *	Pozniej zapisuje je do zmiennych.
 * @param argc Liczba argumentow
 * @param argv[] Zawiera poszczegolne argumenty przekazane do programu
 * @param plik_wejsciowy zawiera plik wejsciowy
 * @param plik_wyjsciowy zawiera plik wyjsciowy 
 * @param tryb zawiera czy program ma robic kompresje, czy dekompresje
 * @param rozmiar_bufora_wejsciowego zawiera jaki rozmiar ma miec bufor wejsciowy
 * @param rozmiar_bufora_historii zawiera jaki rozmiar ma miec bufor historii
 * @date 2025-01-02
 * @author Dyba 
 *	*/
void uruchomienie(int argc, char* argv[], std::string& plik_wejsciowy, std::string& plik_wyjsciowy, std::string& tryb, std::string& rozmiar_bufora_wejsciowego_s, std::string& rozmiar_bufora_historii_s);

/** Sprawdza poprawnosc argumentow wprowadzonych przez uzytkownika
 * @param plik_wejsciowy zawiera plik wejsciowy
 * @param plik_wyjsciowy zawiera plik wyjsciowy
 * @param tryb zawiera czy program ma robic kompresje, czy dekompresje
 * @param rozmiar_bufora_wejsciowego zawiera jaki rozmiar ma miec bufor wejsciowy
 * @param rozmiar_bufora_historii zawiera jaki rozmiar ma miec bufor historii
 * @date 2025-01-03
 * @author Dyba
 *	*/
void sprawdzenie_poprawnosci(std::string& plik_wejsciowy, std::string& plik_wyjsciowy, std::string& tryb, int& rozmiar_bufora_wejsciowego_i, int& rozmiar_bufora_historii_i);

#endif