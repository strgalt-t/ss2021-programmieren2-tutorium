/*
 * Klasse Hose aus UML Diagramm abgeleitet
 */

public class Hose extends Kleidung {

	public Hose(Material material, int groesse) {
		super(material, groesse);
	}

	@Override
	public double getPreis() {
		return this.getGroesse() * 15.5;
	}

	@Override
	public String getHersteller() {
		return "Schreckschraube & Co. GmbH";
	}

}
