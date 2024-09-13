#pragma once
// Was tut dieser Abschnitt?
// Verhindert, dass die Header-Datei mehrmals in einem Projekt eingebunden wird.
// Wie funktioniert es?
// Der Compiler berücksichtigt diese Datei nur einmal pro Kompilierung, auch wenn sie in mehreren Dateien eingebunden wird.
// Warum wird er verwendet?
// Um Mehrfachdefinitionen und potenzielle Fehler durch mehrfaches Einbinden derselben Header-Datei zu verhindern.

#include <vector>
// Was tut dieser Abschnitt?
// Bindet die C++-Standardbibliothek <vector> ein, die die Datenstruktur `std::vector` bereitstellt.
// Wie funktioniert es?
// Ein Vektor ist ein dynamisches Array, dessen Größe zur Laufzeit flexibel verändert werden kann. Es wird verwendet, um mehrere Elemente des gleichen Typs zu speichern.
// Warum wird es verwendet?
// Vektoren ermöglichen das Speichern und Verwalten von Sammlungen wie Büchern und Benutzern, die zur Laufzeit wachsen oder schrumpfen können.

#include "buch.hpp"
// Was tut dieser Abschnitt?
// Bindet die benutzerdefinierte Header-Datei "buch.hpp" ein.
// Wie funktioniert es?
// Diese Datei enthält die Deklaration der `Buch`-Struktur. Durch das Einbinden dieser Datei können wir die Struktur `Buch` in dieser Datei verwenden.
// Warum wird es verwendet?
// Um die `Buch`-Struktur zu verwenden, um auf Bücherobjekte zuzugreifen und sie in den Vektor `buecher` einzufügen.

#include "benutzer.hpp"
// Was tut dieser Abschnitt?
// Bindet die benutzerdefinierte Header-Datei "benutzer.hpp" ein.
// Wie funktioniert es?
// Diese Datei enthält die Deklaration der `Benutzer`-Struktur. Durch das Einbinden dieser Datei können wir die Struktur `Benutzer` in dieser Datei verwenden.
// Warum wird es verwendet?
// Um die `Benutzer`-Struktur zu verwenden, um auf Benutzerobjekte zuzugreifen und sie in den Vektor `benutzer` einzufügen.


// Deklaration der Funktion zum Laden der Daten
void datenLaden(std::vector<Buch>& buecher, std::vector<Benutzer>& benutzer);
// Was tut dieser Abschnitt?
// Deklariert eine Funktion namens `datenLaden`, die zwei Vektoren als Parameter entgegennimmt: einen für `Buch`-Objekte und einen für `Benutzer`-Objekte.
// Wie funktioniert es?
// Die Funktion verwendet zwei Referenzen auf `std::vector` (einen für `Buch` und einen für `Benutzer`). Dadurch kann die Funktion die ursprünglichen Vektoren, die an sie übergeben werden, direkt modifizieren.
// Warum wird es verwendet?
// Diese Funktion wird wahrscheinlich verwendet, um Daten wie Bücher und Benutzer aus einer externen Quelle (wie einer Datei oder Datenbank) zu laden und die entsprechenden Vektoren mit diesen Daten zu füllen.
