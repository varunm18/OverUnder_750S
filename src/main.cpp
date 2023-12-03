#include "main.h"
#include "pros/misc.h"
#include "pros/rtos.hpp"

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
		lcd::set_text(1, "I was pressed!");
	} else {
		lcd::clear_line(1);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	lcd::initialize();
	chassis.calibrate();
	// //SET INITIAL POINT
	chassis.setPose(0, 0, 0);
	
	// lcd::set_text(0, "Hello PROS User!");
	// lcd::register_btn1_cb(on_center_button);

	Task screenTask([&](){
		while(true){
			lcd::print(3, "X: %f", chassis.getPose().x); // x
            lcd::print(4, "Y: %f", chassis.getPose().y); // y
            lcd::print(5, "Theta: %f", chassis.getPose().theta); // heading
			delay(10);
		}
	});
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


void closeAuton(){
	chassis.moveTo(8.6,  -30   , 6000, 100);

}
void farAuton(){
	intake1.move_velocity(190);
	intake2.move_velocity(190);

	chassis.moveTo(0, 53, 4000, 85);

	intake1.move_velocity(100);
	intake2.move_velocity(100);

	chassis.turnTo(-50, 45, 800, false, 80);

	delay(100);

	//push into goal
	chassis.moveTo(-15, 50, 4000, 80);

	intake1.move_velocity(-190);
	intake2.move_velocity(-190);

	delay(200);

	intake1.move_velocity(0);
	intake2.move_velocity(0);

	delay(200);

	chassis.moveTo(-11, 50, 4000, 80);

	delay(100);

	chassis.turnTo(15, 67, 1000, false, 100);

	delay(100);
	
	chassis.moveTo(12, 68, 4000, 80);

	intake1.move_velocity(190);
	intake2.move_velocity(190);

	delay(200);

	chassis.turnTo(-50, 45, 800, false, 80);

	chassis.setPose(0, 0, 0);

	delay(100);

	chassis.moveTo(0, 50, 4000, 80);

	intake1.move_velocity(-190);
	intake2.move_velocity(-190);

// 	chassis.moveTo(-20, 53, 4000, 80);

// 	chassis.turnTo(30, 0, 10000);
}

void skills(){
	cata.move_velocity(90);
}

void runAuton(int autonSelect) {
  switch (autonSelect) {
    case 1: farAuton(); break;
	case 2: closeAuton(); break;
	case 3: skills(); break;
    default: skills(); break;
  }
}

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
void autonomous() {
	runAuton(2);
}

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
int voltage(int vel) {
    return vel * 12 / 127;
}
int velocity(int vel) {
    return vel * 600 / 127;
}
void opcontrol() {

	double power = 0.9;

	cata.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	intake1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	intake2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

	bool shoot = false;
	bool toggle = false;

	while (true) {
		
		int val = limit.get_value();

		if(master.get_digital(DIGITAL_L1)){
			intake1.move_velocity(190);
			intake2.move_velocity(190);
		}
		else if (master.get_digital(DIGITAL_L2)){
			intake1.move_velocity(-190);
			intake2.move_velocity(-190);
		}
		else {
			intake1.move_velocity(0);
			intake2.move_velocity(0);
		}

		// Wings
		if(master.get_digital(DIGITAL_R2)){
			toggle = !toggle;
			while (master.get_digital(DIGITAL_R2))
			{
				delay(200);
			}
		}

		wings.set_value(toggle);

		// CATA Shoot on Command

		// if(master.get_digital(DIGITAL_R2)){
		// 	toggle = !toggle;
		// }

		// if(!val||shoot){
		// 	cata.move_velocity(90);
		// 	shoot = false;
		// }
		// else{
		// 	cata.move_velocity(0);
		// }

		// if(val && master.get_digital(DIGITAL_R1)){
		// 	shoot = true;
		// }

		// CATA AutoShoot
		if(master.get_digital(DIGITAL_R1)){
			shoot = !shoot;
			while (master.get_digital(DIGITAL_R1))
			{
				delay(200);
			}
		}

		if(shoot){
			lcd::print(0, "true");
		}
		else{
			lcd::print(0, "false");
		}

		if(shoot||!val){
			cata.move_velocity(90);
		}
		else{
			cata.move_velocity(0);
		}

		double rX = master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
        double lY = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);

        int left = velocity(lY + rX);
        int right = velocity(lY - rX);

		leftGroup.move_velocity((left)*power);
		rightGroup.move_velocity((right)*power);

		// leftGroup.move(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y));
  		// rightGroup.move(master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y));

	

		delay(20);
	}
}
