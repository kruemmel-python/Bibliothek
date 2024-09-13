#pragma once
// Was tut dieser Abschnitt?
// Verhindert, dass die Header-Datei mehrmals eingebunden wird. Diese Direktive sorgt daf�r, dass der Compiler diese Datei nur einmal pro Kompilierung ber�cksichtigt.
// Warum wird er verwendet?
// Um Mehrfachdefinitionen und potenzielle Fehler durch wiederholtes Einbinden derselben Datei zu verhindern.

#include <string>
// Was tut dieser Abschnitt?
// Bindet die Standard-Bibliothek <string> ein, die Funktionen und Objekte f�r die Arbeit mit Zeichenketten bereitstellt.
// Warum wird er verwendet?
// Um die Felder `titel` und `autor` der Buch-Struktur als Zeichenketten zu definieren.

#include <vector>
// Was tut dieser Abschnitt?
// Bindet die Standard-Bibliothek <vector> ein, die eine dynamische Array-Datenstruktur bereitstellt.
// Warum wird er verwendet?
// Um eine Sammlung von B�chern zu verwalten, die in einem dynamischen Array (std::vector) gespeichert werden kann.

#include "benutzer.hpp"
// Was tut dieser Abschnitt?
// Bindet die benutzerdefinierte Header-Datei "benutzer.hpp" ein.
// Warum wird er verwendet?
// Um die `Benutzer`-Struktur verwenden zu k�nnen, die in einer anderen Header-Datei definiert ist. Sie wird ben�tigt, um festzustellen, an welchen Benutzer ein Buch verliehen wurde.


// Struktur zur Repraesentation eines Buches
struct Buch {
    std::string titel;          // Titel des Buches
    std::string autor;          // Autor des Buches
    int id;                     // Eine eindeutige ID f�r jedes Buch
    bool istVerliehen;          // Ein boolescher Wert, der angibt, ob das Buch verliehen ist (true) oder nicht (false)
    const Benutzer* verliehenAn; // Zeiger auf den Benutzer, an den das Buch verliehen wurde, falls es verliehen ist

    // Konstruktor der Buch-Struktur
    // Was tut dieser Abschnitt?
    // Initialisiert die Felder des Buches. Die ID wird auf 0 gesetzt, das Buch ist zun�chst nicht verliehen (istVerliehen = false) und der Zeiger auf den verliehenen Benutzer wird auf `nullptr` gesetzt.
    // Warum wird er verwendet?
    // Um Standardwerte f�r jedes neue Buchobjekt festzulegen. Es stellt sicher, dass ein neues Buch standardm��ig nicht verliehen ist und keinem Benutzer zugewiesen ist.
    Buch() : id(0), istVerliehen(false), verliehenAn(nullptr) {}
};

// Funktionsdeklarationen

void buchBeschreiben(Buch& buch, const std::string& titel, const std::string& autor, int id);
// Was tut dieser Abschnitt?
// Deklariert eine Funktion, die ein Buch beschreibt, indem sie den Titel, den Autor und die ID festlegt.
// Warum wird er verwendet?
// Damit ein Buch mit bestimmten Eigenschaften initialisiert oder modifiziert werden kann.

void buchAnzeigen(const Buch& buch);
// Was tut dieser Abschnitt?
// Deklariert eine Funktion, die die Informationen eines Buches auf dem Bildschirm anzeigt.
// Warum wird er verwendet?
// Um dem Benutzer die Details eines Buches anzuzeigen, wie z.B. Titel, Autor, ID und den Status der Ausleihe.

void buchVerleihen(Buch& buch, const Benutzer& benutzer);
// Was tut dieser Abschnitt?
// Deklariert eine Funktion, die es erm�glicht, ein Buch an einen Benutzer zu verleihen.
// Warum wird er verwendet?
// Diese Funktion markiert ein Buch als verliehen und verkn�pft es mit dem Benutzer, an den es ausgeliehen wurde.

void buchZurueckgeben(Buch& buch);
// Was tut dieser Abschnitt?
// Deklariert eine Funktion, die es erm�glicht, ein Buch zur�ckzugeben.
// Warum wird er verwendet?
// Um den Verleihstatus eines Buches zur�ckzusetzen, wenn es vom Benutzer zur�ckgegeben wird. Die Funktion setzt das Buch wieder auf "nicht verliehen".

void buchHinzufuegen(std::vector<Buch>& sammlung, const std::string& titel, const std::string& autor, int id);
// Was tut dieser Abschnitt?
// Deklariert eine Funktion, die ein neues Buch zur Sammlung (einem std::vector) hinzuf�gt.
// Warum wird er verwendet?
// Um neue B�cher zur Buchsammlung (z.B. einer Bibliothek) hinzuzuf�gen, indem ein neuer Eintrag im Vector erstellt wird.
