#include "main.h"
#include "Odometry.h"


/////
// For instalattion, upgrading, documentations and tutorials, check out website!
// https://ez-robotics.github.io/EZ-Template/
/////


// Chassis constructor

// Ports
//Motors
int RIGHT_FRONT_WHEELS_PORT = 2;
int RIGHT_BACK_WHEELS_PORT = 4; 
int RIGHT_TOP_WHEELS_PORT = 3;

int LEFT_FRONT_WHEELS_PORT = 9;
int LEFT_BACK_WHEELS_PORT = 10;
int LEFT_TOP_WHEELS_PORT = 7;

int INTAKE_LEFT = 8; 
int INTAKE_RIGHT =  1; 

int CATA_PORT = 11;

float Inatke_Speed = 100;
float Cata_Speed = 75;

 pros::Motor left_wheelsfront (LEFT_FRONT_WHEELS_PORT, true);
 pros::Motor left_wheelsback (LEFT_BACK_WHEELS_PORT, true);
  pros::Motor left_wheelstop (LEFT_TOP_WHEELS_PORT);
  //right drivetrain
  pros::Motor right_wheelsfront (RIGHT_FRONT_WHEELS_PORT);
  pros::Motor right_wheelsback (RIGHT_BACK_WHEELS_PORT);
  pros::Motor right_wheelstop (RIGHT_TOP_WHEELS_PORT, true); // True This reverses the motor
  //intake
  pros::Motor Left_intake (INTAKE_LEFT);
  pros::Motor Right_intake (INTAKE_RIGHT);
  //catapult
  pros::Motor Catapult (CATA_PORT);
  //controller code
  pros::Controller master (CONTROLLER_MASTER);


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
  
  
  pros::delay(500); // Stop the user from doing anything while legacy ports configure.

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
  int speed;
  int turn;
  int leftcontrol;
  int rightcontrol;
  while (true) {


    speed = master.get_analog(ANALOG_LEFT_Y);
    turn = master.get_analog(ANALOG_RIGHT_X);

    leftcontrol = (speed + turn);
    rightcontrol = (speed - turn);
    
    left_wheelsfront.move(leftcontrol);
    left_wheelsback.move(leftcontrol);
    left_wheelstop.move(leftcontrol);

    right_wheelsfront.move(rightcontrol);
    right_wheelsback.move(rightcontrol);
    right_wheelstop.move(rightcontrol);

    //intake 
    if (master.get_digital(DIGITAL_R2)) {
      Left_intake.move(Inatke_Speed);
      Right_intake.move(-Inatke_Speed);
    }

    else if (master.get_digital(DIGITAL_R1)) {
      Left_intake.move(-Inatke_Speed);
      Right_intake.move(Inatke_Speed);
    }
    else {
      Left_intake.move(0);
      Right_intake.move(0);
    }
    
    //catapult
    if (master.get_digital(DIGITAL_L2)) {
      Catapult.move(Cata_Speed);
    }

    else if (master.get_digital(DIGITAL_L1)) {
      Catapult.move(-Cata_Speed);
    }
    else {
      Catapult.move(0);
    }

      pros::screen::set_pen(COLOR_BLUE);
      int i = 0;
    for (i =0;i<0;i++) {
       // Will print seconds started since program started on line 3
       pros::screen::print(pros::E_TEXT_MEDIUM, 3, "This is a test");
    };

    pros::delay(ez::util::DELAY_TIME); // This is used for timer calculations!  Keep this ez::util::DELAY_TIME
  }
}
