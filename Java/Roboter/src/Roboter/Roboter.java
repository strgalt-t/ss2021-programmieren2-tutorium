package Roboter;

public abstract class Roboter {

	private String manufacturer;
	private String name;
	private boolean canFly;

	public Roboter(String manufacturer, String name, boolean canFly) {
		this.setManufacturer(manufacturer);
		this.setName(name);
		this.setCanFly(canFly);
	}

	public boolean getCanFly() {
		return canFly;
	}

	public void setCanFly(boolean canFly) {
		this.canFly = canFly;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getManufacturer() {
		return manufacturer;
	}

	public void setManufacturer(String manufacturer) {
		this.manufacturer = manufacturer;
	}

	@Override
	public abstract String toString();

}
