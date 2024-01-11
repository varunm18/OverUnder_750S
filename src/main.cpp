#include "main.h"
#include "pros/misc.h"
#include "pros/rtos.h"
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
	cata.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	intake.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
	// //SET INITIAL POINT
	chassis.setPose(0, 0, 0);
	
	// lcd::set_text(0, "Hello PROS User!");
	// lcd::register_btn1_cb(on_center_button);

	Task screenTask([&]() {
        lemlib::Pose pose(0, 0, 0);
        while (true) {
            // print robot location to the brain screen
            pros::lcd::print(1, "X: %f", chassis.getPose().x); // x
            pros::lcd::print(2, "Y: %f", chassis.getPose().y); // y
            pros::lcd::print(3, "Theta: %f", chassis.getPose().theta); // heading
            // delay to save resources
            pros::delay(50);
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
	// pushes triball
	chassis.moveTo(-2.6, -12.9, 1000, 80);
	delay(100);
	chassis.setPose(0, 0, 0);
	delay(20);
	chassis.moveTo(-3.1, -17.1, 1000, 120);
	delay(20);
	chassis.setPose(0, 0, 0);
	delay(20);


	//wings
	chassis.moveTo(-0.4, 10.3, 1000, 120);
	delay(20);
	chassis.turnTo(-0.9, 12.1, 1000,false,80);
	delay(20);
	chassis.setPose(0, 0, 0);
	delay(20);
	chassis.moveTo(0.2, 16, 1000, 120);
	delay(20);
	wings.set_value(true);
	delay(20);
	chassis.turnTo(-0.9, 12.1, 1000,false,80);
	delay(20);
	chassis.setPose(0, 0, 0);
	delay(20);
	wings.set_value(false);
	delay(20);

	//bar
	chassis.turnTo(-8.7, 8.7, 1000,false,80);
	delay(20);
	chassis.setPose(0, 0, 0);
	delay(20);
	chassis.moveTo(0, -6, 1000, 80);
	chassis.setPose(0, 0, 0);
	delay(20);
	chassis.turnTo(-5.35, 10.5, 1000,false,80);
	delay(20);
	chassis.setPose(0, 0, 0);
	delay(20);
	chassis.turnTo(2.57, 14.01, 1000,false,80);
	delay(20);
	chassis.setPose(0, 0, 0);
	delay(20);
	chassis.moveTo(0.77, -38.36, 4000, 50);
	delay(20);
	/*
	chassis.moveTo(-7.0, 21.5, 1000, 80);
	delay(20);
	wings.set_value(true);
	delay(20);
	chassis.turnTo(-25.0, 30.0, 1000,false, 80);
	delay(20);
	chassis.setPose(0, 0, 0);
	delay(20);
	chassis.moveTo(0.73, 10.1, 1000, 120);
	delay(20);
	wings.set_value(false);
	chassis.turnTo(0, -2, 1000,false,80);
	delay(200);
	chassis.moveTo(0, -20, 1000, 120);
	delay(20);*/

	

	
	delay(20);

	// chassis.moveTo(8, -27.3, 1000, 100);
	// chassis.setPose(0, 0, 0);
	// delay(20);
	// chassis.moveTo(0, -15, 1000, 150);
	// delay(20);
	//rush middle to disrupt triballs with wings

	//move back and turn to goal

	//move and push matchload into goal

	//turn and move to matchload place

	//move back for triball in mathload place

	//move and stop under low bar
}

void farAutonRisky(){

	//move straight
	intake.move_velocity(190);
	chassis.moveTo(0, 42.75, 1500, 100);
	delay(200);
	chassis.setPose(0, 0, 0);
	delay(20);

	//turn to goal
	chassis.turnTo(5, 3, 1000, false, 80);
	intake.move_velocity(0);
	delay(200);
	chassis.setPose(0, 0, 0);
	delay(20);

	// //push into goal
	chassis.moveTo(0, 10, 1000, 100);
	// chassis.moveTo(0, 6, 0, 1500, true, 0, 0.6, 100);
	delay(20);
	chassis.setPose(0, 0, 0);
	delay(20);
	chassis.moveTo(0, -5, 1000, 120);
	delay(20);
	chassis.setPose(0, 0, 0);
	delay(20);
	intake.move_velocity(190);
	chassis.turnTo(-5, -7, 1000, false, 80);
	delay(20);
	chassis.moveTo(-5, -7, 1000, 120);
	delay(20);
	

	chassis.turnTo(-7, 5, 1000, false, 80);
	delay(20);
	chassis.setPose(0, 0, 0);
	delay(20);
	intake.move_velocity(0);
	delay(20);
	chassis.moveTo(0, 15, 1000, 120);
	delay(20);
	chassis.setPose(0, 0, 0);
	delay(20);
	chassis.moveTo(0, -15, 1000, 120);
	delay(20);
	chassis.setPose(0, 0, 0);
	delay(20);
	chassis.turnTo(1, -5, 1000, false, 80);
	delay(20);
	intake.move_velocity(190);
	delay(20);
	chassis.setPose(0, 0, 0);
	delay(20);
	chassis.moveTo(0, 15, 1000, 120);
	delay(20);
	chassis.setPose(0, 0, 0);
	delay(20);
	chassis.turnTo(3, -5, 1000, false, 120);
	delay(20);
	chassis.setPose(0, 0, 0);
	delay(20);
	intake.move_velocity(0);
	chassis.moveTo(0, 30, 1000, 120);
	delay(20);
	chassis.setPose(0, 0, 0);
	delay(20);
	chassis.moveTo(0, -10, 1500, 150);
	delay(20);
	chassis.moveTo(0, 300, 1500, 150);
}

void farAutonSafe(){

}


void skills(){


	//Turn to goal
	chassis.turnTo(-21, 39.84, 800);
	delay(20);
	chassis.setPose(0, 0, 0);
	delay(20);
	chassis.moveTo(0, 2, 500);
	delay(20);

	//Shoot
	cata.move_velocity(98);
	delay(45000);
	int val = limit.get_value();
	while(!val){
		cata.move_velocity(90);
		val = limit.get_value();
	}
	cata.move_velocity(0);

//7 black 3 yellow

	//Move to opposite side
	chassis.setPose(0, 0, 0);
	delay(20);
	chassis.turnTo(12.86, 22.12, 800,false,80);
	delay(20);
	chassis.setPose(0, 0, 0);
	delay(20);
	chassis.moveTo(0, -80, 5000, 80);
	delay(20);
	chassis.setPose(0, 0, 0);
	delay(20);
	chassis.turnTo(-16.5, 0.6, 800,false,80);
	delay(20);
	chassis.setPose(0, 0, 0);
	delay(20);
	chassis.moveTo(0, -15, 1000, 80);
	delay(20);
	chassis.setPose(0, 0, 0);
	delay(20);
	chassis.turnTo(-28.25, 23.59, 800,false,80);
	delay(20);
	chassis.setPose(0, 0, 0);
	delay(20);
	chassis.moveTo(0, -29.79, 2000, 80);
	delay(20);
	chassis.setPose(0, 0, 0);
	delay(20);
	chassis.turnTo(10.07, 12.59, 1000,false,80);
	delay(20);
	chassis.moveTo(-10.07, -15.59, 2000, 80);
	delay(20);
	chassis.setPose(0, 0, 0);
	delay(20);
	chassis.turnTo(20.25, 0, 1000,false,80);
	delay(20);
	wings.set_value(true);
	delay(20);
	chassis.setPose(0, 0, 0);
	delay(20);
	chassis.moveTo(0, -28.0, 2000);
	delay(20);
	chassis.setPose(0, 0, 0);
	delay(20);
	for (int i=0; i<100000; i++) {
		chassis.moveTo(0, 5.0, 1000);
		delay(20);
		chassis.moveTo(0, -8.0, 1000);
		delay(20);
	}
}

void runAuton(int autonSelect) {
  switch (autonSelect) {
    case 1: farAutonRisky(); break;
	case 2: closeAuton(); break;
	case 3: farAutonSafe(); break;
	case 4: skills(); break;
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
	runAuton(1);
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
	
	bool shoot = false;
	bool toggle = false;

	while (true) {
		
		int val = limit.get_value();

		if(master.get_digital(DIGITAL_L1)){
			intake.move_velocity(190);
		}
		else if (master.get_digital(DIGITAL_L2)){
			intake.move_velocity(-190);
		}
		else {
			intake.move_velocity(0);
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

		if(shoot||!val){
			cata.move_velocity(90);
		}
		else{
			cata.move_velocity(0);
		}

		double rX = master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
        double lY = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);

		// std::pair<double, double> speed = curvatureDrive(rX, lY);
		// float left = speed.first;
		// float right = speed.second;

		int left = velocity(lY + rX);
		int right = velocity(lY - rX);

		leftGroup.move_velocity((left)*power);
		rightGroup.move_velocity((right)*power);

	

		delay(20);
	}
}
