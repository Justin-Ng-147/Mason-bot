#include "main.h"

void skills(){
    
     //score red stake
    intake.move(127);
    pros::delay(1000);
    intake.move(0);

    //get mogo
    mogo.set_value(false);
    chassis.swingToPoint(-22,13,DriveSide::RIGHT,4000,{.forwards=false});
    lemlib::Pose start_pose = chassis.getPose();
    chassis.moveDistance(30,4000,{.forwards=false,.maxSpeed=45});
    // while(start_pose.distance(chassis.getPose()) < 25) pros::delay(10);
    while(mogo_distance.get_distance()>60 && chassis.isInMotion()) pros::delay(10);
    mogo.set_value(true);
    chassis.cancelMotion();

    //get 1st ring
    chassis.turnToPoint(-25,40,4000);
    intake.move(127);
    chassis.moveToPoint(-25,40,4000,{},false);
    intake.move(0);

    //get 2nd ring
    chassis.turnToPoint(-48,37,4000);
    intake.move(127);
    chassis.moveToPoint(-48,37,4000,{},false);
    intake.move(0);
    
    //get 3rd ring
    chassis.turnToPoint(-60,62,4000);
    intake.move(127);
    chassis.moveToPoint(-60,62,4000,{},false);
    intake.move(0);

    //get 4th and 5th ring
    // chassis.turnToPoint(-46,4,4000,{.minSpeed=10,.earlyExitRange=5});
    chassis.swingToPoint(-48,5,DriveSide::RIGHT,4000,{.maxSpeed=75});
    intake.move(127);
    chassis.moveToPoint(-48,5,4000,{.minSpeed=60,.earlyExitRange=20});
    chassis.moveToPoint(-48,5,4000,{.maxSpeed=40},false);
    intake.move(0);

    //get 6th ring
    intake.move(127);
    chassis.moveToPose(-60,25,10,4000,{.lead=.5},false);
    

    //score mogo
    chassis.moveDistance(15,1000,{.forwards=false},false);
    intake.move(0);
    mogo.set_value(false);
    pros::delay(500);
    chassis.moveDistance(12,4000);

    //get new mogo
    mogo.set_value(false);
    chassis.turnToPoint(32,16,4000,{.forwards=false});
    start_pose = chassis.getPose();
    chassis.moveToPoint(32,16,4000,{.forwards=false,.minSpeed=60,.earlyExitRange=40});
    chassis.moveToPoint(32,16,4000,{.forwards=false,.maxSpeed=40});
    while(mogo_distance.get_distance()>60 && chassis.isInMotion()) pros::delay(10);
    mogo.set_value(true);
    chassis.cancelMotion();

    //get 1st ring
    chassis.turnToPoint(26,44,4000);
    intake.move(127);
    chassis.moveToPoint(26,44,4000,{},false);
    intake.move(0);

    //get 2nd ring
    chassis.turnToPoint(48,44,4000);
    intake.move(127);
    chassis.moveToPoint(48,44,4000,{},false);
    intake.move(0);
    
    //get 3rd ring
    chassis.turnToPoint(63,69,4000);
    intake.move(127);
    chassis.moveToPoint(63,69,4000,{},false);
    intake.move(0);

    //get 4th and 5th ring
    // chassis.turnToPoint(-46,4,4000,{.minSpeed=10,.earlyExitRange=5});
    chassis.swingToPoint(54,6,DriveSide::LEFT,4000,{.maxSpeed=75});
    intake.move(127);
    chassis.moveToPoint(54,6,4000,{.minSpeed=60,.earlyExitRange=20});
    chassis.moveToPoint(54,6,4000,{.maxSpeed=40},false);
    intake.move(0);

    //get 6th ring
    intake.move(127);
    chassis.moveToPose(64,25,-15,4000,{.lead=.5},false);
    

    //score mogo
    chassis.moveDistance(15,1000,{.forwards=false},false);
    intake.move(0);
    mogo.set_value(false);
    pros::delay(500);
    chassis.moveDistance(10,4000);

    // -20 87
    //get 1st ring
    chassis.turnToPoint(-20,87,4000);
    intake.move(100);
    chassis.moveToPoint(-20,87,4000,{},false);
    intake.move(0);

    //12 120
    //get mogo
    chassis.turnToPoint(10,125,2000,{.forwards=false});
    start_pose = chassis.getPose();
    chassis.moveToPoint(10,125,4000,{.forwards=false,.maxSpeed=45});
    while(mogo_distance.get_distance()>60 && chassis.isInMotion()) pros::delay(10);
    mogo.set_value(true);
    chassis.cancelMotion();

    //-20,87
    //get 2nd ring
    chassis.turnToPoint(-20,87,4000);
    intake.move(127);
    chassis.moveToPoint(-20,87,4000,{},false);
    intake.move(0);

    //-42 93
    //get 3rd ring
    chassis.turnToPoint(-42,93,4000);
    intake.move(127);
    chassis.moveToPoint(-42,93,4000,{},false);
    

    //get 4th ring
    // 180 4 124
    chassis.moveToPoint(0,123,4000,{.forwards=false},false);
    // 34 89 
    chassis.turnToPoint(34,89,2000);
    intake.move(127);
    chassis.moveToPoint(34,89,4000,{},false);
    intake.move(0);

    //get 5th ring
    // 56 89
    chassis.turnToPoint(56,90,4000);
    intake.move(127);
    chassis.moveToPoint(56,90,4000,{},false);
    
    //get 6th ring
    chassis.turnToPoint(65,125,4000);
    swiper.set_value(true);
    intake.move(127);
    chassis.moveToPoint(65,125,4000,{},false);
    
    
    //score 3rd mogo
    //66 127
    chassis.turnToHeading(225,4000,{.direction=AngularDirection::CW_CLOCKWISE},false);
    // chassis.moveDistance(20,1000,{},false);
    // pros::delay(500);
    mogo.set_value(false);
    intake.move(0);
    swiper.set_value(false);
    chassis.moveDistance(30,1500,{.forwards=false},false);
    pros::delay(500);
    chassis.moveDistance(10,1000);

    //score 4th mogo
    intake.move(127);
    chassis.moveToPoint(-57,132,3000,{},false);
    intake.move(0);
    chassis.moveDistance(10,1000,{.forwards=false});
    
    

    // hang
    // -8.5 83
    hang.set_value(true);
    chassis.turnToPoint(-8,82,1000);
    chassis.moveDistance(70,3000,{.maxSpeed=80});

}