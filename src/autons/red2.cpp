#include "main.h"

void red2(){
    //get contested mogo
    chassis.setPose(0,0,9);
    mogo.set_value(false);
    chassis.moveToPoint(6,40,4000,{.minSpeed=20,.earlyExitRange=5},false);
    swiper.set_value(true);
    left.move(-127);
    right.move(-127);
    pros::delay(100);
    left.move(0);
    right.move(0);
    

    //get mogo
    chassis.turnToPoint(-12,28,2000,{.forwards=false},false);
    
    // chassis.moveToPoint(-12,28,2000,{.forwards=false});
    chassis.moveDistance(40,3000,{.forwards=false,.maxSpeed=60});
    swiper.set_value(false);
    while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
    pros::delay(50);
    mogo.set_value(true);
    pros::delay(50);
    chassis.cancelMotion();

    //20 36
    intake.move(127);
    chassis.moveToPoint(20,32,2000,{},false);
    // intake.move(0);


    chassis.turnToPoint(5,-3,2000,{.forwards=false,.minSpeed = 10,.earlyExitRange=5});
    chassis.moveToPoint(5,-3,2000,{.forwards=false},false);
    swiper.set_value(true);
    chassis.turnToPoint(22,-9,2000,{});
    chassis.moveToPoint(22,-9,2000);
    chassis.turnToHeading(40,3000,{.direction=AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed=120, .earlyExitRange = 3},false);
    left.move(127);
    right.move(-127);
    pros::delay(50);
    left.move(0);
    right.move(0);
    swiper.set_value(false);
    intake.move(127);
    // intake.move(127;)
    // chassi
    chassis.moveDistance(12,2000,{.maxSpeed=30,.minSpeed=30,.earlyExitRange=3});
    chassis.turnToPoint(32,28,3000);
    chassis.moveDistance(40,10000,{.maxSpeed=30,.minSpeed=30,.earlyExitRange=3},false);
    // chassis.waitUntil(20);
    // chassis.cancelMotion();
    // chassis.moveDistance(10,1000,{.forwards=false,.minSpeed = 30,.earlyExitRange=4});
    // chassis.moveDistance(20,10000,{.maxSpeed=30});
    // mogo.set_value(false);



    // chassis.moveDistance(15,2000,{.forwards=false},false);
    // pros::delay(500);
    // mogo.set_value(false);

    // chassis.turnToPoint(28,45,2000,{.forwards=false});
    // chassis.moveToPoint(28,45,2000,{.forwards = false,.maxSpeed=60});
    // if(mogo_seated()){
    //     pros::delay(50);
    //     mogo.set_value(true);
    //     pros::delay(50);
    //     chassis.cancelMotion();
    // }

    pros::delay(500);
    mogo.set_value(false);
    chassis.turnToPoint(-23,39,2000,{.minSpeed=30,.earlyExitRange=3},false);
    intake.move(0);
    chassis.moveToPoint(-23,39,2000);
}

