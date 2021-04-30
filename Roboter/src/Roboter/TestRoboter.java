package Roboter;

public class TestRoboter {

	static boolean testFlyingRobot() {
		try {
			FlyingRobot zeus = new FlyingRobot("Toshiba", "Zeus", 750);
			assert zeus.getManufacturer() == "Toshiba";
			assert zeus.getName() == "Zeus";
			assert zeus.getCanFly() : true;
			assert zeus.getFuel() == 750;
			assert zeus.getFuelUsagePerHour() == 100;
			assert zeus.calculateOperatingTime() == 7.5;
		} catch (AssertionError e) {
			e.printStackTrace();
			return false;
		}
		return true;
	}

	public static void main(String[] args) {
		testFlyingRobot();
	}

}
