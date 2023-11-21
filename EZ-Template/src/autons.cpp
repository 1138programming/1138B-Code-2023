#include "main.h"


/////
// For instalattion, upgrading, documentations and tutorials, check out website!
// https://ez-robotics.github.io/EZ-Template/
/////


const int DRIVE_SPEED = 110; // This is 110/127 (around 87% of max speed).  We don't suggest making this 127.
                             // If this is 127 and the robot tries to heading correct, it's only correcting by
                             // making one side slower.  When this is 87%, it's correcting by making one side
                             // faster and one side slower, giving better heading correction.
const int TURN_SPEED  = 90;
const int SWING_SPEED = 90;



///
// Constants
///

// It's best practice to tune constants when the robot is empty and with heavier game objects, or with lifts up vs down.
// If the objects are light or the cog doesn't change much, then there isn't a concern here.

void default_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void one_mogo_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void two_mogo_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}


void modified_exit_condition() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}




///
// Drive Example
///
void drive_example() {
  // The first parameter is target inches
  // The second parameter is max speed the robot will drive at
  // The third parameter is a boolean (true or false) for enabling/disabling a slew at the start of drive motions
  // for slew, only enable it when the drive distance is greater then the slew distance + a few inches


  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_drive_pid(-12, DRIVE_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-12, DRIVE_SPEED);
  chassis.wait_drive();
}



///
// Turn Example
///
void turn_example() {
  // The first parameter is target degrees
  // The second parameter is max speed the robot will drive at


  chassis.set_turn_pid(90, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();
}



///
// Combining Turn + Drive
///
void drive_and_turn() {
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_drive();
}



///
// Wait Until and Changing Max Speed
///
void wait_until_change_speed() {
  // wait_until will wait until the robot gets to a desired position


  // When the robot gets to 6 inches, the robot will travel the remaining distance at a max speed of 40
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_until(6);
  chassis.set_max_speed(40); // After driving 6 inches at DRIVE_SPEED, the robot will go the remaining distance at 40 speed
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  // When the robot gets to -6 inches, the robot will travel the remaining distance at a max speed of 40
  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_until(-6);
  chassis.set_max_speed(40); // After driving 6 inches at DRIVE_SPEED, the robot will go the remaining distance at 40 speed
  chassis.wait_drive();
}



///
// Swing Example
///
void swing_example() {
  // The first parameter is ez::LEFT_SWING or ez::RIGHT_SWING
  // The second parameter is target degrees
  // The third parameter is speed of the moving side of the drive


  chassis.set_swing_pid(ez::LEFT_SWING, 45, SWING_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_until(12);

  chassis.set_swing_pid(ez::RIGHT_SWING, 0, SWING_SPEED);
  chassis.wait_drive();
}



///
// Auto that tests everything
///
void combining_movements() {
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_swing_pid(ez::RIGHT_SWING, -45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_drive();
}



///
// Interference example
///
void tug (int attempts) {
  for (int i=0; i<attempts-1; i++) {
    // Attempt to drive backwards
    printf("i - %i", i);
    chassis.set_drive_pid(-12, 127);
    chassis.wait_drive();

    // If failsafed...
    if (chassis.interfered) {
      chassis.reset_drive_sensor();
      chassis.set_drive_pid(-2, 20);
      pros::delay(1000);
    }
    // If robot successfully drove back, return
    else {
      return;
    }
  }
}

// If there is no interference, robot will drive forward and turn 90 degrees. 
// If interfered, robot will drive forward and then attempt to drive backwards. 
void interfered_example() {
 chassis.set_drive_pid(24, DRIVE_SPEED, true);
 chassis.wait_drive();

 if (chassis.interfered) {
   tug(3);
   return;
 }

 chassis.set_turn_pid(90, TURN_SPEED);
 chassis.wait_drive();
}

void bo_6ball_code() {
  // chassis.set_drive_constants(12, 1, 0, 1.5, 0);
  // chassis.set_heading_constants(12, .25, 0, 1, 0);
  // chassis.set_turn_constants(12, 0.23, 0, 1, 0);
  // chassis.drive_settle_time = 0;
  // chassis.turn_settle_time = 0;
  Intake.move(-127);
  chassis.set_drive_pid(-24,127,false,false);
  chassis.wait_drive();
  chassis.set_turn_pid(45,127);
  chassis.wait_drive();
  chassis.set_drive_pid(-24,127,false,false);
  chassis.wait_drive();
  chassis.set_drive_pid(5,127,false,false);
  chassis.wait_drive();
  chassis.set_turn_pid(180,127);
  chassis.wait_drive(); 
  chassis.set_drive_pid(5,127,false,false);
  chassis.wait_drive();
  // vex::wait(100,msec);
  // Blocker.set(false);
  // Intake.spin(fwd,100,percent); //start intake
  // chassis.drive_distance(6); // drive to 1st triball
  // chassis.drive_distance(-40); // drive back
  // chassis.turn_timeout = 500;
  // chassis.turn_to_angle(330); //turn to push the preload
  // Wings.set(true);
  // hassis.heading_kp = 1.3;
  // chassis.heading_kd = 1.5;
  // chassis.drive_distance(-12,310); // push the preload a little bit towards the goal
  // chassis.heading_kp = 0.25;
  // chassis.heading_kd = 1;
  // chassis.drive_distance(-5,280);
  // chassis.drive_timeout = 500;
  // chassis.drive_distance(-18, 270);
  // chassis.drive_timeout = 1500;
  // Wings.set(false); // raise the wings
  // chassis.drive_distance(5);
  // chassis.turn_to_angle(110);
  // Intake.spinFor(reverse,500,msec); // outtake
  // chassis.drive_timeout  750;
  // chassis.drive_distance(20);
  // chassis.drive_timeout = 2000;
  // chassis.drive_distance(-15);
  // chassis.turn_to_angle(0);
  
  // // chassis.turn_to_angle(45);
  // Intake.spin(fwd,100,percent);
  // chassis.drive_distance(60, 43);;
  // chassis.turn_to_angle(160);
  // Intake.spinFor(reverse,500,msec);
  // Turn180();
  // Wings.set(true);
//   chassis.drive_timeout = 1200;
//   chassis.drive_distance(38, 180);
//   chassis.drive_distance(-24);
//   chassis.turn_to_angle(305);
//   chassis.drive_distance(24);
//   chassis.drive_distance(-16);
//   chassis.turn_to_angle(170);
//   chassis.drive_distance(30);
//   // chassis.turn_to_angle(90);
}

void winpoint() {
  chassis.set_angle(0);
  chassis.set_drive_pid(6, 90, false, true); // drive to hang
  chassis.wait_drive();   
  Wings.set_value(true);
  pros::delay(90);
  chassis.set_drive_pid(-10, 90, false, true); // descore match load station
  chassis.wait_drive(); 
  chassis.set_turn_pid(5,90); // start to turn to goal
  chassis.wait_drive();
  chassis.set_turn_pid(45,90);                 //turn
  chassis.set_drive_pid(4, 90, false, false);  //and drive to goal
  Wings.set_value(false);
  pros::delay(90);
  chassis.wait_drive();
  chassis.set_turn_pid(-150,90);  // flip to goal
  chassis.wait_drive();
  chassis.set_drive_pid(-15, 90, false, false); // score presload
  chassis.wait_drive(); 
  chassis.set_drive_pid(4, 90, false, false);
  chassis.wait_drive(); 
  chassis.set_drive_pid(-5, 90, false, false); // make sure preload is scored
  chassis.wait_drive(); 
  chassis.set_turn_pid(10,90); // turn to hang
  chassis.wait_drive();
  chassis.set_drive_pid(-12, 90, false, true); // drive to hang 
  chassis.wait_drive();   

  // chassis.set_turn_pid(145,100);
  // chassis.wait_drive();
  //  chassis.set_drive_pid(17, 90, false, false); // drive to hang
  // chassis.wait_drive(); 
  // 
  // chassis.set_drive_pid(0,120,false,false);

  chassis.set_turn_pid(-45,90);// face hang 
  chassis.wait_drive();
  chassis.set_drive_pid(-5, 90, false, true); // drive to hang
  chassis.wait_drive(); 
  // chassis.set_turn_pid(-215,100);
  chassis.set_drive_pid(-12, 90, false, false); // drive to hang
  chassis.wait_drive(); 

  chassis.set_drive_pid(0,120,false,false);

  // turn180();

  // chassis.set_drive_pid(-12, 90, false, false); // drive to hang
  // chassis.wait_drive(); 
  // // Lift.set_value(true);
  // chassis.set_drive_pid(0,120,false,false);
}



// . . .
// Make your own autonomous functions here!
// . . .

void oneballauto() {
  
chassis.set_drive_pid(-30, 127, false, false);
chassis.wait_drive(); 
chassis.set_drive_pid(0,100,false,false);
  // chassis.set_turn_pid(-45,127);
  // chassis.wait_drive();
  // chassis.set_drive_pid(-24, 127, false, true);
  // chassis.wait_drive(); 


  // chassis.set_turn_pid(45);
}

void fourball() { //working please
  chassis.set_angle(0);
  chassis.set_drive_pid(10,90,false,false);
  chassis.wait_drive();
  chassis.set_turn_pid(-40,50);
  chassis.wait_drive(); 
  chassis.set_drive_pid(16, 90, false, false);
  chassis.wait_drive();
  chassis.set_turn_pid(90, 50);
  chassis.wait_drive();
  Intake.move(-90);
  pros::delay(850);
  Intake.move(0);
  chassis.set_turn_pid(210, 90); // make 50 if it doesnt work
  chassis.wait_drive();
  Intake.move(127);
  chassis.set_drive_pid(7, 45, false, false);
  chassis.wait_drive();
  chassis.set_drive_pid(-5, 45, false, false);
  chassis.wait_drive();
  chassis.set_turn_pid(80, 90);
  chassis.wait_drive();
  chassis.set_drive_pid(15, 75, false, false);
  chassis.wait_drive();
  Intake.move(-127);
  chassis.set_drive_pid(0,100,false,false);
  //experimental
  // chassis.set_drive_pid(-2,100,false,false);
  // chassis.wait_drive();
  // chassis.set_turn_pid(90,90);
  // chassis.set_drive_pid(-8,90,false,false);
  // chassis.wait_drive();
  // chassis.set_turn_pid(0,90);
  // Intake.move(127);
  // chassis.set_drive_pid(8,90,false,false);
  // chassis.wait_drive();
  // chassis.set_turn_pid(90,90);
  // chassis.wait_drive();
  // chassis.set_drive_pid(10,90,false,false);
}

void fourballv2() {
  chassis.set_angle(0);
  chassis.set_drive_pid(6,90,false,false);
  chassis.wait_drive();
  chassis.set_turn_pid(-40,50);
  chassis.wait_drive();
  chassis.set_drive_pid(17, 90, false, false);
  chassis.wait_drive();
  chassis.set_turn_pid(90, 50);
  chassis.wait_drive();
  Intake.move(-127);
  pros::delay(750);
  Intake.move(0);
  chassis.set_turn_pid(260, 50);
  chassis.wait_drive();
  Intake.move(127);
  chassis.set_drive_pid(5, 45, false, false);
  chassis.wait_drive();
  chassis.set_drive_pid(-5, 45, false, false);
  chassis.wait_drive();
  chassis.set_turn_pid(75, 90);
  chassis.wait_drive();
  chassis.set_drive_pid(25, 75, false, false);
}

void turn180() {
  double currentangle = chassis.get_gyro();
  chassis.set_turn_pid(currentangle - 180 ,100);
}