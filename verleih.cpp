#include "verleih.hpp"
#include <iostream>

// Funktion zum Verleihen eines Buches
void buchVerleihProzess(std::vector<Buch>& buchSammlung, std::vector<Benutzer>& benutzerSammlung, int buchId, int benutzerId) {
    bool buchGefunden = false;
    bool benutzerGefunden = false;

    for (auto& buch : buchSammlung) {
        if (buch.id == buchId) {
            buchGefunden = true;
            for (const auto& benutzer : benutzerSammlung) {
                if (benutzer.id == benutzerId) {
                    benutzerGefunden = true;
                    buchVerleihen(buch, benutzer);  // Verleiht das Buch an den Benutzer
                    break;
                }
            }
            break;
        }
    }

    if (!buchGefunden) {
        std::cout << "Buch mit ID " << buchId << " wurde nicht gefunden.\n";
    }
    if (!benutzerGefunden) {
        std::cout << "Benutzer mit ID " << benutzerId << " wurde nicht gefunden.\n";
    }
}

// Funktion zum Zurückgeben eines Buches
void buchRueckgabeProzess(std::vector<Buch>& buchSammlung, int buchId) {
    bool gefunden = false;

    for (auto& buch : buchSammlung) {
        if (buch.id == buchId) {
            if (buch.istVerliehen) {
                buchZurueckgeben(buch);  // Ruft die Rückgabefunktion auf
                gefunden = true;
            }
            else {
                std::cout << "Das Buch '" << buch.titel << "' war nicht verliehen.\n";
            }
            break;
        }
    }

    if (!gefunden) {
        std::cout << "Buch mit ID " << buchId << " wurde nicht gefunden.\n";
    }
}
