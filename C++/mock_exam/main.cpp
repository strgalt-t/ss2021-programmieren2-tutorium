/*
/ Diesemal keine Auftrennung in verschiedene Klassen und Headerfiles -> in Klausur Zeitaufwand und Fehlerquellen minimieren
*/

#include <list>
#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;
// Muessen "bekannt" sein, damit man bei der Definiton der Listen in den Klassen nicht auf Schwierigkeiten trifft
class Rohteil;
class Fertigteil;

class Baugruppe {
    public:
        int bauGruppenNummer;
        list <Rohteil> listRohteile;
        list <Fertigteil> fertigteilListe;
};

class Rohteil {
    public:
        int rohteilNummer;
        list <Baugruppe> listBaugruppe;
};

class Fertigteil {
    public:
        int fertigteilNummer;
        list <Baugruppe> listBaugruppe;
};

list <Fertigteil> listFertigteile;
map<int, int> mapTeile;

// Benoetigt fuer letzte Aufgabe
typedef struct {
        int artNr;
        float preis;
        char name[100];
    } Artikel;

// Artikel aus Datei Lesen
Artikel *artikelLesen() {

    Artikel array[100];

    FILE *fp;
    fp = fopen("artikel.txt", "r+");
    if (fp == NULL) {
        printf("Fehler beim Lesen der Datei!\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_SET);
    int i = 0;
    while(!feof(fp)) {
        fscanf(fp, "%i;%f;%s\n", &array[i].artNr, &array[i].preis, &array[i].name);
        i++;
    }

    fclose(fp);

    return array;
}

// Baugruppen und Rohteile eines Fertigteils ausgeben -> haette auch als Funktion der Klasse Fertigteil definiert werden koennen
void printFertigteil(Fertigteil fertigteil) {
    list<Baugruppe>::iterator listIter1;
    for (listIter1 = fertigteil.listBaugruppe.begin(); listIter1 != fertigteil.listBaugruppe.end(); listIter1++) {
        cout << "BaugruppenNummer: " << listIter1->bauGruppenNummer << endl;

        list<Rohteil>::iterator listIter2;
        for(listIter2 = listIter1->listRohteile.begin(); listIter2 != listIter1->listRohteile.end(); listIter2++) {
            cout << "Rohteilenummer:" << listIter2->rohteilNummer << endl;
        }
    }
}

// Berechne maximale Anzahl an Rohteilen
int maxAnzahlRohteilen() {
    int maxAnzahlRohteile = 0;
    int anzahlRohteil;

    list<Fertigteil>::iterator listIterFertig;
    for(listIterFertig = listFertigteile.begin(); listIterFertig != listFertigteile.end(); listIterFertig++) {
        list<Baugruppe>::iterator listIter1;
        anzahlRohteil = 0;
        // For schleife wirkt auf den ersten Blick sehr kompliziert, da geschachtelte Iteratoren
        for (listIter1 = listIterFertig->listBaugruppe.begin(); listIter1 != listIterFertig->listBaugruppe.end(); listIter1++) {

            list<Rohteil>::iterator listIter2;
            for(listIter2 = listIter1->listRohteile.begin(); listIter2 != listIter1->listRohteile.end(); listIter2++) {
                anzahlRohteil++;
            }
        }
        mapTeile[listIterFertig->fertigteilNummer] = anzahlRohteil;
    }

    map<int, int>::iterator mapIter;
    int max = 0;
    int maxft = 0;

    for(mapIter = mapTeile.begin(); mapIter != mapTeile.end(); mapIter++) {
        if (mapIter->second > max) {
            max = mapIter->second;
            maxft = mapIter->first;
        }
    }
    return maxft;

}

int main() {
    Rohteil rohteil, rohteil2;
    Baugruppe baugruppe, baugruppe2;
    Fertigteil fertigteil, fertigteil2;

    rohteil.rohteilNummer = 1;
    rohteil2.rohteilNummer = 2;

    baugruppe.bauGruppenNummer = 1;
    baugruppe2.bauGruppenNummer = 2;

    fertigteil.fertigteilNummer = 1;
    fertigteil2.fertigteilNummer = 2;

    baugruppe.listRohteile.push_front(rohteil);
    
    fertigteil.listBaugruppe.push_front(baugruppe);

    listFertigteile.push_front(fertigteil);

    baugruppe2.listRohteile.push_front(rohteil);
    fertigteil2.listBaugruppe.push_front(baugruppe);

    baugruppe2.listRohteile.push_front(rohteil2);
    fertigteil2.listBaugruppe.push_front(baugruppe2);

    listFertigteile.push_front(fertigteil2);

    return 0;
}