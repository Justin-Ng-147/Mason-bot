#include "main.h"




/*
true: display odometry data and will run the test auton
false: display competition screen to choose different autons
*/
bool testing = false;

int auton_status = 0;
int test_auton = BLUE4;



/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::delay(100);

	// chassis = init_drive();
	chassis.calibrate();
    pros::delay(100);
    // chassis.setPose(0,0,146);
	chassis.setPose(0,0,0);
	// chassis.setPose(0,0,-12);

	mogo.set_value(true);
	pto.set_value(false);

	// sort_thrower.set_value(true);

	if(testing){
		if (test_auton < 0) sort(REDCOLOR);
		else sort(BLUECOLOR);
		pros::Task screen_task([&]() {
			while (true) {
				// print robot location to the brain screen
				pros::lcd::print(1, "X: %f", chassis.getPose().x); // x
				pros::lcd::print(2, "Y: %f", chassis.getPose().y); // y
				pros::lcd::print(3, "Theta: %f", chassis.getPose().theta); // heading
				// delay to save resources
				pros::delay(20);
			}
		});
	}
	else{
		chooser(auton_status);
		if (auton_status < 0) sort(REDCOLOR);
		else sort(BLUECOLOR);
		pros::lcd::set_text(1, "auton chosen");
	}

}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
	// if(!testing){
	// 	chooser(auton_status);
	// 	pros::lcd::set_text(1, "auton chosen");
	// }
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	init_intake();
	if(testing) run_auton(test_auton);
	else run_auton(auton_status);
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	// intake_task->remove();
	pros::Controller master(pros::E_CONTROLLER_MASTER);

	bool pto_flag = true;
	bool pto_pressed = true;
	bool mogo_flag = true;
	bool mogo_pressed = true;
	bool claw_flag = true;
	bool claw_pressed = true;
	bool hang_flag = true;
	bool hang_pressed = true;
	bool deploy_flag = true;
	bool deploy_pressed = true;
	bool swiper_flag = false;
	bool swiper_pressed = true;

	if (intake_task != nullptr) {
		intake_task->notify();
	}

	while (true) {
		#pragma region arcade
		// Arcade control scheme
		int dir = master.get_analog(ANALOG_LEFT_Y);    // Gets amount forward/backward from left joystick
		int turn = master.get_analog(ANALOG_RIGHT_X);  // Gets the turn left/right from right joystick
		left.move(dir+turn);
		right.move(dir-turn);
		#pragma endregion arcade

		#pragma region intake r1
		if(master.get_digital(DIGITAL_R1)){
			intake.move(127);
			// set_intake_speed(127);
		}
		else if(master.get_digital(DIGITAL_R2)){
			intake.move(-127);
			// set_intake_speed(-127);
		}
		else{
			intake.move(0);
			// set_intake_speed(0);
		}
		#pragma endregion intake

		#pragma region pto a
		if(master.get_digital(DIGITAL_L2) && !pto_pressed){
			pto_flag = !pto_flag;
			pto.set_value(pto_flag);
			pto_pressed = true;
		}
		else if(master.get_digital(DIGITAL_L2) != 1 && pto_pressed){
			pto_pressed = false;
		}
		#pragma endregion pto

		#pragma region mogo x
		if(master.get_digital(DIGITAL_L1) && !mogo_pressed){
			mogo_flag = !mogo_flag;
			mogo.set_value(mogo_flag);
			mogo_pressed = true;
		}
		else if(master.get_digital(DIGITAL_L1) != 1 && mogo_pressed){
			mogo_pressed = false;
		}
		// else if(mogo_seated() && !mogo_flag && !mogo_pressed)
		// {
		// 	mogo.set_value(true);
		// 	mogo_flag = true;
		// }

		if(master.get_digital(DIGITAL_Y) && !hang_pressed){
			hang_flag = !hang_flag;
			hang.set_value(hang_flag);
			hang_pressed = true;
		}
		else if(master.get_digital(DIGITAL_Y) != 1 && hang_pressed){
			hang_pressed = false;
		}
		
		#pragma endregion mogo

		#pragma region swiper b
		if(master.get_digital(DIGITAL_B) && !swiper_pressed){
			swiper_flag = !swiper_flag;
			swiper.set_value(swiper_flag);
			swiper_pressed = true;
		}
		else if(master.get_digital(DIGITAL_B) != 1 && swiper_pressed){
			swiper_pressed = false;
		}

		if(master.get_digital(DIGITAL_RIGHT) && !claw_pressed){
			claw_flag = !claw_flag;
			claw.set_value(claw_flag);
			claw_pressed = true;
		}
		else if(master.get_digital(DIGITAL_RIGHT) != 1 && claw_pressed){
			claw_pressed = false;
		}

		if(master.get_digital(DIGITAL_DOWN) && !deploy_pressed){
			deploy_flag = !deploy_flag;
			deploy.set_value(deploy_flag);
			deploy_pressed = true;
		}
		else if(master.get_digital(DIGITAL_DOWN) != 1 && deploy_pressed){
			deploy_pressed = false;
		}
		
		#pragma endregion swiper


		pros::delay(20);                               // Run for 20 ms then update
	}
}