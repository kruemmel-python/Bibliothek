#pragma once
// Was tut dieser Abschnitt?
// Verhindert, dass die Header-Datei mehrfach in einem Projekt eingebunden wird.
// Wie funktioniert es?
// Der Compiler berücksichtigt diese Datei nur einmal pro Kompilierung, auch wenn sie in mehreren Dateien eingebunden wird.
// Warum wird er verwendet?
// Um Mehrfachdefinitionen und potenzielle Kompilierfehler zu verhindern, die auftreten könnten, wenn dieselbe Datei mehrmals eingebunden wird.

#include <vector>
// Was tut dieser Abschnitt?
// Bindet die C++-Standardbibliothek <vector> ein, die die Datenstruktur `std::vector` bereitstellt.
// Wie funktioniert es?
// Ein Vektor ist ein dynamisches Array, dessen Größe zur Laufzeit flexibel verändert werden kann. Es wird verwendet, um mehrere Elemente des gleichen Typs zu speichern.
// Warum wird es verwendet?
// Vektoren ermöglichen das flexible Speichern und Verwalten von Sammlungen wie Büchern und Benutzern, die zur Laufzeit dynamisch wachsen oder schrumpfen können.

#include "buch.hpp"
// Was tut dieser Abschnitt?
// Bindet die benutzerdefinierte Header-Datei "buch.hpp" ein.
// Wie funktioniert es?
// Diese Datei enthält die Deklaration der `Buch`-Struktur. Durch das Einbinden dieser Datei können wir die Struktur `Buch` in dieser Datei verwenden.
// Warum wird es verwendet?
// Um die `Buch`-Struktur zu verwenden, sodass Bücherobjekte in den Vektor `buecher` gespeichert werden können.

#include "benutzer.hpp"
// Was tut dieser Abschnitt?
// Bindet die benutzerdefinierte Header-Datei "benutzer.hpp" ein.
// Wie funktioniert es?
// Diese Datei enthält die Deklaration der `Benutzer`-Struktur. Durch das Einbinden dieser Datei können wir die Struktur `Benutzer` in dieser Datei verwenden.
// Warum wird es verwendet?
// Um die `Benutzer`-Struktur zu verwenden, sodass Benutzerobjekte in den Vektor `benutzer` gespeichert werden können.


// Deklaration der Funktion zum Speichern der Daten
void datenSpeichern(const std::vector<Buch>& buecher, const std::vector<Benutzer>& benutzer);
// Was tut dieser Abschnitt?
// Deklariert eine Funktion namens `datenSpeichern`, die zwei konstante Vektoren als Parameter entgegennimmt: einen für `Buch`-Objekte und einen für `Benutzer`-Objekte.
// Wie funktioniert es?
// Die Funktion verwendet zwei konstante Referenzen auf `std::vector` (einen für `Buch` und einen für `Benutzer`). Durch das Hinzufügen von `const` stellt die Funktion sicher, dass die Vektoren während des Speicherprozesses nicht verändert werden.
// Warum wird es verwendet?
// Diese Funktion wird wahrscheinlich verwendet, um die aktuellen Sammlungen von Büchern und Benutzern in eine Datei oder eine andere Datenquelle zu speichern. Durch die Verwendung von konstanten Referenzen wird sichergestellt, dass die Daten nicht versehentlich während des Prozesses modifiziert werden.
