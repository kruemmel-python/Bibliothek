#include "datenSpeichern.hpp"
// Was tut dieser Abschnitt?
// Bindet die benutzerdefinierte Header-Datei "datenSpeichern.hpp" ein, die die Deklaration der Funktion `datenSpeichern` enth�lt.
// Warum wird es verwendet?
// Um die Funktion zum Speichern der Daten in einer externen Quelle verwenden zu k�nnen.

#include <iostream>
// Was tut dieser Abschnitt?
// Bindet die Standardbibliothek <iostream> ein, die Funktionen f�r die Ein- und Ausgabe auf der Konsole bereitstellt.
// Warum wird es verwendet?
// Um Fehlermeldungen oder Erfolgsmeldungen auf der Konsole anzuzeigen.

#include <fstream>
// Was tut dieser Abschnitt?
// Bindet die Standardbibliothek <fstream> ein, die Funktionen f�r das Arbeiten mit Dateien bereitstellt.
// Warum wird es verwendet?
// Um Dateien im Ein- und Ausgabemodus zu �ffnen und zu bearbeiten.


// Implementierung der Funktion zum Speichern der Daten
void datenSpeichern(const std::vector<Buch>& buecher, const std::vector<Benutzer>& benutzer) {
    // Was tut dieser Abschnitt?
    // Definiert die Funktion `datenSpeichern`, die Buch- und Benutzer-Daten in eine Datei speichert.
    // Wie funktioniert es?
    // Die Funktion nimmt zwei Vektoren als Eingabe: einen f�r B�cher und einen f�r Benutzer, und speichert deren Daten in einer Datei im JSON-�hnlichen Format.
    // Warum wird es verwendet?
    // Um die aktuellen Daten der B�cher und Benutzer persistent zu speichern.

    std::ofstream datei("daten.json");
    // Was tut dieser Abschnitt?
    // �ffnet die Datei "daten.json" im Ausgabemodus.
    // Wie funktioniert es?
    // `std::ofstream` wird verwendet, um die Datei zum Schreiben zu �ffnen. Falls die Datei nicht ge�ffnet werden kann, wird eine Fehlermeldung ausgegeben.
    // Warum wird es verwendet?
    // Um die Daten der B�cher und Benutzer in der Datei "daten.json" zu speichern.

    if (!datei) {
        std::cerr << "Fehler beim �ffnen der Datei zum Speichern.\n";
        // Was tut dieser Abschnitt?
        // Gibt eine Fehlermeldung aus, falls die Datei nicht ge�ffnet werden kann.
        // Warum wird es verwendet?
        // Um den Benutzer dar�ber zu informieren, dass die Datei nicht ge�ffnet werden konnte.
        return;
        // Was tut dieser Abschnitt?
        // Beendet die Funktion, da die Datei nicht ge�ffnet werden konnte.
        // Warum wird es verwendet?
        // Da ohne die ge�ffnete Datei keine Daten gespeichert werden k�nnen.
    }

    datei << "{\n  \"benutzer\": [\n";
    // Was tut dieser Abschnitt?
    // Schreibt den Beginn des JSON-�hnlichen Formats in die Datei und �ffnet den Block f�r die Benutzerliste.
    // Warum wird es verwendet?
    // Um den Aufbau der JSON-�hnlichen Struktur zu beginnen.

    for (size_t i = 0; i < benutzer.size(); ++i) {
        // Was tut dieser Abschnitt?
        // Durchl�uft die Liste der Benutzer und speichert deren Daten nacheinander in der Datei.
        // Wie funktioniert es?
        // Eine Schleife, die jedes `Benutzer`-Objekt im Vektor durchl�uft und dessen Daten formatiert in die Datei schreibt.
        // Warum wird es verwendet?
        // Um die Benutzerdaten in der Datei zu speichern.

        datei << "    {\n      \"name\": \"" << benutzer[i].name << "\",\n";
        // Was tut dieser Abschnitt?
        // Schreibt den Namen des aktuellen Benutzers im JSON-Format in die Datei.
        // Warum wird es verwendet?
        // Um den Namen des Benutzers in der Datei zu speichern.

        datei << "      \"id\": " << benutzer[i].id << "\n    }";
        // Was tut dieser Abschnitt?
        // Schreibt die ID des aktuellen Benutzers in die Datei.
        // Warum wird es verwendet?
        // Um die ID des Benutzers im JSON-Format zu speichern.

        if (i < benutzer.size() - 1) datei << ",";
        // Was tut dieser Abschnitt?
        // F�gt ein Komma hinzu, wenn der aktuelle Benutzer nicht der letzte in der Liste ist.
        // Warum wird es verwendet?
        // Um das JSON-Format korrekt zu halten (Komma zwischen Objekten).

        datei << "\n";
        // Was tut dieser Abschnitt?
        // F�gt einen Zeilenumbruch nach jedem Benutzerobjekt hinzu.
        // Warum wird es verwendet?
        // Um die Struktur lesbar zu halten.
    }

    datei << "  ],\n  \"buecher\": [\n";
    // Was tut dieser Abschnitt?
    // Schlie�t den Benutzerblock ab und beginnt den Block f�r die B�cherliste im JSON-Format.
    // Warum wird es verwendet?
    // Um die Buchdaten im JSON-�hnlichen Format in die Datei zu schreiben.

    for (size_t i = 0; i < buecher.size(); ++i) {
        // Was tut dieser Abschnitt?
        // Durchl�uft die Liste der B�cher und speichert deren Daten in der Datei.
        // Wie funktioniert es?
        // Eine Schleife, die jedes `Buch`-Objekt im Vektor durchl�uft und dessen Daten formatiert in die Datei schreibt.
        // Warum wird es verwendet?
        // Um die Buchdaten in der Datei zu speichern.

        if (buecher[i].titel.empty() || buecher[i].autor.empty()) {
            std::cerr << "Fehler: Buchdaten unvollstaendig (Titel oder Autor fehlt).\n";
            // Was tut dieser Abschnitt?
            // �berpr�ft, ob die Buchdaten vollst�ndig sind (Titel und Autor). Falls nicht, gibt es eine Fehlermeldung.
            // Warum wird es verwendet?
            // Um sicherzustellen, dass nur vollst�ndige Buchdaten gespeichert werden.
            continue;
            // Was tut dieser Abschnitt?
            // �berspringt den aktuellen Buchdatensatz und geht zur n�chsten Iteration der Schleife �ber.
            // Warum wird es verwendet?
            // Um unvollst�ndige Buchdatens�tze nicht in der Datei zu speichern.
        }

        datei << "    {\n      \"titel\": \"" << buecher[i].titel << "\",\n";
        // Was tut dieser Abschnitt?
        // Schreibt den Titel des aktuellen Buches in die Datei.
        // Warum wird es verwendet?
        // Um den Titel des Buches im JSON-Format zu speichern.

        datei << "      \"autor\": \"" << buecher[i].autor << "\",\n";
        // Was tut dieser Abschnitt?
        // Schreibt den Autor des aktuellen Buches in die Datei.
        // Warum wird es verwendet?
        // Um den Autor des Buches im JSON-Format zu speichern.

        datei << "      \"id\": " << buecher[i].id << ",\n";
        // Was tut dieser Abschnitt?
        // Schreibt die ID des aktuellen Buches in die Datei.
        // Warum wird es verwendet?
        // Um die ID des Buches im JSON-Format zu speichern.

        datei << "      \"istVerliehen\": " << (buecher[i].istVerliehen ? "true" : "false") << ",\n";
        // Was tut dieser Abschnitt?
        // Schreibt den Verleihstatus des Buches in die Datei (true oder false).
        // Warum wird es verwendet?
        // Um anzugeben, ob das Buch aktuell verliehen ist.

        if (buecher[i].istVerliehen && buecher[i].verliehenAn != nullptr) {
            // Was tut dieser Abschnitt?
            // �berpr�ft, ob das Buch verliehen ist und ein g�ltiger Benutzer existiert, an den es verliehen wurde.
            // Wie funktioniert es?
            // Die Bedingung �berpr�ft, ob das Buch verliehen ist (`istVerliehen == true`) und der Zeiger auf den Benutzer nicht `nullptr` ist.
            // Warum wird es verwendet?
            // Um sicherzustellen, dass die ID des Benutzers, an den das Buch verliehen wurde, korrekt gespeichert wird.

            datei << "      \"verliehenAn\": " << buecher[i].verliehenAn->id << "\n";
            // Was tut dieser Abschnitt?
            // Schreibt die ID des Benutzers, an den das Buch verliehen wurde, in die Datei.
            // Warum wird es verwendet?
            // Um die Information festzuhalten, an wen das Buch verliehen wurde.
        }
        else {
            datei << "      \"verliehenAn\": null\n";
            // Was tut dieser Abschnitt?
            // Schreibt "null" in die Datei, falls das Buch nicht verliehen ist.
            // Warum wird es verwendet?
            // Um zu signalisieren, dass das Buch aktuell nicht verliehen ist.
        }

        datei << "    }";
        // Was tut dieser Abschnitt?
        // Schlie�t den aktuellen Buchdatensatz im JSON-Format ab.
        // Warum wird es verwendet?
        // Um das JSON-Objekt f�r dieses Buch zu beenden.

        if (i < buecher.size() - 1) datei << ",";
        // Was tut dieser Abschnitt?
        // F�gt ein Komma hinzu, wenn das aktuelle Buch nicht das letzte in der Liste ist.
        // Warum wird es verwendet?
        // Um das JSON-Format korrekt zu halten (Komma zwischen Objekten).

        datei << "\n";
        // Was tut dieser Abschnitt?
        // F�gt einen Zeilenumbruch nach jedem Buchobjekt hinzu.
        // Warum wird es verwendet?
        // Um die Struktur der Datei lesbar zu halten.
    }

    datei << "  ]\n}\n";
    // Was tut dieser Abschnitt?
    // Schlie�t den JSON-Block der B�cher ab und beendet die gesamte JSON-Struktur.
    // Warum wird es verwendet?
    // Um das JSON-Format korrekt abzuschlie�en.

    datei.close();
    // Was tut dieser Abschnitt?
    // Schlie�t die ge�ffnete Datei.
    // Warum wird es verwendet?
    // Um die Datei ordnungsgem�� zu schlie�en und sicherzustellen, dass alle Daten geschrieben wurden.

    std::cout << "Daten erfolgreich gespeichert.\n";
    // Was tut dieser Abschnitt?
    // Gibt eine Erfolgsmeldung auf der Konsole aus, wenn die Daten erfolgreich gespeichert wurden.
    // Warum wird es verwendet?
    // Um den Benutzer dar�ber zu informieren, dass der Speichervorgang erfolgreich abgeschlossen wurde.
}
