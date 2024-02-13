#include "main.h"
#include "autons.h"

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */

void screen() {
    // loop forever
    while (true) {
        lemlib::Pose pose = chassis.getPose(); // get the current position of the robot
        pros::lcd::print(0, "x: %f", pose.x); // print the x position
        pros::lcd::print(1, "y: %f", pose.y); // print the y position
        pros::lcd::print(2, "heading: %f", pose.theta); // print the heading
        pros::delay(10);
    }
}

ez::GUI display(
    {{left_front_motor, "lF"},
     {left_mid_motor, "lM"},
     {left_back_motor, "lB"},
     {right_front_motor, "rF"},
     {right_mid_motor, "rM"},
     {right_back_motor, "rB"},
     {kicker, "kicker"},
     {intake, "intake"}},
    {{"3 Ball Safe", safe3Ball},
	 {"Disrupt WP", disruptWP},
	 {"Disrupt Bowl", disruptBowl}});

// void on_center_button() {
// 	static bool pressed = false;
// 	pressed = !pressed;
// 	if (pressed) {
// 		pros::lcd::set_text(2, "I was pressed!");
// 	} else {
// 		pros::lcd::clear_line(2);
// 	}
// }

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	display.enable();
  	display.auton_enable();
  	display.auton_print();
	chassis.calibrate(); // calibrate the chassis
    chassis.setPose(0, 0, 0); // X: 0, Y: 0, Heading: 0
	setDriveBrake(MOTOR_BRAKE_BRAKE);
	sylib::initialize();
	intake.set_brake_mode(MOTOR_BRAKE_HOLD);
	//pros::Task debug = pros::Task(screen);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {

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
 * will be stopped. Re-e5nabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	display.auton_call();
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
	
	display.auton_disable();
	// Store the time at the start of the loop
    std::uint32_t clock = sylib::millis();
	while (true) {
		chassis.arcade(master.get_analog(ANALOG_LEFT_Y), master.get_analog(ANALOG_RIGHT_X));
		pneumaticControl();
		intakeControl();
		kickerControl();
		// 10ms delay to allow other tasks to run
        sylib::delay_until(&clock, 10);
	}
}
