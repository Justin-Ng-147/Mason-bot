#include "main.h"


pros::MotorGroup intake({7,-8});
pros::ADIDigitalOut mogo('A');
pros::ADIDigitalOut pto('D');
pros::ADIDigitalOut swiper('C');
pros::ADIDigitalOut hang('B');
pros::ADIDigitalOut sort_thrower('G');


pros::Vision vision(19);
pros::Distance distance(12);
pros::Distance mogo_distance(17);


// red (1,252,215,220,7,.34)
// blue(2,173,254,254,26,.68)
