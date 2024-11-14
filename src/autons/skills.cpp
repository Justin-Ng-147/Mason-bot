#include "main.h"





void skills(){
    // init_intake();
    left.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    right.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    
     //score red stake
    set_intake_speed(127);
    pros::delay(500);
    set_intake_speed(0);

    //get mogo
    mogo.set_value(false);
    chassis.swingToPoint(-22,13,DriveSide::RIGHT,2000,{.forwards=false,.minSpeed=5,.earlyExitRange=5});
    chassis.turnToPoint(-22,13,1000,{.forwards=false});
    lemlib::Pose start_pose = chassis.getPose();
    chassis.moveDistance(30,2000,{.forwards=false,.maxSpeed=50});
    // while(start_pose.distance(chassis.getPose()) < 25) pros::delay(10);
    while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
    pros::delay(100);
    mogo.set_value(true);
    pros::delay(100);
    chassis.cancelMotion();

    //get 1st ring
    chassis.turnToPoint(-25,40,2000,{.minSpeed=5,.earlyExitRange=3},false);
    set_intake_speed(127);
    // chassis.moveToPoint(-25,40,2000,{.minSpeed=5,.earlyExitRange=3},false);
    fast_move(-25,40,2000,false);
    // set_intake_speed(0);

    //get 2nd ring
    chassis.turnToPoint(-48,37,2000,{.minSpeed=5,.earlyExitRange=3});
    set_intake_speed(127);
    // chassis.moveToPoint(-48,37,2000,{.minSpeed=5,.earlyExitRange=3},false);
    fast_move(-48,37,2000,false);
    // set_intake_speed(0);
    
    //get 3rd ring
    chassis.turnToPoint(-60,62,2000,{.minSpeed=5,.earlyExitRange=3});
    set_intake_speed(127);
    // chassis.moveToPoint(-60,62,2000,{},false);
    fast_move(-60,62,2000,false);
    // set_intake_speed(0);

    //get 4th and 5th ring
    // chassis.turnToPoint(-46,4,4000,{.minSpeed=10,.earlyExitRange=5});
    chassis.swingToPoint(-48,5,DriveSide::RIGHT,2000,{.maxSpeed=75,.minSpeed=3,.earlyExitRange=3});
    set_intake_speed(127);
    chassis.moveToPoint(-48,5,2000,{.minSpeed=60,.earlyExitRange=20});
    chassis.moveToPoint(-48,5,2000,{.maxSpeed=40},false);
    // set_intake_speed(0);

    //get 6th ring
    set_intake_speed(127);
    chassis.moveToPose(-60,25,10,2000,{.lead=.5},false);
    

    //score mogo
    chassis.moveDistance(15,1000,{.forwards=false},false);
    set_intake_speed(-127);
    mogo.set_value(false);
    pros::delay(500);
    set_intake_speed(0);
    chassis.moveDistance(12,1000,{.minSpeed=5,.earlyExitRange=3});

    //get new mogo
    mogo.set_value(false);
    chassis.turnToPoint(32,15,2000,{.forwards=false,.minSpeed=5,.earlyExitRange=3});
    start_pose = chassis.getPose();
    chassis.moveToPoint(32,15,4000,{.forwards=false,.minSpeed=5,.earlyExitRange=40});
    chassis.moveToPoint(32,15,3000,{.forwards=false,.maxSpeed=40});
    while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
    pros::delay(100);
    mogo.set_value(true);
    pros::delay(100);
    chassis.cancelMotion();

    //get 1st ring
    chassis.turnToPoint(26,40,2000,{.minSpeed=5,.earlyExitRange=3},false);
    set_intake_speed(127);
    // chassis.moveToPoint(26,40,2000,{.minSpeed=5,.earlyExitRange=3},false);
    fast_move(26,40,2000,false);
    // set_intake_speed(0);

    //get 2nd ring
    chassis.turnToPoint(50,44,2000,{.minSpeed=5,.earlyExitRange=3});
    set_intake_speed(127);
    // chassis.moveToPoint(48,44,2000,{.minSpeed=5,.earlyExitRange=3},false);
    fast_move(50,44,2000,false);
    // set_intake_speed(0);
    
    //get 3rd ring
    chassis.turnToPoint(63,69,2000,{.minSpeed=5,.earlyExitRange=3});
    set_intake_speed(127);
    // chassis.moveToPoint(63,69,2000,{},false);
    fast_move(63,69,2000,false);
    // set_intake_speed(0);

    //get 4th and 5th ring
    // chassis.turnToPoint(-46,4,4000,{.minSpeed=10,.earlyExitRange=5});
    chassis.swingToPoint(54,6,DriveSide::LEFT,2000,{.maxSpeed=75});
    set_intake_speed(127);
    chassis.moveToPoint(54,6,2000,{.minSpeed=60,.earlyExitRange=20});
    chassis.moveToPoint(54,6,2000,{.maxSpeed=40},false);
    // set_intake_speed(0);

    //get 6th ring
    set_intake_speed(127);
    chassis.moveToPose(64,25,-20,3000,{.lead=.5},false);
    

    //score mogo
    chassis.moveDistance(15,1000,{.forwards=false},false);
    set_intake_speed(-127);
    mogo.set_value(false);
    pros::delay(500);
    set_intake_speed(0);
    chassis.moveDistance(7,1000,{.minSpeed=5,.earlyExitRange=3});

    // -20 87
    //get 1st ring
    chassis.turnToPoint(-21,87,2000);
    set_intake_speed(100);
    chassis.moveToPoint(-21,87,4000,{},false);
    // fast_move(-21,87,4000,false);
    set_intake_speed(0);

    //12 120
    //get mogo
    chassis.turnToPoint(10,124,1000,{.forwards=false});
    start_pose = chassis.getPose();
    chassis.moveToPoint(10,124,4000,{.forwards=false,.maxSpeed=60});
    while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
    pros::delay(100);
    mogo.set_value(true);
    pros::delay(100);
    chassis.cancelMotion();

    //-20,87
    //get 2nd ring
    chassis.turnToPoint(-25,85,2000,{.minSpeed=5,.earlyExitRange=3},false);
    set_intake_speed(127);
    // chassis.moveToPoint(-25,85,2000,{},false);
    fast_move(-25,85,2000,false);
    // set_intake_speed(0);

    //-42 93
    //get 3rd ring
    chassis.turnToPoint(-50,90,2000,{.minSpeed=5,.earlyExitRange=3});
    set_intake_speed(127);
    // chassis.moveToPoint(-44,86,2000,{},false);
    fast_move(-50,90,2000,false);
    

    //get 4th ring
    // 180 4 124
    // chassis.moveToPoint(0,123,3000,{.forwards=false,.minSpeed=5,.earlyExitRange=3},false);
    chassis.moveToPoint(0,123,2000,{.forwards=false,.minSpeed=5, .earlyExitRange=10});
    chassis.moveToPoint(0,123,2000,{.forwards=false,.maxSpeed = 40, .minSpeed = 5, .earlyExitRange = 3});
    // 34 89 
    chassis.turnToPoint(34,89,2000,{.minSpeed=5,.earlyExitRange=3});
    set_intake_speed(127);
    // chassis.moveToPoint(34,89,4000,{},false);
    fast_move(34,89,3000,false);
    set_intake_speed(0);

    //get 5th ring
    // 56 89
    chassis.turnToPoint(56,95,2000,{.minSpeed=5,.earlyExitRange=3});
    set_intake_speed(127);
    // chassis.moveToPoint(56,90,4000,{},false);
    fast_move(56,95,2000,false);
    
    //get 6th ring
    chassis.turnToPoint(65,125,2000,{.minSpeed=5,.earlyExitRange=3});
    swiper.set_value(true);
    set_intake_speed(127);
    chassis.moveToPoint(65,125,3000);
    // while(!(vision.get_by_sig(0,REDCOLOR).width>100 && distance.get_distance()<150)&&chassis.isInMotion()) pros::delay(10);
    // set_intake_speed(0);
    
    
    //score 3rd mogo
    //66 127

    // chassis.turnToHeading(-65,4000,{.direction=AngularDirection::CCW_COUNTERCLOCKWISE,.minSpeed=60,.earlyExitRange = 10});
    chassis.turnToPoint(0,40,3000,{.direction=lemlib::AngularDirection::CCW_COUNTERCLOCKWISE,.minSpeed=5,.earlyExitRange=3},false);
    left.brake();
    right.brake();
    
    // chassis.moveDistance(20,1000,{},false);
    // pros::delay(500);
    mogo.set_value(false);
    set_intake_speed(-127);
    swiper.set_value(false);
    chassis.moveDistance(20,1000,{.forwards=false,.maxSpeed=70},false);
    pros::delay(500);
    set_intake_speed(0);
    chassis.moveDistance(10,1000,{.minSpeed=5,.earlyExitRange=3});




    //get last mogo
    set_intake_speed(127);
    chassis.moveToPoint(15,115,4000,{},false);
    set_intake_speed(0);
    chassis.turnToPoint(-25,128,2000,{.forwards=false});
    chassis.moveToPoint(-25,128,4000,{.forwards=false,.maxSpeed=60});
    while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
    pros::delay(100);
    mogo.set_value(true);
    pros::delay(100);
    chassis.cancelMotion();

    set_intake_speed(127);

    if(mogo_seated()){
        chassis.turnToPoint(-60,130,2000,{.minSpeed=5,.earlyExitRange=3},false);
        swiper.set_value(true);
        chassis.moveToPoint(-60,130,2000);
        chassis.turnToPoint(0,80,2000,{.direction=lemlib::AngularDirection::CCW_COUNTERCLOCKWISE,.minSpeed=5,.earlyExitRange=3},false);
        left.brake();
        right.brake();
        mogo.set_value(false);
        set_intake_speed(0);
        swiper.set_value(false);
        chassis.moveDistance(30,1000,{.forwards=false},false);
        // pros::delay(500);
        chassis.moveDistance(10,1000,{.minSpeed=5,.earlyExitRange=3});
    }
    else{
        // chassis.swingToPoint(-60,130,lemlib::DriveSide::LEFT,2000,{.direction=lemlib::AngularDirection::CCW_COUNTERCLOCKWISE,.minSpeed=5,.earlyExitRange=3},false);
        chassis.turnToPoint(-60,130,2000,{.direction=lemlib::AngularDirection::CCW_COUNTERCLOCKWISE,.minSpeed=5,.earlyExitRange=3},false);
        set_intake_speed(0);
        // swiper.set_value(true);
        chassis.moveToPoint(-60,130,2000);
        // chassis.turnToPoint(0,80,2000,{.direction=lemlib::AngularDirection::CCW_COUNTERCLOCKWISE},false);
        // mogo.set_value(false);
        // set_intake_speed(0);
        // swiper.set_value(false);
        chassis.moveDistance(10,1000,{.forwards=false,.minSpeed=5,.earlyExitRange=3});
        chassis.moveDistance(20,1000,{.maxSpeed=60},false);
        // pros::delay(500);
        chassis.moveDistance(10,1000,{.forwards=false,.minSpeed=5,.earlyExitRange=3});
    }

    hang.set_value(true);
    chassis.turnToPoint(-4.5,79,2000,{.minSpeed=5,.earlyExitRange=3});
    chassis.moveToPoint(-4.5,79,2000,{.minSpeed=5,.earlyExitRange=30},false);
    set_intake_speed(0);
    chassis.moveDistance(50,1000,{.maxSpeed=60});

    intake_task->remove();
}


// void skills(){
//     init_intake();
//     pros::delay(1000);
//     set_intake_speed(127);
//     pros::delay(2000);
//     set_intake_speed(0);
//     pros::delay(2000);
//     set_intake_speed(127);
// }
