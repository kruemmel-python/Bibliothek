#include "benutzer.hpp"
// Was tut dieser Abschnitt?
// Bindet die benutzerdefinierte Header-Datei "benutzer.hpp" ein.
// Wie funktioniert es?
// Diese Datei enthält die Deklaration der `Benutzer`-Struktur. Durch das Einbinden dieser Datei können wir auf die Eigenschaften der `Benutzer`-Objekte zugreifen.
// Warum wird es verwendet?
// Um die Struktur `Benutzer` zu verwenden, damit die Benutzerinformationen im Funktionskörper angezeigt werden können.

#include <iostream>
// Was tut dieser Abschnitt?
// Bindet die Standardbibliothek <iostream> ein, die die Funktionen für die Ein- und Ausgabe auf der Konsole bereitstellt.
// Wie funktioniert es?
// Sie ermöglicht die Verwendung von `std::cout`, das zur Ausgabe von Text auf der Konsole verwendet wird.
// Warum wird es verwendet?
// Um die Benutzerinformationen auf der Konsole anzuzeigen.


// Funktion zur Anzeige der Benutzerinformationen
void benutzerAnzeigen(const Benutzer& benutzer) {
    // Was tut dieser Abschnitt?
    // Definiert eine Funktion `benutzerAnzeigen`, die ein `Benutzer`-Objekt als Konstante per Referenz übergibt.
    // Wie funktioniert es?
    // Die Funktion verwendet eine konstante Referenz (`const Benutzer&`), um sicherzustellen, dass der übergebene `Benutzer`-Wert innerhalb der Funktion nicht verändert wird, während auf seine Daten zugegriffen wird.
    // Warum wird es verwendet?
    // Diese Funktion wird verwendet, um die Informationen eines bestimmten Benutzers anzuzeigen.

    std::cout << "Benutzername: " << benutzer.name << std::endl;
    // Was tut dieser Abschnitt?
    // Gibt den Namen des Benutzers auf der Konsole aus, gefolgt von einem Zeilenumbruch.
    // Wie funktioniert es?
    // `std::cout` schreibt den Text "Benutzername: " und den Namen des Benutzers, der im `name`-Attribut des `Benutzer`-Objekts gespeichert ist, in den Standardausgabestream.
    // Warum wird es verwendet?
    // Um den Benutzernamen auf der Konsole anzuzeigen.

    std::cout << "Benutzer-ID: " << benutzer.id << std::endl;
    // Was tut dieser Abschnitt?
    // Gibt die Benutzer-ID auf der Konsole aus, gefolgt von einem Zeilenumbruch.
    // Wie funktioniert es?
    // `std::cout` schreibt den Text "Benutzer-ID: " und den Wert der `id`-Variable, die die eindeutige Benutzer-ID speichert, in den Standardausgabestream.
    // Warum wird es verwendet?
    // Um die Benutzer-ID auf der Konsole anzuzeigen.

    std::cout << "---------------------" << std::endl;
    // Was tut dieser Abschnitt?
    // Gibt eine Trennlinie aus, um die Ausgabe besser lesbar zu gestalten.
    // Wie funktioniert es?
    // `std::cout` schreibt die Zeichenkette "---------------------" in den Standardausgabestream und fügt anschließend einen Zeilenumbruch hinzu.
    // Warum wird es verwendet?
    // Um eine optische Trennung zwischen den Benutzerinformationen zu schaffen und die Konsolenausgabe übersichtlicher zu gestalten.
}
