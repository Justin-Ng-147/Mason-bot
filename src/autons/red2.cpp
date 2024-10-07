#include "main.h"

void red2(){
    chassis.turnToPoint(0,-50,100000);
    chassis.moveDistance(30,10000,{.earlyExitRange = 25});
    chassis.moveDistance(30,10000,{.maxSpeed=40});
}

