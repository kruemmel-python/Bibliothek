# Buch- und Benutzerverwaltungsprogramm

## Projektbeschreibung

Dieses Programm dient zur Verwaltung von Büchern und Benutzern in einer Bibliothek. Es ermöglicht das Hinzufügen, Verleihen und Zurückgeben von Büchern sowie das Verwalten von Benutzern. Das Programm ist für Anfänger und Fortgeschrittene in C++ geeignet, um grundlegende und erweiterte Konzepte der Programmierung, insbesondere der objektorientierten Programmierung, zu erlernen und anzuwenden.

Das Programm bietet folgende Funktionen:
- Hinzufügen neuer Bücher und Benutzer.
- Verleihen von Büchern an Benutzer.
- Rückgabe von Büchern.
- Speichern und Laden der Daten in einer Datei im JSON-ähnlichen Format.

## Funktionen

- **Buch hinzufügen**: Ein neues Buch mit Titel, Autor und ID wird zur Sammlung hinzugefügt.
- **Buch verleihen**: Ein Buch wird einem Benutzer anhand der Buch-ID und Benutzer-ID ausgeliehen.
- **Buch zurückgeben**: Ein verliehenes Buch wird zurückgegeben und steht wieder zur Ausleihe bereit.
- **Benutzer hinzufügen**: Ein neuer Benutzer mit Name und ID wird in die Benutzersammlung aufgenommen.
- **Alle Bücher anzeigen**: Listet alle in der Sammlung befindlichen Bücher auf.
- **Alle Benutzer anzeigen**: Listet alle registrierten Benutzer auf.
- **Daten speichern**: Speichert den aktuellen Zustand der Bücher und Benutzer in einer Datei.
- **Daten laden**: Lädt Bücher- und Benutzerdaten aus einer Datei.

## Installation

1. **Voraussetzungen**:
   - C++ Compiler (z.B. g++, clang++)
   - C++ Standardbibliotheken

2. **Kompilierung**:
   Kompiliere das Programm mit dem folgenden Befehl:
   ```bash
   g++ -o buchVerwaltung main.cpp verleih.cpp datenLaden.cpp datenSpeichern.cpp buch.cpp benutzer.cpp
   ```

3. **Ausführung**:
   Starte das Programm nach der Kompilierung:
   ```bash
   ./buchVerwaltung
   ```

## Bedienung

Beim Start des Programms werden vorhandene Daten aus der Datei `daten.json` geladen. Das Hauptmenü bietet verschiedene Optionen, um Bücher und Benutzer zu verwalten. Verwende die Nummern, um die entsprechenden Optionen auszuwählen.

### Menüoptionen:
- **1**: Buch hinzufügen
- **2**: Buch verleihen
- **3**: Buch zurückgeben
- **4**: Alle Bücher anzeigen
- **5**: Benutzer hinzufügen
- **6**: Alle Benutzer anzeigen
- **7**: Daten speichern
- **8**: Daten laden
- **9**: Programm beenden

## Lehrplanintegration

Das Programm deckt verschiedene Aspekte des C++-Lernplans ab, insbesondere in den Bereichen der Basisprogrammierung und der objektorientierten Programmierung. Im Folgenden wird erläutert, welche Bereiche des Lehrplans durch das Programm abgedeckt werden:

### Woche 1-2: Grundlagen von C++
- **Eingabe/Ausgabe (S. 40-48, S. 57)**: Die Verwendung von `iostream` für Eingaben und Ausgaben wird in der gesamten Benutzerinteraktion des Programms genutzt.
- **Main-Funktion (S. 66-68)**: Die Struktur der `main`-Funktion bildet das Herzstück des Programms, in der alle Funktionen zusammenkommen.
- **Datentypen (S. 77-83)**: Verschiedene grundlegende Datentypen wie `int`, `string` und `bool` werden im gesamten Programm verwendet, um Buch- und Benutzerdaten zu speichern.
  
### Woche 3-4: Programmierung in C++
- **Funktionen (S. 173-180, S. 184-188)**: Das Programm ist modular aufgebaut, mit klaren Funktionen für das Hinzufügen, Verleihen und Zurückgeben von Büchern sowie das Speichern und Laden von Daten.
- **Kontrollstrukturen (S. 195, S. 204-213)**: `if`- und `switch`-Anweisungen werden verwendet, um die Benutzerinteraktion und die Auswahl im Menü zu steuern.
- **Modularisierung (S. 251)**: Das Programm ist in mehrere Dateien und Funktionen aufgeteilt, was das Verständnis und die Wartung verbessert.

### Woche 5-6: Objektorientierte Programmierung (OOP)
- **Strukturen und Klassen (S. 273-279, S. 281-288)**: Die Struktur der Buch- und Benutzerklassen zeigt, wie einfache Strukturen zur Modellierung von realen Objekten in C++ verwendet werden können.
- **Konstanten und `const` (S. 301-314)**: Die `const`-Schlüsselwörter werden verwendet, um sicherzustellen, dass bestimmte Daten unveränderlich sind, wie z.B. die Benutzer-ID.
- **Lebenszyklus von Klassen (S. 399-411)**: Die Konstruktoren für Bücher und Benutzer demonstrieren den Lebenszyklus von Objekten und deren Initialisierung.

### Woche 7-8: Fortgeschrittene Programmierung
- **Fehlerbehandlung (S. 237)**: Fehler, wie z.B. das Verleihen eines bereits verliehenen Buches, werden durch entsprechende Überprüfungen und Ausgaben behandelt.
- **Speichern und Laden (S. 541-551)**: Die Daten werden in einem JSON-ähnlichen Format gespeichert und geladen, um den Zustand der Bibliothek zu erhalten.

## Weiterentwicklung

Es gibt zahlreiche Möglichkeiten, das Programm weiterzuentwickeln:
- Erweiterung um eine grafische Benutzeroberfläche (GUI).
- Integration einer Datenbank zur Speicherung großer Datenmengen.
- Erweiterte Such- und Filterfunktionen für Bücher und Benutzer.

