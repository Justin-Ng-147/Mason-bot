#include "main.h"

int convert_bit(int input){
    if(input & LCD_BTN_LEFT){
        return -1;
    }
    else if(input & LCD_BTN_CENTER){
        return 100;
    }
    else if(input & LCD_BTN_RIGHT){
        return 1;
    }
    else return 0;
}



void chooser(int& status){
    bool set_text = false;
    int selected = 0;

    while (true)
    {
        selected = convert_bit(pros::lcd::read_buttons());
        // printf("%d , %d\n",pros::lcd::read_buttons(),status);
        if(status == -3){
            if(!set_text){
                pros::lcd::set_text(1, "    blue F   ");
                set_text = true;
            }
            if(selected != 0){
                set_text=false;
                if(selected == 100) return;
                else status += selected;
                pros::delay(500);
                continue;
            }
        }
        else if(status == -2){
            if(!set_text){
                pros::lcd::set_text(1, "    blue +   ");
                set_text = true;
            }
            if(selected != 0){
                set_text=false;
                if(selected == 100) return;
                else status += selected;
                pros::delay(500);
                continue;
            }
        }
        else if(status == -1){
            if(!set_text){
                pros::lcd::set_text(1, "    blue -   ");
                set_text = true;
            }
            if(selected != 0){
                set_text=false;
                if(selected == 100) return;
                else status += selected;
                pros::delay(500);
                continue;
            }
        }
        else if(status == 0){
            if(!set_text){
                pros::lcd::set_text(1, "<-blue       choose       red->");
                set_text = true;
            }
            if(selected != 0){
                set_text=false;
                if(selected != 100) status += selected;
                pros::delay(500);
                continue;
            }
        }
        else if(status == 1){
            if(!set_text){
                pros::lcd::set_text(1, "    red -   ");
                set_text = true;
            }
            if(selected != 0){
                set_text=false;
                if(selected == 100) return;
                else status += selected;
                pros::delay(500);
                continue;
            }
        }
        else if(status == 2){
            if(!set_text){
                pros::lcd::set_text(1, "    red +   ");
                set_text = true;
            }
            if(selected != 0){
                set_text=false;
                if(selected == 100) return;
                else status += selected;
                pros::delay(500);
                continue;
            }
        }
        else if(status == 3){
            if(!set_text){
                pros::lcd::set_text(1, "    red F   ");
                set_text = true;
            }
            if(selected != 0){
                set_text=false;
                if(selected == 100) return;
                else status += selected;
                pros::delay(500);
                continue;
            }
        }
        else if(status == 4){
            if(!set_text){
                pros::lcd::set_text(1, "    skills   ");
                set_text = true;
            }
            if(selected != 0){
                set_text=false;
                if(selected == 100) return;
                else status += selected;
                pros::delay(500);
                continue;
            }
        }
        else status = 0;

        selected = 0;
        pros::delay(20);
    }
}

void run_auton(int selected){
    switch (selected)
    {
    case -3:
        blue2();
        break;
    case -2:
        blue2();
        break;
    case -1:
        blue1();
        break;
    case 1:
        red1();
        break;
    case 2:
        red2();
        break;
    case 3:
        red3();
        break;
    case 4:
        skills();
        break;
    
    default:
        break;
    }
}