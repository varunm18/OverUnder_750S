#include "main.h"
#include "lemlib/asset.hpp"
#include "pros/llemu.hpp"
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
	selector.calibrate();
	chassis.calibrate();
	cata.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	intake.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	// //SET INITIAL POINT
	chassis.setPose(0, 0, 0);
	
	lcd::set_text(0, "Hello PROS User!");
	lcd::register_btn1_cb(on_center_button);

	Task screenTask([&]() {
        lemlib::Pose pose(0, 0, 0);
        while (true) {
            // print robot location to the brain screen
            pros::lcd::print(1, "X: %f", chassis.getPose().x); // x
            pros::lcd::print(2, "Y: %f", chassis.getPose().y); // y
            pros::lcd::print(3, "Theta: %f", chassis.getPose().theta); // heading
			int val = selector.get_value();
			lcd::print(5, "Auton: %i", val);
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

ASSET(SixStart_txt);
ASSET(SixFinish_txt);

void farQuals(){
	//8.7
	chassis.setPose(12, -60, 270);
	intake.move_velocity(590);
	chassis.moveToPoint(8, -60, 600);
	//MAKE THIS FASTER 
	chassis.follow(SixStart_txt, 15, 5000, false);
	chassis.waitUntil(42);
	park.set_value(true);
	chassis.turnTo(58, -24, 300, false);
	park.set_value(false);
	chassis.turnTo(58, -24, 700);
	chassis.moveToPoint(60, -28, 650);
	chassis.waitUntil(0.5);
	intake.move_velocity(-590);
	chassis.moveToPoint(60, -37, 500, false);
	chassis.moveToPoint(60, -28, 500);

	//6.3 left
	chassis.moveToPoint(58, -41, 600, false);
	chassis.turnTo(13, -28, 650);
	chassis.moveToPoint(13, -28, 1500);
	chassis.waitUntil(32);
	intake.move_velocity(590);
	chassis.turnTo(23, -22, 700);
	chassis.moveToPoint(23, -22, 1000);
	chassis.waitUntil(1);
	intake.move_velocity(-590);
	chassis.turnTo(8, -6, 1000);
	chassis.moveToPoint(8, -6, 1000);
	chassis.waitUntil(1);
	intake.move_velocity(590);
	chassis.turnTo(47.5, 0, 1000);
	chassis.moveToPoint(47.5, 0, 1000);
	chassis.waitUntil(1);
	wings.set_value(true);
	chassis.waitUntil(25);
	intake.move_velocity(-590);
	chassis.moveToPoint(28, 0, 600, false);
	chassis.moveToPoint(47.5, 0, 1000);
	wings.set_value(false);
	chassis.moveToPoint(28, 0, 600, false);
	// chassis.waitUntil(1);
	// wings.set_value(true);

	// chassis.turnTo(11.3, -6.4, 500);
	// intake.move_velocity(590);
	// chassis.moveToPoint(11.3, -6.4, 500);
	// chassis.turnTo(53, -6.4, 500);
	// wings.set_value(true);
	// chassis.moveToPoint(53, -6.4, 500);

	delay(2000);
	intake.move_velocity(0);
}

ASSET(CloseFinals_txt);

void closeQuals(){
	chassis.setPose(36, 60, 180);
	wings.set_value(true);
	delay(1000);
	wings.set_value(false);
	delay(200);
	chassis.moveToPoint(25, 9, 2000);
	chassis.waitUntil(20);
	intake.move_velocity(590);
	chassis.moveToPoint(52, 52, 2000, false);
	chassis.waitUntilDone();
	park.set_value(true);
	chassis.turnTo(0, 59, 800, false);
	chassis.turnTo(0, 62, 800);
	park.set_value(false);
	intake.move_velocity(-590);
	delay(500);
	chassis.moveToPoint(60, 36, 1000, false);
	intake.move_velocity(-590);
	chassis.follow(CloseFinals_txt, 15, 5000);

	delay(10000);
	intake.move_velocity(0);
}

ASSET(SkillsStart_txt);
ASSET(SkillsClean_txt);
ASSET(SkillsRotate_txt);
ASSET(SkillsFirst_txt);
ASSET(SkillsRotatetxt2_txt);

void skills(){
	// chassis.setPose(36, 60, 270);
	// chassis.turnTo(48, 48, 400, false);
	// chassis.moveToPoint(51, 45, 800, false);
	// chassis.turnTo(-50, -8, 700);
	// chassis.moveToPoint(57.5, 46.5, 700, false);
	

	// // cata.move_velocity(99);
	// // delay(31000);
	// // cata.move_velocity(0);

	// chassis.follow(SkillsClean3_txt, 15, 3000);
	// chassis.moveToPoint(11, -35, 1000);
	// // intake.move_velocity(-590);
	// // chassis.waitUntil(36);
	// // wings.set_value(true);
	// // chassis.waitUntilDone();
	// // wings.set_value(false);
	// // delay(500);
	// chassis.turnTo(-60, -36, 1000);

	// chassis.follow(SkillsRotate_txt, 15, 4000, false);
	// chassis.turnTo(0, -60, 700, false);
	// chassis.follow(SkillsFirst_txt, 15, 7000, false);

	// delay(5000);
	// intake.move_velocity(0);

	chassis.setPose(36, 60, 270);
	chassis.follow(SkillsStart_txt, 15, 2000, false);
	chassis.moveToPoint(62, 44, 500);
	chassis.turnTo(-50, 8, 500);
	intake.move_velocity(590);
	chassis.moveToPoint(63, 44, 700, false);
	intake.move_velocity(0);

	delay(1000);

	// cata.move_velocity(99);
	// delay(31000);
	// cata.move_velocity(0);

	chassis.follow(SkillsClean_txt, 15, 7000);
	// intake.move_velocity(-590);
	// chassis.waitUntil(40);
	// wings.set_value(true);
	// chassis.waitUntilDone();
	// wings.set_value(false);
	// delay(500);
	// chassis.moveToPoint(15, -38, 700, false);
	// chassis.turnTo(20, -38, 700, false);
	// chassis.follow(SkillsRotatetxt2_txt, 15, 5000,false);
	// chassis.turnTo(-60, -36, 1000);

	// chassis.follow(SkillsRotate_txt, 15, 4000, false);
	// chassis.turnTo(0, -60, 700, false);
	// chassis.follow(SkillsFirst_txt, 15, 7000, false);


	// delay(5000);
	// intake.move_velocity(0);
}

void runAuton(int autonSelect) {
  switch (autonSelect) {
    case 1: farQuals(); break;
	case 2: closeQuals(); break;
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
	int auton = selector.get_value();
	if(auton<1364){
		auton=1;
	}
	else if(1364<auton&&auton<2727){
		auton=2;
	}
	else{
		auton=3;
	}
	runAuton(3);
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
	bool toggle1 = false;
	bool toggle2 = false;
	bool toggle3=false;
	bool shift = false;
	
	// SKILLS
	chassis.setPose(36, 60, 270);
	chassis.follow(SkillsStart_txt, 15, 2000, false);
	chassis.moveToPoint(62, 44, 500);
	chassis.turnTo(-50, 8, 500);
	chassis.moveToPoint(63, 44, 700, false);
	shoot=true;
	cata.move_velocity(99);


	while (true) {

		//Shift
		shift = master.get_digital(DIGITAL_R2);

		// Wings
		if(master.get_digital_new_press(DIGITAL_L2)&&shift){
			toggle1 = !toggle1;
			wings.set_value(toggle1);
		}

		//Hang
		if(master.get_digital_new_press(DIGITAL_L1)&&shift){
			toggle2 = !toggle2;
			hang.set_value(toggle2);
		}
		
		//Park
		if(master.get_digital_new_press(DIGITAL_L1)&&shift){
			toggle3 = !toggle3;
			park.set_value(toggle3);
		}
		
		//Intake
		if(master.get_digital(DIGITAL_L1)&&!shift){
			intake.move_velocity(590);
		}
		else if (master.get_digital(DIGITAL_L2)&&!shift){
			intake.move_velocity(-590);
		}
		else {
			intake.move_velocity(0);
		}

		// Cata
		if(master.get_digital_new_press(DIGITAL_R1)){
			shoot = !shoot;
			cata.move_velocity(shoot*90);
		}

		//Arcade Drive

		double rX = master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
        double lY = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);

		int left = velocity(lY + rX);
		int right = velocity(lY - rX);

		// leftGroup.move_velocity((left)*power);
		// rightGroup.move_velocity((right)*power);
		
		chassis.curvature(lY, rX, 10);

		delay(20);
	}
}
