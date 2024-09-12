#include "buch.hpp"
#include <iostream>

// Funktion zur Beschreibung eines Buches
void buchBeschreiben(Buch& buch, const std::string& titel, const std::string& autor, int id) {
    buch.titel = titel;
    buch.autor = autor;
    buch.id = id;
    buch.istVerliehen = false;  // Standardmäßig nicht verliehen
    buch.verliehenAn = nullptr; // Kein Benutzer hat es ausgeliehen
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
    std::cout << "---------------------" << std::endl;
}

// Funktion zum Hinzufügen eines Buches zur Sammlung
void buchHinzufuegen(std::vector<Buch>& sammlung, const std::string& titel, const std::string& autor, int id) {
    Buch neuesBuch;
    buchBeschreiben(neuesBuch, titel, autor, id);
    sammlung.push_back(neuesBuch);
    std::cout << "Das Buch '" << titel << "' wurde zur Sammlung hinzugefügt.\n";
}

// Funktion zum Verleihen des Buches an einen Benutzer
void buchVerleihen(Buch& buch, const Benutzer& benutzer) {
    if (!buch.istVerliehen) {
        buch.istVerliehen = true;
        buch.verliehenAn = &benutzer;
        std::cout << "Das Buch '" << buch.titel << "' wurde an " << benutzer.name << " (ID: " << benutzer.id << ") verliehen.\n";
    }
    else {
        std::cout << "Das Buch '" << buch.titel << "' ist bereits verliehen.\n";
    }
}

// Funktion zur Rückgabe des Buches
void buchZurueckgeben(Buch& buch) {
    if (buch.istVerliehen) {
        std::cout << "Das Buch '" << buch.titel << "' wurde von " << buch.verliehenAn->name << " zurückgegeben.\n";
        buch.istVerliehen = false;
        buch.verliehenAn = nullptr;  // Verweis auf den Benutzer entfernen
    }
    else {
        std::cout << "Das Buch '" << buch.titel << "' war nicht verliehen.\n";
    }
}
 