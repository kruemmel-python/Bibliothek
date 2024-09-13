#pragma once
// Was tut dieser Abschnitt?
// Verhindert, dass die Header-Datei mehrmals in einem Projekt eingebunden wird.
// Wie funktioniert es?
// Der Compiler ber�cksichtigt diese Datei nur einmal pro Kompilierung, auch wenn sie in mehreren Dateien eingebunden wird.
// Warum wird er verwendet?
// Um Mehrfachdefinitionen und potenzielle Fehler durch mehrfaches Einbinden derselben Header-Datei zu verhindern.

#include <vector>
// Was tut dieser Abschnitt?
// Bindet die C++-Standardbibliothek <vector> ein, die die Datenstruktur `std::vector` bereitstellt.
// Wie funktioniert es?
// Ein Vektor ist ein dynamisches Array, dessen Gr��e zur Laufzeit flexibel ver�ndert werden kann. Es wird verwendet, um mehrere Elemente des gleichen Typs zu speichern.
// Warum wird es verwendet?
// Vektoren erm�glichen das Speichern und Verwalten von Sammlungen wie B�chern und Benutzern, die zur Laufzeit wachsen oder schrumpfen k�nnen.

#include "buch.hpp"
// Was tut dieser Abschnitt?
// Bindet die benutzerdefinierte Header-Datei "buch.hpp" ein.
// Wie funktioniert es?
// Diese Datei enth�lt die Deklaration der `Buch`-Struktur. Durch das Einbinden dieser Datei k�nnen wir die Struktur `Buch` in dieser Datei verwenden.
// Warum wird es verwendet?
// Um die `Buch`-Struktur zu verwenden, um auf B�cherobjekte zuzugreifen und sie in den Vektor `buecher` einzuf�gen.

#include "benutzer.hpp"
// Was tut dieser Abschnitt?
// Bindet die benutzerdefinierte Header-Datei "benutzer.hpp" ein.
// Wie funktioniert es?
// Diese Datei enth�lt die Deklaration der `Benutzer`-Struktur. Durch das Einbinden dieser Datei k�nnen wir die Struktur `Benutzer` in dieser Datei verwenden.
// Warum wird es verwendet?
// Um die `Benutzer`-Struktur zu verwenden, um auf Benutzerobjekte zuzugreifen und sie in den Vektor `benutzer` einzuf�gen.


// Deklaration der Funktion zum Laden der Daten
void datenLaden(std::vector<Buch>& buecher, std::vector<Benutzer>& benutzer);
// Was tut dieser Abschnitt?
// Deklariert eine Funktion namens `datenLaden`, die zwei Vektoren als Parameter entgegennimmt: einen f�r `Buch`-Objekte und einen f�r `Benutzer`-Objekte.
// Wie funktioniert es?
// Die Funktion verwendet zwei Referenzen auf `std::vector` (einen f�r `Buch` und einen f�r `Benutzer`). Dadurch kann die Funktion die urspr�nglichen Vektoren, die an sie �bergeben werden, direkt modifizieren.
// Warum wird es verwendet?
// Diese Funktion wird wahrscheinlich verwendet, um Daten wie B�cher und Benutzer aus einer externen Quelle (wie einer Datei oder Datenbank) zu laden und die entsprechenden Vektoren mit diesen Daten zu f�llen.
