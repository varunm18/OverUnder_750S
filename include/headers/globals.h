#include "lemlib/api.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "pros/misc.hpp"

using namespace pros;

extern Controller master;

extern Motor cata;
extern Motor intake1;
extern Motor intake2;

extern Motor leftBack;
extern Motor leftMid;
extern Motor leftFront;
extern Motor rightBack;
extern Motor rightMid;
extern Motor rightFront;

extern ADIDigitalIn limit;
extern ADIEncoder verticalEnc;
extern ADIEncoder horizontalEnc;

extern Imu inertial;

//Lemlib

extern lemlib::Chassis chassis;