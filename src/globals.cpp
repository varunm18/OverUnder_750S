#include "main.h"

Controller master(pros::E_CONTROLLER_MASTER);

Motor cata(16, E_MOTOR_GEAR_RED);
Motor intake1(20, E_MOTOR_GEAR_GREEN);
Motor intake2(14, E_MOTOR_GEAR_GREEN);

Motor leftBack(-11, E_MOTOR_GEAR_BLUE);
Motor leftMid(-12, E_MOTOR_GEAR_BLUE);
Motor leftFront(-13, E_MOTOR_GEAR_BLUE);

Motor rightBack(-1, E_MOTOR_GEAR_BLUE);
Motor rightMid(-2, E_MOTOR_GEAR_BLUE);
Motor rightFront(-3, E_MOTOR_GEAR_BLUE);

ADIDigitalIn limit('A');
ADIEncoder verticalEnc('B', 'C');
ADIEncoder horizontalEnc('D', 'E');

Imu inertial(4);


//Lemlib

MotorGroup leftGroup({leftBack, leftMid, leftFront});
MotorGroup rightGroup({rightBack, rightMid, rightFront});

lemlib::Drivetrain_t drivetrain = {
	&leftGroup,
	&rightGroup,
	10,
	2.75,
	450
};

lemlib::TrackingWheel verticalTrack(&verticalEnc, 2.75, -4.6);
lemlib::TrackingWheel horizontalTrack(&horizontalEnc, 2.75, 1.7);

lemlib::OdomSensors_t odom {
	&verticalTrack,
	nullptr,
	&horizontalTrack,
	nullptr,
	&inertial
};

lemlib::ChassisController_t lateralPID{
	8,
	30,
	1,
	100,
	3,
	500,
	5
};

lemlib::ChassisController_t angularPID{
	4,
	40,
	1,
	100,
	3,
	500,
	40
};

lemlib::Chassis chassis(drivetrain, lateralPID, angularPID, odom);