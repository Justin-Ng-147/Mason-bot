#include "main.h"






void skills(){
    //set up
    chassis.setPose(-12.5, 5, 134);
    intake.set_encoder_units_all(MOTOR_ENCODER_ROTATIONS);
    left.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    right.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    
    //score preload
    arm.move(127);
    pros::delay(700);
    arm.brake();

    //get mogo 1
    chassis.moveDistance(20,1000,{.forwards = false,.maxSpeed=80});
    while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
    pros::delay(50);
    mogo.set_value(false);
    chassis.cancelMotion();
    left.brake();
    right.brake();
    pros::delay(100);

    //mogo 1 move arm back to start position
    arm_mutex.lock();
    arm_move=false;
    arm_mutex.unlock();
    target_mutex.lock();
    global_target=100;
    target_mutex.unlock();

    //mogo 1 get ring 1
    chassis.turnToPoint(-24,40,1000,{.minSpeed=5,.earlyExitRange=3},false);
    set_intake_speed(127);
    fast_move(-24,40,2000,false);

    //mogo 1 get ring 2 move to half way point to avoid hang post
    chassis.turnToPoint(-46,66,1000,{.minSpeed=5,.earlyExitRange=3},false);
    fast_move(-46,66,1000,true);
    //mogo 1 move arm to load ring
    arm_mutex.lock();
    arm_move=false;
    arm_mutex.unlock();
    target_mutex.lock();
    global_target=2600;
    target_mutex.unlock();
    //mogo 1 get ring 2 move to ring
    set_intake_speed(127,false);
    fast_move(-50,91,1000,true);

    //mogo 1 task that when the ring is on the arm lift the arm up out of the way of other intaked rings
    pros::Task skills_task1{[=]
    {
        while(top_distance.get_distance()>100) pros::delay(10);
        pros::delay(800);
        target_mutex.lock();
        global_target=5000;
        target_mutex.unlock();
        set_intake_speed(-40);
        pros::delay(500);
        set_intake_speed(127);
    }};

    //mogo 1 move to stake
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
    
    //mogo 1 back away from stake and move arm back to start pos
    chassis.moveDistance(18,1000,{.forwards=false,.minSpeed=5,.earlyExitRange=3},false); 
    target_mutex.lock();
    global_target=100;
    target_mutex.unlock();
    
    //mogo 1 get 3 rings in a line
    chassis.turnToPoint(-49,6,1000,{.minSpeed=3,.earlyExitRange=5});
    set_intake_speed(127);
    chassis.moveToPoint(-49,6,2000,{.minSpeed=60,.earlyExitRange=20});
    chassis.moveToPoint(-49,6,2000,{.maxSpeed=40},false);

    //mogo 1 get last ring and set up to drop off mogo
    chassis.moveToPose(-60,25,10,2000,{.lead=.5},false);
    

    //mogo 1 score mogo
    chassis.moveDistance(13,1000,{.forwards=false},false);
    set_intake_speed(-127);
    mogo.set_value(true);
    pros::delay(200);
    set_intake_speed(0);
    //mogo 1 move away from corner
    chassis.moveDistance(9,1000,{.minSpeed=5,.earlyExitRange=3});
    

    //get new mogo 2                             
    chassis.turnToPoint(33,15,1000,{.forwards=false});
    chassis.moveToPoint(33,15,4000,{.forwards=false,.minSpeed=5,.earlyExitRange=40});
    chassis.moveToPoint(33,15,3000,{.forwards=false,.maxSpeed=70});
    while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
    pros::delay(50);
    mogo.set_value(false);
    chassis.cancelMotion();

    //mogo 2 get 1st ring
    chassis.turnToPoint(28,40,1000,{.minSpeed=5,.earlyExitRange=3},false);
    set_intake_speed(127);
    fast_move(28,40,2000,false);

    //mogo 2 get ring 2 move to half way point to avoid hang post
    chassis.turnToPoint(45,64,1000,{.minSpeed=5,.earlyExitRange=3},false);
    fast_move(45,64,1000,true);
    //mogo 2 move arm to load ring
    arm_mutex.lock();
    arm_move=false;
    arm_mutex.unlock();
    target_mutex.lock();
    global_target=2600;
    target_mutex.unlock();
    //mogo 2 get ring 2 move to ring
    set_intake_speed(127,false);
    fast_move(52,91,1000,true);

    //mogo 2 task that when the ring is on the arm lift the arm up out of the way of other intaked rings
    pros::Task skills_task2{[=]
    {
        while(top_distance.get_distance()>100) pros::delay(10);
        pros::delay(800);
        target_mutex.lock();
        global_target=5000;
        target_mutex.unlock();
        set_intake_speed(-40);
        pros::delay(500);
        set_intake_speed(127);
    }};
    
    //mogo 2 move to stake
    chassis.moveToPoint(45,66,2000,{.forwards=false},false);
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

    //mogo 2 back away from stake and move arm back to start pos
    chassis.moveDistance(17,1000,{.forwards=false,.minSpeed=5,.earlyExitRange=3},false); 
    target_mutex.lock();
    global_target=100;
    target_mutex.unlock();
    

    //mogo 2 get 3 rings in a line
    set_intake_speed(127);
    chassis.turnToPoint(51,5,1000,{.minSpeed=3,.earlyExitRange=5});
    chassis.moveToPoint(51,5,2000,{.minSpeed=60,.earlyExitRange=20});
    chassis.moveToPoint(51,5,2000,{.maxSpeed=40},false);
    
    //mogo 2 get last ring and set up to drop off mogo
    chassis.moveToPose(64,25,-10,3000,{.lead=.5},false);

    //mogo 2 score mogo
    chassis.moveDistance(14,1000,{.forwards=false},false);
    set_intake_speed(-127);
    mogo.set_value(true);
    pros::delay(200);
    set_intake_speed(0);
    //mogo 2 move away from corner
    chassis.moveDistance(5,1000,{.minSpeed=5,.earlyExitRange=3});

    //mogo 3 go through center and get ring 1 & 2
    chassis.turnToPoint(-17,87,1000);
    set_intake_speed(60);
    chassis.moveToPoint(-17,87,4000);
    while(distance.get_distance()>100 &&chassis.isInMotion()) pros::delay(10);
    set_intake_speed(0);
    // while(chassis.getPose().y<85 &&chassis.isInMotion()) pros::delay(10);
    chassis.moveToPoint(-22,89,1000);
    //put ring in arm
    target_mutex.lock();
    global_target=2600;
    target_mutex.unlock();
    set_intake_speed(127,false);
    while(top_distance.get_distance()>100) pros::delay(10);
    pros::delay(800);
    target_mutex.lock();
    global_target=5000;
    target_mutex.unlock();
    set_intake_speed(-60);
    while(arm_control.get_position()<3600)pros::delay(10);
    //mogo 3 intake 2nd ring
    set_intake_speed(127);
    pros::Task skills_task3{[=]
    {
        while(true){
            if(pros::Task::notify_take(true, 10)) break;
            if(distance.get_distance() < 100 || top_distance.get_distance() < 100){
                set_intake_speed(0);
                break;
            }
        }
    }};

    //get mogo 3
    chassis.turnToPoint(3,118,1000,{.forwards=false});
    chassis.moveToPoint(3,118,4000,{.forwards=false,.maxSpeed=60});
    while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
    pros::delay(100);
    mogo.set_value(false);
    skills_task3.notify();
    set_intake_speed(127);

    //mogo 3 face alliance stake
    chassis.turnToHeading(0,1000,{},false);
    set_intake_speed(0);
    //mogo 3 score on alliance stake
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

    //mogo 3 get 2nd ring that dropped in front of alliance stake
    chassis.moveDistance(12,1000,{.forwards=false,.minSpeed=60,.earlyExitRange=3});
    arm_mutex.lock();
    arm_move=false;
    arm_mutex.unlock();
    target_mutex.lock();
    global_target=5000;
    target_mutex.unlock();
    // chassis.moveDistance(14,1000,{.minSpeed=60,.earlyExitRange=3});
    // chassis.moveDistance(22,1000,{.forwards=false,.minSpeed=5,.earlyExitRange=3});
    

    //mogo 3 get ring on far side
    // chassis.turnToPoint(-42,117,1000,{.minSpeed=3,.earlyExitRange=5});
    // fast_move(-42,117,3000,true);

    //mogo 3 move to 4th ring
    chassis.turnToPoint(27,92,1000,{.minSpeed=3,.earlyExitRange=5});
    // fast_move(8,107,2000,true);
    fast_move(27,92,2000,true);

    //mogo 3 get 5th ring
    chassis.turnToPoint(53,115,1000,{.minSpeed=3,.earlyExitRange=5});
    fast_move(53,115,2000,true); 
    //mogo 3 get 6th ring
    chassis.turnToHeading(90,1000,{.minSpeed=5,.earlyExitRange=3});
    chassis.moveDistance(8,1000,{.minSpeed=5,.earlyExitRange=3});

    //mogo 3 swipe corner
    chassis.turnToHeading(20,1000,{.direction=AngularDirection::CCW_COUNTERCLOCKWISE,.minSpeed=5,.earlyExitRange=3},false);
    swiper.set_value(true);
    pros::delay(500);
    set_intake_speed(0);
    chassis.moveDistance(15,1000,{.minSpeed=5,.earlyExitRange=3});
    set_intake_speed(-127);
    chassis.turnToHeading(210,2000,{.direction=AngularDirection::CCW_COUNTERCLOCKWISE});
    left.move(127);
    right.move(-127);
    pros::delay(100);
    //mogo 3 score mogo
    chassis.moveDistance(15,500,{.forwards=false});
    mogo.set_value(true);
    chassis.moveDistance(13,1000,{.minSpeed=5,.earlyExitRange=3});
    set_intake_speed(127);
    swiper.set_value(false);

    //push mogo 4
    fast_move(-9,127,2000,true);
    set_intake_speed(-127);
    chassis.turnToHeading(285,1000,{.minSpeed=5,.earlyExitRange=3});
    chassis.moveDistance(48,1500,{.minSpeed=127},false);
    set_intake_speed(60);
    chassis.moveDistance(10,1000,{.forwards=false},false);

    
    //hang
  chassis.turnToPoint(-20,92,1000,{.forwards=false,.minSpeed=20,.earlyExitRange=3});
    chassis.moveToPoint(-20,92,2000,{.forwards=false,.minSpeed=5,.earlyExitRange=3});
    target_mutex.lock();
    global_target=20000;
    target_mutex.unlock();
    set_intake_speed(0);
    chassis.turnToHeading(313,1000,{.minSpeed=20,.earlyExitRange=3});
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
