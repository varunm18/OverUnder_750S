#include "main.h"

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");

	pros::lcd::register_btn1_cb(on_center_button);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
double voltage(int vel) {
    return vel * 12 / 127;
}
double velocity(int vel) {
    return vel * 600 / 127;
}
void opcontrol() {
	cata.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	intake1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	intake2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	bool shoot = false;
	double power = 0.9;
	bool toggle = true;
	while (true) {
		int val = limit.get_value();

		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
			intake1.move_velocity(190);
			intake2.move_velocity(190);
		}
		else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
			intake1.move_velocity(-190);
			intake2.move_velocity(-190);
		}
		else {
			intake1.move_velocity(0);
			intake2.move_velocity(0);
		}

		if(master.get_digital(DIGITAL_R2)){
			toggle = !toggle;
		}

		if(toggle){
			cata.move_velocity(-50);
			// if(!val||shoot){
			// 	cata.move_velocity(-90);
			// 	shoot = false;
			// }
			// else{
			// 	cata.move_velocity(0);
			// }

			// if(val && master.get_digital(DIGITAL_R1)){
			// 	shoot = true;
			// }
		}
		else{
			cata.move_velocity(0);
		}

		double lY = master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
        double rX = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);

        int left = velocity(lY + rX);
        int right = velocity(lY - rX);

		// leftBack.move_voltage((left * 1000)*power);
		// leftMid.move_voltage((left * 1000)*power);
		// leftFront.move_voltage((left * 1000)*power);

		leftBack.move_velocity((left)*power);
		leftMid.move_velocity((left)*power);
		leftFront.move_velocity((left)*power);
		rightBack.move_velocity((right)*power);
		rightMid.move_velocity((right)*power);
		rightFront.move_velocity((right)*power);
	
		// leftBack.move_voltage((rB * 1000)*power);
		// leftFront.move_voltage((rF * 1000)*power);

		// rightBack.move_voltage((lB * 1000)*power);
		// rightFront.move_voltage((lF * 1000)*power);
	}
}
