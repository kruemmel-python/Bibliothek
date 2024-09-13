#include "verleih.hpp"
// Was tut dieser Abschnitt?
// Bindet die benutzerdefinierte Header-Datei "verleih.hpp" ein, die die Deklarationen der Verleihfunktionen enth�lt.
// Warum wird es verwendet?
// Um die Funktionen zum Verleihen und Zur�ckgeben von B�chern zu verwenden.

#include <iostream>
// Was tut dieser Abschnitt?
// Bindet die Standardbibliothek <iostream> ein, die Funktionen f�r die Ein- und Ausgabe auf der Konsole bereitstellt.
// Warum wird es verwendet?
// Um Ausgaben auf der Konsole zu machen, wie Fehlermeldungen oder Best�tigungen.


// Funktion zum Verleihen eines Buches
void buchVerleihProzess(std::vector<Buch>& buchSammlung, std::vector<Benutzer>& benutzerSammlung, int buchId, int benutzerId) {
    // Was tut dieser Abschnitt?
    // Definiert die Funktion `buchVerleihProzess`, die ein Buch an einen Benutzer verleiht, indem die Buch- und Benutzer-Sammlungen nach IDs durchsucht werden.
    // Warum wird es verwendet?
    // Um das gew�nschte Buch zu finden und es an den Benutzer zu verleihen.

    bool buchGefunden = false;  // Variable, um zu verfolgen, ob das Buch gefunden wurde
    bool benutzerGefunden = false;  // Variable, um zu verfolgen, ob der Benutzer gefunden wurde

    // Durchl�uft die Buchsammlung, um das Buch mit der passenden ID zu finden
    for (auto& buch : buchSammlung) {
        if (buch.id == buchId) {
            // Wenn das Buch gefunden wird, setze buchGefunden auf true
            buchGefunden = true;

            // Durchl�uft die Benutzersammlung, um den Benutzer mit der passenden ID zu finden
            for (const auto& benutzer : benutzerSammlung) {
                if (benutzer.id == benutzerId) {
                    // Wenn der Benutzer gefunden wird, setze benutzerGefunden auf true
                    benutzerGefunden = true;

                    // Verleiht das Buch an den Benutzer
                    buchVerleihen(buch, benutzer);
                    // Was tut dieser Abschnitt?
                    // Ruft die Funktion `buchVerleihen` auf, um das gefundene Buch dem gefundenen Benutzer zu verleihen.
                    // Warum wird es verwendet?
                    // Um den Verleihvorgang durchzuf�hren, nachdem sowohl das Buch als auch der Benutzer gefunden wurden.

                    break;  // Beendet die Schleife, da der Benutzer gefunden wurde
                }
            }

            break;  // Beendet die Schleife, da das Buch gefunden wurde
        }
    }

    // Wenn das Buch nicht gefunden wurde, gibt eine Fehlermeldung aus
    if (!buchGefunden) {
        std::cout << "Buch mit ID " << buchId << " wurde nicht gefunden.\n";
    }

    // Wenn der Benutzer nicht gefunden wurde, gibt eine Fehlermeldung aus
    if (!benutzerGefunden) {
        std::cout << "Benutzer mit ID " << benutzerId << " wurde nicht gefunden.\n";
    }
}


// Funktion zum Zurueckgeben eines Buches
void buchRueckgabeProzess(std::vector<Buch>& buchSammlung, int buchId) {
    // Was tut dieser Abschnitt?
    // Definiert die Funktion `buchRueckgabeProzess`, die ein Buch in die Sammlung zur�ckgibt.
    // Warum wird es verwendet?
    // Um ein verliehenes Buch in der Sammlung als zur�ckgegeben zu markieren.

    bool gefunden = false;  // Variable, um zu verfolgen, ob das Buch gefunden wurde

    // Durchl�uft die Buchsammlung, um das Buch mit der passenden ID zu finden
    for (auto& buch : buchSammlung) {
        if (buch.id == buchId) {
            // �berpr�ft, ob das Buch verliehen ist
            if (buch.istVerliehen) {
                // Wenn das Buch verliehen ist, rufe die R�ckgabefunktion auf
                buchZurueckgeben(buch);
                // Was tut dieser Abschnitt?
                // Ruft die Funktion `buchZurueckgeben` auf, um das Buch als zur�ckgegeben zu markieren.
                // Warum wird es verwendet?
                // Um das Buch in den Status "nicht verliehen" zur�ckzusetzen.

                gefunden = true;  // Setzt gefunden auf true, da das Buch erfolgreich zur�ckgegeben wurde
            }
            else {
                // Wenn das Buch nicht verliehen war, gibt eine Fehlermeldung aus
                std::cout << "Das Buch '" << buch.titel << "' war nicht verliehen.\n";
            }

            break;  // Beendet die Schleife, da das Buch gefunden wurde
        }
    }

    // Wenn das Buch nicht gefunden wurde, gibt eine Fehlermeldung aus
    if (!gefunden) {
        std::cout << "Buch mit ID " << buchId << " wurde nicht gefunden.\n";
    }
}
