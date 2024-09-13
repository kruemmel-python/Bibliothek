#include "datenLaden.hpp"
// Was tut dieser Abschnitt?
// Bindet die benutzerdefinierte Header-Datei "datenLaden.hpp" ein, die die Deklaration der Funktion `datenLaden` enthält.
// Wie funktioniert es?
// Ermöglicht den Zugriff auf die Funktionsdeklaration für das Laden von Buch- und Benutzer-Daten.
// Warum wird es verwendet?
// Um die Funktion zum Laden der Daten aus einer externen Quelle verwenden zu können.

#include <iostream>
// Was tut dieser Abschnitt?
// Bindet die Standardbibliothek <iostream> ein, die Funktionen für die Ein- und Ausgabe auf der Konsole bereitstellt.
// Wie funktioniert es?
// Ermöglicht die Verwendung von `std::cout` und `std::cerr`, um Text auf der Konsole auszugeben.
// Warum wird es verwendet?
// Um Informationen oder Fehlermeldungen auf der Konsole anzuzeigen.

#include <fstream>
// Was tut dieser Abschnitt?
// Bindet die Standardbibliothek <fstream> ein, die Funktionen für die Arbeit mit Dateien bereitstellt.
// Wie funktioniert es?
// Ermöglicht die Verwendung von `std::ifstream` zum Lesen von Dateien.
// Warum wird es verwendet?
// Um die Datei mit den gespeicherten Daten zu öffnen und die Buch- und Benutzerinformationen einzulesen.

#include <sstream>
// Was tut dieser Abschnitt?
// Bindet die Standardbibliothek <sstream> ein, die Funktionen für die Arbeit mit String-Streams bereitstellt.
// Wie funktioniert es?
// `std::istringstream` wird verwendet, um Zeichenfolgen zu analysieren und in einzelne Werte zu zerlegen.
// Warum wird es verwendet?
// Um die in der Datei eingelesenen Zeilen effizient zu analysieren und daraus Daten zu extrahieren.


// Implementierung der Funktion zum Laden der Daten aus einer JSON-aehnlichen Datei
void datenLaden(std::vector<Buch>& buecher, std::vector<Benutzer>& benutzerSammlung) {
    // Was tut dieser Abschnitt?
    // Definiert die Funktion `datenLaden`, die Buch- und Benutzer-Daten aus einer Datei lädt und die Vektoren `buecher` und `benutzerSammlung` mit den geladenen Daten füllt.
    // Wie funktioniert es?
    // Die Funktion öffnet eine Datei, liest sie zeilenweise ein und füllt die entsprechenden Daten in die Buch- und Benutzer-Vektoren.
    // Warum wird es verwendet?
    // Um die Daten einer Buch- und Benutzersammlung aus einer externen Datei zu laden.

    std::ifstream datei("daten.json");
    // Was tut dieser Abschnitt?
    // Öffnet die Datei "daten.json" im Eingabemodus.
    // Wie funktioniert es?
    // `std::ifstream` wird verwendet, um die Datei im Lesemodus zu öffnen. Wenn die Datei nicht geöffnet werden kann, gibt der folgende Block eine Fehlermeldung aus.
    // Warum wird es verwendet?
    // Um die gespeicherten Daten aus der Datei "daten.json" zu laden.

    if (!datei) {
        std::cerr << "Fehler beim Öffnen der Datei zum Laden.\n";
        // Was tut dieser Abschnitt?
        // Gibt eine Fehlermeldung auf der Konsole aus, wenn die Datei nicht geöffnet werden kann.
        // Warum wird es verwendet?
        // Um den Benutzer darüber zu informieren, dass die Datei nicht gefunden oder geöffnet werden konnte.
        return;
        // Was tut dieser Abschnitt?
        // Beendet die Funktion, falls die Datei nicht geöffnet werden konnte.
        // Warum wird es verwendet?
        // Da die Datei nicht geöffnet werden konnte, ist es nicht möglich, die Daten zu laden. Die Funktion wird daher beendet.
    }

    std::string zeile;
    std::string name, titel, autor;
    int id = 0, verliehenAn = 0;
    bool istVerliehen = false, istBenutzer = false, istBuch = false;
    // Was tut dieser Abschnitt?
    // Initialisiert Variablen, die später verwendet werden, um die gelesenen Daten zu speichern.
    // `zeile`: Speichert jede Zeile aus der Datei.
    // `name`, `titel`, `autor`: Speichert die jeweiligen Attribute für Benutzer und Bücher.
    // `id`, `verliehenAn`: Speichert die ID von Büchern und Benutzern.
    // `istVerliehen`, `istBenutzer`, `istBuch`: Speichert, ob ein Buch verliehen ist bzw. ob Benutzer- oder Buchdaten geladen werden.
    // Warum wird es verwendet?
    // Um die in der Datei gefundenen Daten vorübergehend zu speichern, bis sie verarbeitet werden.

    // Leere Vektoren, bevor neue Daten geladen werden
    buecher.clear();
    benutzerSammlung.clear();
    // Was tut dieser Abschnitt?
    // Leert die Vektoren `buecher` und `benutzerSammlung`, bevor neue Daten hinzugefügt werden.
    // Warum wird es verwendet?
    // Um sicherzustellen, dass keine alten oder doppelten Daten mehr in den Vektoren vorhanden sind, bevor die neuen Daten geladen werden.

    while (std::getline(datei, zeile)) {
        // Was tut dieser Abschnitt?
        // Liest die Datei zeilenweise ein.
        // Wie funktioniert es?
        // `std::getline` liest jede Zeile der Datei und speichert sie in der Variablen `zeile`.
        // Warum wird es verwendet?
        // Um jede Zeile der Datei zu analysieren und die darin enthaltenen Daten zu verarbeiten.

        std::istringstream iss(zeile);
        // Was tut dieser Abschnitt?
        // Erzeugt einen String-Stream-Objekt `iss`, der es ermöglicht, die Zeichenfolge `zeile` zu analysieren.
        // Wie funktioniert es?
        // Der String-Stream behandelt die Zeichenfolge so, als wäre sie ein Eingabestream, ähnlich einer Datei oder der Konsole.
        // Warum wird es verwendet?
        // Um die eingelesene Zeile zu zerlegen und die darin enthaltenen Daten zu extrahieren.

        std::string key;
        // Was tut dieser Abschnitt?
        // Definiert eine Variable `key`, die als Zwischenspeicher für Schlüssel in der JSON-ähnlichen Struktur verwendet wird.
        // Warum wird es verwendet?
        // Um die Schlüssel aus den JSON-Zeilen zu lesen und die richtigen Werte zu extrahieren.

        // Benutzer blockweise laden
        if (zeile.find("\"benutzer\"") != std::string::npos) {
            istBenutzer = true;
            istBuch = false;
            continue;
        }
        // Was tut dieser Abschnitt?
        // Überprüft, ob in der aktuellen Zeile das Schlüsselwort "benutzer" vorkommt.
        // Wie funktioniert es?
        // Wenn das Wort "benutzer" in der Zeile gefunden wird, setzt es `istBenutzer` auf `true` und `istBuch` auf `false`, um anzuzeigen, dass nun Benutzerdaten geladen werden.
        // Warum wird es verwendet?
        // Um zu unterscheiden, ob die nachfolgenden Daten Benutzer- oder Buchinformationen betreffen.

        // Buch blockweise laden
        if (zeile.find("\"buecher\"") != std::string::npos) {
            istBenutzer = false;
            istBuch = true;
            continue;
        }
        // Was tut dieser Abschnitt?
        // Überprüft, ob in der aktuellen Zeile das Schlüsselwort "buecher" vorkommt.
        // Wie funktioniert es?
        // Wenn das Wort "buecher" in der Zeile gefunden wird, setzt es `istBenutzer` auf `false` und `istBuch` auf `true`, um anzuzeigen, dass nun Buchdaten geladen werden.
        // Warum wird es verwendet?
        // Um zu unterscheiden, ob die nachfolgenden Daten Benutzer- oder Buchinformationen betreffen.

        // Start eines neuen Buches
        if (zeile.find("{") != std::string::npos && istBuch) {
            // Was tut dieser Abschnitt?
            // Erkennt den Beginn eines neuen Buch-Datensatzes (gekennzeichnet durch "{").
            // Wie funktioniert es?
            // Wenn ein neues Buch beginnt (durch ein "{" in den Buchdaten), werden die Buchdaten zurückgesetzt.
            // Warum wird es verwendet?
            // Um die Werte der Buchvariablen zu bereinigen, bevor neue Daten geladen werden.

            // Reset Buch-Variablen
            titel = "";
            autor = "";
            id = 0;
            istVerliehen = false;
            verliehenAn = 0;
            continue;
        }
        // Was tut dieser Abschnitt?
        // Setzt die Buchvariablen auf Standardwerte zurück.
        // Warum wird es verwendet?
        // Um sicherzustellen, dass keine alten Daten von vorherigen Büchern übernommen werden.

        // Ende eines Buches
        if (zeile.find("}") != std::string::npos && istBuch) {
            // Was tut dieser Abschnitt?
            // Erkennt das Ende eines Buch-Datensatzes (gekennzeichnet durch "}").
            // Wie funktioniert es?
            // Wenn der Buchdatensatz endet (durch ein "}" in den Buchdaten), wird das Buch überprüft und hinzugefügt.

            // Überprüfen, ob das Buch bereits existiert (nach ID)
            bool buchExistiert = false;
            for (const auto& buch : buecher) {
                if (buch.id == id) {
                    buchExistiert = true;
                    break;
                }
            }
            // Was tut dieser Abschnitt?
            // Überprüft, ob das Buch mit der gleichen ID bereits in der Sammlung `buecher` existiert.
            // Warum wird es verwendet?
            // Um sicherzustellen, dass keine doppelten Buchdatensätze hinzugefügt werden.

            // Buch nur hinzufügen, wenn es noch nicht existiert und ID gültig ist
            if (!buchExistiert && id != 0) {
                // Was tut dieser Abschnitt?
                // Fügt das Buch nur hinzu, wenn es noch nicht existiert und eine gültige ID hat.

                Buch neuesBuch;
                buchBeschreiben(neuesBuch, titel, autor, id);
                neuesBuch.istVerliehen = istVerliehen;
                // Was tut dieser Abschnitt?
                // Erstellt ein neues Buch und beschreibt es mit den geladenen Daten (Titel, Autor, ID, Verleihstatus).

                if (istVerliehen && verliehenAn != 0) {
                    // Was tut dieser Abschnitt?
                    // Überprüft, ob das Buch verliehen ist und ob die ID des Benutzers, an den das Buch verliehen wurde, gültig ist (ungleich 0).
                    // Wie funktioniert es?
                    // Wenn das Buch verliehen ist (`istVerliehen == true`) und `verliehenAn` eine gültige Benutzer-ID enthält (ungleich 0), wird die nachfolgende Logik ausgeführt.
                    // Warum wird es verwendet?
                    // Um sicherzustellen, dass das Buch an einen existierenden Benutzer verliehen wurde und die Verleihinformationen korrekt sind.

                    bool benutzerGefunden = false;
                    // Was tut dieser Abschnitt?
                    // Initialisiert eine boolesche Variable `benutzerGefunden` als `false`. Diese Variable dient dazu, zu prüfen, ob ein Benutzer mit der ID `verliehenAn` in der Benutzersammlung gefunden wird.
                    // Warum wird es verwendet?
                    // Um zu verfolgen, ob der Benutzer, dem das Buch verliehen wurde, in der Sammlung der Benutzer existiert.

                    for (auto& benutzer : benutzerSammlung) {
                        // Was tut dieser Abschnitt?
                        // Durchläuft die Benutzersammlung `benutzerSammlung`, um nach einem Benutzer mit der passenden ID zu suchen.
                        // Wie funktioniert es?
                        // Eine Schleife, die jedes `Benutzer`-Objekt in der Sammlung durchgeht und überprüft, ob die ID des aktuellen Benutzers der verliehenAn-ID entspricht.
                        // Warum wird es verwendet?
                        // Um den richtigen Benutzer zu finden, dem das Buch verliehen wurde, und das Buch entsprechend zu verknüpfen.

                        if (benutzer.id == verliehenAn) {
                            // Was tut dieser Abschnitt?
                            // Überprüft, ob die ID des aktuellen Benutzers in der Schleife mit der `verliehenAn`-ID übereinstimmt.
                            // Wie funktioniert es?
                            // Wenn die ID des Benutzers der ID desjenigen entspricht, an den das Buch verliehen wurde, wird die folgende Logik ausgeführt.
                            // Warum wird es verwendet?
                            // Um den Benutzer zu identifizieren, an den das Buch verliehen wurde.

                            neuesBuch.verliehenAn = &benutzer;
                            // Was tut dieser Abschnitt?
                            // Verknüpft das neue Buch mit dem Benutzer, indem es den Zeiger `verliehenAn` auf die Adresse des gefundenen Benutzers setzt.
                            // Wie funktioniert es?
                            // `neuesBuch.verliehenAn` ist ein Zeiger auf ein `Benutzer`-Objekt. Dieser Zeiger wird auf die Adresse des gefundenen Benutzers gesetzt.
                            // Warum wird es verwendet?
                            // Um anzugeben, welcher Benutzer das Buch ausgeliehen hat.

                            benutzerGefunden = true;
                            // Was tut dieser Abschnitt?
                            // Setzt die Variable `benutzerGefunden` auf `true`, um anzuzeigen, dass der Benutzer in der Sammlung gefunden wurde.
                            // Warum wird es verwendet?
                            // Um sicherzustellen, dass der Benutzer identifiziert wurde, und um die Schleife frühzeitig zu beenden.

                            break;
                            // Was tut dieser Abschnitt?
                            // Beendet die Schleife, da der Benutzer gefunden wurde.
                            // Warum wird es verwendet?
                            // Da der gesuchte Benutzer gefunden wurde, ist es nicht nötig, die Schleife weiter durchzulaufen.
                        }
                    }

                    if (!benutzerGefunden) {
                        // Was tut dieser Abschnitt?
                        // Überprüft, ob der Benutzer in der Benutzersammlung nicht gefunden wurde.
                        // Wie funktioniert es?
                        // Wenn `benutzerGefunden` weiterhin `false` ist, bedeutet dies, dass kein Benutzer mit der ID `verliehenAn` in der Sammlung existiert.
                        // Warum wird es verwendet?
                        // Um festzustellen, ob das Buch an einen ungültigen oder nicht existierenden Benutzer verliehen wurde.

                        std::cerr << "Warnung: Benutzer mit ID " << verliehenAn << " nicht gefunden.\n";
                        // Was tut dieser Abschnitt?
                        // Gibt eine Fehlermeldung auf der Konsole aus, die darauf hinweist, dass der Benutzer mit der angegebenen ID nicht gefunden wurde.
                        // Warum wird es verwendet?
                        // Um den Benutzer oder Entwickler zu informieren, dass die Verleihinformation ungültig ist, da der Benutzer nicht existiert.

                        neuesBuch.istVerliehen = false;
                        // Was tut dieser Abschnitt?
                        // Setzt den Verleihstatus des Buches auf "nicht verliehen".
                        // Warum wird es verwendet?
                        // Da der Benutzer nicht gefunden wurde, wird das Buch als nicht verliehen markiert.

                        neuesBuch.verliehenAn = nullptr;
                        // Was tut dieser Abschnitt?
                        // Setzt den Zeiger `verliehenAn` auf `nullptr`, da kein gültiger Benutzer gefunden wurde.
                        // Warum wird es verwendet?
                        // Um zu signalisieren, dass das Buch keinem Benutzer zugeordnet ist.
                    }
                }

                buecher.push_back(neuesBuch);
                // Was tut dieser Abschnitt?
                // Fügt das neu erstellte Buch zur Sammlung `buecher` hinzu.
                // Wie funktioniert es?
                // Das neu beschriebene Buch-Objekt `neuesBuch` wird mittels der `push_back`-Methode am Ende des Vektors `buecher` hinzugefügt.
                // Warum wird es verwendet?
                // Um das Buch dauerhaft in die Sammlung aller Bücher aufzunehmen.

            }
            continue;
            // Was tut dieser Abschnitt?
            // Setzt die Schleife fort und überspringt die nachfolgende Logik, da die Bearbeitung dieses Buches abgeschlossen ist.
            // Warum wird es verwendet?
            // Um sicherzustellen, dass die Verarbeitung dieses Buches abgeschlossen ist und zur nächsten Zeile der Datei übergegangen wird.
        }

        // Start eines neuen Benutzers
        if (zeile.find("{") != std::string::npos && istBenutzer) {
            // Was tut dieser Abschnitt?
            // Erkennt den Beginn eines neuen Benutzersatzes (gekennzeichnet durch "{").
            // Wie funktioniert es?
            // Wenn ein neuer Benutzer beginnt (durch ein "{" in den Benutzerdaten), werden die Benutzerdaten zurückgesetzt.
            // Warum wird es verwendet?
            // Um die Werte der Benutzervariablen zu bereinigen, bevor neue Daten geladen werden.

            // Reset Benutzer-Variablen
            name = "";
            id = 0;
            // Was tut dieser Abschnitt?
            // Setzt die Benutzervariablen auf Standardwerte zurück.
            // Warum wird es verwendet?
            // Um sicherzustellen, dass keine alten Daten von vorherigen Benutzern übernommen werden.

            continue;
            // Was tut dieser Abschnitt?
            // Setzt die Schleife fort und überspringt die nachfolgende Logik, da der Benutzerdatensatz nun bereit für neue Daten ist.
            // Warum wird es verwendet?
            // Um sicherzustellen, dass die Verarbeitung dieses Benutzers fortgesetzt wird, ohne unnötige Logik zu durchlaufen.
        }

        // Ende eines Benutzers
        if (zeile.find("}") != std::string::npos && istBenutzer) {
            // Was tut dieser Abschnitt?
            // Erkennt das Ende eines Benutzersatzes (gekennzeichnet durch "}").
            // Wie funktioniert es?
            // Wenn der Benutzerdatensatz endet (durch ein "}" in den Benutzerdaten), wird der Benutzer überprüft und hinzugefügt.

            // Benutzer nur hinzufügen, wenn ID gültig ist
            if (id != 0) {
                benutzerSammlung.emplace_back(name, id);
                // Was tut dieser Abschnitt?
                // Fügt den neu erstellten Benutzer zur Sammlung `benutzerSammlung` hinzu, wenn die ID gültig ist (ungleich 0).
                // Wie funktioniert es?
                // Die Methode `emplace_back` fügt das `Benutzer`-Objekt mit dem Namen und der ID ans Ende des Vektors hinzu.
                // Warum wird es verwendet?
                // Um den neuen Benutzer dauerhaft in die Benutzersammlung aufzunehmen, sofern er eine gültige ID hat.
            }

            continue;
            // Was tut dieser Abschnitt?
            // Setzt die Schleife fort, da die Verarbeitung des Benutzers abgeschlossen ist.
            // Warum wird es verwendet?
            // Um sicherzustellen, dass der nächste Benutzerdatensatz oder der nächste Abschnitt verarbeitet wird.
        }

        // Benutzer-Daten laden
        if (istBenutzer) {
            if (zeile.find("\"name\"") != std::string::npos) {
                std::getline(iss, key, ':');
                iss >> std::ws;
                std::getline(iss, name, '"');
                std::getline(iss, name, '"');
                // Was tut dieser Abschnitt?
                // Liest den Namen des Benutzers aus der aktuellen Zeile.
                // Wie funktioniert es?
                // Die Funktion `std::getline` liest den Schlüssel "name" und den entsprechenden Wert (den Benutzernamen) und speichert ihn in der Variable `name`.
                // Warum wird es verwendet?
                // Um den Namen des Benutzers aus der Datei zu extrahieren.
            }
            if (zeile.find("\"id\"") != std::string::npos) {
                std::getline(iss, key, ':');
                iss >> id;
                // Was tut dieser Abschnitt?
                // Liest die ID des Benutzers aus der aktuellen Zeile.
                // Wie funktioniert es?
                // Nachdem der Schlüssel "id" gefunden wurde, wird die ID als Ganzzahl in der Variable `id` gespeichert.
                // Warum wird es verwendet?
                // Um die ID des Benutzers aus der Datei zu laden.
            }

            continue;
            // Was tut dieser Abschnitt?
            // Setzt die Schleife fort, um den nächsten Datensatz oder Abschnitt zu verarbeiten.
            // Warum wird es verwendet?
            // Um sicherzustellen, dass nach dem Laden der aktuellen Daten die Schleife fortgesetzt wird.
        }

        // Buch-Daten laden
        if (istBuch) {
            if (zeile.find("\"titel\"") != std::string::npos) {
                std::getline(iss, key, ':');
                iss >> std::ws;
                std::getline(iss, titel, '"');
                std::getline(iss, titel, '"');
                // Was tut dieser Abschnitt?
                // Liest den Titel des Buches aus der aktuellen Zeile.
                // Wie funktioniert es?
                // Nachdem der Schlüssel "titel" gefunden wurde, wird der Titel des Buches in der Variable `titel` gespeichert.
                // Warum wird es verwendet?
                // Um den Titel des Buches aus der Datei zu extrahieren.
            }
            else if (zeile.find("\"autor\"") != std::string::npos) {
                std::getline(iss, key, ':');
                iss >> std::ws;
                std::getline(iss, autor, '"');
                std::getline(iss, autor, '"');
                // Was tut dieser Abschnitt?
                // Liest den Autor des Buches aus der aktuellen Zeile.
                // Wie funktioniert es?
                // Nachdem der Schlüssel "autor" gefunden wurde, wird der Name des Autors in der Variable `autor` gespeichert.
                // Warum wird es verwendet?
                // Um den Namen des Autors des Buches aus der Datei zu laden.
            }
            else if (zeile.find("\"id\"") != std::string::npos) {
                std::getline(iss, key, ':');
                iss >> id;
                // Was tut dieser Abschnitt?
                // Liest die ID des Buches aus der aktuellen Zeile.
                // Wie funktioniert es?
                // Nachdem der Schlüssel "id" gefunden wurde, wird die ID des Buches in der Variable `id` gespeichert.
                // Warum wird es verwendet?
                // Um die ID des Buches aus der Datei zu laden.
            }
            else if (zeile.find("\"istVerliehen\"") != std::string::npos) {
                istVerliehen = zeile.find("true") != std::string::npos;
                // Was tut dieser Abschnitt?
                // Überprüft, ob das Buch verliehen ist, indem nach dem Schlüssel "istVerliehen" gesucht wird.
                // Wie funktioniert es?
                // Wenn in der Zeile das Wort "true" gefunden wird, wird der Verleihstatus auf `true` gesetzt. Andernfalls bleibt der Status `false`.
                // Warum wird es verwendet?
                // Um den Verleihstatus des Buches zu laden und festzustellen, ob es verliehen ist.
            }
            else if (zeile.find("\"verliehenAn\"") != std::string::npos) {
                std::getline(iss, key, ':');
                if (zeile.find("null") != std::string::npos) {
                    verliehenAn = 0;
                    // Was tut dieser Abschnitt?
                    // Setzt den Wert `verliehenAn` auf 0, wenn das Buch an niemanden verliehen ist.
                    // Warum wird es verwendet?
                    // Um anzuzeigen, dass das Buch nicht verliehen wurde.
                }
                else {
                    iss >> verliehenAn;
                    // Was tut dieser Abschnitt?
                    // Liest die ID des Benutzers, an den das Buch verliehen wurde.
                    // Warum wird es verwendet?
                    // Um den Benutzer zu identifizieren, an den das Buch verliehen wurde.
                }
            }

            continue;
            // Was tut dieser Abschnitt?
            // Setzt die Schleife fort, um die Verarbeitung des aktuellen Buches abzuschließen und den nächsten Abschnitt zu analysieren.
            // Warum wird es verwendet?
            // Um sicherzustellen, dass nach dem Laden der aktuellen Buchdaten die Schleife fortgesetzt wird.
        }
    }

    datei.close();
    std::cout << "Daten erfolgreich geladen.\n";
    // Was tut dieser Abschnitt?
    // Schließt die Datei und gibt eine Erfolgsmeldung auf der Konsole aus.
    // Warum wird es verwendet?
    // Um den Ladevorgang abzuschließen und die Ressourcen (Datei) freizugeben.
}
