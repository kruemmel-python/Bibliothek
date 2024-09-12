#include "benutzer.hpp"
#include <iostream>

// Funktion zur Anzeige der Benutzerinformationen
void benutzerAnzeigen(const Benutzer& benutzer) {
    std::cout << "Benutzername: " << benutzer.name << std::endl;
    std::cout << "Benutzer-ID: " << benutzer.id << std::endl;
    std::cout << "---------------------" << std::endl;
}
