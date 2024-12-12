#include "main.h"





void skills(){
    // init_intake();
    left.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    right.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    
     //score red stake
    set_intake_speed(127);
    pros::delay(1000);
    set_intake_speed(-127);

    //get mogo
    mogo.set_value(false);
    set_intake_speed(0);
    chassis.swingToPoint(-22,14,DriveSide::RIGHT,2000,{.forwards=false,.direction=lemlib::AngularDirection::CW_CLOCKWISE,.maxSpeed=70,.minSpeed=5,.earlyExitRange=5},false);
    chassis.turnToPoint(-22,14,1000,{.forwards=false});
    lemlib::Pose start_pose = chassis.getPose();
    chassis.moveDistance(30,2000,{.forwards=false,.maxSpeed=50});
    // while(start_pose.distance(chassis.getPose()) < 25) pros::delay(10);
    while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
    pros::delay(100);
    mogo.set_value(true);
    pros::delay(100);
    chassis.cancelMotion();

    //get 1st ring
    chassis.turnToPoint(-24,40,1000,{.minSpeed=5,.earlyExitRange=3},false);
    set_intake_speed(127);
    // chassis.moveToPoint(-25,40,2000,{},false);
    fast_move(-24,40,2000,false);
    // set_intake_speed(0);

    //get new 2nd ring
    chassis.turnToPoint(-59,60,1000,{.minSpeed=5,.earlyExitRange=3});
    fast_move(-59,60,2000,false);

    // //get 2nd ring
    // chassis.turnToPoint(-48,38,1000,{.minSpeed=5,.earlyExitRange=3});
    // set_intake_speed(127);
    // // chassis.moveToPoint(-48,37,2000,{.minSpeed=5,.earlyExitRange=3},false);
    // fast_move(-48,38,2000,false);
    // // set_intake_speed(0);
    
    // //get 3rd ring
    // chassis.turnToPoint(-59,62,1000,{.minSpeed=5,.earlyExitRange=3});
    // set_intake_speed(127);
    // // chassis.moveToPoint(-60,62,2000,{},false);
    // fast_move(-59,62,2000,false);
    // // set_intake_speed(0);

    //get 4th and 5th ring
    // chassis.turnToPoint(-46,4,4000,{.minSpeed=10,.earlyExitRange=5});
    chassis.swingToPoint(-48,6,DriveSide::RIGHT,2000,{.maxSpeed=75,.minSpeed=3,.earlyExitRange=3});
    set_intake_speed(127);
    chassis.moveToPoint(-48,6,2000,{.minSpeed=60,.earlyExitRange=45});
    chassis.moveToPoint(-48,6,2000,{.maxSpeed=40},false);
    pros::delay(1000);
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
    // chassis.turnToPoint(32,12.5,1000,{.forwards=false,.minSpeed=5,.earlyExitRange=3});
    // start_pose = chassis.getPose();
    chassis.turnToPoint(32,12.5,1000,{.forwards=false,.maxSpeed=60});
    chassis.moveToPoint(32,12.5,4000,{.forwards=false,.minSpeed=5,.earlyExitRange=40});
    chassis.moveToPoint(32,12.5,3000,{.forwards=false,.maxSpeed=40});
    while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
    pros::delay(100);
    mogo.set_value(true);
    pros::delay(100);
    chassis.cancelMotion();

    //get 1st ring
    chassis.turnToPoint(28,40,1000,{.minSpeed=5,.earlyExitRange=3},false);
    set_intake_speed(127);
    // chassis.moveToPoint(26,40,2000,{.minSpeed=5,.earlyExitRange=3},false);
    fast_move(28,40,2000,false);
    // set_intake_speed(0);

    //get new 2nd ring
    chassis.turnToPoint(60,62,1000,{.minSpeed=5,.earlyExitRange=3});
    fast_move(60,62,2000,false);

    // //get 2nd ring
    // chassis.turnToPoint(52,40,1000,{.minSpeed=5,.earlyExitRange=3});
    // set_intake_speed(127);
    // // chassis.moveToPoint(48,44,2000,{.minSpeed=5,.earlyExitRange=3},false);
    // fast_move(52,40,2000,false);
    // // set_intake_speed(0);
    
    // //get 3rd ring
    // chassis.turnToPoint(65,67,1000,{.minSpeed=5,.earlyExitRange=3});
    // set_intake_speed(127);
    // // chassis.moveToPoint(63,69,2000,{},false);
    // fast_move(65,67,2000,false);
    // // set_intake_speed(0);

    //get 4th and 5th ring
    // chassis.turnToPoint(-46,4,4000,{.minSpeed=10,.earlyExitRange=5});
    chassis.swingToPoint(54,6,DriveSide::LEFT,2000,{.maxSpeed=75});
    set_intake_speed(127);
    chassis.moveToPoint(54,6,2000,{.minSpeed=60,.earlyExitRange=45});
    chassis.moveToPoint(54,6,2000,{.maxSpeed=40},false);
    pros::delay(1000);
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
    chassis.moveDistance(6,1000,{.minSpeed=5,.earlyExitRange=3});

    // -20 87
    //get 1st ring
    chassis.turnToPoint(-21,88,1000);
    set_intake_speed(70);
    chassis.moveToPoint(-21,88,4000,{},false);
    // fast_move(-21,87,4000,false);
    set_intake_speed(0);

    //12 120
    //get mogo
    chassis.turnToPoint(10,122,1000,{.forwards=false});
    start_pose = chassis.getPose();
    chassis.moveToPoint(10,122,4000,{.forwards=false,.maxSpeed=60});
    while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
    pros::delay(200);
    mogo.set_value(true);
    pros::delay(100);
    chassis.cancelMotion();

    //-20,87
    //get 2nd ring
    chassis.turnToPoint(-25,86,1000,{.minSpeed=5,.earlyExitRange=3},false);
    set_intake_speed(127);
    // chassis.moveToPoint(-25,85,2000,{},false);
    fast_move(-25,86,2000,false);
    // set_intake_speed(0);

    //-42 93
    //get 3rd ring
    chassis.turnToPoint(-50,94,1000,{.minSpeed=5,.earlyExitRange=3});
    set_intake_speed(127);
    // chassis.moveToPoint(-50,94,2000,{},false);
    fast_move(-50,94,2000,false);

    //get new 4th ring

    chassis.turnToPoint(-47,118,1000,{.minSpeed=5,.earlyExitRange=3});
    swiper.set_value(true);
    fast_move(-47,118,2000,true);
    

    //get 4th ring
    // 180 4 124
    // chassis.moveToPoint(0,123,3000,{.forwards=false,.minSpeed=5,.earlyExitRange=3},false);
    chassis.moveToPoint(0,120,2000,{.forwards=false,.minSpeed=5, .earlyExitRange=10});
    chassis.moveToPoint(0,120,2000,{.forwards=false,.maxSpeed = 40, .minSpeed = 5, .earlyExitRange = 3});
    // 34 89 
    chassis.turnToPoint(33,90,1000,{.minSpeed=5,.earlyExitRange=3});
    swiper.set_value(false);
    set_intake_speed(127);
    // chassis.moveToPoint(34,89,4000,{},false);
    fast_move(33,90,3000,false);
    // set_intake_speed(0);

    //get 5th ring
    // 56 89
    chassis.turnToPoint(56,95,1000,{.minSpeed=5,.earlyExitRange=3});
    set_intake_speed(127);
    // chassis.moveToPoint(56,90,4000,{},false);
    fast_move(56,95,2000,false);
    
    //get 6th ring
    chassis.turnToPoint(68,125,1000,{.minSpeed=5,.earlyExitRange=3});
    swiper.set_value(true);
    set_intake_speed(127,false);
    chassis.moveToPoint(68,125,1000,{.maxSpeed=60});
    pros::Task auton_task{[=]{
        pros::delay(500);
        while(true){
            if(vision.get_by_sig(0,REDCOLOR).width>100 && distance.get_distance()<150){
                set_intake_speed(0);
                break;
            }
            pros::delay(10);
        }
    }};
    chassis.waitUntil(10);
    chassis.cancelMotion();
    left.brake();
    right.brake();
    pros::delay(500);
    chassis.moveToPoint(68,125,1000);

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
    // set_intake_speed(-127);
    swiper.set_value(false);
    chassis.moveDistance(20,1000,{.forwards=false,.maxSpeed=70},false);
    set_intake_speed(-127);
    pros::delay(50);
    set_intake_speed(0);
    chassis.moveDistance(20,1000,{.minSpeed=5,.earlyExitRange=3});

    chassis.turnToPoint(5,110,1000,{.minSpeed=5,.earlyExitRange=3},false);
    chassis.moveToPoint(5,110,2000);
    mogo.set_value(true);

    chassis.turnToPoint(1.5,130.5,1000,{.forwards=false});
    // chassis.moveToPoint(1.5,130.5,2000,{.forwards=false},false);
    chassis.moveDistance(24,1000,{.forwards=false},false);
    set_intake_speed(127);
    pros::delay(1000);
    
    // return;

    chassis.turnToPoint(-14,129,1000,{.minSpeed=5,.earlyExitRange=3});
    // intake.move(127);
    set_intake_speed(127);
    chassis.moveToPoint(-14,129,2000,{.minSpeed=127},false);
    // intake.move(0);
    set_intake_speed(0);
    claw.set_value(true);
    chassis.turnToHeading(-65, 1000,{.minSpeed=5,.earlyExitRange=3});
    chassis.moveDistance(35,2000,{.minSpeed=127});
    set_intake_speed(-127);
    chassis.moveDistance(10,1000,{.forwards=false,.minSpeed=5,.earlyExitRange=3});
    // chassis.moveDistance(20,1000,{.maxSpeed=60});
    // chassis.moveDistance(10,1000,{.forwards=false,.minSpeed=5,.earlyExitRange=3});
   

    hang.set_value(true);
    chassis.turnToPoint(-4,77,2000,{.minSpeed=5,.earlyExitRange=3});
    chassis.moveToPoint(-4,77,2000,{.minSpeed=5,.earlyExitRange=40});
    chassis.moveToPoint(-4,77,2000,{.maxSpeed=30,.minSpeed=5,.earlyExitRange=25});
    set_intake_speed(0);
    chassis.turnToHeading(135,1000);
    chassis.moveDistance(50,1000,{.maxSpeed=70});
    chassis.moveDistance(50,300,{.forwards=false,.maxSpeed=60});


    //get last mogo
    // set_intake_speed(127);
    // chassis.moveToPoint(15,115,4000,{},false);
    // set_intake_speed(0);
    // chassis.turnToPoint(-25,128,2000,{.forwards=false});
    // chassis.moveToPoint(-25,128,2000,{.forwards=false,.maxSpeed=60});
    // while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
    // pros::delay(100);
    // mogo.set_value(true);
    // pros::delay(100);
    // chassis.cancelMotion();

    // set_intake_speed(127);

    // if(mogo_seated()){
    //     chassis.turnToPoint(-60,130,2000,{.minSpeed=5,.earlyExitRange=3},false);
    //     swiper.set_value(true);
    //     chassis.moveToPoint(-60,130,2000);
    //     chassis.turnToPoint(0,80,2000,{.direction=lemlib::AngularDirection::CCW_COUNTERCLOCKWISE,.minSpeed=5,.earlyExitRange=3},false);
    //     left.brake();
    //     right.brake();
    //     mogo.set_value(false);
    //     set_intake_speed(0);
    //     swiper.set_value(false);
    //     chassis.moveDistance(30,1000,{.forwards=false},false);
    //     // pros::delay(500);
    //     chassis.moveDistance(10,1000,{.minSpeed=5,.earlyExitRange=3});
    // }
    // else{
    //     // chassis.swingToPoint(-60,130,lemlib::DriveSide::LEFT,2000,{.direction=lemlib::AngularDirection::CCW_COUNTERCLOCKWISE,.minSpeed=5,.earlyExitRange=3},false);
    //     chassis.turnToPoint(-60,130,2000,{.direction=lemlib::AngularDirection::CCW_COUNTERCLOCKWISE,.minSpeed=5,.earlyExitRange=3},false);
    //     set_intake_speed(0);
    //     // swiper.set_value(true);
    //     chassis.moveToPoint(-60,130,2000);
    //     // chassis.turnToPoint(0,80,2000,{.direction=lemlib::AngularDirection::CCW_COUNTERCLOCKWISE},false);
    //     // mogo.set_value(false);
    //     // set_intake_speed(0);
    //     // swiper.set_value(false);
    //     chassis.moveDistance(10,1000,{.forwards=false,.minSpeed=5,.earlyExitRange=3});
    //     chassis.moveDistance(20,1000,{.maxSpeed=60},false);
    //     // pros::delay(500);
    //     chassis.moveDistance(10,1000,{.forwards=false,.minSpeed=5,.earlyExitRange=3});
    // }

    //fast push mogo
    // chassis.turnToPoint(-20,122,2000,{.minSpeed=5,.earlyExitRange=3});
    // set_intake_speed(127);
    // // intake.move(127);
    // chassis.moveToPoint(-20,122,2000,{},false);
    // set_intake_speed(0);
    // // intake.move(0);
    // chassis.turnToHeading(-80, 1000,{.minSpeed=5,.earlyExitRange=3});
    // chassis.moveDistance(35,2000);
    // chassis.moveDistance(10,1000,{.forwards=false});

    
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
