package Roboter;

public class RoboterMain {

	public static void main(String[] args) {
		FlyingRobot zeus = new FlyingRobot("Toshiba", "Zeus", 750);

		FlyingRobot titan = new FlyingRobot("Albstadt Robot Manufacturing", "Bock", 900, 1750);

		System.out.println(zeus.toString());
		System.out.println(titan.toString());
	}

}
