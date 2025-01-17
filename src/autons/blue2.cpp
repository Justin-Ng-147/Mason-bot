#include "main.h"

// void blue2(){
//     //set up
//     chassis.setPose(0,0,-12);
//     mogo.set_value(false);

//     // chassis.moveToPoint(-7,40,4000,{.minSpeed=20,.earlyExitRange=20},false);
//     chassis.moveToPoint(-14,38,4000,{.minSpeed=20,.earlyExitRange=8});
//     intake.move(-127);
//     pros::delay(100);
//     intake.move(0);
//     while(chassis.isInMotion()) pros::delay(10);
//     swiper.set_value(true);
//     left.move(-127);
//     right.move(-127);
//     pros::delay(100);
//     left.move(0);
//     right.move(0);
    

//     //get mogo
//     chassis.turnToPoint(12,27,2000,{.forwards=false},false);
    
//     // chassis.moveToPoint(-12,28,2000,{.forwards=false});
//     chassis.moveDistance(40,3000,{.forwards=false,.maxSpeed=60});
//     swiper.set_value(false);
//     while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
//     pros::delay(50);
//     mogo.set_value(true);
//     pros::delay(50);
//     chassis.cancelMotion();

//     //20 36
//     chassis.moveToPoint(-20,40,2000);
//     pros::delay(200);
//     intake.move(127);
//     // intake.move(0);


//     // chassis.turnToPoint(4,-5,2000,{.forwards=false,.minSpeed = 10,.earlyExitRange=5});
//     // chassis.moveToPoint(4,-5,2000,{.forwards=false},false);


//     //-31, -2
//     chassis.turnToPoint(-32,-1,2000,{},false);
//     swiper.set_value(true);
//     chassis.moveToPoint(-32,-1,2000);

//     // intake.move(0);
//     chassis.turnToHeading(145,3000,{.direction=AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed=127, .earlyExitRange = 3},false);
//     left.move(127);
//     right.move(-127);
//     pros::delay(50);
//     left.move(0);
//     right.move(0);
    // swiper.set_value(false);
    // intake.move(127);
    // chassis.moveDistance(12,2000,{.maxSpeed=30,.minSpeed=30,.earlyExitRange=3});
    // chassis.turnToPoint(18,-12,3000);
    // // chassis.moveDistance(6,1000,{.forwards=false,.minSpeed=30,.earlyExitRange=3});
    // chassis.moveDistance(40,10000,{.maxSpeed=30,.minSpeed=30,.earlyExitRange=3},false);
    // pros::delay(1000);    


//     //touch hang
//     // chassis.turnToPoint(45,9,2000,{.minSpeed = 10,.earlyExitRange=3});
//     // chassis.moveToPoint(45,9,2000,{.maxSpeed=40});

//     // chassis.turnToHeading(0,1000,{.minSpeed = 10,.earlyExitRange=3});
//     // chassis.moveDistance(15,2000);

//     mogo.set_value(false);
//     chassis.turnToPoint(-14,38,4000,{.forwards=false,.minSpeed=5,.earlyExitRange=5});
//     chassis.moveToPoint(-14,38,4000,{.forwards=false});
//      if(mogo_seated()){
//         pros::delay(50);
//         mogo.set_value(true);
//         pros::delay(50);
//         // chassis.cancelMotion();
//     }



//     // chassis.turnToPoint(-22,-12,2000,{},false);
//     // swiper.set_value(true);
//     // chassis.moveToPoint(-22,-12,2000,{},false);
//     // intake.move(0);
//     // chassis.turnToHeading(60,3000,{.direction=AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed=120, .earlyExitRange = 3},false);
//     // left.move(127);
//     // right.move(-127);
//     // pros::delay(50);
//     // left.move(0);
//     // right.move(0);
//     // swiper.set_value(false);
//     // intake.move(127);
//     // // intake.move(127;)
//     // // chassi
//     // chassis.moveDistance(12,2000,{.maxSpeed=30,.minSpeed=30,.earlyExitRange=3});
//     // chassis.turnToPoint(32,28,3000);
//     // chassis.moveDistance(40,10000,{.maxSpeed=30,.minSpeed=30,.earlyExitRange=3},false);
//     // // chassis.waitUntil(20);
//     // // chassis.cancelMotion();
//     // // chassis.moveDistance(10,1000,{.forwards=false,.minSpeed = 30,.earlyExitRange=4});
//     // // chassis.moveDistance(20,10000,{.maxSpeed=30});
//     // // mogo.set_value(false);



//     // // chassis.moveDistance(15,2000,{.forwards=false},false);
//     // // pros::delay(500);
//     // // mogo.set_value(false);

//     // // chassis.turnToPoint(28,45,2000,{.forwards=false});
//     // // chassis.moveToPoint(28,45,2000,{.forwards = false,.maxSpeed=60});
//     // // if(mogo_seated()){
//     // //     pros::delay(50);
//     // //     mogo.set_value(true);
//     // //     pros::delay(50);
//     // //     chassis.cancelMotion();
//     // // }



//     // // pros::delay(500);
//     // // mobo.set_value(false);
//     // chassis.turnToPoint(-23,39,2000,{.forwards=false,.minSpeed=30,.earlyExitRange=3},false);
//     // intake.move(0);
//     // chassis.moveToPoint(-23,39,2000,{.forwards=false});
// }

//final auton no suck
void blue2(){
    //set up
    chassis.setPose(0,0,-12);
    mogo.set_value(false);
    left.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    right.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);

    // chassis.moveToPoint(-7,40,4000,{.minSpeed=20,.earlyExitRange=20},false);
    chassis.moveToPoint(-15,38,4000,{.minSpeed=1,.earlyExitRange=6},false);
    left.brake();
    right.brake();
    swiper.set_value(true);
    pros::delay(100);
    left.move(0);
    right.move(0);
    

    //get mogo
    chassis.turnToPoint(12,27,1000,{.forwards=false},false);
    
    // chassis.moveToPoint(-12,28,2000,{.forwards=false});
    chassis.moveDistance(40,3000,{.forwards=false,.maxSpeed=60});
    chassis.waitUntil(10);
    swiper.set_value(false);
    while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
    pros::delay(50);
    mogo.set_value(true);
    pros::delay(50);
    chassis.cancelMotion();

    //20 36
    chassis.moveToPoint(-10,30,2000,{.minSpeed=5,.earlyExitRange=3});
    chassis.moveToPoint(-20,40,2000);
    // pros::delay(200);
    // intake.move(127);
    set_intake_speed(127);
    // intake.move(0);


    // chassis.turnToPoint(4,-5,2000,{.forwards=false,.minSpeed = 10,.earlyExitRange=5});
    // chassis.moveToPoint(4,-5,2000,{.forwards=false},false);


    //-31, -2
    chassis.turnToPoint(-32,-1,2000,{},false);
    swiper.set_value(true);
    chassis.moveToPoint(-32,-1,2000);

    // intake.move(0);
    chassis.turnToHeading(145,3000,{.direction=AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed=127, .earlyExitRange = 3},false);
    left.move(127);
    right.move(-127);
    pros::delay(50);
    left.move(0);
    right.move(0);
    swiper.set_value(false);
    // intake.move(127);
    set_intake_speed(127);
    // intake.move(127;)
    // chassi
    //  pros::Task auton_task{[=]{
    //     while(true){
    //         if(vision.get_by_sig(0,BLUECOLOR).width>100 && distance.get_distance()<150){
    //             pros::delay(1000);
    //             set_intake_speed(0);
    //             // ring_in_mutex.lock();
    //             // ring_in = true;
    //             // ring_in_mutex.unlock();
    //             break;
    //         }
    //         pros::delay(10);
    //     }
    // }};
    chassis.moveDistance(12,2000,{.maxSpeed=30,.minSpeed=30,.earlyExitRange=3});
    chassis.turnToPoint(18,-12,3000);
    // chassis.moveDistance(6,1000,{.forwards=false,.minSpeed=30,.earlyExitRange=3});
    chassis.moveDistance(40,10000,{.maxSpeed=30,.minSpeed=30,.earlyExitRange=3},false);
    pros::delay(1000);    



    // chassis.moveDistance(15,2000,{.forwards=false},false);
    // pros::delay(500);
    // mogo.set_value(false);

    mogo.set_value(false);


    //touch hang
    // chassis.turnToPoint(45,9,2000,{.minSpeed = 10,.earlyExitRange=3});
    // chassis.moveToPoint(45,9,2000,{.maxSpeed=40});

    // chassis.turnToHeading(0,1000,{.minSpeed = 10,.earlyExitRange=3});
    // chassis.moveDistance(15,2000);

    chassis.turnToPoint(-14,38,2000,{},false);
    // intake.move(127);
    chassis.moveToPoint(-14,38,2000);
    chassis.turnToHeading(180,2000);
     if(mogo_seated()){
        pros::delay(50);
        mogo.set_value(true);
        pros::delay(50);
        // chassis.cancelMotion();
    }



    // chassis.turnToPoint(-22,-12,2000,{},false);
    // swiper.set_value(true);
    // chassis.moveToPoint(-22,-12,2000,{},false);
    // intake.move(0);
    // chassis.turnToHeading(60,3000,{.direction=AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed=120, .earlyExitRange = 3},false);
    // left.move(127);
    // right.move(-127);
    // pros::delay(50);
    // left.move(0);
    // right.move(0);
    // swiper.set_value(false);
    // intake.move(127);
    // // intake.move(127;)
    // // chassi
    // chassis.moveDistance(12,2000,{.maxSpeed=30,.minSpeed=30,.earlyExitRange=3});
    // chassis.turnToPoint(32,28,3000);
    // chassis.moveDistance(40,10000,{.maxSpeed=30,.minSpeed=30,.earlyExitRange=3},false);
    // // chassis.waitUntil(20);
    // // chassis.cancelMotion();
    // // chassis.moveDistance(10,1000,{.forwards=false,.minSpeed = 30,.earlyExitRange=4});
    // // chassis.moveDistance(20,10000,{.maxSpeed=30});
    // // mogo.set_value(false);



    // // chassis.moveDistance(15,2000,{.forwards=false},false);
    // // pros::delay(500);
    // // mogo.set_value(false);

    // // chassis.turnToPoint(28,45,2000,{.forwards=false});
    // // chassis.moveToPoint(28,45,2000,{.forwards = false,.maxSpeed=60});
    // // if(mogo_seated()){
    // //     pros::delay(50);
    // //     mogo.set_value(true);
    // //     pros::delay(50);
    // //     chassis.cancelMotion();
    // // }



    // // pros::delay(500);
    // // mobo.set_value(false);
    // chassis.turnToPoint(-23,39,2000,{.forwards=false,.minSpeed=30,.earlyExitRange=3},false);
    // intake.move(0);
    // chassis.moveToPoint(-23,39,2000,{.forwards=false});
}
