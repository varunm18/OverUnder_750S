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
	// chassis.calibrate();
	cata.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	intake.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
	// //SET INITIAL POINT
	// chassis.setPose(0, 0, 0);
	
	// lcd::set_text(0, "Hello PROS User!");
	// lcd::register_btn1_cb(on_center_button);

	// Task screenTask([&]() {
    //     lemlib::Pose pose(0, 0, 0);
    //     while (true) {
    //         // print robot location to the brain screen
    //         pros::lcd::print(1, "X: %f", chassis.getPose().x); // x
    //         pros::lcd::print(2, "Y: %f", chassis.getPose().y); // y
    //         pros::lcd::print(3, "Theta: %f", chassis.getPose().theta); // heading
    //         // delay to save resources
    //         pros::delay(50);
    //     }
    // });
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
	chassis.moveTo(-3.1, -17.1, 1000, 200);
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
	chassis.moveTo(0, 8, 1000, 120);
	delay(20);
	wings.set_value(true);
	delay(10);
	chassis.setPose(0, 0, 0);
	delay(20);
	chassis.moveTo(-2, 8, 1000, 120);
	delay(20);
	chassis.setPose(0, 0, 0);
	delay(20);
	chassis.turnTo(20, -3, 800, 200);
	delay(20);
	wings.set_value(false);
	delay(20);
	chassis.setPose(0, 0, 0);
	delay(20);
	chassis.moveTo(-9.49, 25.43, 5000, 80);
	delay(20);
	chassis.setPose(0, 0, 0);
	delay(20);
	chassis.turnTo(3.67, 1.30, 1000,false,80);
	wings.set_value(true);
	delay(20);
	delay(20);
	chassis.setPose(0, 0, 0);
	delay(20);
	chassis.moveTo(-1.6, 14.72, 1000, 80);
	delay(20);
	chassis.setPose(0, 0, 0);
	delay(20);
	chassis.moveTo(0, 10, 1000, 120);
	delay(20);
	chassis.setPose(0, 0, 0);
	delay(20);
	chassis.turnTo(-5, 0, 1000,false,80);


	// chassis.turnTo(-0.9, 12.1, 1000,false,80);
	// delay(20);
	// chassis.setPose(0, 0, 0);
	// delay(20);
	// wings.set_value(false);
	// delay(20);

	//bar
	// chassis.turnTo(-8.7, 8.7, 1000,false,80);
	// delay(20);
	// chassis.setPose(0, 0, 0);
	// delay(20);
	// chassis.moveTo(-1.6, 14.72, 1000, 80);
	// chassis.setPose(0, 0, 0);
	// delay(20);
	// chassis.turnTo(-5.35, 10.5, 1000,false,80);
	// delay(20);
	// chassis.setPose(0, 0, 0);
	// delay(20);
	// chassis.turnTo(2.57, 14.01, 1000,false,80);
	// delay(20);
	// chassis.setPose(0, 0, 0);
	// delay(20);
	// chassis.moveTo(0.77, -38.36, 4000, 50);
	// delay(20);
}

void farAutonRisky(){
	intake.move_velocity(190);
	chassis.moveTo(0, 29, 1000, 80);
	delay(10);
	chassis.setPose(0, 0, 0);
	delay(10);
	chassis.turnTo(10, 6.5, 800, false, 100);
	delay(10);
	intake.move_velocity(-190);
	delay(400);
	chassis.setPose(0, 0, 0);
	delay(10);
	chassis.turnTo(-20, -26, 1000, false, 100);
	delay(10);
	chassis.setPose(0, 0, 0);
	delay(10);
	intake.move_velocity(190);
	delay(10);
	chassis.moveTo(0, 20.5, 700, 180);
	delay(10);
	chassis.moveTo(0, 8, 600, 80);
	delay(10);

	chassis.setPose(0, 0, 0);
	delay(10);
	chassis.turnTo(6, -10, 700,false, 100);
	delay(10);
	chassis.setPose(0, 0, 0);
	delay(10);
	chassis.moveTo(0, 8, 600, 80);
	delay(10);
	intake.move_velocity(-190);
	delay(200);
	chassis.moveTo(0, 0, 700, 80);
	delay(10);
	chassis.setPose(0, 0, 0);
	delay(10);
	chassis.turnTo(-49.5, 10.48, 700, false, 100);
	delay(10);
	intake.move_velocity(190);
	delay(10);
	chassis.setPose(0, 0, 0);
	delay(10);

	chassis.moveTo(0, 19, 750, 100);
	delay(10);
	chassis.setPose(0, 0 , 0);
	delay(10);
	chassis.turnTo(30, 2.95, 700, false, 100);
	delay(10);
	chassis.setPose(0, 0 , 0);
	delay(10);
	chassis.moveTo(0, 5, 600, 80);
	delay(10);
	intake.move_velocity(-190);
	delay(300);

	chassis.setPose(0, 0 , 0);
	delay(10);
	intake.move_velocity(190);
	delay(10);
	chassis.turnTo(-5, -14.54, 750, false, 100);
	delay(10);
	chassis.setPose(0, 0 , 0);
	delay(10);
	chassis.moveTo(0, 18, 700, 100);
	delay(10);
	chassis.setPose(0, 0 , 0);
	delay(10);
	chassis.moveTo(0, -5, 400, 100);
	delay(10);

	chassis.setPose(0, 0 , 0);
	delay(10);
	chassis.turnTo(0, -24, 800, false, 100);
	delay(10);
	chassis.setPose(0, 0 , 0);
	delay(10);
	wings.set_value(true);
	delay(10);
	intake.move_velocity(-190);
	chassis.moveTo(0, 25, 700, 200);
	delay(10);
	chassis.setPose(0, 0 , 0);
	delay(10);
	chassis.moveTo(0, -20, 700, 2000);

}

void farAutonSafe(){

}


void skills(){
	//Turn to goal
	chassis.turnTo(-30, 39.84, 800);
	delay(10);
	chassis.setPose(0, 0, 0);
	delay(10);
	chassis.moveTo(0, 7, 500);
	delay(10);

	//Shoot
	cata.move_velocity(98);
	delay(43000);
	int val = limit.get_value();
	while(!val){
		cata.move_velocity(90);
		val = limit.get_value();
	}
	cata.move_velocity(0);

	//Move to opposite side
	chassis.setPose(0, 0, 0);
	delay(10);
	chassis.turnTo(12, 11.75, 800, false, 80);
	delay(10);
	chassis.setPose(0, 0, 0);
	delay(10);
	chassis.moveTo(12, -82, 3000, 120);
	delay(10);
	delay(10);
	chassis.setPose(0, 0, 0);
	delay(10);
	chassis.turnTo(-30.71, -5, 800,false,80);
	delay(10);
	chassis.setPose(0, 0, 0);
	delay(10);
	chassis.moveTo(0, -21, 800, 120);
	delay(10);
	chassis.setPose(0, 0, 0);
	delay(10);
	chassis.turnTo(28, -5, 800, false, 80);
	delay(10);
	chassis.setPose(0, 0, 0);
	delay(10);
	chassis.moveTo(0, 18, 800, 120);
	delay(10);
	chassis.setPose(0, 0, 0);
	delay(10);
	chassis.turnTo(5, 1, 800, false, 80);
	delay(10);
	chassis.setPose(0, 0, 0);
	delay(10);
	chassis.moveTo(0, 33.5, 1200, 120);
	delay(10);
	chassis.setPose(0, 0, 0);
	delay(10);
	chassis.turnTo(5, 1, 800, false, 80);
	delay(10);
	chassis.setPose(0, 0, 0);
	delay(10);
	wings.set_value(true);
	for(int i=0; i<4; i++){
		chassis.moveTo(0, 27, 1200, 120);
		delay(10);
		chassis.moveTo(0, -5, 600, 120);
		delay(10);
	}
	chassis.moveTo(0, -5, 600, 120);
	delay(10);
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
	
	bool shoot = false;
	bool toggle = false;
	// SKILLS
	// chassis.turnTo(-30, 39.84, 800);
	// delay(10);
	// chassis.setPose(0, 0, 0);
	// delay(10);
	// chassis.moveTo(0, 7, 500);
	// delay(10);
	// shoot=true;

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
