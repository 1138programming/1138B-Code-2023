#include "main.h"
#include "Odometry.h"
#include "Constants.cpp"

/////
// For instalattion, upgrading, documentations and tutorials, check out website!
// https://ez-robotics.github.io/EZ-Template/
/////


// Chassis constructor

// Ports
//Motors

  //intake
  pros::Motor Left_intake (INTAKE_LEFT);
  pros::Motor Right_intake (INTAKE_RIGHT);
  float Inatke_Speed = 100;
  float Outtake_Coefficient = 1;

  //catapult
  pros::Motor Catapult (CATA_PORT, true);
  float Cata_Speed = 75;
  pros::Rotation Cata_Rotation (CATA_ROT);
  bool inRange(unsigned low, unsigned high, unsigned x) //check if rotational sensor data is within a range of degrees        
    { 
      if (low > high) {
        return (low <= x || x <= high);
      }
      else {  
        return (low <= x && x <= high);         
      }        
    }          

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
  
  
  pros::delay(500); // Stop the user from doing anything while legacy ports configure.
  Catapult.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD); // sets the catapult motor to hold
  pros::lcd::initialize();
  pros::lcd::set_text_color(0,255,0);

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
  pros::screen::set_pen(COLOR_BLUE);
  
  bool intaketoggle = false;
  bool intakebuttonstate = false;
  float outtake_speed = (Inatke_Speed * Outtake_Coefficient);
  float catarotationdegrees;
  while (true) {

    //drive

   
    //tank testing
    //leftcontrol = turn;
    //rightcontrol = speed;



    //intake/outtake
    
    if (master.get_digital(DIGITAL_R2)) { //outtake (push button)
      intaketoggle = false;
      Left_intake.move(outtake_speed);
      Right_intake.move(-outtake_speed);
    }

    else if (master.get_digital_new_press(DIGITAL_R1)) { //toggle the intake
      intaketoggle = !intaketoggle;
    }
    if (intaketoggle) { // activates the intake based on toggle status
      Left_intake.move(-Inatke_Speed);
      Right_intake.move(Inatke_Speed);
    }
    else if (!intaketoggle && !master.get_digital(DIGITAL_R2)) {
      Left_intake.move(0);
      Right_intake.move(0);
    }
    //catapult
    catarotationdegrees = Cata_Rotation.get_angle() / 100; //define the catapult rotation when the button is first pressed
    if (master.get_digital(DIGITAL_L2)) {
      Catapult.move(-Cata_Speed);
    }
    else if (master.get_digital(DIGITAL_L1)) {
      float catarotationdegrees;
      while (!inRange(358,2,catarotationdegrees)) {
        catarotationdegrees = Cata_Rotation.get_angle() / 100;
        Catapult.move(Cata_Speed); // move catapult until it reaches position from rotation sensor
        catarotationdegrees = Cata_Rotation.get_angle() / 100; //check the catapult position while moving
        pros::lcd::set_text(1, ("Catapult Rotation = " + std::to_string(catarotationdegrees))); //print rotation sensor data on screen for debugging (not sure if this is gonna work)
      } 
    }
    else {
      Catapult.brake(); // holds the catapult in place
    }

    pros::delay(ez::util::DELAY_TIME);// This is used for timer calculations!  Keep this ez::util::DELAY_TIME
    //update od 
  }
  
    
}