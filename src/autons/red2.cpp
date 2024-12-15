#include "main.h"

// void red2(){
//     //get contested mogo
//     chassis.setPose(0,0,12);
//     mogo.set_value(false);
//     chassis.moveToPoint(6,40,4000,{.minSpeed=20,.earlyExitRange=5},false);
//     swiper.set_value(true);
//     left.move(-127);
//     right.move(-127);
//     pros::delay(100);
//     left.move(0);
//     right.move(0);
    

//     //get mogo
//     chassis.turnToPoint(-12,28,2000,{.forwards=false},false);
    
//     // chassis.moveToPoint(-12,28,2000,{.forwards=false});
//     chassis.moveDistance(40,3000,{.forwards=false,.maxSpeed=60});
//     swiper.set_value(false);
//     while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
//     pros::delay(100);
//     mogo.set_value(true);
//     pros::delay(100);
//     chassis.cancelMotion();

//     //20 36
//     //intake ring
//     chassis.moveToPoint(15,32,2000);
//     pros::delay(200);
//     intake.move(127);
//     // intake.move(0);

//     //start
//     // chassis.turnToPoint(5,-3,2000,{.forwards=false,.minSpeed = 10,.earlyExitRange=5});
//     // chassis.moveToPoint(5,-3,2000,{.forwards=false},false);
//     // chassis.turnToPoint(22,-9,2000,{},false);
//     // swiper.set_value(true);
//     // chassis.moveToPoint(22,-9,2000,{},false);
//     // intake.move(0);
//     // chassis.turnToHeading(35,3000,{.direction=AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed=127, .earlyExitRange = 3},false);
//     // left.move(127);
//     // right.move(-127);
//     // pros::delay(50);
//     // left.move(0);
//     // right.move(0);
//     // swiper.set_value(false);
//     // intake.move(127);
//     // chassis.moveDistance(12,2000,{.maxSpeed=30,.minSpeed=30,.earlyExitRange=3});
//     // chassis.turnToPoint(32,28,3000);
//     // chassis.moveDistance(40,10000,{.maxSpeed=30,.minSpeed=30,.earlyExitRange=3},false);
//     //end




//     chassis.turnToPoint(-4,-5,2000,{.forwards=false,.minSpeed = 10,.earlyExitRange=5});
//     chassis.moveToPoint(-4,-5,2000,{.forwards=false},false);
//     chassis.turnToPoint(22,-12,2000,{},false);
//     swiper.set_value(true);
//     chassis.moveToPoint(22,-12,2000,{},false);
//     intake.move(0);
//     chassis.turnToHeading(40,3000,{.direction=AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed=127, .earlyExitRange = 3},false);
//     left.move(127);
//     right.move(-127);
//     pros::delay(50);
//     left.move(0);
//     right.move(0);
//     swiper.set_value(false);
//     intake.move(127);
//     chassis.moveDistance(12,2000,{.maxSpeed=30,.minSpeed=30,.earlyExitRange=3});
//     chassis.turnToPoint(32,28,3000);
//     chassis.moveDistance(6,1000,{.forwards=false,.minSpeed=30,.earlyExitRange=3});
//     chassis.moveDistance(42,10000,{.maxSpeed=30,.minSpeed=30,.earlyExitRange=3},false);

    

//     chassis.moveDistance(15,2000,{.forwards=false},false);
//     pros::delay(500);
//     mogo.set_value(false);

//     chassis.turnToPoint(20,40,2000,{.forwards=false});
//     chassis.moveToPoint(20,40,2000,{.forwards = false,.maxSpeed=60});
//     if(mogo_seated()){
//         pros::delay(50);
//         mogo.set_value(true);
//         pros::delay(50);
//         // chassis.cancelMotion();
//     }

//     // pros::delay(500);
//     // mogo.set_value(false);
//     // chassis.turnToPoint(-23,39,2000,{.minSpeed=30,.earlyExitRange=3},false);
//     // intake.move(0);
//     // chassis.moveToPoint(-23,39,2000);
// }
bool ring_in = false;
pros::Mutex ring_in_mutex;
//finals + side
void red2(){
    left.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    right.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    //get contested mogo
    chassis.setPose(0,0,12);
    mogo.set_value(false);
    chassis.moveToPoint(8,41,4000,{.minSpeed=1},false);
    swiper.set_value(true);
    left.brake();
    right.brake();
    pros::delay(100);
    left.move(0);
    right.move(0);
    chassis.turnToHeading(-45,1000,{.minSpeed=5,.earlyExitRange=3},false);
    swiper.set_value(false);
    

    //get mogo
    chassis.turnToPoint(-12,28,1000,{.forwards=false},false);
    
    // chassis.moveToPoint(-12,28,2000,{.forwards=false});
    chassis.moveDistance(40,3000,{.forwards=false,.maxSpeed=60});
    // chassis.waitUntil(15);
    // swiper.set_value(false);
    while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
    pros::delay(100);
    mogo.set_value(true);
    pros::delay(100);
    chassis.cancelMotion();

    //20 36
    //intake ring
    // chassis.moveToPoint(-10,30,2000,{.minSpeed=5,.earlyExitRange=3});
    set_intake_speed(127);
    chassis.moveToPoint(19,30,2000,{},false);
    // pros::delay(1000);
    // set_intake_speed(-127);
    // chassis.moveToPoint(24,30,1000,{.minSpeed=5,.earlyExitRange=3});
    
    // pros::delay(200);
    // intake.move(127);
    // intake.move(0);




    chassis.turnToPoint(-5,-5,2000,{.forwards=false,.minSpeed = 5,.earlyExitRange=3});
    chassis.moveToPoint(-5,-5,2000,{.forwards=false},false);
    chassis.turnToPoint(22,-12,2000,{.minSpeed = 5,.earlyExitRange=3},false);
    swiper.set_value(true);
    chassis.moveToPoint(22,-12,2000,{.minSpeed = 5});
    // intake.move(0);
    set_intake_speed(0);
    chassis.turnToHeading(45,3000,{.direction=AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed=127, .earlyExitRange = 3},false);
    left.move(127);
    right.move(-127);
    pros::delay(50);
    left.move(0);
    right.move(0);
    swiper.set_value(false);
    // chassis.turnToHeading(105,3000,{.direction=AngularDirection::CW_CLOCKWISE},false);
    // swiper.set_value(true);
    // pros::delay(200);
    // chassis.turnToHeading(45,3000,{.direction=AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed=127, .earlyExitRange = 3},false);
    // left.move(127);
    // right.move(-127);
    // pros::delay(50);
    // left.move(0);
    // right.move(0);
    // swiper.set_value(false);


    set_intake_speed(127);
    pros::Task auton_task{[=]{
        while(true){
            if(vision.get_by_sig(0,REDCOLOR).width>100 && distance.get_distance()<150){
                pros::delay(1000);
                set_intake_speed(0);
                // ring_in_mutex.lock();
                // ring_in = true;
                // ring_in_mutex.unlock();
                break;
            }
            pros::delay(10);
        }
    }};
    chassis.moveDistance(12,2000,{.maxSpeed=60,.minSpeed=5,.earlyExitRange=3});
    chassis.turnToPoint(32,28,2000,{.minSpeed=5,.earlyExitRange=3});
    chassis.moveDistance(40,10000,{.maxSpeed=60,.minSpeed=5,.earlyExitRange=3});
    // while(chassis.isInMotion()){
    //     ring_in_mutex.lock();
    //     if(ring_in){
    //         chassis.cancelMotion();
    //         // pros::delay(1000);
    //         // set_intake_speed(0);
    //         break;
    //     }
    //     ring_in_mutex.unlock();
    //     pros::delay(10);
    // }

    chassis.moveDistance(15,2000,{.forwards=false},false);
    mogo.set_value(false);
    pros::delay(500);
    

    chassis.turnToPoint(20,40,2000,{.forwards=false,.minSpeed=5,.earlyExitRange=3});
    chassis.moveToPoint(20,40,2000,{.forwards = false,.maxSpeed=60});
    if(mogo_seated()){
        pros::delay(50);
        mogo.set_value(true);
        pros::delay(50);
        // chassis.cancelMotion();
    }

}

