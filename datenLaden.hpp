#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "buch.hpp"
#include "benutzer.hpp"

// Funktion zum Laden der Daten aus einer JSON-ähnlichen Datei
void datenLaden(std::vector<Buch>& buecher, std::vector<Benutzer>& benutzer) {
    std::ifstream datei("daten.json");  // Öffne die Datei zum Lesen

    if (!datei) {
        std::cerr << "Fehler beim Öffnen der Datei.\n";
        return;
    }

    std::string zeile;
    bool istBenutzer = false, istBuch = false;
    std::string name, titel, autor;
    int id = 0, verliehenAn = 0;  // Initialisierung der Variablen
    bool istVerliehen = false;

    while (std::getline(datei, zeile)) {
        std::istringstream iss(zeile);
        std::string key;

        // Benutzerinformationen laden
        if (zeile.find("\"benutzer\"") != std::string::npos) {
            istBenutzer = true;
            istBuch = false;
            continue;
        }

        // Bücherinformationen laden
        if (zeile.find("\"buecher\"") != std::string::npos) {
            istBenutzer = false;
            istBuch = true;
            continue;
        }

        if (istBenutzer) {
            if (zeile.find("\"name\"") != std::string::npos) {
                std::getline(iss, key, ':');
                iss >> std::ws;  // Entferne Leerzeichen
                std::getline(iss, name, '"');
                std::getline(iss, name, '"');
            }
            if (zeile.find("\"id\"") != std::string::npos) {
                std::getline(iss, key, ':');
                iss >> id;  // Initialisiere die ID korrekt
                benutzer.emplace_back(name, id);
            }
        }

        if (istBuch) {
            if (zeile.find("\"titel\"") != std::string::npos) {
                std::getline(iss, key, ':');
                iss >> std::ws;  // Entferne Leerzeichen
                std::getline(iss, titel, '"');
                std::getline(iss, titel, '"');
            }
            if (zeile.find("\"autor\"") != std::string::npos) {
                std::getline(iss, key, ':');
                iss >> std::ws;  // Entferne Leerzeichen
                std::getline(iss, autor, '"');
                std::getline(iss, autor, '"');
            }
            if (zeile.find("\"id\"") != std::string::npos) {
                std::getline(iss, key, ':');
                iss >> id;  // Initialisiere die ID korrekt
            }
            if (zeile.find("\"istVerliehen\"") != std::string::npos) {
                std::getline(iss, key, ':');
                istVerliehen = zeile.find("true") != std::string::npos;
            }
            if (zeile.find("\"verliehenAn\"") != std::string::npos) {
                std::getline(iss, key, ':');
                iss >> verliehenAn;
            }

            // Buch korrekt initialisieren und zur Sammlung hinzufügen
            Buch neuesBuch;
            buchBeschreiben(neuesBuch, titel, autor, id);
            neuesBuch.istVerliehen = istVerliehen;
            if (istVerliehen) {
                // Finde den Benutzer, dem das Buch verliehen wurde
                for (const auto& benutzer : benutzer) {
                    if (benutzer.id == verliehenAn) {
                        neuesBuch.verliehenAn = &benutzer;
                        break;
                    }
                }
            }
            buecher.push_back(neuesBuch);
        }
    }

    datei.close();  // Schließe die Datei
    std::cout << "Daten erfolgreich geladen.\n";
}
