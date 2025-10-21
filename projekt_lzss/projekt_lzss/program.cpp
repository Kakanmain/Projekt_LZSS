/** @file */
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <algorithm>

#include "program.h"
#include "struktura.h"

void przesun_bufor_historii(std::vector<std::string>& bufor_wejsciowy, std::vector<std::string>& bufor_historii, unsigned int ile, const konfiguracja& config, const int& indeks) {
	for (int j = 0; j < ile && j < bufor_wejsciowy.size(); j++) {
		std::rotate(bufor_historii.rbegin(), bufor_historii.rbegin() + 1, bufor_historii.rend()); //przesuniêcie w prawo
		if (config.tryb == "c") {
			bufor_historii[0] = bufor_wejsciowy[j];
		}
		else if(config.tryb == "d" && ile == 1) {
			bufor_historii[0] = bufor_wejsciowy[1];
		}
		else {
			bufor_historii[0] = bufor_historii[indeks+1];
		}
	}
}

void przesun_bufor_wejsciowy(std::vector<std::string>& bufor_wejsciowy, unsigned int ile, const konfiguracja& config, int& licznik_znaków) {
	char znak = 0;
	int tmp = 0;
	std::ifstream wejscie (config.plik_wejsciowy);
	wejscie.seekg(licznik_znaków+1, std::ios::beg);
	if (wejscie) {
		while (wejscie.get(znak) && tmp < ile) {
			bufor_wejsciowy[tmp] = std::string(1, znak);
			tmp++;
		}
	}

	if (tmp == 0) {
		for (int j = 0; j < ile; j++) {
			std::rotate(bufor_wejsciowy.begin(), bufor_wejsciowy.begin() + 1, bufor_wejsciowy.end());
			bufor_wejsciowy.pop_back();
		}
	}
	else {
		int j = 0;
		for (j; j < ile && tmp > 0; j++) {
			std::rotate(bufor_wejsciowy.begin(), bufor_wejsciowy.begin() + 1, bufor_wejsciowy.end());
			licznik_znaków++;
			tmp--;
		}
		for (j; j < ile; j++) {
			std::rotate(bufor_wejsciowy.begin(), bufor_wejsciowy.begin() + 1, bufor_wejsciowy.end());
			bufor_wejsciowy.pop_back();
		}
	}
}

void kompresja(std::vector<std::string>& bufor_wejsciowy, std::vector<std::string>& bufor_historii, const konfiguracja& config, int& licznik_znaków) {
	std::ofstream wyjscie (config.plik_wyjsciowy);
	if (wyjscie) {
		while (!bufor_wejsciowy.empty()) {
			int licz1 = 0;
			int licz3 = 0;
			std::vector<int> tmp_v;
			for (int y = 0; y < bufor_historii.size(); y++) {
				int licz2 = 0;
				if (bufor_wejsciowy[0] != bufor_historii[y] && licz3 == 0) {
					licz1++;
					if (licz1 == bufor_historii.size()) {
						wyjscie << "1" << bufor_wejsciowy[0];
						przesun_bufor_historii(bufor_wejsciowy, bufor_historii, 1, config, 0);
						przesun_bufor_wejsciowy(bufor_wejsciowy, 1, config, licznik_znaków); //przesuwa okienka vektora o 1
					}
				}
				else if (bufor_wejsciowy[0] == bufor_historii[y]) {
					for (int i = 0; (y - i) >= 0 && (0 + i) < bufor_wejsciowy.size() && bufor_wejsciowy[0 + i] == bufor_historii[y - i]; i++) {
						licz2++;
						licz3++;
					}
					tmp_v.push_back(y);
					tmp_v.push_back(licz2);
				} else {
					if (y == bufor_historii.size() - 1) {
						int max = tmp_v[1];
						int y_max = tmp_v[0];;
						for (int i = 1; i <= tmp_v.size(); i += 2) {
							if (tmp_v[i] > max) {
								max = tmp_v[i];
								y_max = tmp_v[i-1];
							}
						}
						if (max == 1) {
							wyjscie << "1" << bufor_wejsciowy[0]; 
							przesun_bufor_historii(bufor_wejsciowy, bufor_historii, 1, config, 0);
							przesun_bufor_wejsciowy(bufor_wejsciowy, 1, config, licznik_znaków);
							break;
						}
						else {
							wyjscie << "0(" << y_max << "," << max << ")";
							przesun_bufor_historii(bufor_wejsciowy, bufor_historii, max, config, 0);
							przesun_bufor_wejsciowy(bufor_wejsciowy, max, config, licznik_znaków);
							std::cout << "";
							break;
						}
					}
				}
			}
		}
	}
}

void dekompresja(std::vector<std::string>& bufor_wejsciowy, std::vector<std::string>& bufor_historii, const konfiguracja& config, int& licznik_znaków) {
	std::ofstream wyjscie(config.plik_wyjsciowy);
	if (wyjscie) {
		while (!bufor_wejsciowy.empty()) {
			if (bufor_wejsciowy[0] == "1") {
				wyjscie << bufor_wejsciowy[1];
				przesun_bufor_historii(bufor_wejsciowy, bufor_historii, 1, config, 0);
				przesun_bufor_wejsciowy(bufor_wejsciowy, 2, config, licznik_znaków);
			}
			else if (bufor_wejsciowy[0] == "0") {
				std::string indeks_z = bufor_wejsciowy[2];
				std::string dlugosc_z = bufor_wejsciowy[4];
				int indeks, dlugosc;
				std::stringstream ss1(bufor_wejsciowy[2]);
				std::stringstream ss2(bufor_wejsciowy[4]);
				ss1 >> indeks;
				ss2 >> dlugosc;
				int d = dlugosc;

				for (int i = indeks; i >= 0 && d > 0; i--) {
					wyjscie << bufor_historii[i];
					d--;
				}
				przesun_bufor_historii(bufor_wejsciowy, bufor_historii, dlugosc, config, indeks);
				przesun_bufor_wejsciowy(bufor_wejsciowy, 6, config, licznik_znaków);
			}
			else {
				bufor_wejsciowy.clear();
			}
		}
	}
}

void kompresja_dekompresja(const konfiguracja& config) {

	std::vector<std::string> bufor_wejsciowy(config.rozmiar_bufora_wejsciowego);
	std::vector<std::string> bufor_historii(config.rozmiar_bufora_historii);
	char znak;
	int licznik_znaków = 0; //liczy ile znaków z pliku ju¿ mine³o
	std::string liczba_string;

	std::ifstream wejscie(config.plik_wejsciowy);
	std::ofstream wyjscie(config.plik_wyjsciowy);
	if (wejscie and wyjscie) {
		bool w_nawiasie = false;
		std::string liczba_bufor = "";

		while (wejscie.get(znak) && licznik_znaków < config.rozmiar_bufora_wejsciowego) {
			liczba_string = std::string(1, znak);

			if (config.tryb == "c") {
				bufor_wejsciowy[licznik_znaków] = liczba_string;
				licznik_znaków++;
			}
			else {
				if (liczba_string == "(") {
					w_nawiasie = true;
					bufor_wejsciowy[licznik_znaków] = liczba_string;
					licznik_znaków++;
				}
				else if (liczba_string == ")" || liczba_string == ",") {
					if (!liczba_bufor.empty()) {
						bufor_wejsciowy[licznik_znaków] = liczba_bufor;
						licznik_znaków++;
						liczba_bufor = "";
					}
					bufor_wejsciowy[licznik_znaków] = liczba_string;
					licznik_znaków++;
					if (liczba_string == ")") {
						w_nawiasie = false;  
					}
				}
				else if (w_nawiasie) {
					liczba_bufor += liczba_string; 
				}
				else {
					bufor_wejsciowy[licznik_znaków] = liczba_string;
					licznik_znaków++;
				}
			}
		}
		if (!liczba_bufor.empty()) {
			bufor_wejsciowy[licznik_znaków] = liczba_bufor;
			licznik_znaków++;
		}

		while (bufor_wejsciowy.size() > licznik_znaków) {
			bufor_wejsciowy.pop_back();
		}

		if (config.tryb == "c") { //kompresja
			kompresja(bufor_wejsciowy, bufor_historii, config, licznik_znaków);
		}
		else { //dekompresja
			dekompresja(bufor_wejsciowy, bufor_historii, config, licznik_znaków);
		}
	}
}