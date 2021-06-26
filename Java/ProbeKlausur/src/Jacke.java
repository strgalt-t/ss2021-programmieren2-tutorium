/*
 * Klasse Jacke aus UML Diagram abgeleitet
 */

public class Jacke extends Kleidung {

	public Jacke(Material material, int groesse) {
		super(material, groesse);
	}

	@Override
	public double getPreis() {
		return this.getGroesse() * 21.5;
	}

	@Override
	public String getHersteller() {
		return "Schreckschraube & Co. GmbH";
	}

}
