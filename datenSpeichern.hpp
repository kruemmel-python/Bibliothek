#pragma once
// Was tut dieser Abschnitt?
// Verhindert, dass die Header-Datei mehrfach in einem Projekt eingebunden wird.
// Wie funktioniert es?
// Der Compiler ber�cksichtigt diese Datei nur einmal pro Kompilierung, auch wenn sie in mehreren Dateien eingebunden wird.
// Warum wird er verwendet?
// Um Mehrfachdefinitionen und potenzielle Kompilierfehler zu verhindern, die auftreten k�nnten, wenn dieselbe Datei mehrmals eingebunden wird.

#include <vector>
// Was tut dieser Abschnitt?
// Bindet die C++-Standardbibliothek <vector> ein, die die Datenstruktur `std::vector` bereitstellt.
// Wie funktioniert es?
// Ein Vektor ist ein dynamisches Array, dessen Gr��e zur Laufzeit flexibel ver�ndert werden kann. Es wird verwendet, um mehrere Elemente des gleichen Typs zu speichern.
// Warum wird es verwendet?
// Vektoren erm�glichen das flexible Speichern und Verwalten von Sammlungen wie B�chern und Benutzern, die zur Laufzeit dynamisch wachsen oder schrumpfen k�nnen.

#include "buch.hpp"
// Was tut dieser Abschnitt?
// Bindet die benutzerdefinierte Header-Datei "buch.hpp" ein.
// Wie funktioniert es?
// Diese Datei enth�lt die Deklaration der `Buch`-Struktur. Durch das Einbinden dieser Datei k�nnen wir die Struktur `Buch` in dieser Datei verwenden.
// Warum wird es verwendet?
// Um die `Buch`-Struktur zu verwenden, sodass B�cherobjekte in den Vektor `buecher` gespeichert werden k�nnen.

#include "benutzer.hpp"
// Was tut dieser Abschnitt?
// Bindet die benutzerdefinierte Header-Datei "benutzer.hpp" ein.
// Wie funktioniert es?
// Diese Datei enth�lt die Deklaration der `Benutzer`-Struktur. Durch das Einbinden dieser Datei k�nnen wir die Struktur `Benutzer` in dieser Datei verwenden.
// Warum wird es verwendet?
// Um die `Benutzer`-Struktur zu verwenden, sodass Benutzerobjekte in den Vektor `benutzer` gespeichert werden k�nnen.


// Deklaration der Funktion zum Speichern der Daten
void datenSpeichern(const std::vector<Buch>& buecher, const std::vector<Benutzer>& benutzer);
// Was tut dieser Abschnitt?
// Deklariert eine Funktion namens `datenSpeichern`, die zwei konstante Vektoren als Parameter entgegennimmt: einen f�r `Buch`-Objekte und einen f�r `Benutzer`-Objekte.
// Wie funktioniert es?
// Die Funktion verwendet zwei konstante Referenzen auf `std::vector` (einen f�r `Buch` und einen f�r `Benutzer`). Durch das Hinzuf�gen von `const` stellt die Funktion sicher, dass die Vektoren w�hrend des Speicherprozesses nicht ver�ndert werden.
// Warum wird es verwendet?
// Diese Funktion wird wahrscheinlich verwendet, um die aktuellen Sammlungen von B�chern und Benutzern in eine Datei oder eine andere Datenquelle zu speichern. Durch die Verwendung von konstanten Referenzen wird sichergestellt, dass die Daten nicht versehentlich w�hrend des Prozesses modifiziert werden.
