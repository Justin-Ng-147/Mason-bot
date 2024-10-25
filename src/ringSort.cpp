#include "main.h"

pros::Task* sort_task = nullptr;

pros::vision_signature_s_t RED_SIG =
    pros::Vision::signature_from_utility(1, 11049, 12603, 11826,-1625, -703, -1164,5, 0);

pros::vision_signature_s_t BLUE_SIG =
    pros::Vision::signature_from_utility(2, 11049, 12603, 11826,-1625, -703, -1164,5, 0);
    

void setup(){
    vision.set_signature(1, &RED_SIG);
    vision.set_signature(2, &BLUE_SIG);
    intake.set_encoder_units_all(pros::E_MOTOR_ENCODER_ROTATIONS);
    vision.get_object_count();
    pros::delay(100);
    sort_thrower.set_value(true);
}

/*
 *return 1 if ready to be tossed
 *return 2 if already tossed
 *return 0 if none 
 */
int ring_tossed(double start){
  double dif = fabs(intake.get_position())-fabs(start);
  // printf("%f\n",dif);
  if(dif > 1.5) return 2;
  else if(dif > 0) return 1;
  else return 0;
}

void sort(){
  if (sort_task == nullptr) {
    sort_task = new pros::Task{ [=]{
      // int count = 0;
      int colors = 0;
      bool sort = false;

      setup();
      while(true){
        pros::vision_object_s_t rtn = vision.get_by_sig(0,1);

        if(rtn.width>100 && colors == 0 && distance.get_distance()<150){
          colors = 1;
        }

        // if(count == 1){
          if(colors == 1){
            // printf("found\n");
            while(vision.get_by_sig(0,1).width>100) pros::delay(10);
            if(!sort){
                sort_thrower.set_value(false);
                sort = true;
                }
            double start = intake.get_position();
            // printf("sorting\n");
            int flag = 0;
            while (flag != 2)
            {
              if(!sort){
                sort_thrower.set_value(false);
                sort = true;
                }
              
              if(vision.get_by_sig(0,1).width>100 && distance.get_distance()<150){
                  start = intake.get_position();
              }

              flag = ring_tossed(start);
              // if(flag == 1 && !sort){
              //   sort_thrower.set_value(false);
              //   sort = true;
              // }
              pros::delay(10);
            }
            sort_thrower.set_value(true);
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