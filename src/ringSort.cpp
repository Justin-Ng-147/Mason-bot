#include "main.h"

pros::Task *sort_task = nullptr;
pros::Mutex intake_control;

pros::vision_signature_s_t RED_SIG =
    pros::Vision::signature_from_utility(1, 11049, 12603, 11826, -1625, -703, -1164, 5, 0);

pros::vision_signature_s_t BLUE_SIG =
    pros::Vision::signature_from_utility(2, -3785, -3395, -3590, 5827, 7261, 6544, 6.000, 0);

void setup()
{
  vision.set_signature(1, &RED_SIG);
  vision.set_signature(2, &BLUE_SIG);
  intake.set_encoder_units_all(pros::E_MOTOR_ENCODER_ROTATIONS);
  vision.get_object_count();
  pros::delay(100);
  // sort_thrower.set_value(true);
}

/*
 *return 1 if ready to be tossed
 *return 2 if already tossed
 *return 0 if none
 */
int ring_tossed(double start)
{
  double dif = fabs(intake.get_position()) - fabs(start);
  // printf("%f\n",dif);
  if (dif > 1.2)
    return 2;
  else if (dif > 0)
    return 1;
  else
    return 0;
}

void sort(int color)
{
  if (sort_task == nullptr)
  {
    sort_task = new pros::Task{[=]
                               {
                                 // int count = 0;
                                 int colors = 0;
                                 bool sort = false;

                                 setup();
                                 // while(true){
                                 //   pros::vision_object_s_t rtn = vision.get_by_sig(0,color);

                                 //   if(rtn.width>100 && distance.get_distance()<60){
                                 //     intake_control.lock();
                                 //     pros::Task::notify_take(true,10);
                                 //     while(top_distance.get_distance()>100  && !pros::Task::notify_take(true,10));
                                 //     pros::delay(25);
                                 //     intake.move(-60);
                                 //     pros::delay(250);
                                 //     intake.move(0);
                                 //     intake_control.unlock();
                                 //   }
                                 //   pros::delay(10);
                                 // }
                               }};
  }
}

bool mogo_seated()
{
  return mogo_distance.get_distance() < 25;
}

pros::Mutex intake_mutex;
int intake_speed = 0;
bool antijam = true;
pros::Task *intake_task = nullptr;

void init_intake()
{
  if (intake_task == nullptr)
  {
    intake_task = new pros::Task{[=]
                                 {
                                   int count = 0;
                                   int prev_speed = 0;
                                   while (!pros::Task::notify_take(true, 10))
                                   {
                                     intake_mutex.lock();
                                     int speed = intake_speed;
                                     bool antijam_temp = antijam;
                                     intake_mutex.unlock();

                                     intake.move(speed);
                                     if (speed != prev_speed)
                                       pros::delay(100);
                                     prev_speed = speed;

                                     if (speed > 0 && intake.get_efficiency() < 1 && antijam_temp)
                                     {
                                       count += 1;
                                     }
                                     if (count > 10 && antijam_temp)
                                     {
                                       intake.move(-127);
                                       pros::delay(500);
                                       intake.move(0);
                                       prev_speed = 0;
                                       count = 0;
                                     }
                                   }
                                 }};
  }
}

void set_intake_speed(int speed, bool jam)
{
  pros::Task intake_task2{[=]
                          {
                            intake_mutex.lock();
                            intake_speed = speed;
                            antijam = jam;
                            intake_mutex.unlock();
                          }};
  // intake_task2.remove();
  // delete &intake_task2;
}

void fast_move(float x, float y, int timeout, bool async = true)
{
  chassis.moveToPoint(x, y, timeout, {.minSpeed = 5, .earlyExitRange = 10});
  chassis.moveToPoint(x, y, timeout, {.maxSpeed = 30, .minSpeed = 5, .earlyExitRange = 3}, async);
}

// void init_driver_intake(){
//     pros::Task driver_intake{[=]{
//       while(true){
//         if(master.get_digital(DIGITAL_R1)){
//           intake_control.lock();
//           intake.move(127);
//           intake_control.unlock();
//           // set_intake_speed(127);
//         }
//         else if(master.get_digital(DIGITAL_R2)){
//           intake_control.lock();
//           intake.move(-127);
//           intake_control.unlock();
//           // set_intake_speed(-127);
//         }
//         else{
//           sort_task->notify();
//           intake_control.lock();
//           intake.move(0);
//           intake_control.unlock();
//           // set_intake_speed(0);
//         }
//       }
//     }};
// }

pros::Mutex arm_mutex;
pros::Mutex target_mutex;
int global_target = 0;
bool arm_move = true;

// void arm_to_pos(){
// 	  pros::Task arm_task_0{[=]{
// 		int target;
// 		int pos = arm_control.get_position();
// 		int error = target - pos;
// 		int speed;
// 		bool prevsgn = error>0;
//         while(true){

// 			target_mutex.lock();
// 			target = global_target;
// 			target_mutex.unlock();
// 			pos = arm_control.get_position();
// 			error = target - pos;
// 			speed = error *.03;
// 			if(speed>127) speed = 127;
// 			if(speed<-127) speed = -127;
// 			arm_mutex.lock();
// 			if(!arm_move) arm.move(speed);
// 			arm_mutex.unlock();

// 			// if(prevsgn != (error>0)) break;
// 			prevsgn = (error>=0);
// 			pros::delay(10);
// 		}
// 		arm.brake();

//     }};
// }

void arm_to_pos()
{
  pros::Task arm_task_0{[=]
    {
      lemlib::PID arm_pid(.07,0,.2);
      arm_pid.reset();
      int target;
      int pos = arm_control.get_position();
      int error = target - pos;
      float speed;
      while (true)
      {

        target_mutex.lock();
        target = global_target;
        target_mutex.unlock();
        pos = arm_control.get_position();
        error = target - pos;
        // if(abs(error)<100) error = 0;
        speed = arm_pid.update(error);
        if (speed > 127)
          speed = 127;
        if (speed < -127)
          speed = -127;
        arm_mutex.lock();
        if (!arm_move)
          arm.move(speed);
        arm_mutex.unlock();
        pros::delay(10);
      }
    }};
}