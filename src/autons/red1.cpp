#include "main.h"

// void red1(){
//     // chassis.moveDistance()
// }

/*
skills run
*/
void red1(){
    //score red stake
    intake.move(127);
    pros::delay(1000);
    intake.move(0);

    //get mogo
    mogo.set_value(false);
    chassis.swingToPoint(-22,14,DriveSide::RIGHT,4000,{.forwards=false});
    lemlib::Pose start_pose = chassis.getPose();
    chassis.moveDistance(30,4000,{.forwards=false,.maxSpeed=60});
    while(start_pose.distance(chassis.getPose()) < 25) pros::delay(10);
    mogo.set_value(true);

    //get 1st ring
    chassis.turnToPoint(-25,40,4000,{.minSpeed=10,.earlyExitRange=5});
    intake.move(127);
    chassis.moveToPoint(-25,40,4000,{},false);
    intake.move(0);

    //get 2nd ring
    chassis.turnToPoint(-48,37,4000,{.minSpeed=10,.earlyExitRange=5});
    intake.move(127);
    chassis.moveToPoint(-48,37,4000,{},false);
    intake.move(0);
    
    //get 3rd ring
    chassis.turnToPoint(-60,62,4000,{.minSpeed=10,.earlyExitRange=5});
    intake.move(127);
    chassis.moveToPoint(-60,62,4000,{},false);
    intake.move(0);

    //get 4th and 5th ring
    // chassis.turnToPoint(-46,4,4000,{.minSpeed=10,.earlyExitRange=5});
    chassis.swingToPoint(-46,4,DriveSide::RIGHT,4000);
    intake.move(127);
    chassis.moveToPoint(-46,5,4000,{.minSpeed=60,.earlyExitRange=20});
    chassis.moveToPoint(-46,5,4000,{.maxSpeed=40},false);
    intake.move(0);

    //get 6th ring
    intake.move(127);
    chassis.moveToPose(-60,25,8,4000,{.lead=.8},false);
    intake.move(0);

    //score mogo
    chassis.moveDistance(15,1000,{.forwards=false},false);
    mogo.set_value(false);
    pros::delay(500);
    chassis.moveDistance(15,4000);

    //get new mogo
    mogo.set_value(false);
    chassis.turnToPoint(32,18,4000,{.forwards=false});
    start_pose = chassis.getPose();
    chassis.moveToPoint(32,18,4000,{.forwards=false,.minSpeed=60,.earlyExitRange=35});
    chassis.moveToPoint(32,18,4000,{.forwards=false,.maxSpeed=45});
    while(start_pose.distance(chassis.getPose()) < 80) pros::delay(10);
    mogo.set_value(true);

    //get 1st ring
    chassis.turnToPoint(30,44,4000,{.minSpeed=10,.earlyExitRange=5});
    intake.move(127);
    chassis.moveToPoint(30,44,4000,{},false);
    intake.move(0);

    //get 2nd ring
    chassis.turnToPoint(53,44,4000,{.minSpeed=10,.earlyExitRange=5});
    intake.move(127);
    chassis.moveToPoint(53,44,4000,{},false);
    intake.move(0);
    
    //get 3rd ring
    chassis.turnToPoint(66,69,4000,{.minSpeed=10,.earlyExitRange=5});
    intake.move(127);
    chassis.moveToPoint(66,69,4000,{},false);
    intake.move(0);

    //get 4th and 5th ring
    // chassis.turnToPoint(-46,4,4000,{.minSpeed=10,.earlyExitRange=5});
    chassis.swingToPoint(53,6,DriveSide::LEFT,4000);
    intake.move(127);
    chassis.moveToPoint(53,6,4000,{.minSpeed=60,.earlyExitRange=20});
    chassis.moveToPoint(53,6,4000,{.maxSpeed=40},false);
    intake.move(0);

    //get 6th ring
    intake.move(127);
    chassis.moveToPose(66,25,-10,4000,{.lead=.8},false);
    intake.move(0);

    //score mogo
    chassis.moveDistance(15,1000,{.forwards=false},false);
    mogo.set_value(false);
    pros::delay(500);
    chassis.moveDistance(15,4000);

}
