#include "main.h"






void skills(){
    chassis.setPose(-12.5, 5, 134);
    intake.set_encoder_units_all(MOTOR_ENCODER_ROTATIONS);
    left.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    right.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    
    arm.move(127);
    pros::delay(700);
    arm.brake();

    chassis.moveDistance(20,1000,{.forwards = false,.maxSpeed=80});
    while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
    pros::delay(50);
    mogo.set_value(false);
    // pros::delay(50);
    chassis.cancelMotion();
    left.brake();
    right.brake();
    pros::delay(100);
    arm_mutex.lock();
    arm_move=false;
    arm_mutex.unlock();

    target_mutex.lock();
    global_target=100;
    target_mutex.unlock();



    //get 1st ring
    chassis.turnToPoint(-24,40,1000,{.minSpeed=5,.earlyExitRange=3},false);
    set_intake_speed(127);
    // chassis.moveToPoint(-25,40,2000,{},false);
    fast_move(-24,40,2000,false);

    //get stake ring
    chassis.turnToPoint(-46,66,1000,{.minSpeed=5,.earlyExitRange=3},false);
    fast_move(-46,66,1000,true);
    arm_mutex.lock();
    arm_move=false;
    arm_mutex.unlock();

    target_mutex.lock();
    global_target=2600;
    target_mutex.unlock();
    set_intake_speed(127,false);
    fast_move(-50,91,1000,true);

    pros::Task skills_task1{[=]
    {
        while(top_distance.get_distance()>100) pros::delay(10);
        pros::delay(500);
        target_mutex.lock();
        global_target=5000;
        target_mutex.unlock();
        set_intake_speed(-40);
        pros::delay(500);
        set_intake_speed(127);
    }};
    //move to stake
    // -48 65
    chassis.moveToPoint(-46,65,2000,{.forwards=false},false);
    chassis.turnToHeading(-90,1000);
    chassis.moveDistance(50,2000,{.maxSpeed = 60});
    chassis.waitUntil(12);
    target_mutex.lock();
    global_target=15000;
    target_mutex.unlock();
    int count = 0;
    while(arm_control.get_position()<11000 && chassis.isInMotion()) pros::delay(10);
    while(chassis.isInMotion()){
        if(count > 30){
            chassis.cancelMotion();
            break;
        } 
        count +=1;
        pros::delay(10);
    }
    


    chassis.moveDistance(18,1000,{.forwards=false,.minSpeed=5,.earlyExitRange=3},false); 
    target_mutex.lock();
    global_target=100;
    target_mutex.unlock();
    


    // return;

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
    chassis.turnToPoint(-49,6,1000,{.minSpeed=3,.earlyExitRange=5});
    // chassis.swingToPoint(-48,6,DriveSide::RIGHT,2000,{.maxSpeed=75,.minSpeed=3,.earlyExitRange=3});
    set_intake_speed(127);
    chassis.moveToPoint(-49,6,2000,{.minSpeed=60,.earlyExitRange=20});
    chassis.moveToPoint(-49,6,2000,{.maxSpeed=40},false);
    // pros::delay(1000);
    // set_intake_speed(0);

    //get 6th ring
    chassis.moveToPose(-60,25,10,2000,{.lead=.5},false);
    

    //score mogo
    chassis.moveDistance(14,1000,{.forwards=false},false);
    set_intake_speed(-127);
    mogo.set_value(true);
    pros::delay(200);
    set_intake_speed(0);
    chassis.moveDistance(9,1000,{.minSpeed=5,.earlyExitRange=3});
    

    //get new mogo                             
    // mogo.set_value(false);
    chassis.turnToPoint(33,15,1000,{.forwards=false});
    chassis.moveToPoint(33,15,4000,{.forwards=false,.minSpeed=5,.earlyExitRange=40});
    chassis.moveToPoint(33,15,3000,{.forwards=false,.maxSpeed=70});
    while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
    pros::delay(50);
    mogo.set_value(false);
    chassis.cancelMotion();

    //get 1st ring
    chassis.turnToPoint(28,40,1000,{.minSpeed=5,.earlyExitRange=3},false);
    set_intake_speed(127);
    fast_move(28,40,2000,false);
    // set_intake_speed(0);

    //get stake ring
    //45 64
    chassis.turnToPoint(45,64,1000,{.minSpeed=5,.earlyExitRange=3},false);
    fast_move(45,64,1000,true);
    arm_mutex.lock();
    arm_move=false;
    arm_mutex.unlock();

    target_mutex.lock();
    global_target=2600;
    target_mutex.unlock();
    set_intake_speed(127,false);
    fast_move(52,90,1000,true);
     pros::Task skills_task2{[=]
    {
        while(top_distance.get_distance()>100) pros::delay(10);
        pros::delay(500);
        target_mutex.lock();
        global_target=5000;
        target_mutex.unlock();
        set_intake_speed(-40);
        pros::delay(500);
        set_intake_speed(127);
    }};
    
    //move to stake
    chassis.moveToPoint(45,65,2000,{.forwards=false},false);
    chassis.turnToHeading(90,1000);
    chassis.moveDistance(60,2000,{.maxSpeed = 60});
    chassis.waitUntil(16);
    target_mutex.lock();
    global_target=15000;
    target_mutex.unlock();
    count = 0;
    while(arm_control.get_position()<11000 && chassis.isInMotion()) pros::delay(10);
    while(chassis.isInMotion()){
        if(count > 30){
            chassis.cancelMotion();
            break;
        } 
        count +=1;
        pros::delay(10);
    }


    chassis.moveDistance(17,1000,{.forwards=false,.minSpeed=5,.earlyExitRange=3},false); 
    target_mutex.lock();
    global_target=100;
    target_mutex.unlock();
    

    //get 6th ring
    set_intake_speed(127);
    chassis.turnToPoint(51,5,1000,{.minSpeed=3,.earlyExitRange=5});
    chassis.moveToPoint(51,5,2000,{.minSpeed=60,.earlyExitRange=20});
    chassis.moveToPoint(51,5,2000,{.maxSpeed=40},false);
    
    chassis.moveToPose(64,25,-10,3000,{.lead=.5},false);

    //score mogo
    chassis.moveDistance(15,1000,{.forwards=false},false);
    set_intake_speed(-127);
    mogo.set_value(true);
    pros::delay(200);
    set_intake_speed(0);
    chassis.moveDistance(5,1000,{.minSpeed=5,.earlyExitRange=3});

    // -20 87
    //get 1st ring
    chassis.turnToPoint(-22,89,1000);
    set_intake_speed(60);
    chassis.moveToPoint(-22,89,4000);
    // fast_move(-21,87,4000,false);
    while(distance.get_distance()>100 &&chassis.isInMotion()) pros::delay(10);
    set_intake_speed(0);
    while(chassis.getPose().y<85 &&chassis.isInMotion()) pros::delay(10);
    while(top_distance.get_distance()>100 &&chassis.isInMotion()){
        set_intake_speed(50);
        pros::delay(10);
    }
    set_intake_speed(0);

    //12 120
    //get mogo
    chassis.turnToPoint(4,118,1000,{.forwards=false});
    chassis.moveToPoint(4,118,4000,{.forwards=false,.maxSpeed=60});
    while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
    pros::delay(100);
    mogo.set_value(false);
    target_mutex.lock();
    global_target=2600;
    target_mutex.unlock();
    set_intake_speed(127,false);

    //face alliance stake
    chassis.turnToHeading(0,1000,{},false);
    set_intake_speed(0);
    chassis.moveDistance(50,1000,{.maxSpeed = 70});
    chassis.moveDistance(8,1000,{.forwards=false});
    set_intake_speed(-50);
    arm_mutex.lock();
    arm_move=true;
    arm_mutex.unlock();
    arm.move(127);
    pros::delay(1000);
    set_intake_speed(127);
    arm.brake();

    target_mutex.lock();
    global_target=5000;
    target_mutex.unlock();
    chassis.moveDistance(10,1000,{.forwards=false,.minSpeed=60,.earlyExitRange=3});
    chassis.moveDistance(14,1000,{.minSpeed=60,.earlyExitRange=3});
    chassis.moveDistance(22,1000,{.forwards=false,.minSpeed=5,.earlyExitRange=3});
    arm_mutex.lock();
    arm_move=false;
    arm_mutex.unlock();

    // target_mutex.lock();
    // global_target=100;
    // target_mutex.unlock();

    //get 2 rings on the side
    chassis.turnToPoint(-39,117,1000,{.minSpeed=3,.earlyExitRange=5});
    fast_move(-39,117,3000,true);
    // chassis.turnToHeading(-15,1000,{.minSpeed=5,.earlyExitRange=3});
    // chassis.moveDistance(10,1000,{.minSpeed=5,.earlyExitRange=3});

    //get 3 rings close to + side
    chassis.turnToPoint(8,107,1000,{.minSpeed=3,.earlyExitRange=5});
    fast_move(8,107,2000,true);
    fast_move(27,92,2000,true);

    chassis.turnToPoint(53,115,1000,{.minSpeed=3,.earlyExitRange=5});
    fast_move(53,115,2000,true); 
    chassis.turnToHeading(90,1000,{.minSpeed=5,.earlyExitRange=3});
    chassis.moveDistance(10,1000,{.minSpeed=5,.earlyExitRange=3});

    chassis.turnToHeading(25,1000,{.direction=AngularDirection::CCW_COUNTERCLOCKWISE,.minSpeed=5,.earlyExitRange=3},false);
    swiper.set_value(true);
    pros::delay(500);
    set_intake_speed(0);
    chassis.moveDistance(15,1000,{.minSpeed=5,.earlyExitRange=3});
    set_intake_speed(-127);
    chassis.turnToHeading(210,1000,{.direction=AngularDirection::CCW_COUNTERCLOCKWISE});
    left.move(127);
    right.move(-127);
    pros::delay(100);
    chassis.moveDistance(15,500,{.forwards=false});
    mogo.set_value(true);
    chassis.moveDistance(13,1000,{.minSpeed=5,.earlyExitRange=3});
    set_intake_speed(127);
    swiper.set_value(false);

    fast_move(-9,127,2000,true);
    set_intake_speed(-127);
    chassis.turnToHeading(285,1000,{.minSpeed=5,.earlyExitRange=3});
    chassis.moveDistance(48,1500,{.minSpeed=127},false);
    set_intake_speed(127);
    chassis.moveDistance(10,1000,{.forwards=false},false);

    

    chassis.turnToPoint(-20,92,2000,{.forwards=false,.minSpeed=5,.earlyExitRange=3});
    chassis.moveToPoint(-20,92,2000,{.forwards=false,.minSpeed=5,.earlyExitRange=3});
    target_mutex.lock();
    global_target=20000;
    target_mutex.unlock();
    set_intake_speed(0);
    chassis.turnToHeading(313,1000,{.minSpeed=5,.earlyExitRange=3});
    chassis.moveDistance(50,1000,{.forwards=false,.maxSpeed=100});


    return;
    // -9 127 285
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
