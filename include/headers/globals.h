#include "lemlib/api.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "pros/misc.hpp"
#include "pros/motors.hpp"

using namespace pros;

extern Controller master;

extern Motor cata;

extern Motor intake;

extern Motor leftBack;
extern Motor leftMid;
extern Motor leftFront;
extern Motor rightBack;
extern Motor rightMid;
extern Motor rightFront;

extern MotorGroup leftGroup;
extern MotorGroup rightGroup;

extern ADIDigitalOut wings;
extern ADIDigitalOut hang;
extern ADIDigitalOut park;
extern ADIAnalogIn selector;

extern ADIEncoder verticalEnc;
extern ADIEncoder horizontalEnc;

extern Imu inertial;

//Lemlib

extern lemlib::Chassis chassis;