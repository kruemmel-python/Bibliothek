#pragma once
#include "buch.hpp"
#include "benutzer.hpp"
#include <vector>

// Funktion zum Verleihen eines Buches
void buchVerleihProzess(std::vector<Buch>& buchSammlung, std::vector<Benutzer>& benutzerSammlung, int buchId, int benutzerId);

// Funktion zum Zurückgeben eines Buches
void buchRueckgabeProzess(std::vector<Buch>& buchSammlung, int buchId);

