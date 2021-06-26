import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class Rechnung {
	/*
	 * Strings zum richtigen Ausgeben der Rechnung
	 */
	FileWriter fWriter;
	String seperatorString = "==== ==== ==== ====";
	String billString = "==== Rechnung ==== ";
	float billSum = 0;

	public void ausgebenRechnung(String dname, ArrayList<Kleidung> bestellung) {
		/*
		 * Try-Catch falls es Probleme beim oeffnen der Datei gibt
		 */
		try {
			fWriter = new FileWriter(dname);
		} catch (IOException e) {
			e.printStackTrace();
		}
		PrintWriter pWriter = new PrintWriter(fWriter, true);

		// Rechnungs header
		pWriter.println(seperatorString);
		pWriter.println(billString);
		pWriter.println(seperatorString);
		
		// Rechnungs body
		for (Kleidung k : bestellung) {
			// Preis addiert
			billSum += k.getPreis();
			pWriter.println("Hersteller: " + k.getHersteller());
			pWriter.println("Produkt: " + k.getClass().getName());
			pWriter.println("Preis: " + k.getPreis() + " EUR");
		}

		// Rechnungs footer
		pWriter.println(seperatorString);
		pWriter.println("Summe: " + billSum + " EUR");
	}

	public void ausgebenArtikel(String dname, ArrayList<Kleidung> artikelListe) {
		try {
			fWriter = new FileWriter(dname);
		} catch (IOException e) {
			e.printStackTrace();
		}
		PrintWriter pWriter = new PrintWriter(fWriter, true);

		pWriter.println("Anzahl Artikel: " + artikelListe.size());

		for (Kleidung k : artikelListe) {
			pWriter.println("Produkt: " + k.getClass().getName());
			pWriter.println("Hersteller: " + k.getHersteller());
			pWriter.println("Groesse: " + k.getGroesse());
			pWriter.println("Material: " + k.getMaterial().getName() + "," + k.getMaterial().getFarbe());
		}
	}

	public ArrayList<Kleidung> einlesen(String dname) {
		// Array fuer Rueckgabe der eingelesenen Kleider
		ArrayList<Kleidung> arrayResult = new ArrayList<Kleidung>();
		Scanner scanner = null;
		// Try-Catch um FileNotFoundException abzufangen
		try {
			scanner = new Scanner(new File(dname));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		// ArrayList um Zeilen aus Datei als Strings zwischenzuspeichern
		ArrayList<String> arrayList = new ArrayList<String>();
		// Zeilen einlesen und speichern
		while (scanner.hasNext()) {
			arrayList.add(scanner.nextLine());
		}
		
		// Erste Zeile des Formats fuer uns nicht noetig -> Rauswerfen
		arrayList.remove(0);
		
		// Solange Liste nicht leer ist Schleife durchlaufen
		while (!arrayList.isEmpty()) {
			// Erste Zeile Kleidungstyp -> unnoetigen Teil weglassen und speichern
			String stringKleidung = arrayList.remove(0).substring(9);
			// In unserem Beispiel ist der Hersteller immer der gleiche -> wird nicht benoetigt
			arrayList.remove(0);
			// Dritte Zeile Groesse -> unnoetigen Teil weglassen und speichern
			String stringGroesse = arrayList.remove(0).substring(9);
			// Vierte Zeile Material -> unnoetigen Teil weglassen, dann aufsplitten in Farbe und Name und im Array speichern
			String [] stringMaterial = arrayList.remove(0).substring(10).split(",");
			
			// Je nach Typ richtiges Kleidungsstueck anlegen und dem arrayResult hinzufuegen
			if (stringKleidung.equals("Hose")) {
				Hose hose = new Hose(new Material(stringMaterial[1], stringMaterial[0]),Integer.parseInt(stringGroesse));
				arrayResult.add(hose);
			} else if (stringKleidung.equals("Jacke")) {
				int groesse = Integer.parseInt(stringGroesse);
				Material material = new Material(stringMaterial[1], stringMaterial[0]);
				Jacke jacke = new Jacke(material, groesse);
				arrayResult.add(jacke);
			} else {
				System.out.println("Error parsing clothing");
				System.exit(1);
			}
		}
		return arrayResult;

	}
}
