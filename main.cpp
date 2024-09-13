#include "buch.hpp"
#include "benutzer.hpp"
#include "datenLaden.hpp"
#include "datenSpeichern.hpp"
#include "verleih.hpp"
#include <iostream>
#include <vector>

void menue() {
    std::cout << "------ Buch- und Benutzerverwaltungsprogramm ------\n";
    std::cout << "1. Buch hinzufuegen\n";
    std::cout << "2. Buch verleihen\n";
    std::cout << "3. Buch zurueckgeben\n";
    std::cout << "4. Alle Buecher anzeigen\n";
    std::cout << "5. Benutzer hinzufuegen\n";
    std::cout << "6. Alle Benutzer anzeigen\n";
    std::cout << "7. Daten speichern\n";
    std::cout << "8. Daten laden\n";
    std::cout << "9. Programm beenden\n";
    std::cout << "--------------------------------------------------\n";
}

int main() {
    std::vector<Buch> buchSammlung;
    std::vector<Benutzer> benutzerSammlung;

    // Stelle sicher, dass die Sammlungen beim Programmstart leer sind
    buchSammlung.clear();
    benutzerSammlung.clear();

    // Daten automatisch beim Start des Programms laden
    datenLaden(buchSammlung, benutzerSammlung);
    std::cout << "Daten wurden beim Programmstart geladen.\n";

    int auswahl;
    bool laufend = true;

    while (laufend) {
        menue();
        std::cout << "Bitte waehlen Sie eine Option: ";
        std::cin >> auswahl;
        std::cin.ignore();  // Zum Entfernen des '\n' aus dem Eingabepuffer nach der Zahl

        switch (auswahl) {
        case 1: {
            // Buch hinzufuegen
            std::string titel, autor;
            int id;
            std::cout << "Titel: ";
            std::getline(std::cin, titel);
            std::cout << "Autor: ";
            std::getline(std::cin, autor);
            std::cout << "ID: ";
            std::cin >> id;
            std::cin.ignore();  // Zum Entfernen des '\n' nach der Eingabe der ID
            buchHinzufuegen(buchSammlung, titel, autor, id);
            break;
        }
        case 2: {
            // Buch verleihen
            int buchId, benutzerId;
            std::cout << "Geben Sie die ID des zu verleihenden Buches ein: ";
            std::cin >> buchId;
            std::cout << "Geben Sie die ID des Benutzers ein: ";
            std::cin >> benutzerId;
            buchVerleihProzess(buchSammlung, benutzerSammlung, buchId, benutzerId);
            break;
        }
        case 3: {
            // Buch zurueckgeben
            int buchId;
            std::cout << "Geben Sie die ID des zurueckzugebenden Buches ein: ";
            std::cin >> buchId;
            buchRueckgabeProzess(buchSammlung, buchId);
            break;
        }
        case 4: {
            // Alle Buecher anzeigen
            if (buchSammlung.empty()) {
                std::cout << "Es gibt keine Buecher in der Sammlung.\n";
            }
            else {
                for (const auto& buch : buchSammlung) {
                    buchAnzeigen(buch);
                    std::cout << "---------------------\n";
                }
            }
            break;
        }
        case 5: {
            // Neuen Benutzer hinzufuegen
            std::string name;
            int id;
            std::cout << "Benutzername: ";
            std::getline(std::cin, name);
            std::cout << "ID: ";
            std::cin >> id;
            std::cin.ignore();  // Zum Entfernen des '\n' nach der Eingabe der ID
            Benutzer neuerBenutzer(name, id);
            benutzerSammlung.push_back(neuerBenutzer);
            std::cout << "Benutzer '" << name << "' wurde hinzugefuegt.\n";
            break;
        }
        case 6: {
            // Alle Benutzer anzeigen
            if (benutzerSammlung.empty()) {
                std::cout << "Es gibt keine Benutzer.\n";
            }
            else {
                for (const auto& benutzer : benutzerSammlung) {
                    benutzerAnzeigen(benutzer);
                    std::cout << "---------------------\n";
                }
            }
            break;
        }
        case 7: {
            // Daten speichern
            datenSpeichern(buchSammlung, benutzerSammlung);
            std::cout << "Daten wurden gespeichert.\n";
            break;
        }
        case 8: {
            // Daten laden
            datenLaden(buchSammlung, benutzerSammlung);
            std::cout << "Daten wurden geladen.\n";
            break;
        }
        case 9: {
            // Programm beenden
            laufend = false;
            std::cout << "Programm beendet.\n";
            break;
        }
        default:
            std::cout << "Ungueltige Auswahl! Bitte waehlen Sie eine gueltige Option.\n";
        }
    }

    return 0;
}
