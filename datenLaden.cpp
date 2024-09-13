#include "datenLaden.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

// Implementierung der Funktion zum Laden der Daten aus einer JSON-aehnlichen Datei
void datenLaden(std::vector<Buch>& buecher, std::vector<Benutzer>& benutzerSammlung) {
    std::ifstream datei("daten.json");
    if (!datei) {
        std::cerr << "Fehler beim Öffnen der Datei zum Laden.\n";
        return;
    }

    std::string zeile;
    std::string name, titel, autor;
    int id = 0, verliehenAn = 0;
    bool istVerliehen = false, istBenutzer = false, istBuch = false;

    // Leere Vektoren, bevor neue Daten geladen werden
    buecher.clear();
    benutzerSammlung.clear();

    while (std::getline(datei, zeile)) {
        std::istringstream iss(zeile);
        std::string key;

        // Benutzer blockweise laden
        if (zeile.find("\"benutzer\"") != std::string::npos) {
            istBenutzer = true;
            istBuch = false;
            continue;
        }

        // Buch blockweise laden
        if (zeile.find("\"buecher\"") != std::string::npos) {
            istBenutzer = false;
            istBuch = true;
            continue;
        }

        // Start eines neuen Buches
        if (zeile.find("{") != std::string::npos && istBuch) {
            // Reset Buch-Variablen
            titel = "";
            autor = "";
            id = 0;
            istVerliehen = false;
            verliehenAn = 0;
            continue;
        }

        // Ende eines Buches
        if (zeile.find("}") != std::string::npos && istBuch) {
            // Überprüfen, ob das Buch bereits existiert (nach ID)
            bool buchExistiert = false;
            for (const auto& buch : buecher) {
                if (buch.id == id) {
                    buchExistiert = true;
                    break;
                }
            }

            // Buch nur hinzufügen, wenn es noch nicht existiert und ID gültig ist
            if (!buchExistiert && id != 0) {
                Buch neuesBuch;
                buchBeschreiben(neuesBuch, titel, autor, id);
                neuesBuch.istVerliehen = istVerliehen;

                if (istVerliehen && verliehenAn != 0) {
                    bool benutzerGefunden = false;
                    for (auto& benutzer : benutzerSammlung) {
                        if (benutzer.id == verliehenAn) {
                            neuesBuch.verliehenAn = &benutzer;
                            benutzerGefunden = true;
                            break;
                        }
                    }
                    if (!benutzerGefunden) {
                        std::cerr << "Warnung: Benutzer mit ID " << verliehenAn << " nicht gefunden.\n";
                        neuesBuch.istVerliehen = false;
                        neuesBuch.verliehenAn = nullptr;
                    }
                }

                buecher.push_back(neuesBuch);
             //   std::cout << "DEBUG: Buch wird beschrieben - Titel: " << titel << ", Autor: " << autor << ", ID: " << id << std::endl;
            }
            continue;
        }

        // Start eines neuen Benutzers
        if (zeile.find("{") != std::string::npos && istBenutzer) {
            // Reset Benutzer-Variablen
            name = "";
            id = 0;
            continue;
        }

        // Ende eines Benutzers
        if (zeile.find("}") != std::string::npos && istBenutzer) {
            // Benutzer nur hinzufügen, wenn ID gültig ist
            if (id != 0) {
                benutzerSammlung.emplace_back(name, id);
            }
            continue;
        }

        // Benutzer-Daten laden
        if (istBenutzer) {
            if (zeile.find("\"name\"") != std::string::npos) {
                std::getline(iss, key, ':');
                iss >> std::ws;
                std::getline(iss, name, '"');
                std::getline(iss, name, '"');
            }
            if (zeile.find("\"id\"") != std::string::npos) {
                std::getline(iss, key, ':');
                iss >> id;
            }
            continue;
        }

        // Buch-Daten laden
        if (istBuch) {
            if (zeile.find("\"titel\"") != std::string::npos) {
                std::getline(iss, key, ':');
                iss >> std::ws;
                std::getline(iss, titel, '"');
                std::getline(iss, titel, '"');
           //     std::cout << "DEBUG: Titel geladen: " << titel << std::endl;
            }
            else if (zeile.find("\"autor\"") != std::string::npos) {
                std::getline(iss, key, ':');
                iss >> std::ws;
                std::getline(iss, autor, '"');
                std::getline(iss, autor, '"');
              //  std::cout << "DEBUG: Autor geladen: " << autor << std::endl;
            }
            else if (zeile.find("\"id\"") != std::string::npos) {
                std::getline(iss, key, ':');
                iss >> id;
               // std::cout << "DEBUG: ID geladen: " << id << std::endl;
            }
            else if (zeile.find("\"istVerliehen\"") != std::string::npos) {
                istVerliehen = zeile.find("true") != std::string::npos;
            }
            else if (zeile.find("\"verliehenAn\"") != std::string::npos) {
                std::getline(iss, key, ':');
                if (zeile.find("null") != std::string::npos) {
                    verliehenAn = 0;
                }
                else {
                    iss >> verliehenAn;
                }
            }
            continue;
        }
    }

    datei.close();
    std::cout << "Daten erfolgreich geladen.\n";
}

