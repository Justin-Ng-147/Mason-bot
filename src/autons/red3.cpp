#include "main.h"

// void red3(){
//      //setup
//     chassis.setPose(0,0,146);
//     intake.set_encoder_units_all(MOTOR_ENCODER_ROTATIONS);
//     mogo.set_value(false);

//     //score ring
//     pto.set_value(true);
//     chassis.moveDistance(11,1000,{},false);
//     claw.set_value(true);
//     pros::delay(200);
//     deploy.set_value(true);

//     // get mogo
//     chassis.moveToPoint(-13, 31,4000,{.forwards = false,.maxSpeed=60});
//     intake.move(-127);
//     pros::delay(300);
//     intake.move(0);
//     deploy.set_value(false);
//     pto.set_value(false);

//     while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
//     chassis.cancelMotion();
//     pros::delay(50);
//     mogo.set_value(true);
//     pros::delay(50);
//     left.move(127);
//     right.move(127);
//     pros::delay(100);
//     left.move(0);
//     right.move(0);
    

//     //get 2 rings
//     chassis.swingToPoint(-30,44,DriveSide::LEFT,2000,{.maxSpeed=80});
//     intake.move(127);
//     chassis.moveToPoint(-30,44,2000);
//     chassis.turnToHeading(267,1000);
//     chassis.moveDistance(15,2000,{},false);
//     // chassis.moveDistance(15,2000);

//     chassis.turnToHeading(290,1000,{.minSpeed=5,.earlyExitRange=3});
//     chassis.moveDistance(10,1000,{.forwards=false,.minSpeed=5,.earlyExitRange=3});
//     chassis.turnToPoint(-30,11,2000,{.minSpeed=5,.earlyExitRange=3});

//     chassis.turnToPoint(-30,11,2000,{.minSpeed=5,.earlyExitRange=3});
//     // chassis.moveDistance(10,2000);
//     // pros::delay(1000);
//     // intake.move(127);
//     chassis.moveToPoint(-30,11,4000,{.minSpeed=5,.earlyExitRange=3});
//     pros::delay(500);
//     chassis.cancelMotion();
//     left.move(-127);
//     right.move(-127);
//     pros::delay(100);
//     left.move(0);
//     right.move(0);
//     pros::delay(500);
//     chassis.moveToPoint(-30,11,4000,{.minSpeed=5,.earlyExitRange=3});
//     // intake.move(0);

//     //28 -1
//     chassis.turnToPoint(32,-1,2000,{.minSpeed=5,.earlyExitRange=3});
//     chassis.moveToPoint(32,-1,2000,{.minSpeed=127,.earlyExitRange = 40});
//     chassis.moveToPoint(32,-1,4000,{.maxSpeed = 40},false);
//     // while(!(vision.get_by_sig(0,REDCOLOR).width>100 && distance.get_distance()<150)) pros::delay(10);
//     // chassis.cancelMotion();
//     // intake.move(0);

//     chassis.moveToPoint(55,-1,2000);

//     // /22.5 30
//     // move to post
//     // intake.move(0);
//     // chassis.turnToPoint(25,35,2000,{.minSpeed=5,.earlyExitRange=3},false);
//     // intake.move(127);
//     // chassis.moveToPoint(25,35,2000);

//     // // -54 -6
//     // chassis.turnToPoint(-44,-5,4000);
//     // chassis.moveDistance(44,1000);
//     // chassis.moveDistance(20,2000,{.forwards=false});

//     // //26 1.5
//     // chassis.moveToPoint(35,6,4000,{.minSpeed=127,.earlyExitRange = 40});
//     // chassis.moveToPoint(35,6,4000,{.maxSpeed = 40},false);
//     // intake.move(0);
//     // // while(!(vision.get_by_sig(0,1).width < 100 && ringdistancesensor.get_distance()<75)) pros::delay(100);
//     // // chassis.cancelMotion();

//     // // chassis.moveToPoint(72,-10,4000,{.forwards = false},false);
//     // // intake.move(0);
//     // // mobo.set_value(false);
//     // // chassis.moveDistance(10,1500);
    
//     // swiper.set_value(true);
//     // chassis.turnToPoint(69,-8,2000);
//     // chassis.moveToPoint(69,-8,2000);
//     // chassis.turnToHeading(-45,1000,{.direction=AngularDirection::CCW_COUNTERCLOCKWISE},false);
//     // chassis.moveDistance(20,1000,{.forwards=false},false);
//     // mogo.set_value(false);
//     // pros::delay(200);
//     // chassis.moveDistance(10,1000);
// }




//red side 4 ring 3 goal
void red3(){
    intake.set_encoder_units_all(MOTOR_ENCODER_ROTATIONS);
    chassis.setPose(0,0,-146);
    mogo.set_value(false);

    //score ring
    // pto.set_value(true);
    chassis.moveDistance(11,1000,{},false);
    deploy.set_value(true);
    claw.set_value(true);
    pros::delay(200);

    // pto.set_value(false);
    chassis.moveToPoint(15, 31,4000,{.forwards = false,.maxSpeed=60});
    while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
    pros::delay(50);
    mogo.set_value(true);
    pros::delay(50);
    chassis.cancelMotion();
    deploy.set_value(false);


    // -18 11
    //get 2 ring red
    // chassis.turnToPoint(-18,11,2000,{},false);
    // set_intake_speed(127);
    // chassis.moveToPoint(-18,11,2000,{.maxSpeed=70});

    set_intake_speed(127);
    // chassis.moveToPoint(-23,-5,2000,{.minSpeed=5,.earlyExitRange=40});
    // chassis.moveToPoint(-23,-5,2000,{.maxSpeed=50,.minSpeed=5,.earlyExitRange=3},false);
    chassis.moveToPoint(-10,12,2000,{},false);
    pros::Clock::time_point start_time =  pros::Clock::now();
    while(!(vision.get_by_sig(0,REDCOLOR).width>100 && distance.get_distance()<150) || (pros::Clock::now()-start_time).count()>1000) pros::delay(10);

    

    chassis.turnToPoint(44,32,2000,{.direction=lemlib::AngularDirection::CW_CLOCKWISE,.minSpeed=1,.earlyExitRange=3});
    // mogo.set_value(false);
    // set_intake_speed(127);
    chassis.moveToPoint(44,32,2000);
    // chassis.waitUntil(10);
    mogo.set_value(false);
    // fast_move(38,30,2000,false);
    while(!(vision.get_by_sig(0,REDCOLOR).width>100 && distance.get_distance()<150)&&chassis.isInMotion()) pros::delay(10);
    set_intake_speed(0);
    
    
    chassis.turnToPoint(40,47,2000,{.forwards=false},false);
    chassis.moveToPoint(40,47,4000,{.forwards = false,.maxSpeed=40});
    while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
    pros::delay(50);
    mogo.set_value(true);
    pros::delay(50);
    chassis.cancelMotion();

    chassis.turnToPoint(38,0,2000,{.minSpeed=5,.earlyExitRange=3});
    set_intake_speed(127);
    chassis.moveToPoint(38,0,2000);
    // fast_move(38,0,2000,true);
    swiper.set_value(true);
    chassis.turnToPoint(46,-6,2000,{.minSpeed=5,.earlyExitRange=3},false);
    chassis.moveToPoint(46,-6,2000,{},false);
    // fast_move(46,-6,2000,false);
    set_intake_speed(0);
    chassis.turnToHeading(60,3000,{.direction=AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed=127, .earlyExitRange = 3},false);
    left.move(127);
    right.move(-127);
    pros::delay(50);
    left.move(0);
    right.move(0);
    swiper.set_value(false);
    set_intake_speed(127);
    chassis.moveDistance(15,1000);
    while(!(vision.get_by_sig(0,REDCOLOR).width>100 && distance.get_distance()<150)&&chassis.isInMotion()) pros::delay(10);
    chassis.cancelMotion();
    chassis.moveToPoint(1,44,4000,{.forwards=false},false);
    set_intake_speed(0);
    // chassis.turnToHeading(0,1000);
    // chassis.moveDistance(6,1000,{.forwards=false,.minSpeed=30,.earlyExitRange=3});
    // chassis.moveDistance(42,10000,{.maxSpeed=30,.minSpeed=30,.earlyExitRange=3},false);
}