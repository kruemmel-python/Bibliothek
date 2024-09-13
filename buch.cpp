#include "buch.hpp"
// Was tut dieser Abschnitt?
// Bindet die benutzerdefinierte Header-Datei "buch.hpp" ein.
// Wie funktioniert es?
// Diese Datei enthält die Deklaration der `Buch`-Struktur. Durch das Einbinden dieser Datei können wir auf die Eigenschaften von Buch-Objekten zugreifen.
// Warum wird es verwendet?
// Um auf die `Buch`-Struktur zuzugreifen, um Buchinformationen zu bearbeiten und anzuzeigen.

#include <iostream>
// Was tut dieser Abschnitt?
// Bindet die Standardbibliothek <iostream> ein, die die Funktionen für die Ein- und Ausgabe auf der Konsole bereitstellt.
// Wie funktioniert es?
// Ermöglicht die Verwendung von `std::cout`, das zur Ausgabe von Text auf der Konsole verwendet wird.
// Warum wird es verwendet?
// Um Buchinformationen und Fehlermeldungen auf der Konsole anzuzeigen.


// Funktion zur Beschreibung eines Buches
void buchBeschreiben(Buch& buch, const std::string& titel, const std::string& autor, int id) {
    // Was tut dieser Abschnitt?
    // Definiert eine Funktion, die den Titel, den Autor und die ID eines Buches festlegt.
    // Wie funktioniert es?
    // Die Funktion nimmt eine Referenz auf ein `Buch`-Objekt sowie die Werte für Titel, Autor und ID als Parameter und setzt diese Werte im Buch-Objekt.
    // Warum wird es verwendet?
    // Diese Funktion initialisiert ein Buchobjekt, das anschließend zur Sammlung hinzugefügt oder angezeigt werden kann.

    buch.titel = titel;            // Setzt den Titel des Buches
    buch.autor = autor;            // Setzt den Autor des Buches
    buch.id = id;                  // Setzt die eindeutige ID des Buches
    buch.istVerliehen = false;     // Standardmäßig wird das Buch als "nicht verliehen" markiert
    buch.verliehenAn = nullptr;    // Da das Buch nicht verliehen ist, wird der Verweis auf den Benutzer auf `nullptr` gesetzt.

    // DEBUG: Ausgabe zum Überprüfen der Werte
    // std::cout << "DEBUG: Buch wird beschrieben - Titel: " << titel << ", Autor: " << autor << ", ID: " << id << "\n";
    // Dieser Abschnitt könnte während der Entwicklung verwendet werden, um sicherzustellen, dass die Werte korrekt gesetzt wurden. Es hilft beim Debuggen.
}


// Funktion zur Anzeige der Buchinformationen
void buchAnzeigen(const Buch& buch) {
    // Was tut dieser Abschnitt?
    // Zeigt die Informationen eines Buches, wie Titel, Autor, ID und Verleihstatus, auf der Konsole an.
    // Wie funktioniert es?
    // Die Funktion verwendet `std::cout`, um die verschiedenen Attribute des Buches anzuzeigen.
    // Warum wird es verwendet?
    // Um den Benutzer über die aktuellen Eigenschaften eines Buches zu informieren.

    std::cout << "Titel: " << buch.titel << std::endl;            // Zeigt den Titel des Buches an
    std::cout << "Autor: " << buch.autor << std::endl;            // Zeigt den Autor des Buches an
    std::cout << "ID: " << buch.id << std::endl;                  // Zeigt die ID des Buches an
    std::cout << "Verleihstatus: " << (buch.istVerliehen ? "Verliehen" : "Nicht verliehen") << std::endl;
    // Überprüft, ob das Buch verliehen ist und zeigt den entsprechenden Status an ("Verliehen" oder "Nicht verliehen").

    if (buch.istVerliehen && buch.verliehenAn != nullptr) {
        // Was tut dieser Abschnitt?
        // Wenn das Buch verliehen ist und der Zeiger `verliehenAn` nicht null ist, zeigt er den Namen und die ID des Benutzers an, an den das Buch verliehen wurde.
        // Wie funktioniert es?
        // `buch.verliehenAn` ist ein Zeiger auf einen Benutzer. Wenn das Buch verliehen wurde, enthält dieser Zeiger den Benutzer, an den das Buch verliehen wurde.
        std::cout << "Verliehen an: " << buch.verliehenAn->name << " (ID: " << buch.verliehenAn->id << ")" << std::endl;
    }
}


// Funktion zum Verleihen eines Buches an einen Benutzer
void buchVerleihen(Buch& buch, const Benutzer& benutzer) {
    // Was tut dieser Abschnitt?
    // Verleiht ein Buch an einen Benutzer, indem es den Verleihstatus auf "verliehen" setzt und das Buch mit dem Benutzer verknüpft.
    // Wie funktioniert es?
    // Die Funktion überprüft, ob das Buch noch nicht verliehen ist. Wenn dies der Fall ist, wird das Buch als verliehen markiert, und der Zeiger `verliehenAn` wird auf den Benutzer gesetzt.
    // Warum wird es verwendet?
    // Um den Verleihprozess eines Buches an einen Benutzer durchzuführen.

    if (!buch.istVerliehen) {
        buch.istVerliehen = true;                    // Setzt den Verleihstatus auf "verliehen"
        buch.verliehenAn = &benutzer;                // Verknüpft das Buch mit dem Benutzer, an den es verliehen wurde
        // std::cout << "DEBUG: Das Buch '" << buch.titel << "' wurde an " << benutzer.name << " (ID: " << benutzer.id << ") verliehen.\n";
    }
    else {
        std::cout << "Fehler: Das Buch '" << buch.titel << "' ist bereits verliehen.\n";
        // Zeigt eine Fehlermeldung an, falls das Buch bereits verliehen ist.
    }
}


// Funktion zur Rueckgabe eines Buches
void buchZurueckgeben(Buch& buch) {
    // Was tut dieser Abschnitt?
    // Markiert ein Buch als zurückgegeben, indem der Verleihstatus auf "nicht verliehen" gesetzt und der Verweis auf den Benutzer entfernt wird.
    // Wie funktioniert es?
    // Die Funktion überprüft, ob das Buch tatsächlich verliehen ist. Falls ja, wird der Verleihstatus zurückgesetzt, und der Benutzerzeiger wird auf `nullptr` gesetzt.
    // Warum wird es verwendet?
    // Um den Rückgabeprozess eines Buches durchzuführen.

    if (buch.istVerliehen && buch.verliehenAn != nullptr) {
        std::cout << "Das Buch '" << buch.titel << "' wurde von " << buch.verliehenAn->name << " zurueckgegeben.\n";
        // Gibt eine Meldung aus, dass das Buch vom Benutzer zurückgegeben wurde.
        buch.istVerliehen = false;                  // Setzt den Verleihstatus auf "nicht verliehen"
        buch.verliehenAn = nullptr;                 // Setzt den Zeiger auf den Benutzer auf `nullptr`
    }
    else {
        std::cout << "Fehler: Das Buch '" << buch.titel << "' war nicht verliehen.\n";
        // Zeigt eine Fehlermeldung an, falls das Buch nicht verliehen war.
    }
}


// Funktion zum Hinzufuegen eines Buches zur Sammlung
void buchHinzufuegen(std::vector<Buch>& sammlung, const std::string& titel, const std::string& autor, int id) {
    // Was tut dieser Abschnitt?
    // Fügt ein neues Buch zur Sammlung (Vektor) hinzu, wenn es nicht bereits existiert.
    // Wie funktioniert es?
    // Die Funktion überprüft, ob ein Buch mit derselben ID bereits in der Sammlung vorhanden ist. Falls nicht, wird das neue Buch erstellt und zur Sammlung hinzugefügt.
    // Warum wird es verwendet?
    // Um der Sammlung (z.B. einer Bibliothek) neue Bücher hinzuzufügen.

        // Pruefen, ob ein Buch mit der gleichen ID bereits in der Sammlung existiert
    for (const auto& buch : sammlung) {
        if (buch.id == id) {
            std::cout << "Fehler: Ein Buch mit der ID " << id << " existiert bereits in der Sammlung.\n";
            return;  // Beenden, wenn das Buch bereits existiert
        }
    }

    // Wenn kein Buch mit der ID existiert, hinzufuegen
    Buch neuesBuch;                                      // Erstellt ein neues Buch-Objekt
    buchBeschreiben(neuesBuch, titel, autor, id);        // Beschreibt das Buch mit den übergebenen Werten (Titel, Autor, ID)
    sammlung.push_back(neuesBuch);                       // Fügt das Buch zur Sammlung (Vektor) hinzu
    std::cout << "Das Buch '" << titel << "' wurde erfolgreich zur Sammlung hinzugefuegt.\n";
}
