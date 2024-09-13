#include "buch.hpp"
#include "benutzer.hpp"
#include "datenLaden.hpp"
#include "datenSpeichern.hpp"
#include "verleih.hpp"
#include <iostream>
#include <vector>

// Funktion zur Darstellung des Menüs für Benutzeraktionen
void menue() {
    std::cout << "------ Buch- und Benutzerverwaltungsprogramm ------\n";
    // Menüoptionen für den Benutzer anzeigen
    std::cout << "1. Buch hinzufuegen\n";        // Option 1: Ein neues Buch hinzufügen
    std::cout << "2. Buch verleihen\n";          // Option 2: Ein Buch an einen Benutzer verleihen
    std::cout << "3. Buch zurueckgeben\n";       // Option 3: Ein verliehenes Buch zurückgeben
    std::cout << "4. Alle Buecher anzeigen\n";   // Option 4: Alle Bücher anzeigen
    std::cout << "5. Benutzer hinzufuegen\n";    // Option 5: Einen neuen Benutzer hinzufügen
    std::cout << "6. Alle Benutzer anzeigen\n";  // Option 6: Alle Benutzer anzeigen
    std::cout << "7. Daten speichern\n";         // Option 7: Aktuelle Daten in einer Datei speichern
    std::cout << "8. Daten laden\n";             // Option 8: Daten aus einer Datei laden
    std::cout << "9. Programm beenden\n";        // Option 9: Programm beenden
    std::cout << "--------------------------------------------------\n";
}

int main() {
    // Zwei Vektoren, um Bücher und Benutzer zu speichern
    std::vector<Buch> buchSammlung;  // Sammlung aller Bücher
    std::vector<Benutzer> benutzerSammlung;  // Sammlung aller Benutzer

    // Sicherstellen, dass die Sammlungen beim Programmstart leer sind
    buchSammlung.clear();
    benutzerSammlung.clear();

    // Daten automatisch beim Start des Programms laden
    datenLaden(buchSammlung, benutzerSammlung);
    std::cout << "Daten wurden beim Programmstart geladen.\n";

    int auswahl;  // Variable für die Auswahl der Menüoption
    bool laufend = true;  // Flag, um die Schleife auszuführen, solange das Programm läuft

    // Hauptschleife des Programms
    while (laufend) {
        menue();  // Zeigt das Menü an
        std::cout << "Bitte waehlen Sie eine Option: ";
        std::cin >> auswahl;  // Liest die Benutzerauswahl ein
        std::cin.ignore();  // Entfernt den Zeilenumbruch nach der Eingabe

        // Verarbeitet die Benutzerauswahl
        switch (auswahl) {
        case 1: {
            // Option 1: Buch hinzufügen
            std::string titel, autor;
            int id;
            std::cout << "Titel: ";
            std::getline(std::cin, titel);  // Liest den Buchtitel ein
            std::cout << "Autor: ";
            std::getline(std::cin, autor);  // Liest den Autor des Buches ein
            std::cout << "ID: ";
            std::cin >> id;  // Liest die ID des Buches ein
            std::cin.ignore();  // Entfernt den Zeilenumbruch nach der Eingabe der ID
            buchHinzufuegen(buchSammlung, titel, autor, id);  // Fügt das Buch der Sammlung hinzu
            break;
        }
        case 2: {
            // Option 2: Buch verleihen
            int buchId, benutzerId;
            std::cout << "Geben Sie die ID des zu verleihenden Buches ein: ";
            std::cin >> buchId;  // Liest die Buch-ID ein
            std::cout << "Geben Sie die ID des Benutzers ein: ";
            std::cin >> benutzerId;  // Liest die Benutzer-ID ein
            buchVerleihProzess(buchSammlung, benutzerSammlung, buchId, benutzerId);  // Verleiht das Buch
            break;
        }
        case 3: {
            // Option 3: Buch zurückgeben
            int buchId;
            std::cout << "Geben Sie die ID des zurueckzugebenden Buches ein: ";
            std::cin >> buchId;  // Liest die ID des zurückzugebenden Buches ein
            buchRueckgabeProzess(buchSammlung, buchId);  // Gibt das Buch zurück
            break;
        }
        case 4: {
            // Option 4: Alle Bücher anzeigen
            if (buchSammlung.empty()) {
                std::cout << "Es gibt keine Buecher in der Sammlung.\n";  // Falls keine Bücher vorhanden sind
            }
            else {
                for (const auto& buch : buchSammlung) {
                    buchAnzeigen(buch);  // Zeigt die Informationen jedes Buches an
                    std::cout << "---------------------\n";  // Trennt die Anzeige der Bücher
                }
            }
            break;
        }
        case 5: {
            // Option 5: Neuen Benutzer hinzufügen
            std::string name;
            int id;
            std::cout << "Benutzername: ";
            std::getline(std::cin, name);  // Liest den Benutzernamen ein
            std::cout << "ID: ";
            std::cin >> id;  // Liest die Benutzer-ID ein
            std::cin.ignore();  // Entfernt den Zeilenumbruch nach der Eingabe der ID
            Benutzer neuerBenutzer(name, id);  // Erstellt einen neuen Benutzer
            benutzerSammlung.push_back(neuerBenutzer);  // Fügt den Benutzer zur Sammlung hinzu
            std::cout << "Benutzer '" << name << "' wurde hinzugefuegt.\n";
            break;
        }
        case 6: {
            // Option 6: Alle Benutzer anzeigen
            if (benutzerSammlung.empty()) {
                std::cout << "Es gibt keine Benutzer.\n";  // Falls keine Benutzer vorhanden sind
            }
            else {
                for (const auto& benutzer : benutzerSammlung) {
                    benutzerAnzeigen(benutzer);  // Zeigt die Informationen jedes Benutzers an
                    std::cout << "---------------------\n";  // Trennt die Anzeige der Benutzer
                }
            }
            break;
        }
        case 7: {
            // Option 7: Daten speichern
            datenSpeichern(buchSammlung, benutzerSammlung);  // Speichert die aktuellen Daten in der Datei
            std::cout << "Daten wurden gespeichert.\n";
            break;
        }
        case 8: {
            // Option 8: Daten laden
            datenLaden(buchSammlung, benutzerSammlung);  // Lädt die Daten aus der Datei
            std::cout << "Daten wurden geladen.\n";
            break;
        }
        case 9: {
            // Option 9: Programm beenden
            laufend = false;  // Setzt das Flag auf false, um die Schleife zu beenden
            std::cout << "Programm beendet.\n";
            break;
        }
        default:
            std::cout << "Ungueltige Auswahl! Bitte waehlen Sie eine gueltige Option.\n";  // Warnung bei ungültiger Auswahl
        }
    }

    return 0;  // Programm erfolgreich beenden
}
