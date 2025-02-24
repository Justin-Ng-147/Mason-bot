#ifndef _ROBOT_HPP_
#define _ROBOT_HPP_

extern pros::MotorGroup intake;
extern pros::ADIDigitalOut mogo;
extern pros::ADIDigitalOut pto;
extern pros::ADIDigitalOut swiper;
extern pros::ADIDigitalOut intake_lift;
// extern pros::Vision vision;
extern pros::Distance distance;
extern pros::ADIDigitalOut sort_thrower;
extern pros::Distance mogo_distance;
extern pros::ADIDigitalOut deploy;
extern pros::ADIDigitalOut claw;

extern pros::MotorGroup arm;
extern pros::Rotation arm_control;
extern pros::Distance top_distance;
extern pros::Optical ring_color;
extern pros::Controller master;

extern pros::Distance ladybrown_dist;

#endif