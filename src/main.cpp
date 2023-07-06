#include "main.h"
#include "Odometry.h"
#include "Constants.h"
#include "Base.h"
#include "pagehandler.h"
#include "screens.h"
#include "motors.h"
#include "functions.h"
/////
// For instalattion, upgrading, documentations and tutorials, check out website!
// https://ez-robotics.github.io/EZ-Template/
/////       

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
  
  lv_init();
  pageHandler(-1);
  lv_task_handler();
  pros::delay(1500); //pause to show loading
  pros::delay(500); // Stop the user from doing anything while legacy ports configure.
  Catapult::init(); //initilize the catapult
  Base_Init();

  // Configure your chassis controls
  
  // These are already defaulted to these buttons, but you can change the left/right curve buttons here!
  // chassis.set_left_curve_buttons (pros::E_CONTROLLER_DIGITAL_LEFT, pros::E_CONTROLLER_DIGITAL_RIGHT); // If using tank, only the left side is used. 
  // chassis.set_right_curve_buttons(pros::E_CONTROLLER_DIGITAL_Y,    pros::E_CONTROLLER_DIGITAL_A);


}



/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
  // . . .
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
void competition_initialize() {
  // . . .
}



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


  ez::as::auton_selector.call_selected_auton(); // Calls selected auton from autonomous selector.
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
  // This is preference to what you like to drive on.
  //left drivetrain
  
  //controller code
  pros::Controller master (CONTROLLER_MASTER);
  
  bool intaketoggle = false;
  
  float catarotationdegrees;
  while (true) {

    //drive
    BaseDrive::driveController(master);
   
    //intake/outtake 

    if (master.get_digital(DIGITAL_R2)) { //outtake (push button)
      intaketoggle = false;
      Intake::reverse();
    }

    else if (master.get_digital_new_press(DIGITAL_R1)) { //toggle the intake
      intaketoggle = !intaketoggle;
    }
    if (intaketoggle) { // activates the intake based on toggle status
      Intake::run();
    }
    else if (!intaketoggle && !master.get_digital(DIGITAL_R2)) {
      Intake::stop();
    }
    
    //catapult
    if (master.get_digital(DIGITAL_L2)) {

    }
    else if (master.get_digital(DIGITAL_L1)) {
      Catapult::run();
    }
    else {
      Catapult::stop(); // holds the catapult in place
    }
    //update cata data on debug

    pros::delay(ez::util::DELAY_TIME);// This is used for timer calculations!  Keep this ez::util::DELAY_TIME
    //update od 
  }
  
    
}