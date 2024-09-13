#pragma once
// Was tut dieser Abschnitt? 
// Verhindert, dass die Header-Datei mehrmals in einem Projekt eingebunden wird. 
// Diese Direktive sorgt daf�r, dass der Compiler diese Datei nur einmal pro Kompilierung ber�cksichtigt.
// Warum wird er verwendet?
// Es verhindert Mehrfachdefinitionen und reduziert Kompilierfehler bei mehrfacher Einbindung derselben Header-Datei.

#include <string>
// Was tut dieser Abschnitt?
// Bindet die Bibliothek <string> ein, die Funktionen und Objekte f�r die Arbeit mit Zeichenketten (std::string) bereitstellt.
// Warum wird er verwendet?
// Damit die Klasse `Benutzer` einen Namen als Zeichenkette speichern kann.

struct Benutzer {
    std::string name;   // Speichert den Namen des Benutzers als Zeichenkette (std::string)
    const int id;       // Speichert die eindeutige ID des Benutzers. Diese ist konstant und kann nach der Initialisierung nicht ge�ndert werden.

    // Konstruktor zum Erstellen eines Benutzers
    // Was tut dieser Abschnitt?
    // Dies ist ein Konstruktor, der zwei Parameter entgegennimmt: den Namen des Benutzers und seine ID. Der Name wird der entsprechenden Variablen zugewiesen, und die ID wird als konstant deklariert und kann nicht mehr ver�ndert werden.
    // Wie funktioniert das?
    // Der Initialisierungslisten-Operator (:) wird verwendet, um die Variablen `name` und `id` beim Erstellen des Objekts zu initialisieren.
    // Warum wird er verwendet?
    // Initialisierungslisten sind effizienter, insbesondere f�r `const` Variablen wie `id`, die nur einmal beim Erstellen des Objekts zugewiesen werden k�nnen.
    Benutzer(const std::string& name, int id) : name(name), id(id) {}
};

// Funktionsdeklarationen fuer Benutzer
// Was tut dieser Abschnitt?
// Deklariert eine Funktion namens `benutzerAnzeigen`, die ein `Benutzer`-Objekt entgegennimmt und nichts zur�ckgibt (void).
// Warum wird er verwendet?
// Diese Funktion k�nnte verwendet werden, um Informationen �ber einen Benutzer (wie Name und ID) anzuzeigen, jedoch wird ihre Implementierung woanders bereitgestellt.
void benutzerAnzeigen(const Benutzer& benutzer);
