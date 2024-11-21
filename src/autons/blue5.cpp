#include "main.h"

//4 ring 3 goal +
void blue5(){
    intake.set_encoder_units_all(MOTOR_ENCODER_ROTATIONS);
    chassis.setPose(0,0,146);
    mogo.set_value(false);

    //score ring
    // pto.set_value(true);
    chassis.moveDistance(11,1000,{},false);
    deploy.set_value(true);
    claw.set_value(true);
    pros::delay(200);

    // pto.set_value(false);
    chassis.moveToPoint(-15, 31,4000,{.forwards = false,.maxSpeed=70});
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
    chassis.moveToPoint(12,12,2000);
    // fast_move(10,12,2000,false);
    pros::Clock::time_point start_time2 =  pros::Clock::now();
    while(!(vision.get_by_sig(0,BLUECOLOR).width>100 && distance.get_distance()<150) && ((pros::Clock::now()-start_time2).count()<3000)) pros::delay(10);
    pros::delay(500);

    

    chassis.turnToPoint(-42,32,2000,{.direction=lemlib::AngularDirection::CW_CLOCKWISE,.minSpeed=5,.earlyExitRange=3});
    // mogo.set_value(false);
    // set_intake_speed(127);
    chassis.moveToPoint(-42,32,2000);
    chassis.waitUntil(10);
    mogo.set_value(false);
    // fast_move(38,30,2000,false);
    while(!(vision.get_by_sig(0,BLUECOLOR).width>100 && distance.get_distance()<150)&&chassis.isInMotion()) pros::delay(10);
    set_intake_speed(0);
    
    
    chassis.turnToPoint(-40,44,2000,{.forwards=false},false);
    chassis.moveToPoint(-40,44,4000,{.forwards = false,.maxSpeed=60});
    while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
    pros::delay(50);
    mogo.set_value(true);
    pros::delay(50);
    chassis.cancelMotion();

    chassis.moveDistance(5,1000,{.minSpeed=127,.earlyExitRange=3});
    chassis.turnToPoint(-53,-4,2000,{.minSpeed=5,.earlyExitRange=3});
    set_intake_speed(127);
    swiper.set_value(true);
    chassis.moveToPoint(-53,-4,2000);
    chassis.turnToHeading(145,3000,{.direction=AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed=127, .earlyExitRange = 3},false);
    left.move(127);
    right.move(-127);
    pros::delay(50);
    left.move(0);
    right.move(0);
    set_intake_speed(127);
    swiper.set_value(false);
    chassis.moveDistance(15,1000);
    while(!(vision.get_by_sig(0,REDCOLOR).width>100 && distance.get_distance()<150)&&chassis.isInMotion()) pros::delay(10);
    chassis.cancelMotion();
    chassis.moveToPoint(0,38,4000,{},false);
    set_intake_speed(0);
    // // chassis.turnToHeading(0,1000);
    // // chassis.moveDistance(6,1000,{.forwards=false,.minSpeed=30,.earlyExitRange=3});
    // // chassis.moveDistance(42,10000,{.maxSpeed=30,.minSpeed=30,.earlyExitRange=3},false);
}