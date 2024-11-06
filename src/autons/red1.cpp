#include "main.h"

void red1(){
    //setup
    chassis.setPose(0,0,146);
    intake.set_encoder_units_all(MOTOR_ENCODER_ROTATIONS);
    mogo.set_value(false);

    //score ring
    pto.set_value(true);
    chassis.moveDistance(11,1000,{},false);
    deploy.set_value(true);
    claw.set_value(true);
    pros::delay(200);

    // get mogo
    chassis.moveToPoint(-13, 31,4000,{.forwards = false,.maxSpeed=60});
    intake.move(-127);
    pros::delay(300);
    intake.move(0);
    deploy.set_value(false);
    pto.set_value(false);

    while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
    chassis.cancelMotion();
    pros::delay(50);
    mogo.set_value(true);
    pros::delay(50);
    left.move(127);
    right.move(127);
    pros::delay(100);
    left.move(0);
    right.move(0);
    

    //get 2 rings
    chassis.swingToPoint(-30,44,DriveSide::LEFT,2000,{.maxSpeed=80});
    intake.move(127);
    chassis.moveToPoint(-30,44,2000);
    chassis.turnToHeading(265,1000);
    chassis.moveDistance(15,2000,{},false);
    // chassis.moveDistance(15,2000);

    chassis.turnToPoint(-30,11,2000,{.minSpeed=5,.earlyExitRange=3});
    // chassis.moveDistance(10,2000);
    // pros::delay(1000);
    // intake.move(127);
    chassis.moveToPoint(-30,11,4000);
    // intake.move(0);

    //28 -1
    chassis.turnToPoint(28,-1,2000,{.minSpeed=5,.earlyExitRange=3});
    chassis.moveToPoint(28,-1,2000,{.minSpeed=127,.earlyExitRange = 40});
    chassis.moveToPoint(28,-1,4000,{.maxSpeed = 40},false);
    // while(!(vision.get_by_sig(0,REDCOLOR).width>100 && distance.get_distance()<150)) pros::delay(10);
    // chassis.cancelMotion();
    // intake.move(0);

    // /22.5 30
    intake.move(0);
    chassis.turnToPoint(25,35,2000,{.minSpeed=5,.earlyExitRange=3},false);
    intake.move(127);
    chassis.moveToPoint(25,35,2000);

    // // -54 -6
    // chassis.turnToPoint(-44,-5,4000);
    // chassis.moveDistance(44,1000);
    // chassis.moveDistance(20,2000,{.forwards=false});

    // //26 1.5
    // chassis.moveToPoint(35,6,4000,{.minSpeed=127,.earlyExitRange = 40});
    // chassis.moveToPoint(35,6,4000,{.maxSpeed = 40},false);
    // intake.move(0);
    // // while(!(vision.get_by_sig(0,1).width < 100 && ringdistancesensor.get_distance()<75)) pros::delay(100);
    // // chassis.cancelMotion();

    // // chassis.moveToPoint(72,-10,4000,{.forwards = false},false);
    // // intake.move(0);
    // // mobo.set_value(false);
    // // chassis.moveDistance(10,1500);
    
    // swiper.set_value(true);
    // chassis.turnToPoint(69,-8,2000);
    // chassis.moveToPoint(69,-8,2000);
    // chassis.turnToHeading(-45,1000,{.direction=AngularDirection::CCW_COUNTERCLOCKWISE},false);
    // chassis.moveDistance(20,1000,{.forwards=false},false);
    // mogo.set_value(false);
    // pros::delay(200);
    // chassis.moveDistance(10,1000);
}

// void red1(){
//     //setup
//     chassis.setPose(0,0,144);
//     intake.set_encoder_units_all(MOTOR_ENCODER_ROTATIONS);
//     mogo.set_value(false);

//     //score ring
//     pto.set_value(true);
//     chassis.moveDistance(10,1000,{},false);
//     deploy.set_value(true);
//     claw.set_value(true);
//     pros::delay(200);

//     // get mogo
//     chassis.moveToPoint(-13, 31,4000,{.forwards = false,.maxSpeed=70});
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
    

//     //get 2 rings
//     chassis.swingToPoint(-30,44,DriveSide::LEFT,2000,{.maxSpeed=80});
//     intake.move(127);
//     chassis.moveToPoint(-30,44,2000);
//     chassis.turnToHeading(271,1000);
//     chassis.moveDistance(15,2000,{},false);
//     // chassis.moveDistance(15,2000);

//     chassis.turnToPoint(-30,11,2000,{.minSpeed=5,.earlyExitRange=3});
//     // chassis.moveDistance(10,2000);
//     // pros::delay(1000);
//     // intake.move(127);
//     chassis.moveToPoint(-30,11,4000,{.maxSpeed=90});
//     // intake.move(0);

//     //28 -1
//     chassis.turnToPoint(28,-1,2000,{.minSpeed=5,.earlyExitRange=3});
//     chassis.moveToPoint(28,-1,2000,{.minSpeed=127,.earlyExitRange = 40},false);
//     mogo.set_value(false);
//     chassis.moveToPoint(28,-1,4000,{.maxSpeed = 40});
//     while(!(vision.get_by_sig(0,REDCOLOR).width>100 && distance.get_distance()<150)&&chassis.isInMotion()) pros::delay(10);
//     chassis.cancelMotion();


//     chassis.turnToPoint(38,29, 2000,{.forwards=false});
//     int move = 0;
//     while(vision.get_by_sig(0,REDCOLOR).width>100) {
//         if(!chassis.isInMotion()){
//             chassis.moveToPoint(38,29, 2000, {.forwards=false});
//             move = 1;
//         }
//         pros::delay(5);
//     }
//     intake.move(0);
//     if(move==0) chassis.moveToPoint(38,29, 2000, {.forwards=false});
//     while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
//     chassis.cancelMotion();
//     pros::delay(50);
//     mogo.set_value(true);
//     pros::delay(50);

//     chassis.turnToPoint(60,22,2000,{.minSpeed=5,.earlyExitRange=3},false);
//     intake.move(127);
//     chassis.moveToPoint(60,22,2000);

//     chassis.moveToPoint(36,37,1000,{.forwards=false});
    
//     //38 29

//     // chassis.turnToPoint(25,30,2000);
//     // chassis.moveToPoint(25,30,2000);

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