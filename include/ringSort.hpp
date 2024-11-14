#ifndef _RINGSORT_HPP_
#define _RINGSORT_HPP_

    #define REDCOLOR 1
    #define BLUECOLOR 2

    void sort(int color);
    bool mogo_seated();
    void init_intake();
    void set_intake_speed(int speed);
    void fast_move(float x, float y, int timeout,bool async);

    extern pros::Task* intake_task;

#endif