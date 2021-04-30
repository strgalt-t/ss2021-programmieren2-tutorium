package Roboter;

public final class FlyingRobot extends Roboter implements Engine {
	final static boolean CAN_FLY = true;
	private final static int FUEL_USAGE_PER_HOUR = 100;
	private float fuel;
	private float fuelUsagePerHour;

	public FlyingRobot(String manufacturer, String name, int fuel) {
		super(manufacturer, name, CAN_FLY);
		this.setFuel(fuel);
		this.setFuelUsagePerHour(FUEL_USAGE_PER_HOUR);

	}

	public FlyingRobot(String manufacturer, String name, int fuel, int fuelUsagePerHour) {
		super(manufacturer, name, CAN_FLY);
		this.setFuel(fuel);
		this.setFuelUsagePerHour(fuelUsagePerHour);
	}

	public float getFuel() {
		return fuel;
	}

	public void setFuel(int fuel) {
		this.fuel = fuel;
	}

	public float getFuelUsagePerHour() {
		return fuelUsagePerHour;
	}

	public void setFuelUsagePerHour(int fuelUsage) {
		this.fuelUsagePerHour = fuelUsage;
	}

	@Override
	public float calculateOperatingTime() {
		float operatingTime = getFuel() / getFuelUsagePerHour();
		return operatingTime;
	}

	@Override
	public String toString() {
		String information = "[ Manufacturer: " + getManufacturer() + " | Name: " + getName() + " | Operating Time: "
				+ calculateOperatingTime() + "h ]";
		return information;
	}

}
