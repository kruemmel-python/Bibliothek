#include "buch.hpp"
#include "benutzer.hpp"
#include "datenLaden.hpp"
#include "datenSpeichern.hpp"
#include "verleih.hpp"
#include <iostream>
#include <vector>

// Funktion zur Darstellung des Men�s f�r Benutzeraktionen
void menue() {
    std::cout << "------ Buch- und Benutzerverwaltungsprogramm ------\n";
    // Men�optionen f�r den Benutzer anzeigen
    std::cout << "1. Buch hinzufuegen\n";        // Option 1: Ein neues Buch hinzuf�gen
    std::cout << "2. Buch verleihen\n";          // Option 2: Ein Buch an einen Benutzer verleihen
    std::cout << "3. Buch zurueckgeben\n";       // Option 3: Ein verliehenes Buch zur�ckgeben
    std::cout << "4. Alle Buecher anzeigen\n";   // Option 4: Alle B�cher anzeigen
    std::cout << "5. Benutzer hinzufuegen\n";    // Option 5: Einen neuen Benutzer hinzuf�gen
    std::cout << "6. Alle Benutzer anzeigen\n";  // Option 6: Alle Benutzer anzeigen
    std::cout << "7. Daten speichern\n";         // Option 7: Aktuelle Daten in einer Datei speichern
    std::cout << "8. Daten laden\n";             // Option 8: Daten aus einer Datei laden
    std::cout << "9. Programm beenden\n";        // Option 9: Programm beenden
    std::cout << "--------------------------------------------------\n";
}

int main() {
    // Zwei Vektoren, um B�cher und Benutzer zu speichern
    std::vector<Buch> buchSammlung;  // Sammlung aller B�cher
    std::vector<Benutzer> benutzerSammlung;  // Sammlung aller Benutzer

    // Sicherstellen, dass die Sammlungen beim Programmstart leer sind
    buchSammlung.clear();
    benutzerSammlung.clear();

    // Daten automatisch beim Start des Programms laden
    datenLaden(buchSammlung, benutzerSammlung);
    std::cout << "Daten wurden beim Programmstart geladen.\n";

    int auswahl;  // Variable f�r die Auswahl der Men�option
    bool laufend = true;  // Flag, um die Schleife auszuf�hren, solange das Programm l�uft

    // Hauptschleife des Programms
    while (laufend) {
        menue();  // Zeigt das Men� an
        std::cout << "Bitte waehlen Sie eine Option: ";
        std::cin >> auswahl;  // Liest die Benutzerauswahl ein
        std::cin.ignore();  // Entfernt den Zeilenumbruch nach der Eingabe

        // Verarbeitet die Benutzerauswahl
        switch (auswahl) {
        case 1: {
            // Option 1: Buch hinzuf�gen
            std::string titel, autor;
            int id;
            std::cout << "Titel: ";
            std::getline(std::cin, titel);  // Liest den Buchtitel ein
            std::cout << "Autor: ";
            std::getline(std::cin, autor);  // Liest den Autor des Buches ein
            std::cout << "ID: ";
            std::cin >> id;  // Liest die ID des Buches ein
            std::cin.ignore();  // Entfernt den Zeilenumbruch nach der Eingabe der ID
            buchHinzufuegen(buchSammlung, titel, autor, id);  // F�gt das Buch der Sammlung hinzu
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
            // Option 3: Buch zur�ckgeben
            int buchId;
            std::cout << "Geben Sie die ID des zurueckzugebenden Buches ein: ";
            std::cin >> buchId;  // Liest die ID des zur�ckzugebenden Buches ein
            buchRueckgabeProzess(buchSammlung, buchId);  // Gibt das Buch zur�ck
            break;
        }
        case 4: {
            // Option 4: Alle B�cher anzeigen
            if (buchSammlung.empty()) {
                std::cout << "Es gibt keine Buecher in der Sammlung.\n";  // Falls keine B�cher vorhanden sind
            }
            else {
                for (const auto& buch : buchSammlung) {
                    buchAnzeigen(buch);  // Zeigt die Informationen jedes Buches an
                    std::cout << "---------------------\n";  // Trennt die Anzeige der B�cher
                }
            }
            break;
        }
        case 5: {
            // Option 5: Neuen Benutzer hinzuf�gen
            std::string name;
            int id;
            std::cout << "Benutzername: ";
            std::getline(std::cin, name);  // Liest den Benutzernamen ein
            std::cout << "ID: ";
            std::cin >> id;  // Liest die Benutzer-ID ein
            std::cin.ignore();  // Entfernt den Zeilenumbruch nach der Eingabe der ID
            Benutzer neuerBenutzer(name, id);  // Erstellt einen neuen Benutzer
            benutzerSammlung.push_back(neuerBenutzer);  // F�gt den Benutzer zur Sammlung hinzu
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
            datenLaden(buchSammlung, benutzerSammlung);  // L�dt die Daten aus der Datei
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
            std::cout << "Ungueltige Auswahl! Bitte waehlen Sie eine gueltige Option.\n";  // Warnung bei ung�ltiger Auswahl
        }
    }

    return 0;  // Programm erfolgreich beenden
}
