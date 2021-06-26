/*
 * Abstrakte Klasse Kleidung aus UML Diagram abgeleitet
 */
public abstract class Kleidung {
	private Material material;
	private int groesse;
	
	public Kleidung(Material material, int groesse) {
		this.material = material;
		this.groesse = groesse;
	}
	
	public Material getMaterial() {
		return this.material;
	}
	
	public int getGroesse() {
		return this.groesse;
	}
	
	public abstract double getPreis();
	
	public abstract String getHersteller();
	
}
