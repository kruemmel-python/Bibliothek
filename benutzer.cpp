#include "benutzer.hpp"
// Was tut dieser Abschnitt?
// Bindet die benutzerdefinierte Header-Datei "benutzer.hpp" ein.
// Wie funktioniert es?
// Diese Datei enth�lt die Deklaration der `Benutzer`-Struktur. Durch das Einbinden dieser Datei k�nnen wir auf die Eigenschaften der `Benutzer`-Objekte zugreifen.
// Warum wird es verwendet?
// Um die Struktur `Benutzer` zu verwenden, damit die Benutzerinformationen im Funktionsk�rper angezeigt werden k�nnen.

#include <iostream>
// Was tut dieser Abschnitt?
// Bindet die Standardbibliothek <iostream> ein, die die Funktionen f�r die Ein- und Ausgabe auf der Konsole bereitstellt.
// Wie funktioniert es?
// Sie erm�glicht die Verwendung von `std::cout`, das zur Ausgabe von Text auf der Konsole verwendet wird.
// Warum wird es verwendet?
// Um die Benutzerinformationen auf der Konsole anzuzeigen.


// Funktion zur Anzeige der Benutzerinformationen
void benutzerAnzeigen(const Benutzer& benutzer) {
    // Was tut dieser Abschnitt?
    // Definiert eine Funktion `benutzerAnzeigen`, die ein `Benutzer`-Objekt als Konstante per Referenz �bergibt.
    // Wie funktioniert es?
    // Die Funktion verwendet eine konstante Referenz (`const Benutzer&`), um sicherzustellen, dass der �bergebene `Benutzer`-Wert innerhalb der Funktion nicht ver�ndert wird, w�hrend auf seine Daten zugegriffen wird.
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
    // `std::cout` schreibt die Zeichenkette "---------------------" in den Standardausgabestream und f�gt anschlie�end einen Zeilenumbruch hinzu.
    // Warum wird es verwendet?
    // Um eine optische Trennung zwischen den Benutzerinformationen zu schaffen und die Konsolenausgabe �bersichtlicher zu gestalten.
}
