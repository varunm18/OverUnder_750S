#include "lemlib/api.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "pros/misc.hpp"
#include "pros/motors.hpp"

using namespace pros;

extern Controller master;

extern Motor cata;

extern MotorGroup intake;

extern Motor leftBack;
extern Motor leftMid;
extern Motor leftFront;
extern Motor rightBack;
extern Motor rightMid;
extern Motor rightFront;

extern MotorGroup leftGroup;
extern MotorGroup rightGroup;

extern ADIDigitalIn limit;
extern ADIDigitalOut wings;
extern ADIEncoder verticalEnc;
extern ADIEncoder horizontalEnc;

extern Imu inertial;

//Lemlib

extern lemlib::Chassis chassis;