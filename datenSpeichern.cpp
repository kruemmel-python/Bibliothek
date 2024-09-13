#include "datenSpeichern.hpp"
#include <iostream>
#include <fstream>

// Implementierung der Funktion zum Speichern der Daten
void datenSpeichern(const std::vector<Buch>& buecher, const std::vector<Benutzer>& benutzer) {
    std::ofstream datei("daten.json");
    if (!datei) {
        std::cerr << "Fehler beim Öffnen der Datei zum Speichern.\n";
        return;
    }

    datei << "{\n  \"benutzer\": [\n";
    for (size_t i = 0; i < benutzer.size(); ++i) {
        datei << "    {\n      \"name\": \"" << benutzer[i].name << "\",\n";
        datei << "      \"id\": " << benutzer[i].id << "\n    }";
        if (i < benutzer.size() - 1) datei << ",";
        datei << "\n";
    }
    datei << "  ],\n  \"buecher\": [\n";

    for (size_t i = 0; i < buecher.size(); ++i) {
        if (buecher[i].titel.empty() || buecher[i].autor.empty()) {
            std::cerr << "Fehler: Buchdaten unvollständig (Titel oder Autor fehlt).\n";
            continue;
        }
        datei << "    {\n      \"titel\": \"" << buecher[i].titel << "\",\n";
        datei << "      \"autor\": \"" << buecher[i].autor << "\",\n";
        datei << "      \"id\": " << buecher[i].id << ",\n";
        datei << "      \"istVerliehen\": " << (buecher[i].istVerliehen ? "true" : "false") << ",\n";

        if (buecher[i].istVerliehen && buecher[i].verliehenAn != nullptr) {
            datei << "      \"verliehenAn\": " << buecher[i].verliehenAn->id << "\n";
        }
        else {
            datei << "      \"verliehenAn\": null\n";  // Keine Benutzer-ID, wenn nicht verliehen
        }

        datei << "    }";
        if (i < buecher.size() - 1) datei << ",";
        datei << "\n";
    }
    datei << "  ]\n}\n";

    datei.close();
    std::cout << "Daten erfolgreich gespeichert.\n";
}
