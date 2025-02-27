#include "main.h"


pros::MotorGroup intake({7,10});
pros::MotorGroup arm({8,-9});
pros::ADIDigitalOut mogo('A');
pros::ADIDigitalOut pto('D');
pros::ADIDigitalOut swiper('C');
pros::ADIDigitalOut intake_lift('B');
pros::ADIDigitalOut sort_thrower('G');
pros::ADIDigitalOut deploy('F');
pros::ADIDigitalOut claw('E');


pros::Rotation arm_control(-19);


// pros::Vision vision(14);
pros::Distance distance(8);
pros::Distance top_distance(16);
pros::Distance mogo_distance(13);
pros::Optical ring_color(20);
// pros::Distance ladybrown_dist(8);

pros::Controller master(pros::E_CONTROLLER_MASTER);


// red (1,252,215,220,7,.34)
// blue(2,173,254,254,26,.68)
