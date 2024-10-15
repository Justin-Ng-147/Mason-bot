#include "main.h"




/*
true: display odometry data and will run the test auton
false: display competition screen to choose different autons
*/
bool testing = true; 

int auton_status = 0;
int test_auton = RED1;



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
    chassis.setPose(0,0,0);

	mogo.set_value(true);
	pto.set_value(true);

	if(testing){
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
		pros::lcd::set_text(1, "auton chosen");
	}

}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
	if(!testing){
		chooser(auton_status);
		pros::lcd::set_text(1, "auton chosen");
	}
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
	pros::Controller master(pros::E_CONTROLLER_MASTER);

	bool pto_flag = false;
	bool pto_pressed = true;
	bool mogo_flag = false;
	bool mogo_pressed = true;

	while (true) {
		// Arcade control scheme
		int dir = master.get_analog(ANALOG_LEFT_Y);    // Gets amount forward/backward from left joystick
		int turn = master.get_analog(ANALOG_RIGHT_X);  // Gets the turn left/right from right joystick
		chassis.arcade(dir,turn);

		if(master.get_digital(DIGITAL_R1)){
			intake.move(127);
		}
		else if(master.get_digital(DIGITAL_R2)){
			intake.move(-127);
		}
		else{
			intake.move(0);
		}

		if(master.get_digital(DIGITAL_A) && !pto_pressed){
			pto_flag = !pto_flag;
			pto.set_value(pto_flag);
			pto_pressed = true;
		}
		else if(master.get_digital(DIGITAL_A) != 1 && pto_pressed){
			pto_pressed = false;
		}

		if(master.get_digital(DIGITAL_X)){
			mogo_flag = !mogo_flag;
			pto.set_value(mogo_flag);
		}

		pros::delay(20);                               // Run for 20 ms then update
	}
}