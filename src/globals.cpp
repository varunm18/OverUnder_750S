#include "main.h"
#include "pros/motors.hpp"

Controller master(pros::E_CONTROLLER_MASTER);

Motor cata(10, E_MOTOR_GEAR_RED);

Motor intake1(1, E_MOTOR_GEAR_GREEN);
Motor intake2(-2, E_MOTOR_GEAR_GREEN);
MotorGroup intake({intake1, intake2});

Motor leftBack(-8, E_MOTOR_GEAR_BLUE);
Motor leftMid(-7, E_MOTOR_GEAR_BLUE);
Motor leftFront(-6, E_MOTOR_GEAR_BLUE);

Motor rightBack(18, E_MOTOR_GEAR_BLUE);
Motor rightMid(19, E_MOTOR_GEAR_BLUE);
Motor rightFront(20, E_MOTOR_GEAR_BLUE);

ADIDigitalIn limit('A');
ADIDigitalOut wings('E');
ADIEncoder verticalEnc('B', 'C');
ADIEncoder horizontalEnc('D', 'F');

Imu inertial(21);


//Lemlib

MotorGroup leftGroup({leftBack, leftMid, leftFront});
MotorGroup rightGroup({rightBack, rightMid, rightFront});

lemlib::Drivetrain_t drivetrain = {
	&leftGroup,
	&rightGroup,
	12.625,
	2.75,
	450
};

lemlib::TrackingWheel verticalTrack(&verticalEnc, 2.75, -4.6);
lemlib::TrackingWheel horizontalTrack(&horizontalEnc, 2.75, 1.7);

lemlib::OdomSensors_t odom {
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	&inertial
};

lemlib::ChassisController_t lateralPID{
	18.514,
	1.81583,
    1,
    1000,
    3,
    500,
	5
};

// 18.514,
// 	1.81583,

lemlib::ChassisController_t angularPID{
	2.2,
	0.97,
	1,
	100,
	3,
	500,
	40
};

// 2.2,
// 	0.97,

lemlib::Chassis chassis(drivetrain, lateralPID, angularPID, odom);