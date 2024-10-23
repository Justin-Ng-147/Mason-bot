#include "main.h"

pros::vision_signature_s_t RED_SIG =
    pros::Vision::signature_from_utility(1, 11049, 12603, 11826,-1625, -703, -1164,5, 0);

pros::vision_signature_s_t BLUE_SIG =
    pros::Vision::signature_from_utility(2, 11049, 12603, 11826,-1625, -703, -1164,5, 0);
    

void setup(){
    vision.set_signature(1, &RED_SIG);
    vision.set_signature(2, &BLUE_SIG);
    intake.set_encoder_units_all(pros::E_MOTOR_ENCODER_ROTATIONS);
}

/*
 *return 1 if ready to be tossed
 *return 2 if already tossed
 *return 0 if none 
 */
int ring_tossed(){
    if(intake.get_position() > 2) return 2;
    else if(intake.get_position() > 1) return 1;
    else return 0;
}

void sort(){
    int count = 0;
  int colors = 0;
  int found = 0;
  
  while(true){
    pros::vision_object_s_t rtn = vision.get_by_sig(0,1);

    if(rtn.signature==1 && colors == 0){
      colors = 1;
    }
    // if(Distance5.objectDistance(mm) < 70 && found ==0){
    //   found = 1;
    // }

    if(count == 10){
      if(colors == 1){
        printf("found\n");
      }
      else{
        // printf("bla: %d\n",vision.get_object_count());
        printf("0\n");
      } 
      count = 0;
      colors = 0;
    }

    count ++;
    pros::delay(10);
  }
}