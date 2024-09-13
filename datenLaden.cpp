#include "datenLaden.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

// Implementierung der Funktion zum Laden der Daten aus einer JSON-ähnlichen Datei
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
                if (id != 0) {  // Ignoriere Benutzer mit ID 0
                    benutzerSammlung.emplace_back(name, id);
                }
            }
        }

        // Buch-Daten laden
        if (istBuch) {
            if (zeile.find("\"titel\"") != std::string::npos) {
                std::getline(iss, key, ':');
                iss >> std::ws;
                std::getline(iss, titel, '"');
                std::getline(iss, titel, '"');
            }
            if (zeile.find("\"autor\"") != std::string::npos) {
                std::getline(iss, key, ':');
                iss >> std::ws;
                std::getline(iss, autor, '"');
                std::getline(iss, autor, '"');
            }
            if (zeile.find("\"id\"") != std::string::npos) {
                std::getline(iss, key, ':');
                iss >> id;
            }
            if (zeile.find("\"istVerliehen\"") != std::string::npos) {
                istVerliehen = zeile.find("true") != std::string::npos;
            }
            if (zeile.find("\"verliehenAn\"") != std::string::npos) {
                std::getline(iss, key, ':');
                if (zeile.find("null") != std::string::npos) {
                    verliehenAn = 0;
                }
                else {
                    iss >> verliehenAn;
                }
            }

            // Überprüfen, ob das Buch bereits existiert (nach ID)
            bool buchExistiert = false;
            for (const auto& buch : buecher) {
                if (buch.id == id) {
                    buchExistiert = true;
                    break;
                }
            }

            // Buch nur hinzufügen, wenn es noch nicht existiert
            if (!buchExistiert) {
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
            }
            else {
                // Stelle sicher, dass der Verleihstatus korrekt aktualisiert wird
                for (auto& buch : buecher) {
                    if (buch.id == id) {
                        buch.istVerliehen = istVerliehen;
                        if (istVerliehen && verliehenAn != 0) {
                            for (auto& benutzer : benutzerSammlung) {
                                if (benutzer.id == verliehenAn) {
                                    buch.verliehenAn = &benutzer;
                                    break;
                                }
                            }
                        }
                        else {
                            buch.verliehenAn = nullptr;
                        }
                    }
                }
            }
        }
    }

    datei.close();
    std::cout << "Daten erfolgreich geladen.\n";
}
