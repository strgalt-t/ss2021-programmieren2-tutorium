import java.util.ArrayList;

public class ProdukteMain {
	public static void main(String [] args) {
		ArrayList<Kleidung> liste= new ArrayList<Kleidung>();
		// 2 Materialien fuer 2 KleidungsstueckeMaterial 
		Material material1= new Material("schweinchenrosa","Seide");
		Material material2= new Material("schwarz","Jeans");
		// Der Liste 2 neue Kleidungsstuecke 
		liste.add(new Hose(material2,2));
		liste.add(new Jacke(material1,3));
		// Objekt der Klasse Rechnung erstellen
		Rechnung r= new Rechnung();
		// Liste uebergebenund Rechnung in Datei "rechnung.txt" ausgeben
		r.ausgebenRechnung("rechnung.txt", liste);
		r.ausgebenArtikel("artikel.txt", liste);
		ArrayList<Kleidung> array = r.einlesen("artikel.txt");
		System.out.println(array.toString());
	}
}