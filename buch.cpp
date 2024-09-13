#include "buch.hpp"
#include <iostream>

// Funktion zur Beschreibung eines Buches
void buchBeschreiben(Buch& buch, const std::string& titel, const std::string& autor, int id) {
    buch.titel = titel;
    buch.autor = autor;
    buch.id = id;
    buch.istVerliehen = false;  // Standardmaeßig nicht verliehen
    buch.verliehenAn = nullptr; // Kein Benutzer hat es ausgeliehen

    // DEBUG: Ausgabe zum Überprüfen der Werte
    //std::cout << "DEBUG: Buch wird beschrieben - Titel: " << titel << ", Autor: " << autor << ", ID: " << id << "\n";
}


// Funktion zur Anzeige der Buchinformationen
void buchAnzeigen(const Buch& buch) {
    std::cout << "Titel: " << buch.titel << std::endl;
    std::cout << "Autor: " << buch.autor << std::endl;
    std::cout << "ID: " << buch.id << std::endl;
    std::cout << "Verleihstatus: " << (buch.istVerliehen ? "Verliehen" : "Nicht verliehen") << std::endl;

    if (buch.istVerliehen && buch.verliehenAn != nullptr) {
        std::cout << "Verliehen an: " << buch.verliehenAn->name << " (ID: " << buch.verliehenAn->id << ")" << std::endl;
    }
}

// Funktion zum Verleihen eines Buches an einen Benutzer
void buchVerleihen(Buch& buch, const Benutzer& benutzer) {
    if (!buch.istVerliehen) {
        buch.istVerliehen = true;
        buch.verliehenAn = &benutzer;
       // std::cout << "DEBUG: Das Buch '" << buch.titel << "' wurde an " << benutzer.name << " (ID: " << benutzer.id << ") verliehen.\n";
    }
    else {
        std::cout << "Fehler: Das Buch '" << buch.titel << "' ist bereits verliehen.\n";
    }
}

// Funktion zur Rueckgabe eines Buches
void buchZurueckgeben(Buch& buch) {
    if (buch.istVerliehen && buch.verliehenAn != nullptr) {
        std::cout << "Das Buch '" << buch.titel << "' wurde von " << buch.verliehenAn->name << " zurueckgegeben.\n";
        buch.istVerliehen = false;
        buch.verliehenAn = nullptr;  // Verweis auf den Benutzer entfernen
    }
    else {
        std::cout << "Fehler: Das Buch '" << buch.titel << "' war nicht verliehen.\n";
    }
}


// Funktion zum Hinzufuegen eines Buches zur Sammlung
void buchHinzufuegen(std::vector<Buch>& sammlung, const std::string& titel, const std::string& autor, int id) {
    // Pruefen, ob ein Buch mit der gleichen ID bereits in der Sammlung existiert
    for (const auto& buch : sammlung) {
        if (buch.id == id) {
            std::cout << "Fehler: Ein Buch mit der ID " << id << " existiert bereits in der Sammlung.\n";
            return;  // Beenden, wenn das Buch bereits existiert
        }
    }

    // Wenn kein Buch mit der ID existiert, hinzufuegen
    Buch neuesBuch;
    buchBeschreiben(neuesBuch, titel, autor, id);
    sammlung.push_back(neuesBuch);
    std::cout << "Das Buch '" << titel << "' wurde erfolgreich zur Sammlung hinzugefuegt.\n";
}

