#include "lemlib/chassis/chassis.hpp"
#include "lemlib/chassis/trackingWheel.hpp"
#include "main.h"
#include "pros/adi.hpp"
#include "pros/motors.hpp"

Controller master(pros::E_CONTROLLER_MASTER);

Motor cata(20, E_MOTOR_GEAR_RED);

Motor intake(1, E_MOTOR_GEAR_BLUE);

Motor leftBack(-14, E_MOTOR_GEAR_BLUE);
Motor leftMid(-15, E_MOTOR_GEAR_BLUE);
Motor leftFront(13, E_MOTOR_GEAR_BLUE);

Motor rightBack(-18, E_MOTOR_GEAR_BLUE);
Motor rightMid(16, E_MOTOR_GEAR_BLUE);
Motor rightFront(17, E_MOTOR_GEAR_BLUE);

ADIDigitalOut wings('A');
ADIDigitalOut hang('F');
ADIDigitalOut park('F');
ADIAnalogIn selector('C');

// ADIEncoder verticalEnc('B', 'C');
// ADIEncoder horizontalEnc('D', 'E');

Imu inertial(11);


//Lemlib

MotorGroup leftGroup({leftBack, leftMid, leftFront});
MotorGroup rightGroup({rightBack, rightMid, rightFront});

lemlib::Drivetrain drivetrain = {
	&leftGroup,
	&rightGroup,
	12.625,
	2.75,
	450,
	0
};

// lemlib::TrackingWheel verticalTrack(&verticalEnc, 2.75, -4.6);
// lemlib::TrackingWheel horizontalTrack(&horizontalEnc, 2.75, 1.7);

lemlib::OdomSensors odom{
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	&inertial
};

lemlib::ControllerSettings lateralPID{
	16,
	0,
	21,
	3,
	0.1,
	100,
	3,
	500,
	0
};

//24.95

//18, 0.3

//20.4, 5.4

//21.604, 5.93

//21.6128, 5.984

lemlib::ControllerSettings angularPID{
	3.6,
	0,
	18,
	3,
	0.1,
	100,
	3,
	500,
	0
};

//3, 10
//3.5, 11


// lemlib::ChassisController_t lateralPID{
// 	9.9,
// 	1.1,
//     1,
//     1000,
//     3,
//     500,
// 	5
// };

// // 18.514,
// // 	1.81583,

// lemlib::ChassisController_t angularPID{
// 	1,
// 	0.1,
// 	1,
// 	100,
// 	3,
// 	500,
// 	40
// };

// 2.2,
// 	0.97,
lemlib::Chassis chassis(drivetrain, lateralPID, angularPID, odom);