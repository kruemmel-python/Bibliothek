#include <iostream>
#include <vector>
#include "buch.hpp"
#include "benutzer.hpp"
#include "datenSpeichern.hpp"
#include "datenLaden.hpp"

void menue() {
    std::cout << "------ Buch- und Benutzerverwaltungsprogramm ------\n";
    std::cout << "1. Buch hinzuf�gen\n";
    std::cout << "2. Buch verleihen\n";
    std::cout << "3. Buch zur�ckgeben\n";
    std::cout << "4. Alle B�cher anzeigen\n";
    std::cout << "5. Benutzer hinzuf�gen\n";
    std::cout << "6. Alle Benutzer anzeigen\n";
    std::cout << "7. Daten speichern\n";
    std::cout << "8. Daten laden\n";
    std::cout << "9. Programm beenden\n";
    std::cout << "--------------------------------------------------\n";
}

int main() {
    std::vector<Buch> buchSammlung;
    std::vector<Benutzer> benutzerSammlung;

    int auswahl;
    bool laufend = true;

    while (laufend) {
        menue();
        std::cout << "Bitte w�hlen Sie eine Option: ";
        std::cin >> auswahl;
        std::cin.ignore();  // Zum Entfernen des '\n' aus dem Eingabepuffer nach der Zahl

        switch (auswahl) {
        case 1: {
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
            if (buchSammlung.empty()) {
                std::cout << "Es gibt keine B�cher, die verliehen werden k�nnen.\n";
            }
            else if (benutzerSammlung.empty()) {
                std::cout << "Es gibt keine Benutzer, die das Buch ausleihen k�nnen.\n";
            }
            else {
                int buchId, benutzerId;
                std::cout << "Geben Sie die ID des zu verleihenden Buches ein: ";
                std::cin >> buchId;
                std::cout << "Geben Sie die ID des Benutzers ein: ";
                std::cin >> benutzerId;
                std::cin.ignore();
                bool buchGefunden = false;
                bool benutzerGefunden = false;
                for (auto& buch : buchSammlung) {
                    if (buch.id == buchId) {
                        buchGefunden = true;
                        for (const auto& benutzer : benutzerSammlung) {
                            if (benutzer.id == benutzerId) {
                                benutzerGefunden = true;
                                buchVerleihen(buch, benutzer);
                                break;
                            }
                        }
                        break;
                    }
                }
                if (!buchGefunden) {
                    std::cout << "Buch mit ID " << buchId << " wurde nicht gefunden.\n";
                }
                if (!benutzerGefunden) {
                    std::cout << "Benutzer mit ID " << benutzerId << " wurde nicht gefunden.\n";
                }
            }
            break;
        }
        case 3: {
            if (buchSammlung.empty()) {
                std::cout << "Es gibt keine B�cher, die zur�ckgegeben werden k�nnen.\n";
            }
            else {
                int buchId;
                std::cout << "Geben Sie die ID des zur�ckzugebenden Buches ein: ";
                std::cin >> buchId;
                std::cin.ignore();
                bool gefunden = false;
                for (auto& buch : buchSammlung) {
                    if (buch.id == buchId) {
                        buchZurueckgeben(buch);
                        gefunden = true;
                        break;
                    }
                }
                if (!gefunden) {
                    std::cout << "Buch mit ID " << buchId << " wurde nicht gefunden.\n";
                }
            }
            break;
        }
        case 4: {
            if (buchSammlung.empty()) {
                std::cout << "Es gibt keine B�cher in der Sammlung.\n";
            }
            else {
                for (const auto& buch : buchSammlung) {
                    buchAnzeigen(buch);
                }
            }
            break;
        }
        case 5: {
            std::string name;
            int id;
            std::cout << "Benutzername: ";
            std::getline(std::cin, name);
            std::cout << "ID: ";
            std::cin >> id;
            std::cin.ignore();  // Puffer leeren

            Benutzer neuerBenutzer(name, id);
            benutzerSammlung.push_back(neuerBenutzer);
            std::cout << "Benutzer '" << name << "' mit ID " << id << " hinzugef�gt.\n";
            break;
        }
        case 6: {
            if (benutzerSammlung.empty()) {
                std::cout << "Es gibt keine Benutzer in der Sammlung.\n";
            }
            else {
                for (const auto& benutzer : benutzerSammlung) {
                    benutzerAnzeigen(benutzer);
                }
            }
            break;
        }
        case 7: {
            datenSpeichern(buchSammlung, benutzerSammlung);
            break;
        }
        case 8: {
            datenLaden(buchSammlung, benutzerSammlung);
            break;
        }
        case 9: {
            laufend = false;
            std::cout << "Programm beendet.\n";
            break;
        }
        default:
            std::cout << "Ung�ltige Auswahl! Bitte w�hlen Sie eine g�ltige Option.\n";
        }
    }

    return 0;
}
