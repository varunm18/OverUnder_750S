# 750S Repo
750Spark's code for the 2023-2024 VEX Robotic's Season(Over Under)

Coded in C++ using the [PROS Library](https://pros.cs.purdue.edu)

### Details:
* Driver control code for tank drive using a curvature controller mapping with input scaling
* Far Side, Close Side and Skills autonomous code
* Autons are implmeneted using [LemLib v0.5.0-rc5](https://github.com/LemLib/LemLib/releases/tag/v0.5.0-rc.5)
* Includes advanced motion profiling with a combined PID and Odometry system that uses tracking wheels and an inertial sensor
* Autons utilize [Jerry Path Generator](https://path.jerryio.com), Pure Pursuit and a Boomerand controller with asynchronous commands
