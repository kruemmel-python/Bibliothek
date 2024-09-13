#pragma once
#include <string>

struct Benutzer {
    std::string name;
    const int id;  // ID des Benutzers

    // Konstruktor zum Erstellen eines Benutzers
    Benutzer(const std::string& name, int id) : name(name), id(id) {}
};

// Funktionsdeklarationen für Benutzer
void benutzerAnzeigen(const Benutzer& benutzer);
