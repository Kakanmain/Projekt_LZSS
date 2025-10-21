/** @file */
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>

#include "sprawdzenie_poprawnosci.h"

void uruchomienie(int argc, char* argv[], std::string& plik_wejsciowy, std::string& plik_wyjsciowy, std::string& tryb, std::string& rozmiar_bufora_wejsciowego_s, std::string& rozmiar_bufora_historii_s) {
	if (argc == 1) { //Gdy nic nie jest wpisane przy uruchomieniu
		std::string slowo = "Napisz co zrobic z programem: -i 'plik wejsciowy' -o 'plik wyjsciowy' -t ('c': kompresja lub 'd': dekompresja) -n 'rozmiar bufora wejsciowego'(musi byc wiekszy niz 0) -k 'rozmiar bufora historii'(musi byc wiekszy niz 0)";
	
		std::cout<<slowo<<std::endl;

		std::exit(1);
	}
	else if (argc == 11) { //gdy wszystko jest wpisane, czyli 10 argumentów (niekoniecznie dobrych) 
		for (int i = 1; i < argc; ++i) {
			std::string arg = argv[i];

			if (arg == "-i") {
				plik_wejsciowy = argv[++i];
			}
			else if (arg == "-o") {
				plik_wyjsciowy = argv[++i];
			}
			else if (arg == "-t") {
				tryb = argv[++i];
			}
			else if (arg == "-n") {
				rozmiar_bufora_wejsciowego_s = argv[++i];
			}
			else if (arg == "-k") {
				rozmiar_bufora_historii_s = argv[++i];
			}
			else {
				std::string slowo1 = "Nieprawidlowy przelacznik: ";
				std::string znak = argv[i];
				std::string slowo2 = ", uruchom program ponownie z poprawionym przelacznikiem";
				std::string slowo = slowo1 + znak + slowo2;

				std::cout << slowo << std::endl;

				std::exit(1);
			}
		}
	}
	else { //gdy nie ma 10 argumentów
		std::string slowo = "Napisz co zrobic z programem: -i 'plik wejsciowy' -o 'plik wyjsciowy' -t ('c': kompresja lub 'd': dekompresja) -n 'rozmiar bufora wejsciowego'(musi byc wiekszy niz 0) -k 'rozmiar bufora historii'(musi byc wiekszy niz 0)";

		std::cout << slowo << std::endl;

		std::exit(1);
	}

	for (int i = 1; i < argc; ++i) { //wypisuje argumenty, potem do usuniêcia
		std::cout << std::string(argv[i]) << " ";
		std::cout << "" << std::endl;
	}
}


void sprawdzenie_poprawnosci(std::string& plik_wejsciowy, std::string& plik_wyjsciowy, std::string& tryb, int& rozmiar_bufora_wejsciowego_i, int& rozmiar_bufora_historii_i) {
	int b³¹d = 0;
	//1 plik_wejsciowy
	std::ifstream strumien_wejsciowy(plik_wejsciowy);
	if (not strumien_wejsciowy) {
		std::cout << "Blad otwierania pliku wejsciowego: " << plik_wejsciowy << ", sprawdz poprwanosc nazwy pliku, czy jest folderze i czy istnieje." << std::endl;
		b³¹d++;
	}

	//2 plik_wyjsciowy	
	std::string odp;
	std::ifstream strumien_wyjsciowy(plik_wyjsciowy);
	if (not strumien_wyjsciowy) {
		std::cout << "Podany plik wyjsciowy nie istnieje, czy mam go utowrzyc? (t: tak, n: nie)" << std::endl;
		std::cin >> odp;
		if (odp == "t" || odp == "tak") {
			std::ofstream strumien_wyjsciowy(plik_wyjsciowy);
			std::cout << "Plik zostal utworzony!" << std::endl;
		}
		else {
			std::cout << "Blad otwierania pliku wyjsciowego: " << plik_wyjsciowy << ", sprawdz poprwanosc nazwy pliku, czy jest folderze i czy istnieje." << std::endl;
		}
	}

	//3 tryb
	if (tryb == "c" || tryb == "d") { // Czy wpisano dobry tryb
		
	}
	else {
		std::cout << "Zly argument: " << tryb << ", podaj poprawny (c: kompresja lub d: dekompresja)" << std::endl;
		b³¹d++;
	}

	//4 rozmiar_bufora_wejsciowego
	if (rozmiar_bufora_wejsciowego_i <= 0) {
		std::cout << "Rozmiar bufora wejsciowego nie moze byc mniejszy lub rowny zero!" << std::endl;
		b³¹d++;
	}

	//5 rozmiar_bufora_historii
	if (rozmiar_bufora_historii_i <= 0) {
		std::cout << "Rozmiar bufora historii nie moze byc mniejszy lub rowny zero!" << std::endl;
		b³¹d++;
	}

	//b³êdy
	if (b³¹d > 0) {
		std::cout << "Ilosc bledow: " << b³¹d << ". Popraw je i uruchom program ponownie." << std::endl;
		std::exit(1);
	}
}



