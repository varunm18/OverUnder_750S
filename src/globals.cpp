#include "main.h"
#include "pros/adi.hpp"
#include "pros/motors.h"

Controller master(pros::E_CONTROLLER_MASTER);

Motor cata(16, E_MOTOR_GEAR_RED, false, pros::E_MOTOR_ENCODER_COUNTS);
Motor intake1(20, E_MOTOR_GEAR_GREEN, false, pros::E_MOTOR_ENCODER_COUNTS);
Motor intake2(14, E_MOTOR_GEAR_GREEN, true, pros::E_MOTOR_ENCODER_COUNTS);

Motor leftBack(11, E_MOTOR_GEAR_BLUE, true);
Motor leftMid(12, E_MOTOR_GEAR_BLUE, true);
Motor leftFront(13, E_MOTOR_GEAR_BLUE, true);

Motor rightBack(1, E_MOTOR_GEAR_BLUE, true);
Motor rightMid(2, E_MOTOR_GEAR_BLUE, true);
Motor rightFront(3, E_MOTOR_GEAR_BLUE, true);

ADIDigitalIn limit('A');

Imu inertial(2);