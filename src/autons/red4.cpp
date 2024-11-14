#include "main.h"

// 3 goal - side
void red4(){
    // setup
    chassis.setPose(0,0,146);
    intake.set_encoder_units_all(MOTOR_ENCODER_ROTATIONS);
    left.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    right.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    mogo.set_value(false);

    //score ring
    // pto.set_value(true);
    chassis.moveDistance(10,1000,{},false);
    deploy.set_value(true);
    claw.set_value(true);
    pros::delay(200);

    // get mogo
    chassis.moveToPoint(-13, 31,4000,{.forwards = false,.maxSpeed=60});
    while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
    pros::delay(50);
    mogo.set_value(true);
    // pros::delay(50);
    chassis.cancelMotion();
    left.brake();
    right.brake();
    deploy.set_value(false);
    pros::delay(100);
    

    //get 2 rings
    set_intake_speed(127);
    chassis.swingToPoint(-30,44,DriveSide::LEFT,2000,{.maxSpeed=80, .minSpeed=5, .earlyExitRange = 10});
    chassis.turnToPoint(-30,44,1000);
    chassis.moveToPoint(-30,44,1000);
    chassis.turnToHeading(267,1000,{.minSpeed=5,.earlyExitRange=3});
    chassis.moveDistance(18,1000);
    // chassis.moveDistance(15,2000);

    chassis.turnToHeading(290,1000,{.minSpeed=5,.earlyExitRange=3});
    chassis.moveDistance(10,1000,{.forwards=false,.minSpeed=5,.earlyExitRange=3});
    chassis.turnToPoint(-30,11,1000,{.minSpeed=5,.earlyExitRange=3});

    // chassis.turnToPoint(-30,11,2000,{.minSpeed=5,.earlyExitRange=3});
    // chassis.moveDistance(10,2000);
    // pros::delay(1000);
    // intake.move(127);
    // chassis.moveToPoint(-30,11,4000,{.minSpeed=5,.earlyExitRange=3});
    // pros::delay(500);
    // chassis.cancelMotion();
    // left.
    // pros::delay(500);
    // chassis.moveToPoint(-30,11,4000,{.minSpeed=5,.earlyExitRange=3});
    fast_move(-30,11,2000,true);



    //28 -1
    chassis.turnToPoint(20,15,1000,{.minSpeed=5,.earlyExitRange=3});
    // chassis.moveToPoint(16,16,2000);
    fast_move(20,15,2000,true);
    mogo.set_value(false);
    // chassis.moveToPoint(28,-1,4000,{.maxSpeed = 40});
    while(!(vision.get_by_sig(0,REDCOLOR).width>100 && distance.get_distance()<150)&&chassis.isInMotion()) pros::delay(10);
    set_intake_speed(0);


    chassis.turnToPoint(38,29, 1000,{.forwards=false});
    chassis.moveToPoint(38,29,2000,{.forwards=false,.maxSpeed=60});
    while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
    pros::delay(50);
    mogo.set_value(true);
    pros::delay(50);
    chassis.cancelMotion();

    chassis.turnToPoint(65,29,2000,{.minSpeed=5,.earlyExitRange=3});
    set_intake_speed(127);
    chassis.moveToPoint(65,29,2000);

    chassis.moveToPoint(26,35,2000,{.forwards=false});
    set_intake_speed(0);

}