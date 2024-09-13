#pragma once
// Was tut dieser Abschnitt?
// Verhindert, dass die Header-Datei mehrfach in einem Projekt eingebunden wird.
// Wie funktioniert es?
// Der Compiler ber�cksichtigt diese Datei nur einmal pro Kompilierung, auch wenn sie in mehreren Dateien eingebunden wird.
// Warum wird er verwendet?
// Um Mehrfachdefinitionen und potenzielle Kompilierfehler zu verhindern, die auftreten k�nnten, wenn dieselbe Datei mehrmals eingebunden wird.

#include "buch.hpp"
// Was tut dieser Abschnitt?
// Bindet die benutzerdefinierte Header-Datei "buch.hpp" ein.
// Wie funktioniert es?
// Diese Datei enth�lt die Deklaration der `Buch`-Struktur. Durch das Einbinden dieser Datei k�nnen wir die Struktur `Buch` in dieser Datei verwenden.
// Warum wird es verwendet?
// Um auf Buch-Objekte zuzugreifen und sie zu modifizieren, insbesondere f�r den Verleihprozess.

#include "benutzer.hpp"
// Was tut dieser Abschnitt?
// Bindet die benutzerdefinierte Header-Datei "benutzer.hpp" ein.
// Wie funktioniert es?
// Diese Datei enth�lt die Deklaration der `Benutzer`-Struktur. Durch das Einbinden dieser Datei k�nnen wir die Struktur `Benutzer` in dieser Datei verwenden.
// Warum wird es verwendet?
// Um auf Benutzer-Objekte zuzugreifen, insbesondere f�r den Verleihprozess.

#include <vector>
// Was tut dieser Abschnitt?
// Bindet die Standardbibliothek <vector> ein, die die Datenstruktur `std::vector` bereitstellt.
// Wie funktioniert es?
// Vektoren sind dynamische Arrays, deren Gr��e zur Laufzeit flexibel ge�ndert werden kann. Sie speichern mehrere Objekte des gleichen Typs.
// Warum wird es verwendet?
// Um Sammlungen von B�chern und Benutzern zu verwalten, die sich zur Laufzeit dynamisch �ndern k�nnen.


// Funktion zum Verleihen eines Buches
void buchVerleihProzess(std::vector<Buch>& buchSammlung, std::vector<Benutzer>& benutzerSammlung, int buchId, int benutzerId);
// Was tut dieser Abschnitt?
// Deklariert eine Funktion namens `buchVerleihProzess`, die die Buch- und Benutzersammlungen sowie die IDs des Buches und des Benutzers entgegennimmt.
// Wie funktioniert es?
// Die Funktion verwendet Referenzen auf die Vektoren `buchSammlung` und `benutzerSammlung`, um auf die tats�chlichen Daten der B�cher und Benutzer zuzugreifen und sie zu modifizieren. Sie nutzt die IDs (`buchId` und `benutzerId`), um das spezifische Buch und den Benutzer zu identifizieren, um den Verleihvorgang durchzuf�hren.
// Warum wird es verwendet?
// Diese Funktion wird verwendet, um ein bestimmtes Buch an einen bestimmten Benutzer zu verleihen, indem das Buch als "verliehen" markiert und der Benutzer mit dem Buch verkn�pft wird.


// Funktion zum Zurueckgeben eines Buches
void buchRueckgabeProzess(std::vector<Buch>& buchSammlung, int buchId);
// Was tut dieser Abschnitt?
// Deklariert eine Funktion namens `buchRueckgabeProzess`, die die Buchsammlung und die ID des Buches entgegennimmt.
// Wie funktioniert es?
// Die Funktion verwendet eine Referenz auf den Vektor `buchSammlung`, um die Buchdaten direkt zu modifizieren. Sie sucht nach dem Buch mit der angegebenen ID und f�hrt den R�ckgabevorgang durch, indem sie das Buch als "nicht verliehen" markiert.
// Warum wird es verwendet?
// Diese Funktion wird verwendet, um ein bestimmtes Buch als zur�ckgegeben zu markieren, damit es f�r den n�chsten Verleih wieder zur Verf�gung steht.
