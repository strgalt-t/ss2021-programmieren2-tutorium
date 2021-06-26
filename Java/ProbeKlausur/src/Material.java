/*
 * Material laut Aufgabe nicht noetig -> hier trotzdem implementiert zum erleichterten Testen
 */


public class Material {
	private String farbe;
	private String name;
	
	public Material(String farbe, String name) {
		this.farbe = farbe;
		this.name = name;
	}
	
	public String getFarbe() {
		return this.farbe;
	}
	
	public String getName() {
		return this.name;
	}
}
