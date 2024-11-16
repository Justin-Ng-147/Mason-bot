#include "main.h"

pros::Task* sort_task = nullptr;

pros::vision_signature_s_t RED_SIG =
    pros::Vision::signature_from_utility(1, 11049, 12603, 11826,-1625, -703, -1164,5, 0);

pros::vision_signature_s_t BLUE_SIG =
    pros::Vision::signature_from_utility(2, -3785, -3395, -3590, 5827, 7261, 6544, 6.000, 0);
    

void setup(){
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
int ring_tossed(double start){
  double dif = fabs(intake.get_position())-fabs(start);
  // printf("%f\n",dif);
  if(dif > 1.3) return 2;
  else if(dif > 0) return 1;
  else return 0;
}

void sort(int color){
  if (sort_task == nullptr) {
    sort_task = new pros::Task{ [=]{
      // int count = 0;
      int colors = 0;
      bool sort = false;

      setup();
      while(true){
        pros::vision_object_s_t rtn = vision.get_by_sig(0,color);

        if(rtn.width>100 && colors == 0 && distance.get_distance()<150){
          colors = 1;
        }
        // printf("found\n");
        // if(count == 1){
          if(colors == 1){
            // printf("found\n");
            // while(vision.get_by_sig(0,color).width>100) pros::delay(10);
            while(vision.get_by_sig(0,color).width>100) pros::delay(5);
            if(!sort){
                sort_thrower.set_value(true);
                sort = true;
                }
            double start = intake.get_position();
            // printf("sorting\n");
            int flag = 0;
            while (flag != 2)
            {
              if(!sort){
                sort_thrower.set_value(true);
                sort = true;
                }
              
              if(vision.get_by_sig(0,color).width>100 && distance.get_distance()<150){
                  start = intake.get_position();
              }

              flag = ring_tossed(start);
              // if(flag == 1 && !sort){
              //   sort_thrower.set_value(false);
              //   sort = true;
              // }
              pros::delay(10);
            }
            sort_thrower.set_value(false);
            sort = false;
          }
          // else{
          //   printf("0\n");
          // } 
          // count = 0;
          colors = 0;
        // }

        // count ++;
        pros::delay(10);
      }
    }};
  }
}

bool mogo_seated(){
  return mogo_distance.get_distance()<45;
}


pros::Mutex intake_mutex;
int intake_speed = 0;
pros::Task* intake_task = nullptr;

void init_intake(){
    if (intake_task == nullptr) {
        intake_task = new pros::Task{[=]{
            int prev_speed = 0;
            while(true){
                intake_mutex.lock();
                int speed = intake_speed;
                intake_mutex.unlock();

                intake.move(speed);
                if(speed != prev_speed) pros::delay(100);
                prev_speed= speed;
                
                if(speed > 0 && intake.get_efficiency() < 3){
                    intake.move(-127);
                    pros::delay(500);
                    intake.move(0);
                    prev_speed = 0;
                }
                pros::delay(10);
            }
        }};
    }
}

void set_intake_speed(int speed){
    pros::Task intake_task2{[=]{
        intake_mutex.lock();
        intake_speed = speed;
        intake_mutex.unlock();
    }};
    // intake_task2.remove();
    // delete &intake_task2;
}

void fast_move(float x, float y, int timeout,bool async = true){
    chassis.moveToPoint(x,y,timeout,{.minSpeed=5, .earlyExitRange=10});
    chassis.moveToPoint(x,y,timeout,{.maxSpeed = 40, .minSpeed = 5, .earlyExitRange = 3},async);
}