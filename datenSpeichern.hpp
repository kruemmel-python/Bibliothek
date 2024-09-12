#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "buch.hpp"
#include "benutzer.hpp"

// Funktion zum Speichern der Benutzer und B�cher in einer Datei
void datenSpeichern(const std::vector<Buch>& buecher, const std::vector<Benutzer>& benutzer) {
    std::ofstream datei("daten.json");  // �ffne die Datei zum Schreiben

    if (!datei) {
        std::cerr << "Fehler beim �ffnen der Datei.\n";
        return;
    }

    // Schreibe den Anfang des JSON-�hnlichen Formats
    datei << "{\n  \"benutzer\": [\n";

    // Speichern der Benutzer
    for (size_t i = 0; i < benutzer.size(); ++i) {
        datei << "    {\n";
        datei << "      \"name\": \"" << benutzer[i].name << "\",\n";
        datei << "      \"id\": " << benutzer[i].id << "\n";
        datei << "    }" << (i + 1 < benutzer.size() ? "," : "") << "\n";
    }

    datei << "  ],\n  \"buecher\": [\n";

    // Speichern der B�cher
    for (size_t i = 0; i < buecher.size(); ++i) {
        datei << "    {\n";
        datei << "      \"titel\": \"" << buecher[i].titel << "\",\n";
        datei << "      \"autor\": \"" << buecher[i].autor << "\",\n";
        datei << "      \"id\": " << buecher[i].id << ",\n";
        datei << "      \"istVerliehen\": " << (buecher[i].istVerliehen ? "true" : "false") << ",\n";
        datei << "      \"verliehenAn\": " << (buecher[i].verliehenAn ? buecher[i].verliehenAn->id : 0) << "\n";
        datei << "    }" << (i + 1 < buecher.size() ? "," : "") << "\n";
    }

    datei << "  ]\n}\n";  // Schreibe das Ende des Formats

    datei.close();  // Schlie�e die Datei
    std::cout << "Daten erfolgreich gespeichert.\n";
}
