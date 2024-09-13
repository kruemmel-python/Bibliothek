#pragma once
#include <string>
#include <vector>
#include "benutzer.hpp"

// Struktur zur Repr�sentation eines Buches
struct Buch {
    std::string titel;
    std::string autor;
    int id;
    bool istVerliehen;
    const Benutzer* verliehenAn;

    Buch() : id(0), istVerliehen(false), verliehenAn(nullptr) {}
};

// Funktionsdeklarationen
void buchBeschreiben(Buch& buch, const std::string& titel, const std::string& autor, int id);
void buchAnzeigen(const Buch& buch);
void buchVerleihen(Buch& buch, const Benutzer& benutzer);  // Funktionsdeklaration f�r das Verleihen eines Buches
void buchZurueckgeben(Buch& buch);
void buchHinzufuegen(std::vector<Buch>& sammlung, const std::string& titel, const std::string& autor, int id);
