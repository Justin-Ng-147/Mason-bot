#include "main.h"


pros::Motor intake(7);
pros::MotorGroup arm({8,-9});
pros::ADIDigitalOut mogo('A');
pros::ADIDigitalOut pto('D');
pros::ADIDigitalOut swiper('C');
pros::ADIDigitalOut hang('B');
pros::ADIDigitalOut sort_thrower('G');
pros::ADIDigitalOut deploy('F');
pros::ADIDigitalOut claw('E');


pros::Rotation arm_control(-19);


pros::Vision vision(19);
pros::Distance distance(12);
pros::Distance mogo_distance(17);


// red (1,252,215,220,7,.34)
// blue(2,173,254,254,26,.68)
